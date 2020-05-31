#include <iostream>
#include <time.h>
#include <vector>
#include <conio.h>

using namespace std;

bool stop = false;
int width = 15;
int height = 15;
int snakeX[225];
int snakeY[225];
int score = 0;
int tailSize;

int main()
{

	srand(time(NULL));

	int positionX = 1 + rand() % 13;
	int positionY = 1 + rand() % 13;
	int fruitX = 1 + rand() % 13;
	int fruitY = 1 + rand() % 13;

	// loop
	while (stop != true)
	{

		system("cls");

		// draw map
		for (int i = 0; i < width + 1; i++) cout << "#";
		cout << endl;

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (j == 0 || j == width - 1) cout << "#";
				if (i == positionY && j == positionX) cout << "*";
				else if (i == fruitY && j == fruitX) cout << "@";
				else
				{
					bool print = false;
					for (int z = 0; z < tailSize; z++)
					{
						if (snakeX[z] == j && snakeY[z] == i)
						{
							print = true;
							cout << "x";
						}
					}
					if (print == false) cout << " ";
				}
			}
			cout << endl;
		}

		for (int i = 0; i < width + 1; i++) cout << "#";

		// output score
		cout << endl << "score: " << score;

		// tail
		int prevX = snakeX[0];
		int prevY = snakeY[0];
		int prev2X, prev2Y;
		snakeX[0] = positionX;
		snakeY[0] = positionY;

		for (int i = 1; i < tailSize; i++)
		{
			prev2X = snakeX[i];
			prev2Y = snakeY[i];
			snakeX[i] = prevX;
			snakeY[i] = prevY;
			prevX = prev2X;
			prevY = prev2Y;
		}
		// check keyboard
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'w':// forward
				positionY--;
				break;

			case 'a':// left
				positionX--;
				break;

			case 's':// back
				positionY++;
				break;

			case 'd':// right
				positionX++;
				break;

			case 'q':
				stop = true;
				cout << "you press q";
				break;

			}
		}

		if (fruitX == positionX && fruitY == positionY)
		{
			score++;
			fruitX = 1 + rand() % 13;
			fruitY = 1 + rand() % 13;
			tailSize++;
		}
		//system("pause");

		// loss condition
		if (positionX > 14 || positionX < 0 || positionY > 14 || positionY < 0)
		{
			stop = true;
			system("cls");

			cout << "\n\n\nyou lose\nyour score: " << score << endl;
		}
	}
	return 0;
}