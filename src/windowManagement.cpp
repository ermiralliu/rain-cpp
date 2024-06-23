#include <windows.h>
#include "windowManagement.hpp"

void showConsole(bool show){
	HWND consoleWindow = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(consoleWindow, show);
	if(show)
		SetActiveWindow(consoleWindow);
}

void showConsole(){
	showConsole(true);
}

void exeToForeground(const char* title){
	showConsole(false);
	HWND rainWindow = FindWindowA(NULL, title);
	SetForegroundWindow(rainWindow);
	SetActiveWindow(rainWindow);
}
