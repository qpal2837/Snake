#include "Food.h"
//
//void Food::effect(Snake* snake) {
//	snake->setLength(snake->getLength() + 1);
//}



Food::Food(int type, const char* typeContent) {
	this->type = type;
	this->typeContent = typeContent;
}

void Food::randomCoord(MapDesign& mapDesign) {
	srand(time(NULL));
	int randomLength = mapDesign.length - 3;
	int randomWidth = mapDesign.width - 3;
	
	while (true) {
		this->x = rand() % randomWidth + 1;
		this->y = rand() % randomLength + 1;
		if (mapDesign.map[this->y][this->x][1]==VACANCY)
		{
			mapDesign.map[this->y][this->x][1] = this->type;
			break;
		}
		
	}


}

void Food::drawFood(MapDesign& mapDesign) {
	Draw& draw = Draw::getDraw();
	draw.writeChar({ (short)this->x,(short)this->y }, WHITE_COLOR, this->typeContent);
}
///*
//void Food::effect(Snake* snake) */{
//}

void Food::createFood(MapDesign& mapDesign) {
	randomCoord(mapDesign);
	drawFood(mapDesign);
}