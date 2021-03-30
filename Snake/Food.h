#pragma once
#include "MapDesign.h"
#include <vector>
using namespace std;

class Food {
public:

	//x轴坐标
	int x;
	//y轴坐标
	int y;
	//类型
	int type;
	//表现方式
	const char* typeContent;
	/**
	 *	有参构造
	 *
	 * @param type 食物类型
	 * @param typeContent	食物的字符串表现方式
	 */
	Food(int type, const char* typeContent);


	/**
	 *	随机生成食物位置
	 *
	 * @param MapDesign 地图类引用
	 */
	void randomCoord(MapDesign& mapDesign);
	/**
	 *	创建食物
	 *
	 * @param MapDesign 地图类引用
	 */
	void createFood(MapDesign& mapDesign);
	/**
	 *	绘制食物
	 *
	 * @param MapDesign 地图类引用
	 */
	void drawFood(MapDesign& mapDesign);
private:

};