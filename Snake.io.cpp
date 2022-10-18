#include <iostream>
#include <conio.h>

//Edit here the direction of termcolor folder
#include <D:\Projects\C++\Snake.io\Snake.io\termcolor-master\include\termcolor\termcolor.hpp>
#include "windows.h"

using namespace std;
using namespace termcolor;

bool gameOver;
const int width = 20;
int width2 = 40;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;
int fps;
string spacebar = "          ";

void Initialization() {		//èíèöèàëèçàöèÿ âñåãî
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = (rand() % width) +3;
	fruitY = rand() % height;
	score = 0;
	fps = 100;
}

void Draw() {	//îòðèñîâêà ñöåíû
	system("cls");
	for (int i = 0; i < width+1; i++) {
		cout << "#";
	}
	cout << endl;

	for (int i = 0; i < height; i++) {
		for (int p = 0; p < width; p++) {
			if (p == 0|| p == width - 1) 
				cout << "#";
			if (i == y && p == x)
				cout << "O";
			else if (i == fruitY && p == fruitX)
				cout << "F";
			else cout << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < width+1; i++) {
		cout << "#";
	}
	cout << endl;
	cout << "Score: " << score<< spacebar << "FPS: " << fps << "\nControlling: \nW - Up \nA - Left\nD - Right\nS - Down\nX - Exit";
	Sleep(fps);
}

void Input() {		//ñ÷èòûâàíèå íàæàòèé
	if (_kbhit()) {
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'w':
			dir = UP;
			break;
		case 'x':
			gameOver = true;
			break;
/*		case 'ô':
			dir = LEFT;
			break;
		case 'â':
			dir = RIGHT;
			break;
		case 'û':
			dir = DOWN;
			break;
		case 'ö':
			dir = UP;
			break;
		case '÷':
			gameOver = true;
			break;*/
		}
	}
}

void Logic() {		//îïèñàíèå ìåõàíèê
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}
	if (x > width-2 || x < 0)
		gameOver = true;
	if (y > height || y < 0)
		gameOver = true;
	if (x == fruitX && y == fruitY) {
		score+=10;
		if (score == 100) { fps -= 10; }
		else if (score == 150) { fps -= 10; }
		else if (score == 200) { fps -= 10; }
		else if (score == 250) { fps -= 10; }
		else if (score == 300) { fps -= 10; }
		else if (score == 350) { fps -= 10; }
		fruitX = rand() % width;
		fruitY = rand() % height;
	}
}

void main() {
	Initialization();
		while (!gameOver) {
			Draw();
			Input();
			Logic();
		}
		system("cls");
		cout << termcolor::red << ".|'''''|                              .|''''|,                      \n|| .                                  ||    ||                      \n|| |''||  '''|.  '||),,(|,  .|''|,    ||    || \\  // .|''|, '||''| \n||    || .|''||   || || ||  ||..||    ||    ||  \\//  ||..||  ||    \n`|....|' `|..||. .||    ||. `|...     `|....|'   \/   `|...  .||.   \n\n\n" << termcolor::nocolorize;
		cout << termcolor::blue << "Your Score: " << termcolor::green << score << termcolor::nocolorize << " " << endl << termcolor::bright_magenta << "Press 'r' to Reatart" << endl;
		system("pause");
		system("pause");
}
