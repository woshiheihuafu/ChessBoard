#pragma once
#include"config.h"
class CChessBoard
{
public:
	int m_flag;//��Ϸ������־
	int m_step;//��Ϸ����
	int m_remx;//�����¼
	int m_remy;
	int m_arr[NUM_LINE][NUM_LINE];//��¼��������
	int m_kind;//��������
public:
	CChessBoard(void);
	~CChessBoard(void);
public:
	void init_begin();//��ʼ����Ϸ��ʼ����
	void init_board();//��ʼ������
	void put_chess(int,int);//����
	bool ifwin(int,int);//�ж��Ƿ�ʤ��
	void rem_chess(int x,int y);//����
	bool if_begin(int,int);//���ݵ���ж��Ƿ�ʼ��Ϸ
	bool if_end(int,int);//���ݵ���ж��Ƿ������Ϸ
	bool if_put(int,int);//�ж��Ƿ�����
	bool if_rem(int,int);//�ж��Ƿ����
	bool if_lose(int,int);//�ж��Ƿ�����
};