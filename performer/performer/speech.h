#pragma once
#include<iostream>
#include<vector>
#include "speaker.h"
#include<map>
#include<algorithm>
#include <random>
#include<ctime>
#include<deque>
#include<functional>
#include<numeric>
#include<fstream>


class SpeedManager
{
public:
	//构造函数
	SpeedManager();

	//菜单
	void menu();
	//初始化容器和属性
	void initSpeech();

	//创建选手
	void CreateSpeaker();

	//开始比赛
	void StartSpeech();

	//抽签
	void speedDraw();

	//比赛
	void Speechcontest();

	//显示结果
	void showScore();

	//保存记录
	void saveRecord();

	//读取记录
	void loadRecord();

	//判断文件是否为空
	bool fileempty;


	//查看记录
	void showRcord();

	//清空记录
	void clearRecord();


	//存放往届记录的容器
	map<int, vector<string>>M_Record;


	//0.退出系统
	void exitManager();

	//析构
	~SpeedManager();



	//成员属性
	//保存第一轮比赛选手编号容器
	vector<int>v1;


	//第一轮晋级选手编号容器
	vector<int>v2;

	//胜出前三名选手编号容器
	vector<int>vVictory;

	//存放编号以及对应具体选手容器
	map<int, Speaker>m_Speaker;

	//存放比赛轮数
	int m_Index;
};