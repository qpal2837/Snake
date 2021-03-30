
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
	draw.writeChar({ (short)scoreWordX,(short)scoreWordY }, WHITE_COLOR, "分数:");
	draw.writeInt({ (short)scoreX,(short)scoreY }, WHITE_COLOR, 0);
	draw.writeChar({ (short)pauseTipX,(short)pauseTipY }, WHITE_COLOR, "暂停/开始键:P");
	draw.writeChar({ (short)setSpeedTipX,(short)setSpeedTipY }, WHITE_COLOR, "加速键:= 减速键:-");
	draw.writeChar({ (short)saveTipX,(short)saveTipY }, WHITE_COLOR, "存档键:I");
	draw.writeChar({ (short)terrainTipX,(short)terrainTipY }, WHITE_COLOR, "地形:冰-移动速度变快  草-移动速度变慢");
	draw.writeChar({ (short)controlSnakeTipX,(short)controlSnakeTipY }, WHITE_COLOR, "1P:上W 下S 左A 右D");
	draw.writeChar({ (short)controlSnakeBTipX,(short)controlSnakeBTipY }, WHITE_COLOR, "2P:上U 下J 左H 右K");
	draw.writeChar({ (short)customMapTipX,(short)customMapTipY }, WHITE_COLOR, "自定义地图按键: ");
	draw.writeChar({ (short)customMapTipX,(short)customMapTipY + 1 },WHITE_COLOR, "0 + 鼠标左键:砖块");
	draw.writeChar({ (short)customMapTipX,(short)customMapTipY + 2 }, WHITE_COLOR, "3 + 鼠标左键:冰块");
	draw.writeChar({ (short)customMapTipX,(short)customMapTipY + 3 }, WHITE_COLOR, "4 + 鼠标左键:草丛");
	draw.writeChar({ (short)customMapTipX,(short)customMapTipY + 4 }, WHITE_COLOR, "5 + 鼠标左键:空地");
	draw.writeChar({ (short)customMapTipX,(short)customMapTipY + 5 }, WHITE_COLOR, "回车键:开始");
}
