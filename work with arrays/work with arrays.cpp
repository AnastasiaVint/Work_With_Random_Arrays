#define _CRT_SECURE_NO_WARNINGS


#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <queue>

using namespace std;

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	HANDLE stdoutput = GetStdHandle(STD_OUTPUT_HANDLE);
	srand(time(NULL));

	int size = (50 + rand() % 151);

	CONSOLE_CURSOR_INFO curinfo;

	GetConsoleCursorInfo(stdoutput, &curinfo);

	curinfo.bVisible = false;

	SetConsoleCursorInfo(stdoutput, &curinfo);

	cout << "Випадковий розмір масиву -> ";

	for (int i = 50; i <= size; i++) {
		printf("%-3d", i);
		printf("\x8\x8\x8");
	}

	curinfo.bVisible = true;

	SetConsoleCursorInfo(stdoutput, &curinfo);

	cout << endl;

	int* arr = (int*)malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++) *(arr + i) = ((rand() % 101) - 50);
	cout << endl;

	int open, c = 0;
	queue<int> q;

	for (int i = 0; i < size; i++) {
		if (i == 0) cout << "   ";
		if (*(arr + i) == *(arr + i + 1) && size > 1) {
			open = (rand() % 15 + 1) << 4 | 0;
			c++;
			q.push(open);
			SetConsoleTextAttribute(stdoutput, open);
			printf("(");
			SetConsoleTextAttribute(stdoutput, 7);
		}

		if (*(arr + i - 1) == *(arr + i) && size > 1) {
			printf("%d", *(arr + i));
			SetConsoleTextAttribute(stdoutput, q.front());
			q.pop();
			printf(")\t");
			SetConsoleTextAttribute(stdoutput, 7);
		}
		else {
			printf("%d\t", *(arr + i));
		}

		if ((i + 1) % 10 == 0) cout << endl << "   ";
	}

	cout << endl << endl;

	if (c >= 1) {
		cout << "Пари однакових елементів виділені. " << endl << "Кількість пар однакових елементів -> " << c << endl;
	}
	else {
		cout << "Кількість пар однакових елементів -> " << c << endl;
	}


	system("pause");
}
