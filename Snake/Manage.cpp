#include "Manage.h"
#include "Terrain.h"
#pragma comment(lib,"winmm.lib")


void Manage::showMenu() {
	Show show{};
	show.showMenu();
	cout << "请输入" << endl;
	int choice = 0;
	cin >> choice;
	switch (choice) {
	case 1:
		startGame();
		break;
	case 2:
		continueGame();
		break;
	case 3:
		doubleModeGame();
		break;
	case 4:
		customMapGame();
		break;
	default:
		return;
	}
}

void Manage::setWindows() {
	system("mode con cols=200 lines=200");
	keybd_event(VK_SHIFT, 0, 0, 0);
	Sleep(100);
	keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
}

void Manage::createFood() {
	Food food{ FOOD_APPLE,FOOD_APPLE_CONTENT };
	Food foodPOISON{ FOOD_POISON_APPLE,FOOD_POISON_APPLW_CONTENT };
	food.createFood(*(this->mapDesign));
	foodPOISON.createFood(*(this->mapDesign));
	this->foodList.push_back(food);
	this->foodList.push_back(foodPOISON);
}
void Manage::createTerrain() {
	Terrain terrainIce{ ICE,ICE_CONTENT,COLOR_CYAN };
	Terrain terrainGrass{ GRASS,GRASS_CONTENT,COLOR_RED };
	terrainIce.createTerrain(*(this->mapDesign));
	terrainGrass.createTerrain(*(this->mapDesign));
}
void Manage::drawSnake() {
}
void Manage::playDeadMusic() {
	PlaySoundA("sound\\dead.wav", NULL, SND_ASYNC | SND_NODEFAULT);

}
void Manage::playEatMusic() {
	PlaySoundA("sound\\eat.wav", NULL, SND_ASYNC | SND_NODEFAULT);

}
void Manage::playMusic() {
	PlaySoundA("sound\\start.wav", NULL, SND_ASYNC | SND_NODEFAULT);

}


Manage::Manage() {
	this->mapDesign = new MapDesign(MAP_LENGTH, MAP_WIDTH, MAP_ALL_LENGTH, MAP_ALL_WIDTH);
}

void Manage::startGame() {

	playMusic();
	setWindows();
	createTerrain();
	this->mapDesign->drawMap(this->draw);
	this->snake.init(*mapDesign, this->draw);
	createFood();

	moveSnake();


}
void Manage::continueGame() {

	SaveData saveData{};
	SaveDataFormat saveDataFormat{};
	saveData.read(saveDataFormat, *(this->mapDesign), this->snake);
	if (saveDataFormat.valid != 1) {
		cout << "当前不存在有效的存档" << endl;
		return;
	}
	this->snake.x = saveDataFormat.x;
	this->snake.y = saveDataFormat.y;
	this->snake.color = saveDataFormat.color;
	this->snake.length = saveDataFormat.length;
	this->snake.moveFlag = saveDataFormat.moveFlag;
	this->snake.moveWay = saveDataFormat.moveWay;
	this->score = saveDataFormat.score;
	this->snake.speed = saveDataFormat.speed;
	this->snake.status = saveDataFormat.status;
	SaveDataFormat saveDataFormatB{};
	saveData.readSnakeB(saveDataFormatB, this->snakeB);
	if (saveDataFormatB.valid == 1) {
		this->snakeB.x = saveDataFormatB.x;
		this->snakeB.y = saveDataFormatB.y;
		this->snakeB.color = saveDataFormatB.color;
		this->snakeB.length = saveDataFormatB.length;
		this->snakeB.moveFlag = saveDataFormatB.moveFlag;
		this->snakeB.moveWay = saveDataFormatB.moveWay;
		this->snakeB.speed = saveDataFormatB.speed;
		this->snakeB.status = saveDataFormatB.status;
	}

	this->mapDesign->drawMap(this->draw);
	getFoodForMap();
	playMusic();
	moveSnake();
}
void Manage::doubleModeGame() {
	playMusic();
	setWindows();
	createTerrain();
	this->mapDesign->drawMap(this->draw);
	this->snake.init(*mapDesign, this->draw);
	this->snakeB.color = WHITE_COLOR;
	this->snakeB.init(*mapDesign, this->draw);
	createFood();
	moveSnake();
}
void Manage::customMapGame() {
	setWindows();
	createTerrain();
	this->mapDesign->drawMap(this->draw);
	mouseLoop();
	playMusic();
	this->snake.init(*mapDesign, this->draw);
	createFood();
	moveSnake();
}
void Manage::getFoodForMap() {

	for (int i = 0; i < this->mapDesign->length; i++) {
		for (int j = 0; j < this->mapDesign->width; j++) {
			if (mapDesign->map[i][j][1] == FOOD_APPLE) {
				Food food{ FOOD_APPLE,FOOD_APPLE_CONTENT };
				food.x = j;
				food.y = i;
				this->foodList.push_back(food);
				food.drawFood(*(this->mapDesign));
			}
			if (mapDesign->map[i][j][1] == FOOD_POISON_APPLE) {
				Food food{ FOOD_POISON_APPLE,FOOD_POISON_APPLW_CONTENT };
				food.x = j;
				food.y = i;
				this->foodList.push_back(food);
				food.drawFood(*(this->mapDesign));
			}
		}
	}
}

void Manage::moveSnake() {
	updateScore(this->score);
	while (true) {
		draw.hideCursor();
		control();
		if (this->snake.moveFlag && this->snake.status == 1) {
			int result = this->snake.moveSnake(*(this->mapDesign), this->draw, this->foodList);
			if (result == -1) {
				playDeadMusic();
				Show show{};
				show.showGameOver();
				break;
			}
			if (result > 0) {
				playEatMusic();
				playMusic();
				this->score += result;
				updateScore(this->score);
			}
			Sleep(this->snake.speed);
		}

		if (this->snakeB.moveFlag && this->snakeB.status == 1) {
			int result = this->snakeB.moveSnake(*(this->mapDesign), this->draw, this->foodList);
			if (result == -1) {
				playDeadMusic();

				Show show{};
				show.showGameOver();
				break;
			}
			if (result > 0) {
				playEatMusic();
				playMusic();

				this->score += result;
				updateScore(this->score);
			}
			Sleep(this->snakeB.speed);
		}
	}
}
void Manage::mouseLoop() {
	this->draw.hideCursor(true);
	HANDLE input = GetStdHandle(STD_INPUT_HANDLE);


	DWORD count = 0;
	INPUT_RECORD input_record = { 0 };


	DWORD mode = 0;
	GetConsoleMode(input, &mode);
	SetConsoleMode(input, mode | ENABLE_MOUSE_INPUT);
	int df = '0' - 0;
	int value = WALL;

	while (ReadConsoleInput(input, &input_record, 1, &count)) {


		if (input_record.EventType == MOUSE_EVENT) {
			value = _getch();
			if (value == 13) {
				return;
			}
			value -= df;
			auto mosue_event = input_record.Event.MouseEvent;
			auto point = mosue_event.dwMousePosition;
			char buffer[0x20] = { 0 };
			this->draw.writeChar({ 0, 0 }, WHITE_COLOR, buffer);
			if (mosue_event.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
				if (point.X / 2 > 0 && point.X / 2 < this->mapDesign->length-1 && point.Y > 0 && point.Y < this->mapDesign->width - 1) {
					switch (value) {
					case WALL:
						this->draw.writeChar({ point.X / 2, point.Y }, WHITE_COLOR, WALL_CONTENT);
						this->mapDesign->map[point.Y][point.X/2][0] = WALL;
						break;
					case ICE:
						this->draw.writeChar({ point.X / 2, point.Y }, COLOR_CYAN, ICE_CONTENT);
						this->mapDesign->map[point.Y][point.X/2][0] = ICE;

						break;
					case GRASS:
						this->draw.writeChar({ point.X / 2, point.Y }, COLOR_RED, GRASS_CONTENT);
						this->mapDesign->map[point.Y][point.X/2][0] = GRASS;
						break;
					default:
						this->draw.writeChar({ point.X / 2, point.Y }, COLOR_RED, VACANCY_CONTENT);
						break;
					}
				}

			}

		}
	}
}
void Manage::control() {
	int value;
	if (_kbhit()) {
		value = _getch();
		switch (value) {
		case TOP:
		case TOP_LOWER:
		case DOWN:
		case DOWN_LOWER:
		case LEFT:
		case LEFT_LOWER:
		case RIGHT:
		case RIGHT_LOWER:
			controlSnake(value);
			break;
		case TOP_P2:
		case TOP_P2_LOWER:
		case DOWN_P2:
		case DOWN_P2_LOWER:
		case LEFT_P2:
		case LEFT_P2_LOWER:
		case RIGHT_P2:
		case RIGHT_P2_LOWER:
			controlSnake(value);
			break;
		case SPEED_UP:
		case SPEED_DOWN:
			controlSnakeSpeed(value);
			break;
		case PAUSE:
		case PAUSE_LOWER:
			controlPause(value);
			break;
		case SAVE:
		case SAVE_LOWER:
			controlSave(value);
		}
	}
}


void Manage::controlSnake(int value) {
	switch (value) {
	case TOP:
	case TOP_LOWER:
		if (this->snake.coordArr.at(0).Y - 1 == this->snake.coordArr.at(1).Y) {
			return;
		}
		break;
	case DOWN:
	case DOWN_LOWER:
		if (this->snake.coordArr.at(0).Y + 1 == this->snake.coordArr.at(1).Y) {
			return;
		}
		break;
	case LEFT:
	case LEFT_LOWER:
		if (this->snake.coordArr.at(0).X - 1 == this->snake.coordArr.at(1).X) {
			return;
		}
		break;
	case RIGHT:
	case RIGHT_LOWER:
		if (this->snake.coordArr.at(0).X + 1 == this->snake.coordArr.at(1).X) {
			return;
		}
		break;

	case TOP_P2:
	case TOP_P2_LOWER:
		if (this->snakeB.coordArr.at(0).Y - 1 == this->snakeB.coordArr.at(1).Y) {
			return;
		}
		break;
	case DOWN_P2:
	case DOWN_P2_LOWER:
		if (this->snakeB.coordArr.at(0).Y + 1 == this->snakeB.coordArr.at(1).Y) {
			return;
		}
		break;
	case LEFT_P2:
	case LEFT_P2_LOWER:
		if (this->snakeB.coordArr.at(0).X - 1 == this->snakeB.coordArr.at(1).X) {
			return;
		}
		break;
	case RIGHT_P2:
	case RIGHT_P2_LOWER:
		if (this->snakeB.coordArr.at(0).X + 1 == this->snakeB.coordArr.at(1).X) {
			return;
		}
		break;
	}
	char arr[8] = { TOP,TOP_LOWER,DOWN,DOWN_LOWER,LEFT,LEFT_LOWER,RIGHT ,RIGHT_LOWER };
	for (int i = 0; i < 8; i++) {
		if (value == arr[i]) {
			this->snake.moveWay = value;
			break;
		}
	}
	if (this->snakeB.status) {
		char arrB[8] = { TOP_P2,TOP_P2_LOWER,DOWN_P2,DOWN_P2_LOWER,LEFT_P2,LEFT_P2_LOWER,RIGHT_P2 ,RIGHT_P2_LOWER };
		for (int i = 0; i < 8; i++) {
			if (value == arrB[i]) {
				this->snakeB.moveWay = value;
				break;
			}
		}
	}
}

void Manage::controlSnakeSpeed(int value) {

	switch (value) {
	case '-':
		if (snake.speed < 200) {
			this->snake.speed += 20;
		}
		break;
	case '=':
		if (snake.speed > 20) {
			this->snake.speed -= 20;
		}
		break;
	}
}

void Manage::controlPause(int value) {

	if (value == PAUSE || value == PAUSE_LOWER) {
		snake.moveSwitch();
		snakeB.moveSwitch();
	}
}

void Manage::controlSave(int value) {
	if (value == SAVE || value == SAVE_LOWER) {
		SaveDataFormat saveDataFormat{};
		saveDataFormat.valid = 1;
		saveDataFormat.x = this->snake.x;
		saveDataFormat.y = this->snake.y;
		saveDataFormat.length = this->snake.length;
		saveDataFormat.moveFlag = this->snake.moveFlag;
		saveDataFormat.moveWay = this->snake.moveWay;
		saveDataFormat.color = this->snake.color;
		saveDataFormat.score = this->score;
		saveDataFormat.speed = SNAKE_SPEED;
		saveDataFormat.terrainFlag = this->snake.terrainFlag;
		saveDataFormat.status = this->snake.status;
		SaveData saveData{ &saveDataFormat };
		saveData.save(*(this->mapDesign), this->snake);
		if (this->snakeB.status == 1) {
			SaveDataFormat saveDataFormatB{};
			saveDataFormatB.valid = 1;
			saveDataFormatB.x = this->snakeB.x;
			saveDataFormatB.y = this->snakeB.y;
			saveDataFormatB.length = this->snakeB.length;
			saveDataFormatB.moveFlag = this->snakeB.moveFlag;
			saveDataFormatB.moveWay = this->snakeB.moveWay;
			saveDataFormatB.color = this->snakeB.color;
			saveDataFormatB.score = this->score;
			saveDataFormatB.speed = SNAKE_SPEED;
			saveDataFormatB.terrainFlag = this->snakeB.terrainFlag;
			saveDataFormatB.status = this->snakeB.status;
			SaveData saveData{ &saveDataFormatB };
			saveData.saveSnakeB(this->snakeB);

		}
	}

}

void Manage::updateScore(int score) {
	draw.writeInt({ (short)mapDesign->scoreX,(short)mapDesign->scoreY }, WHITE_COLOR, this->score);
}

Manage::~Manage() {
	if (this->mapDesign != nullptr) {
		delete this->mapDesign;
		this->mapDesign = nullptr;
	}
}