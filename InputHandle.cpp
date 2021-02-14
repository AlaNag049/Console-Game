#include<Windows.h>
#include<iostream>

int InputHandle() {
	if (GetKeyState('A') & 0x8000) {
		return -1;
	}
	else if (GetKeyState('D') & 0x8000) {
		return 1;
	}
	else if (GetKeyState('S') & 0x8000) {
		return 120;
	}
	else if (GetKeyState('W') & 0x8000) {
		return -120;
	}
}