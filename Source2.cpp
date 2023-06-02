#include<iostream>
#include"help.h"
#include<conio.h>
#include<cstdio>
#include<time.h>
bool match(int d[][8]);
using namespace std;
int scl = 50;
int u = 0, s = 0;
int score = 0;
void game(int x1, int y1, int x2, int y2);

void f(int d[8][8]) {

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			d[i][j] = rand() % 5;
		}
	}
}
void scores() {
	system("cls");
	cout << "score:" << score;
}

void drawrec(int i, int j) {
	int x = (j + 1) * scl;
	int y = (i + 1) * scl;
	myRect(x, y, x + 20, y + 20, 255, 0, 0);
}
void drawrecs(int i, int j) {
	int x = (j + 1) * scl;
	int y = (i + 1) * scl;
	myRect(x, y, x + 20, y + 20, rand() % 255, rand() % 255, rand() % 255);
}
void drawcir(int i, int j)
{
	int x = (j + 1) * scl;
	int y = (i + 1) * scl;
	myEllipse(x, y, x + 20, y + 20, 0, 255, 0);
}
void drawcirs(int i, int j)
{
	int x = (j + 1) * scl;
	int y = (i + 1) * scl;
	myEllipse(x, y, x + 20, y + 20, rand() % 255, rand() % 255, rand() % 255);
}
void drawline(int i, int j)
{
	int x = (j + 1) * scl;
	int y = (i + 1) * scl;

	myLine(x + 8, y, x + 18, y, 255, 0, 255);
	myLine(x + 18, y, x + 25, y + 10, 255, 0, 255);
	myLine(x + 25, y + 10, x + 18, y + 20, 255, 0, 255);
	myLine(x + 18, y + 20, x + 8, y + 20, 255, 0, 255);
	myLine(x + 8, y + 20, x + 2, y + 10, 255, 0, 255);
	myLine(x + 2, y + 10, x + 8, y, 255, 0, 255);


}
void drawlines(int i, int j)
{
	int x = (j + 1) * scl;
	int y = (i + 1) * scl;

	myLine(x + 8, y, x + 18, y, rand() % 255, rand() % 255, rand() % 255);
	myLine(x + 18, y, x + 25, y + 10, rand() % 255, rand() % 255, rand() % 255);
	myLine(x + 25, y + 10, x + 18, y + 20, rand() % 255, rand() % 255, rand() % 255);
	myLine(x + 18, y + 20, x + 8, y + 20, rand() % 255, rand() % 255, rand() % 255);
	myLine(x + 8, y + 20, x + 2, y + 10, rand() % 255, rand() % 255, rand() % 255);
	myLine(x + 2, y + 10, x + 8, y, rand() % 255, rand() % 255, rand() % 255);
}

void drawcross(int i, int j)
{
	int x = (j + 1) * scl;
	int y = (i + 1) * scl;
	myLine(x + 5, y, x + 10, y, 150, 0, 255);
	myLine(x + 5, y, x, y + 5, 150, 0, 255);
	myLine(x, y + 5, x, y + 15, 150, 0, 255);
	myLine(x, y + 15, x + 5, y + 20, 150, 0, 255);
	myLine(x + 5, y + 20, x + 10, y + 20, 150, 0, 255);
	myLine(x + 10, y + 20, x + 5, y + 15, 150, 0, 255);
	myLine(x + 5, y + 15, x + 5, y + 6, 150, 0, 255);
	myLine(x + 5, y + 6, x + 10, y, 150, 0, 255);
}
void drawcrossz(int i, int j)
{
	int x = (j + 1) * scl;
	int y = (i + 1) * scl;
	myLine(x + 5, y, x + 10, y, 150, 0, 255);
	myLine(x + 5, y, x, y + 5, 150, 0, 255);
	myLine(x, y + 5, x, y + 15, 150, 0, 255);
	myLine(x, y + 15, x + 5, y + 20, 150, 0, 255);
	myLine(x + 5, y + 20, x + 10, y + 20, rand() % 255, rand() % 255, rand() % 255);
	myLine(x + 10, y + 20, x + 5, y + 15, rand() % 255, rand() % 255, rand() % 255);
	myLine(x + 5, y + 15, x + 5, y + 6, rand() % 255, rand() % 255, rand() % 255);
	myLine(x + 5, y + 6, x + 10, y, rand() % 255, rand() % 255, rand() % 255);
}


void drawdia(int i, int j)
{
	int x = (j + 1) * scl;
	int y = (i + 1) * scl;
	myLine(x, y + 10, x + 5, y + 3, 255, 255, 0);
	myLine(x + 10, y + 20, x + 20, y + 10, 255, 255, 0);
	myLine(x, y + 10, x + 10, y + 20, 255, 255, 0);
	myLine(x + 15, y + 3, x + 20, y + 10, 255, 255, 0);
	myLine(x + 5, y + 3, x + 15, y + 3, 255, 255, 0);
}
void drawdias(int i, int j)
{
	int x = (j + 1) * scl;
	int y = (i + 1) * scl;
	myLine(x, y + 10, x + 5, y + 3, rand() % 255, rand() % 255, 0);
	myLine(x + 10, y + 20, x + 20, y + 10, rand() % 255, rand() % 255, 0);
	myLine(x, y + 10, x + 10, y + 20, rand() % 255, rand() % 255, 0);
	myLine(x + 15, y + 3, x + 20, y + 10, rand() % 255, rand() % 255, 0);
	myLine(x + 5, y + 3, x + 15, y + 3, rand() % 255, rand() % 255, 0);
}




void spcgem(int i, int j)
{
	int a = rand() % 255;
	int x = (j + 1) * scl;
	int y = (i + 1) * scl;


	myRect(x, y, x + 20, y + 20, a, a, a);
}

void board()
{
	int k = 25, z = 450;
	myRect(k, k, z, z, 0, 0, 235);
	//myLine(k, k, z, k, 255);
	//myLine(k, k, k, z, 255);
	//myLine(z, k, z, z, 255);
	//myLine(k, z, z, z, 255);
}
void selection(int d[][8], int& u, int& s)
{
	int w = 0;
	int x = (s + 1) * scl;
	int y = (u + 1) * scl;


	if (isCursorKeyPressed(w))
		myRect(x - 10, y - 10, x + 30, y + 30, 0, 0, 0);

	if (w == 1 || w == 2 || w == 3 || w == 4)
		switch (w)
		{
		case 1:
			if (s - 1 >= 0)
				s = s - 1;
			break;
		case 2:
			if (u - 1 >= 0)
				u = u - 1;
			break;
		case 3:
			if (s + 1 <= 7)
				s = s + 1;
			break;
		case 4:
			if (u + 1 <= 7)
				u = u + 1;
			break;
		}
	if (w == 5)
	{
		int flag = 0;
		int p;
		char a = 0;
		while (a != 'a' && a != 'w' && a != 'd' && a != 's' && flag == 0)
		{

			a = _getch();
			if (a == 'f')
				flag = 1;

		}


		switch (a)
		{
		case 'a':
			swap(d[u][s], d[u][s - 1]);
			//if (match(d) == 0);
			//swap(d[u][s], d[u][s - 1]);
			break;
		case 'w':
			swap(d[u][s], d[u - 1][s]);
			//if (match(d) == 0);
			//swap(d[u][s], d[u - 1][s]);
			break;
		case 'd':
			swap(d[u][s], d[u][s + 1]);
			//if (match(d) == 0);
			//swap(d[u][s], d[u][s + 1]);
			break;
		case 's':
			swap(d[u][s], d[u + 1][s]);
			//if (match(d) == 0);
			//swap(d[u][s], d[u + 1][s]);
			break;
		}
		board();
	}
}
void sel(int i, int  j)
{
	int x = (j + 1) * scl;
	int y = (i + 1) * scl;
	myLine(x - 8, y - 8, x + 28, y - 8, 255, 255, 255);
	myLine(x + 28, y - 8, x + 28, y + 28, 255, 255, 255);
	myLine(x + 28, y + 28, x - 8, y + 28, 255, 255, 255);
	myLine(x - 8, y + 28, x - 8, y - 8, 255, 255, 255);
}
void in(int d[][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{

			if (d[i][j] == 0)
				drawline(i, j);
			if (d[i][j] == 1)
				drawrec(i, j);
			if (d[i][j] == 2)
				drawcir(i, j);
			if (d[i][j] == 3)
				drawcross(i, j);
			if (d[i][j] == 4)
				drawdia(i, j);
			if (d[i][j] == 5)
				drawlines(i, j);
			if (d[i][j] == 6)
				drawrecs(i, j);
			if (d[i][j] == 7)
				drawcirs(i, j);
			if (d[i][j] == 8)
				drawcrossz(i, j);
			if (d[i][j] == 9)
				drawdias(i, j);
			if (d[i][j] == 10)
				spcgem(i, j);

			if (i == u && j == s)
				sel(i, j);
		}

	}
	match(d);
}
int whiche(int d[8][8], int i, int j)
{
	switch (d[i][j])
	{
	case 0:
		d[i][j] = 5;
		break;
	case 1:
		d[i][j] = 6;
		break;
	case 2:
		d[i][j] = 7;
		break;
	case 3:
		d[i][j] = 8;
		break;
	case 4:
		d[i][j] = 9;
		break;
	}
	return d[i][j];
}


bool match(int d[][8])
{
	bool flag = 0;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			if (10 == d[i][j] && d[i][j + 1] == d[i][j + 2] || 10 == d[i][j] && d[i + 1][j] == d[i + 2][j] || 10 == d[i][j] && d[i - 1][j] == d[i - 2][j] || 10 == d[i][j] && d[i][j - 1] == d[i][j - 2])
			{
				for (int z = 0; z < 8; z++)
				{
					d[z][j] = rand() % 5;
				}

				while (i > 0)
				{
					for (int z = 0; z < 8; z++)
					{
						d[i][z] = d[i - 1][z];
					}
					i--;
				}
				for (int z = 0; z < 8; z++)
					d[0][z] = rand() % 5;
				score = score + 20;
				scores();
			}

			if (10 == d[i][j] && d[i - 1][j] == d[i + 1][j] || 10 == d[i][j] && d[i][j - 1] == d[i][j + 1])
			{
				for (int z = 0; z < 8; z++)
				{
					d[z][j] = rand() % 5;
				}

				while (i > 0)
				{
					for (int z = 0; z < 8; z++)
					{
						d[i][z] = d[i - 1][z];
					}
					i--;
				}
				for (int z = 0; z < 8; z++)
					d[0][z] = rand() % 5;
				score = score + 20;
				scores();
			}

			if (d[i][j] == d[i][j + 1] && d[i][j + 1] == d[i][j + 2] && d[i][j + 2] == d[1 + i][j + 2] && d[i + 2][j + 2] == d[i + 1][j + 2])
			{
				d[i + 2][j + 2] = 10;
				while (i > 1)
				{
					d[i][j] = d[i - 1][j];
					d[i][j + 1] = d[i - 1][j + 1];
					i--;
				}
				while (i > 1)
				{
					d[i][j + 2] = d[i - 2][j + 2];
					d[i + 1][j + 2] = d[i - 1][j + 2];
					i--;
				}
				d[0][j] = rand() % 5;
				d[1][j] = rand() % 5;
				d[2][j] = rand() % 5;
				board();


				d[0][j] = rand() % 5;
				d[0][j + 1] = rand() % 5;

				board();
				flag = 1;
				score = score + 20;
				scores();
				d[i + 2][j + 2] = 10;
			}
			if (d[i][j] == d[i][j + 1] && d[i][j + 1] == d[i][j + 2] && d[i][j] == d[i - 1][j] && d[i - 2][j] == d[i - 1][j])
			{
				d[i - 2][j] = 10;
				while (i > 1)
				{
					d[i][j] = d[i - 1][j];
					d[i][j + 1] = d[i - 1][j + 1];
					i--;
				}
				while (i > 0)
				{

					d[i - 1][j] = d[i - 3][j];
					d[i - 2][j] = d[i - 4][j];
					i--;
				}
				d[0][j] = rand() % 5;
				d[1][j] = rand() % 5;
				d[2][j] = rand() % 5;
				board();


				d[0][j] = rand() % 5;
				d[0][j + 1] = rand() % 5;
				board();
				flag = 1;
				score = score + 20;
				scores();
				d[i + 2][j + 2] = 10;
			}
			if (d[i][j] == d[i][j + 1] && d[i][j + 1] == d[i][j + 2] && d[i][j + 2] == d[i - 1][j] && d[i - 1][j] == d[i - 2][j])

			{
				d[i][j] = 10;
				while (i > 1)
				{
					d[i][j] = d[i - 2][j];
					d[i][j + 1] = d[i - 1][j + 1];
					i--;
				}
				while (i > 2)
				{
					d[i + 1][j] = d[i - 1][j];
					d[i][j] = d[i - 2][j];
					i--;
				}
				d[0][j] = rand() % 5;
				d[1][j] = rand() % 5;
				board();


				d[0][j] = rand() % 5;
				d[0][j + 1] = rand() % 5;
				d[0][j + 2] = rand() % 5;
				board();
				flag = 1;
				score = score + 20;
				scores();
				d[i][j] = 10;
			}

			if (d[i][j] == d[i][j + 1] && d[i][j + 1] == d[i][j + 2] && d[i][j + 2] == d[i - 1][j + 2] && d[i - 1][j + 2] == d[i - 2][j + 2])

			{
				d[i - 2][j + 2] = 10;
				while (i > 1)
				{
					d[i][j] = d[i - 2][j];
					d[i][j + 1] = d[i - 1][j + 1];
					i--;
				}
				while (i > 2)
				{
					d[i + 1][j] = d[i - 1][j];
					d[i][j] = d[i - 2][j];
					i--;
				}
				d[0][j] = rand() % 5;
				d[1][j] = rand() % 5;
				board();


				d[0][j] = rand() % 5;
				d[0][j + 1] = rand() % 5;
				d[0][j + 2] = rand() % 5;
				board();
				flag = 1;
				score = score + 20;
				scores();
				d[i - 2][j + 2] = 10;
			}






			if (d[i][j] - 5 == d[i][j + 1] && d[i][j + 1] == d[i][j + 2] || d[i][j] == d[i][j + 1] - 5 && d[i][j + 1] - 5 == d[i][j + 2] || d[i][j] == d[i][j + 1] && d[i][j + 1] == d[i][j + 2] - 5)
			{

				while (i > 0)
				{
					for (int z = 0; z < 3; z++)
					{
						d[i + 2][j + z] = d[i - 1][j + z];
						d[i + 1][j + z] = d[i - 2][j + z];
						d[i][j + z] = d[i - 3][j + z];
					}
					i--;
				}

				for (int i = 0; i < 3; i++)
				{
					d[i][j] = rand() % 5;
					d[i][j + 1] = rand() % 5;
					d[i][j + 2] = rand() % 5;
				}
				board();
				flag = 1;
				score = score + 10;
				scores();
			}
			else if (d[i][j] - 5 == d[i + 1][j] && d[i + 1][j] == d[i + 2][j] || d[i][j] == d[i + 1][j] - 5 && d[i + 1][j] - 5 == d[i + 2][j] || d[i][j] == d[i + 1][j] && d[i + 1][j] == d[i + 2][j] - 5)
			{

				while (i > 3)
				{
					for (int z = -1; z < 2; z++)
					{
						d[i + 2][j + z] = d[i - 1][j + z];
						d[i + 1][j + z] = d[i - 2][j + z];
						d[i][j + z] = d[i - 3][j + z];
					}
					i--;
				}

				for (int i = 0; i < 3; i++)
				{
					d[i][j] = rand() % 5;
					d[i][j + 1] = rand() % 5;
					d[i][j + 2] = rand() % 5;
				}
				board();
				flag = 1;

				score = score + 10;
				scores();
			}

			else if (d[i][j] == d[i][j + 1] && d[i][j + 1] == d[i][j + 2] && d[i][j + 2] == d[i][j + 3] && j <= 4)
			{

				d[i][j + 2] = whiche(d, i, j);
				while (i > 0)
				{
					d[i][j] = d[i - 1][j];
					d[i][j + 1] = d[i - 1][j + 1];
					d[i][j + 3] = d[i - 1][j + 3];
					i--;
				}
				d[0][j] = rand() % 5;
				d[0][j + 1] = rand() % 5;
				d[0][j + 3] = rand() % 5;
				board();
				flag = 1;
				score = score + 10;
				scores();
			}
			else if (d[i][j] == d[i][j + 1] && d[i][j + 1] == d[i][j + 2] && j <= 5)
			{
				while (i > 0)
				{
					d[i][j] = d[i - 1][j];
					d[i][j + 1] = d[i - 1][j + 1];
					d[i][j + 2] = d[i - 1][j + 2];
					i--;
				}
				d[0][j] = rand() % 5;
				d[0][j + 1] = rand() % 5;
				d[0][j + 2] = rand() % 5;
				board();
				flag = 1;
				score = score + 10;
				scores();
			}
			else if (d[i][j] == d[i + 1][j] && d[i + 1][j] == d[i + 2][j] && d[i + 2][j] == d[i + 3][j])
			{
				d[i + 3][j] = whiche(d, i, j);
				while (i >= 3)
				{

					d[i + 2][j] = d[i - 1][j];
					d[i + 1][j] = d[i - 2][j];
					d[i][j] = d[i - 3][j];
					i--;
				}
				d[0][j] = rand() % 5;
				d[1][j] = rand() % 5;
				d[2][j] = rand() % 5;
				board();
				flag = 1; score = score + 10;
				scores();
			}
			else if (d[i][j] == d[i + 1][j] && d[i + 1][j] == d[i + 2][j])
			{
				while (i > 0)
				{
					d[i + 2][j] = d[i - 1][j];
					d[i + 1][j] = d[i - 2][j];
					d[i][j] = d[i - 3][j];
					i--;
				}
				d[0][j] = rand() % 5;
				d[1][j] = rand() % 5;
				d[2][j] = rand() % 5;
				board();
				flag = 1;
				score = score + 10;
				scores();

			}
		}
	if (flag == 1)
		return true;
	return false;
}
void start() {
	int x = (1 + scl);
	int y = (1 + scl);

	game(x, y, x + x, y);
	game(x, y, x, y * 3);
	game(x, y * 3, x * 2, y * 3);
	game(x * 2, y * 3, x * 2.5, y * 2.5);
	game(x * 2.5, y * 2.5, x * 2, y * 2);
	game(x * 2, y * 2, x, y * 2);
	game(x + x, y, x * 2.5, y * 1.5);
	game(x * 2.5, y * 1.5, x * 2, y * 2);
	game(x * 3.5, y, x * 3.5, y * 3);
	game(x * 3.5, y * 3, x * 4.5, y * 3);
	game(x * 5.5, y, x * 5.5, y * 3);
	game(x * 6.5, y, x * 8.5, y);
	game(x * 7.5, y, x * 7.5, y * 3);
	game(x * 9.5, y, x * 11.5, y);
	game(x * 11.5, y, x * 9.5, y * 3);
	game(x * 9.5, y * 3, x * 11.5, y * 3);
	//diamond
	//first line
	game(x * 5.5, y * 4, x * 9.5, y * 4);
	//slating1
	game(x * 5.5, y * 4, x * 5, y * 4.5);
	game(x * 5, y * 4.5, x * 7.5, y * 8.5);
	game(x * 9.5, y * 4, x * 10, y * 4.5);
	game(x * 7.5, y * 8.5, x * 10, y * 4.5);






}
void timerline() {

	clock_t time_req;
	time_req = clock();


	int x1 = (0 + 1) * scl;
	int y1 = (9 + 1) * scl;
	int x2 = x1 + 400;
	int y2 = (9 + 1) * scl;

	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, 16, RGB(255, 255, 0)); //2 is the width of the pen
	SelectObject(device_context, pen);
	MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);

}
void timerblack(int a) {

	int x1 = (0 + 1) * scl;
	int y1 = (9 + 1) * scl;
	int x2 = x1 + 400;
	int y2 = (9 + 1) * scl;

	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);
	HPEN pen = CreatePen(PS_SOLID, 16, RGB(0, 0, 0)); //2 is the width of the pen
	SelectObject(device_context, pen);
	MoveToEx(device_context, x2, y2, NULL);
	LineTo(device_context, x2 - a * 7, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
}


void game(int x1, int y1, int x2, int y2) {
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, 8, RGB(100, 255, 150)); //2 is the width of the pen
	SelectObject(device_context, pen);
	MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);

}

void over() {
	game(50, 50, 125, 50);
	game(50, 50, 50, 200);
	game(50, 200, 100, 200);
	game(100, 200, 100, 150);
	game(75, 150, 125, 150);
	game(125, 150, 125, 200);
	game(175, 50, 150, 200);
	game(175, 50, 200, 200);
	game(175, 150, 175, 150);
	game(225, 50, 225, 200);
	game(225, 50, 275, 175);
	game(275, 175, 325, 50);
	game(325, 50, 325, 200);
	game(350, 50, 350, 200);
	game(350, 125, 425, 125);
	game(350, 50, 425, 50);
	game(350, 50, 425, 50);
	game(350, 200, 425, 200);
	game(50, 250, 50, 400);
	game(50, 250, 125, 250);
	game(50, 400, 125, 400);
	game(125, 400, 125, 250);


	game(150, 250, 175, 400);
	game(175, 400, 200, 250);




	game(225, 250, 225, 400);
	game(225, 250, 300, 250);
	game(225, 325, 300, 325);
	game(225, 400, 300, 400);

	game(350, 250, 350, 400);
	game(350, 250, 420, 250);
	game(420, 250, 420, 325);
	game(420, 325, 350, 325);
	game(375, 325, 420, 400);



}



int main() {
	int a;
	char c = 'q';
	int d[8][8];
	f(d);
	int w = 0;

	while (w != 5)
	{
		isCursorKeyPressed(w);
		start();
	}
	board();
	timerline();
	clock_t time_req;
	time_req = clock();
	while (clock() - time_req < 1000000)

	{
		a = (clock() - time_req) / CLOCKS_PER_SEC;
		in(d);
		selection(d, u, s);
		timerline();
		timerblack(a);
	}
	system("cls");
	cout << " score:" << score;
	while (c != 'f')
	{
		c = _getch();
		over();
	}
	over();
	system("pause");
	return 0;
}
