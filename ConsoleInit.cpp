#include<Windows.h>
#include<stdio.h>

HANDLE ConsoleInit(
	const short WindowWidth,
	const short WindowHeight,
	const short FontSize,
	LPCWSTR WindowTitle
)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO conCursorInfo = { 1, FALSE };
	SMALL_RECT smlRect = { 0, 0, WindowWidth - 1, WindowHeight - 1 };
	
	// 1,Create console screen buffer
	hConsole = CreateConsoleScreenBuffer(
		GENERIC_WRITE | GENERIC_READ,
		0,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
	);
	if (hConsole == INVALID_HANDLE_VALUE) {
		printf("CreateConsoleScreenBuffer : Error!! : %d ", GetLastError());
		exit(1);
	}

	// 2,set active console screen buffer
	if (!SetConsoleActiveScreenBuffer(hConsole)) {
		printf("SetConsoleActiveScreenBuffer : Error!! : %d ", GetLastError());
		exit(1);
	}

	// 3,set window size
	if (!SetConsoleWindowInfo(hConsole, TRUE, &smlRect)) {
		printf("SetConsoleWindowInfo : Error!! : %d ", GetLastError());
		exit(1);
	}

	// 4,set console window buffer size
	if (!SetConsoleScreenBufferSize(hConsole, { WindowWidth, WindowHeight }))
	{
		printf("SetConsoleScreenBufferSize : Error! : %d ", GetLastError());
		exit(1);
	}

	// 5,set console cursor window
	if (!SetConsoleCursorInfo(hConsole, &conCursorInfo))
	{
		printf("SetConsoleCursorInfo : Error! : %d ", GetLastError());
		exit(1);
	}

	// 6,set console title bar
	if (!SetConsoleTitle(WindowTitle))
	{
		printf("Error! : %d ", GetLastError());
		exit(1);
	}

	return hConsole;
}