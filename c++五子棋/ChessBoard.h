#pragma once
#include"config.h"
class CChessBoard
{
public:
	int m_flag;//游戏结束标志
	int m_step;//游戏步数
	int m_remx;//悔棋记录
	int m_remy;
	int m_arr[NUM_LINE][NUM_LINE];//记录棋子数组
	int m_kind;//棋子种类
public:
	CChessBoard(void);
	~CChessBoard(void);
public:
	void init_begin();//初始化游戏开始界面
	void init_board();//初始化棋盘
	void put_chess(int,int);//下棋
	bool ifwin(int,int);//判断是否胜利
	void rem_chess(int x,int y);//悔棋
	bool if_begin(int,int);//根据点击判断是否开始游戏
	bool if_end(int,int);//根据点击判断是否接收游戏
	bool if_put(int,int);//判断是否落子
	bool if_rem(int,int);//判断是否悔棋
	bool if_lose(int,int);//判断是否认输
};