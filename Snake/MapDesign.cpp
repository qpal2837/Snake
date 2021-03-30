
#include "MapDesign.h"
MapDesign::MapDesign() {}
MapDesign::~MapDesign() {
	if (this->map != nullptr) {
		delete map;
		map = nullptr;
	}
}
MapDesign::MapDesign(int length, int width, int allLength, int allWidth) :length(length), width(width)
, allLength(allLength), allWidth(allWidth) {
	map = new int** [this->allLength];
	for (int i = 0; i < this->allLength; i++) {
		map[i] = new int* [this->allWidth];
		for (int j = 0; j < this->allWidth; j++) {
			map[i][j] = new int[2];
		}
	}
	for (int i = 0; i < this->allLength; i++) {
		for (int j = 0; j < this->allWidth; j++) {
			map[i][j][0] = VACANCY;
			map[i][j][1] = VACANCY;
		}
	}
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			if (i == 0 || j == 0 || i == length - 1 || j == width - 1) {
				map[i][j][0] = WALL;
			}
		}
	}
	for (int i = 0; i < allLength; i++) {
		for (int j = width; j < allWidth; j++) {
			if (j == allWidth - 1 || j == 0 || i == 0 || i == allLength - 1) {
				map[i][j][0] = WALL;
			}
		}
	}
}

void MapDesign::drawMap(Draw& draw) {
	for (int i = 0; i < allLength; i++) {
		for (int j = 0; j < allWidth; j++) {
			switch (map[i][j][0]) {
			case VACANCY:
				draw.writeChar({ (short)j ,(short)i }, WHITE_COLOR, VACANCY_CONTENT);
				break;
			case WALL:
				draw.writeChar({ (short)j ,(short)i }, WHITE_COLOR, WALL_CONTENT);
				break;
			case ICE:
				draw.writeChar({ (short)j ,(short)i }, COLOR_CYAN, ICE_CONTENT);
				break;
			case GRASS:
				draw.writeChar({ (short)j ,(short)i }, COLOR_RED, GRASS_CONTENT);
				break;
			default:
				break;
			}
		}
	}
	draw.writeChar({ (short)scoreWordX,(short)scoreWordY }, WHITE_COLOR, "����:");
	draw.writeInt({ (short)scoreX,(short)scoreY }, WHITE_COLOR, 0);
	draw.writeChar({ (short)pauseTipX,(short)pauseTipY }, WHITE_COLOR, "��ͣ/��ʼ��:P");
	draw.writeChar({ (short)setSpeedTipX,(short)setSpeedTipY }, WHITE_COLOR, "���ټ�:= ���ټ�:-");
	draw.writeChar({ (short)saveTipX,(short)saveTipY }, WHITE_COLOR, "�浵��:I");
	draw.writeChar({ (short)terrainTipX,(short)terrainTipY }, WHITE_COLOR, "����:��-�ƶ��ٶȱ��  ��-�ƶ��ٶȱ���");
	draw.writeChar({ (short)controlSnakeTipX,(short)controlSnakeTipY }, WHITE_COLOR, "1P:��W ��S ��A ��D");
	draw.writeChar({ (short)controlSnakeBTipX,(short)controlSnakeBTipY }, WHITE_COLOR, "2P:��U ��J ��H ��K");
	draw.writeChar({ (short)customMapTipX,(short)customMapTipY }, WHITE_COLOR, "�Զ����ͼ����: ");
	draw.writeChar({ (short)customMapTipX,(short)customMapTipY + 1 },WHITE_COLOR, "0 + ������:ש��");
	draw.writeChar({ (short)customMapTipX,(short)customMapTipY + 2 }, WHITE_COLOR, "3 + ������:����");
	draw.writeChar({ (short)customMapTipX,(short)customMapTipY + 3 }, WHITE_COLOR, "4 + ������:�ݴ�");
	draw.writeChar({ (short)customMapTipX,(short)customMapTipY + 4 }, WHITE_COLOR, "5 + ������:�յ�");
	draw.writeChar({ (short)customMapTipX,(short)customMapTipY + 5 }, WHITE_COLOR, "�س���:��ʼ");
}
