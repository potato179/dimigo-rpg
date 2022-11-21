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
		printf("���� ��� �Ա� ����");
		gotoxy(39, 13);
		printf("--------------- ���� ��Ģ ---------------");
		gotoxy(30, 15);
		printf("1. ȣ�ǿ��� ����� ���̸� �Դ´�.");
		gotoxy(30, 16);
		printf("2. ������ ���� �����뿡 ����� ������.");
		gotoxy(30, 17);
		printf("3. ��Ȱ�� �����ǿ��� ������ ��������� ������ �ʰ� Ƥ��.");
		gotoxy(30, 18);
		printf("4. �����Ƿ� �ǽ��ϸ� �ȴ�.");
		gotoxy(50, 23);
		printf("���Ա�");
		gotoxy(50, 24);
		printf("�ݼ��ϱ�");

		gotoxy(48, 23);
		printf("��");

		gotoxy(2, 25);
	}
}

void printBound() {
	for (int y = 0; y < 30; y++) {
		for (int x = 0; x < 60; x += 1) {
			if (x == 0 || y == 0 || x == 59 || y == 29) printf("��");
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