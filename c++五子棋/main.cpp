#include"config.h"
#include"ChessBoard.h"


int main()
{
	CChessBoard * CCboard = new CChessBoard;
	CCboard->init_board();
	CCboard->init_begin();
	MOUSEMSG msg;
	while(1)
	{
		msg = GetMouseMsg();
		if(msg.uMsg == WM_LBUTTONDOWN)
		{
			if(CCboard->if_begin(msg.x,msg.y))
			{
				cleardevice();
				CCboard->init_board();
				CCboard->init_begin();
				while(CCboard->m_flag)
				{
					msg = GetMouseMsg();
					if(msg.uMsg == WM_LBUTTONDOWN)
					{
						if(CCboard->if_put(msg.x,msg.y))
							CCboard->put_chess(msg.x,msg.y);
						if(CCboard->if_rem(msg.x,msg.y))
						{
							CCboard->rem_chess(CCboard->m_remx,CCboard->m_remy);
						}
						if(CCboard->if_lose(msg.x,msg.y))
						{
							outtextxy(633, 443,"ÄãÊäÁË~                  ");
							CCboard->m_flag = 0;
						}
						if(CCboard->if_end(msg.x,msg.y))
						{
							delete(CCboard);
							CCboard = NULL;
							return 0;
						}
					}
					
				}
			}
			if(CCboard->if_end(msg.x,msg.y))
			{
				delete(CCboard);
				CCboard = NULL;
				return 0;
			}
		}
	}


	return 0;
}





