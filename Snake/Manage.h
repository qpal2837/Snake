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
	//���������
	Draw draw=Draw::getDraw();
	//��ͼ��ָ��
	MapDesign *mapDesign;
	//�߶���
	Snake snake;
	//p2�߶���
	Snake snakeB;
	//��¼ʳ��ļ���
	vector<Food> foodList;
public:
	int score = 0;
	Manage();
	/**
	 *	��ʼ��Ϸ
	 *
	 */
	void startGame();
	/**
	 *	������Ϸ
	 *
	 */
	void continueGame();
	/**
	 *	�û��������
	 *
	 */
	void control();
	/**
	 *	������
	 * 
	 *	@param int �û�����ֵ
	 */
	void controlSnake( int value);
	/**
	 *	���ƶ�
	 *
	 */
	void moveSnake();
	/**
	 *	�������ƶ��ٶ�
	 * 
	 *	@param int �û�����ֵ
	 */
	void controlSnakeSpeed(int value);
	/**
	 *	������ͣ�ָ�
	 *
	 *	@param int �û�����ֵ
	 */
	void controlPause(int value);
	/**
	 *	���ƴ浵
	 *	@param int �û�����ֵ
	 */
	void controlSave(int value);
	/**
	 *	���·���
	 *	
	 *	@param int ����
	 */
	void updateScore(int score);
	/**
	 *	չʾ�˵�
	 *
	 */
	void showMenu();
	/**
	 *	��������
	 *
	 */
	void setWindows();
	/**
	 *	����ʳ��
	 *
	 */
	void createFood();
	/**
	 *	��������
	 *
	 */
	void playMusic();
	/**
	 *	�ӵ�ͼ�ϻ�ȡʳ������
	 *
	 */
	void getFoodForMap();
	/**
	 *	��������
	 *
	 */
	void createTerrain();
	/**
	 *	˫����Ϸģʽ
	 *
	 */
	void doubleModeGame();
	/**
	 *	������
	 *
	 */
	void drawSnake();
	/**
	 *	��������¼�
	 *
	 */
	void mouseLoop();
	/**
	 *	�Զ����ͼģʽ
	 *
	 */
	void customMapGame();
	/**
	 *	����������Ч
	 *
	 */
	void playDeadMusic();
	/**
	 *	���ų�ʳ����Ч
	 *
	 */
	void playEatMusic();
	~Manage();
};