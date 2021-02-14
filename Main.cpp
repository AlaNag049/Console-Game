#include<iostream>
#include<time.h>
#include<windows.h>
using namespace std;
#include"Console.h"

short nScreenWidth = 120;
short nScreenHeight = 40;

int main() {
	// Construct Console
	HANDLE hConsole = ConsoleInit(nScreenWidth, nScreenHeight, 10, L"Console Game");
	DWORD d = 0;
	WCHAR *elm = new WCHAR[80 * 40];

	// Make Field
	for (int x = 0; x < nScreenWidth; ++x) {
		for (int y = 0; y < nScreenHeight; ++y) {
			if (y == 0 || x == 0 || x == nScreenWidth - 1 || y == nScreenHeight - 1) elm[y * nScreenWidth + x] = '#';
			else elm[y * nScreenWidth + x] = ' ';
		}
	}

	// Game Loop
	int temp = 0;
	int pos = 2459;
	while (1)
	{
		// Input
		temp = InputHandle();
		// Simulate
		if (elm[pos + temp] != '#' && elm[pos + temp] != '@') pos += temp;
		// Draw
		elm[pos] = '@';
		Sleep(1000 / 30);
		WriteConsoleOutputCharacter(hConsole, elm, 120 * 40, { 0,0 }, &d);
	}
	

	while (1);
}