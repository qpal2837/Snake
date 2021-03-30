#pragma once
#include "Draw.h"
#include <string>
#include "Element.h"
#include <windows.h>
class MapDesign {
public:
	int length = 0;
	int width = 0;
	int allLength;
	int allWidth;
	int*** map;



	int scoreWordX = 51;
	int scoreWordY = 3;
	int scoreX = 55;
	int scoreY = 3;
	int pauseTipX = 51;
	int pauseTipY = 5;
	int setSpeedTipX = 51;
	int setSpeedTipY = 7;
	int saveTipX = 51;
	int saveTipY = 9;
	int terrainTipX = 51;
	int terrainTipY = 11;
	int controlSnakeTipX = 51;
	int controlSnakeTipY = 13;
	int controlSnakeBTipX = 51;
	int controlSnakeBTipY = 15;
	int customMapTipX = 51;
	int customMapTipY = 17;

	MapDesign();
	/**
	 *	�вι���
	 *
	 *	@param	length		����򳤶�
	 *	@param	width		�������
	 *	@param	allLength	�ܳ���
	 *	@param	allWidth	�ܿ��
	 */
	MapDesign(int length, int width, int allLength, int allWidth);
	/**
	 *	���Ƶ�ͼ
	 *
	 *	@param Draw&	���������
	 */
	void drawMap(Draw& draw);

	~MapDesign();
};