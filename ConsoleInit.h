#pragma once
#include<Windows.h>

HANDLE ConsoleInit(
	const short WindowWidth,
	const short WindowHeight,
	const short FontSize,
	LPCWSTR WindowTitle
);