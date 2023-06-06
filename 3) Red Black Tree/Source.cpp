#pragma once
#include "Avl.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <windows.h>
#include "support.h"
using namespace std;



int main() {
	system("color 60");

	cout << "	  _____  ______ _______ _____    _______  ___   _____ ______  " << endl;
cout << "    	 +// __ \\//   |//_  __/ //  ||   // __ )//   || / ___// ____/ " << endl;
cout << "	+// / / /// /| | // // // / // //||  // /| || \__ \ / __/    " << endl;
cout << "       +// /_/ /// ___ |// // // ___|| // /_/ // ___ || ___/ / /___   " << endl;
cout << "      +//____////_// |||/_// //_//  ||//_____/_/     || \\____//_____/  " << endl;


	PlaySound(TEXT("start.wav"), NULL, SND_SYNC);
	P_Search();

	return 0;
}