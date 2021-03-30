#pragma once
#include "Snake.h"
#include "MapDesign.h"
#include "Food.h"
#include "windows.h"
#include "Show.h"
#include "SaveData.h"
#include "SaveDataFormat.h"
#include "Value.h"
class Manage {
public:
	//画板类对象
	Draw draw=Draw::getDraw();
	//地图类指针
	MapDesign *mapDesign;
	//蛇对象
	Snake snake;
	//p2蛇对象
	Snake snakeB;
	//记录食物的集合
	vector<Food> foodList;
public:
	int score = 0;
	Manage();
	/**
	 *	开始游戏
	 *
	 */
	void startGame();
	/**
	 *	继续游戏
	 *
	 */
	void continueGame();
	/**
	 *	用户输入控制
	 *
	 */
	void control();
	/**
	 *	控制蛇
	 * 
	 *	@param int 用户输入值
	 */
	void controlSnake( int value);
	/**
	 *	蛇移动
	 *
	 */
	void moveSnake();
	/**
	 *	控制蛇移动速度
	 * 
	 *	@param int 用户输入值
	 */
	void controlSnakeSpeed(int value);
	/**
	 *	控制暂停恢复
	 *
	 *	@param int 用户输入值
	 */
	void controlPause(int value);
	/**
	 *	控制存档
	 *	@param int 用户输入值
	 */
	void controlSave(int value);
	/**
	 *	更新分数
	 *	
	 *	@param int 分数
	 */
	void updateScore(int score);
	/**
	 *	展示菜单
	 *
	 */
	void showMenu();
	/**
	 *	调整窗口
	 *
	 */
	void setWindows();
	/**
	 *	创建食物
	 *
	 */
	void createFood();
	/**
	 *	播放音乐
	 *
	 */
	void playMusic();
	/**
	 *	从地图上获取食物坐标
	 *
	 */
	void getFoodForMap();
	/**
	 *	创建地形
	 *
	 */
	void createTerrain();
	/**
	 *	双人游戏模式
	 *
	 */
	void doubleModeGame();
	/**
	 *	绘制蛇
	 *
	 */
	void drawSnake();
	/**
	 *	接收鼠标事件
	 *
	 */
	void mouseLoop();
	/**
	 *	自定义地图模式
	 *
	 */
	void customMapGame();
	/**
	 *	播放死亡音效
	 *
	 */
	void playDeadMusic();
	/**
	 *	播放吃食物音效
	 *
	 */
	void playEatMusic();
	~Manage();
};