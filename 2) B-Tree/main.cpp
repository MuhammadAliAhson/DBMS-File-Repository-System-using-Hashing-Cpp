#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <windows.h>
#include "Support.h"
#include "Black.h"
using namespace std;



int main() {
	system("color 40");
	PlaySound(TEXT("start.wav"), NULL, SND_SYNC);
	P_Search();

	return 0;
}