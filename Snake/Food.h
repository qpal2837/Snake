#pragma once
#include "MapDesign.h"
#include <vector>
using namespace std;

class Food {
public:

	//x������
	int x;
	//y������
	int y;
	//����
	int type;
	//���ַ�ʽ
	const char* typeContent;
	/**
	 *	�вι���
	 *
	 * @param type ʳ������
	 * @param typeContent	ʳ����ַ������ַ�ʽ
	 */
	Food(int type, const char* typeContent);


	/**
	 *	�������ʳ��λ��
	 *
	 * @param MapDesign ��ͼ������
	 */
	void randomCoord(MapDesign& mapDesign);
	/**
	 *	����ʳ��
	 *
	 * @param MapDesign ��ͼ������
	 */
	void createFood(MapDesign& mapDesign);
	/**
	 *	����ʳ��
	 *
	 * @param MapDesign ��ͼ������
	 */
	void drawFood(MapDesign& mapDesign);
private:

};