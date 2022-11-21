#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#pragma comment(lib, "winmm.lib")

void gotoxy(int x, int y) {
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void clearCursor() {
	CONSOLE_CURSOR_INFO c;
	c.bVisible = FALSE;
	c.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &c);
}

void resizeConsole() {
	char chTemp[100];
	sprintf(chTemp, "mode con cols=120 lines=30");
	system(chTemp);
}

void displayStart() {
	while (1) {
		if (_kbhit()) {
			_getch();
			break;
		}

		gotoxy(50, 10);
		printf("몰래 라면 먹기 게임");
		gotoxy(39, 13);
		printf("--------------- 게임 규칙 ---------------");
		gotoxy(30, 15);
		printf("1. 호실에서 라면을 조이며 먹는다.");
		gotoxy(30, 16);
		printf("2. 복도로 나가 휴지통에 라면을 버린다.");
		gotoxy(30, 17);
		printf("3. 생활관 교무실에서 나오는 빨모쌤한테 잡히지 않게 튄다.");
		gotoxy(30, 18);
		printf("4. 샤워실로 피신하면 된다.");
		gotoxy(50, 23);
		printf("라면먹기");
		gotoxy(50, 24);
		printf("반성하기");

		gotoxy(48, 23);
		printf("▶");

		gotoxy(1, 25);
	}
}

void printBound() {
	for (int y = 0; y < 30; y++) {
		for (int x = 0; x < 60; x += 1) {
			if (x == 0 || y == 0 || x == 59 || y == 29) printf("■");
			else printf("  ");
		}
	}
}

int main() {
	PlaySound(TEXT("yoosuk.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	clearCursor();
	resizeConsole();
	printBound();
	displayStart();
}