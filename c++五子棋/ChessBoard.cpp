#include "ChessBoard.h"
CChessBoard::CChessBoard(void)
{
	for(int i=0;i<NUM_LINE;i++)
	{
		for(int j=0;j<NUM_LINE;j++)
		{
			m_arr[i][j] = 0;
		}
	}
	m_flag = 1;
	m_step = 0;
	m_remx = 0;
	m_remy = 0;
	m_kind = 1;
}


CChessBoard::~CChessBoard(void)
{
	for(int i=0;i<NUM_LINE;i++)
	{
		for(int j=0;j<NUM_LINE;j++)
		{
			m_arr[i][j] = 0;
		}
	}
}

void CChessBoard::init_begin()
{
	rectangle(680,200,760,240);//��ʼ��Ϸ
	rectangle(680,260,760,300);//����
	rectangle(680,320,760,360);//����
	rectangle(680,380,760,420);//�˳���Ϸ
	rectangle(630,440,780,480);//������˭��
	outtextxy(683, 203, _T("��ʼ��Ϸ"));
	outtextxy(683, 263, _T("����"));
	outtextxy(683, 323, _T("����"));
	outtextxy(683, 383, _T("�˳���Ϸ"));
	for(int i=0;i<NUM_LINE;i++)
	{
		for(int j=0;j<NUM_LINE;j++)
		{
			m_arr[i][j] = 0;
		}
	}
	m_step = 0;//��Ϸ����
	m_kind = 1;//��������
	m_flag = 1;
	char str[20];
	sprintf(str,"����%d����,������",m_step++);
	outtextxy(633, 443,&str[0]);
}
void CChessBoard::init_board()
{
	initgraph(800, 630);//��ʼ������
	setbkcolor(RGB(189,183,107));//������ɫ����Ϊ��ɫ
	cleardevice();//�ñ���ɫ�����Ļ
	setlinestyle(PS_SOLID, 2);  // ��ʵ�ߣ����Ϊ2������
	setcolor(RGB(0, 0, 0));  // ����Ϊ��ɫ
	for(int i=1;i<=NUM_LINE;i++)
	{
		line(1*STEP,i*STEP,NUM_LINE*STEP,i*STEP);//����
		line(i*STEP,1*STEP,i*STEP,NUM_LINE*STEP);//����
	}
}
bool CChessBoard::ifwin(int x,int y)
{
	int count = 0;
	while(x+1<=15 && m_arr[x][y] == m_arr[x+1][y])//����
	{
		x++;
	}
	while(x-1>=0 && m_arr[x][y] == m_arr[x-1][y])
	{
		x--;
		count++;
	}
	if(count >= 4) return true;
	count = 0;

	while(y+1 <=15 && m_arr[x][y] == m_arr[x][y+1])//����
	{
		y++;
	}
	while(y-1>=0 && m_arr[x][y] == m_arr[x][y-1])
	{
		y--;
		count++;
	}
	if(count >= 4) return true;
	count = 0;

	while(y+1 <=15 && x+1<=15 && m_arr[x][y] == m_arr[x+1][y+1])//��б
	{
		y++;
		x++;
	}
	while(y-1>=0 && x-1>=0 && m_arr[x][y] == m_arr[x-1][y-1])
	{
		y--;
		x--;
		count++;
	}
	if(count >= 4) return true;
	count = 0;

	while(y+1 <=15 && x-1>=0 && m_arr[x][y] == m_arr[x-1][y+1])//��б
	{
		y++;
		x--;
	}
	while(y-1>=0 && x+1<=15 && m_arr[x][y] == m_arr[x+1][y-1])
	{
		y--;
		x++;
		count++;
	}
	if(count >= 4) return true;
	return false;
}
void CChessBoard::put_chess(int mouse_x,int mouse_y)
{
	char str[20];//���Ҫ��ʾ����
	int xx = (mouse_x-STEP)/STEP;//ȥ�ߺ������1-15
	int yy = (mouse_y-STEP)/STEP;
	if(((mouse_x-STEP)- xx*STEP >= STEP-WORK_SIZE || (mouse_x-STEP)- xx*STEP <= WORK_SIZE) && ((mouse_y-STEP)- yy*STEP >=STEP-WORK_SIZE || (mouse_y-STEP)- yy*STEP <= WORK_SIZE))
	{
		if((mouse_x-STEP)- xx*STEP >=STEP-WORK_SIZE) xx++;
		if((mouse_y-STEP)- yy*STEP >=STEP-WORK_SIZE) yy++;
		if(m_arr[xx][yy] == 0)
		{
			PlaySound(TEXT("chess.wav"), NULL, SND_FILENAME | SND_ASYNC);
			//Sleep(1000);
			if(m_step % 2 == 0)
			sprintf(str,"����%d����,������",m_step++);
			else
				sprintf(str,"����%d����,������",m_step++);
			outtextxy(633, 443,str);
			strcpy(str, "");
			mouse_x = xx*STEP + STEP;
			mouse_y = yy*STEP + STEP;
			//setcolor(RED);
			if(m_kind == 1)
				setfillcolor(BLACK);
			else
				setfillcolor(WHITE);
			//setwritemode(R2_XORPEN);
			m_remx = xx;
			m_remy = yy;
			fillcircle(mouse_x,mouse_y,WORK_SIZE);
			m_arr[xx][yy] = m_kind;
			if(ifwin(xx,yy))
			{
				if(m_kind == 1)
				{
					m_flag = 0;
					outtextxy(633, 443,"��Ӯ��!                  ");
				}
				else
				{
					m_flag = 0;
					outtextxy(633, 443,"������~                  ");
				}
			}
			if(m_kind == 1)
			{
				m_kind = 2;
			}
			else
			{
				m_kind = 1;
			}
		}
	}
}
bool CChessBoard::if_begin(int mouse_x,int mouse_y)
{
	if(mouse_x >= 680 && mouse_x <= 760 && mouse_y >=200 && mouse_y <= 240)
		return true;
	return false;
}
bool CChessBoard::if_end(int mouse_x,int mouse_y)
{
	if(mouse_x >= 680 && mouse_x <= 760 && mouse_y >=380 && mouse_y <= 420)
		return true;
	return false;
}
bool CChessBoard::if_put(int x,int y)
{
	if(x >= STEP && x<=STEP*NUM_LINE && y>=STEP && y<= STEP*NUM_LINE)
		return true;
	return false;
}
bool CChessBoard::if_rem(int x,int y)
{
	if(x >= 680 && x <= 760 && y >= 260 && y <= 300)
		return true;
	return false;
}
bool CChessBoard::if_lose(int x,int y)
{
	if(x >= 680 && x <= 760 && y >=320 && y <= 360)
		return true;
	return false;
}
void CChessBoard::rem_chess(int x,int y)
{
	char str[20];
	setfillcolor(RGB(189,183,107));
	solidrectangle((x+1)*STEP-WORK_SIZE-1, (y+1)*STEP+WORK_SIZE+1, (x+1)*STEP+WORK_SIZE+1,(y+1)*STEP-WORK_SIZE-1);
	if(x!=0)
		line((x+1)*STEP-WORK_SIZE-2,(y+1)*STEP,(x+1)*STEP,(y+1)*STEP);
	if(x!=14)
		line((x+1)*STEP,(y+1)*STEP,(x+1)*STEP+WORK_SIZE+2,(y+1)*STEP);
	if(y!=0)
		line((x+1)*STEP,(y+1)*STEP-WORK_SIZE-2,(x+1)*STEP,(y+1)*STEP);
	if(y!=14)
		line((x+1)*STEP,(y+1)*STEP,(x+1)*STEP,(y+1)*STEP+WORK_SIZE+2);
	m_arr[x][y] = 0;
	m_step-=2;
	if(m_step % 2 == 0)
		sprintf(str,"����%d����,������",m_step++);
	else
		sprintf(str,"����%d����,������",m_step++);
	if(m_kind == 1)
	{
		m_kind = 2;
	}
	else
	{
		m_kind = 1;
	}
	outtextxy(633, 443,str);
}