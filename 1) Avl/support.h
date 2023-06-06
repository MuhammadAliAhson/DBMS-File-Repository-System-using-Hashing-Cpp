#pragma once
Avl tree;
int table = 0;
void fun2(vector<string> v);
void clause();
//---------------============-------------------------//
void myfun(string str) {
	//cout << concatenate;
	std::stringstream sstr(str);
	std::vector<std::string> v;
	while (sstr.good())
	{
		std::string substr;
		getline(sstr, substr, ',');
		v.push_back(substr);
	}

	fun2(v);

	return;
}
void fun2(vector<string> v) {
	string a[7];
	if (v.size() == 7) {
		for (int i = 0; i < v.size(); i++) {
			a[i] = v[i];
		}
	}
	if (v.size() == 8) {
		a[0] = v[0];
		a[1] = v[1];
		a[2] = v[2] +","+ v[3];
		a[3] = v[4];
		a[4] = v[5];
		a[5] = v[6];
		a[6] = v[7];
	}
	if (v.size() == 9) {
		a[0] = v[0];
		a[1] = v[1];
		a[2] = v[2] + "," + v[3]+"," + v[4];
		a[3] = v[5];
		a[4] = v[6];
		a[5] = v[7];
		a[6] = v[8];
	}
	else if (v.size() == 10) {
		a[0] = v[0];
		a[1] = v[1];
		a[2] = v[2] +"," + v[3]+ "," + v[4]+ "," + v[5];
		a[3] = v[6];
		a[4] = v[7];
		a[5] = v[8];
		a[6] = v[9];
	}
	/*for (int i = 0; i < 7; i++) {
		cout << a[i] << endl;
	}*/
	//---------===-----------==-=--------===--------------====-------//
	int id = 0, year = 0, deaths = 0;
	float age_adjust = 0.0;
	string cause_113 = " ";
	string cause_name = " ";
	string state = " ";
	//=========================================================//
	//cout << a[0] << endl;;
	id = stol(a[0]);
	year = stol(a[1]);
	cause_113 = a[2];
	cause_name = a[3];
	state = a[4];
	deaths = stoi(a[5]);
	age_adjust = stof(a[6]);
	node* into = new node;
	into->id = id;
	into->year = year;
	into->cause_113 = cause_113;
	into->cause_name = cause_name;
	into->state = state;
	into->deaths = deaths;
	into->age_adjust = age_adjust;
	//cout << cause_name << endl;
	if (prince == 1) {//ID
		tree.root = tree.insert_Id(tree.root, into);

	}
	else if (prince == 2) {// year
		tree.root = tree.insert_year(tree.root, into);
	}
	else if (prince == 3) {// deaths
		tree.root = tree.insert_deaths(tree.root, into);
	}
	else if (prince == 4) {// age-dactor

		tree.root = tree.insert_age_adjust(tree.root, into);
	}
	else if (prince == 5) {// state
		tree.root = tree.insert_state(tree.root, into);
	}
	else if (prince == 6) {//cause name
		tree.root = tree.insert_cause_name(tree.root, into);
	}
	else if (prince == 7) {//cause 113
		tree.root = tree.insert_cause_113(tree.root, into);

	}

}






int menu() {

	string a1 = "NCHS_-_Leading_Causes_of_Death__United_States_1.csv";
	string a2 = "NCHS_-_Leading_Causes_of_Death__United_States_2.csv";
	string a3 = "NCHS_-_Leading_Causes_of_Death__United_States_3.csv";
	string a4 = "NCHS_-_Leading_Causes_of_Death__United_States_4.csv";
	string a5 = "NCHS_-_Leading_Causes_of_Death__United_States_5.csv";
	string a6 = "NCHS_-_Leading_Causes_of_Death__United_States_6.csv";
	string a7 = "NCHS_-_Leading_Causes_of_Death__United_States_7.csv";
	string a8 = "NCHS_-_Leading_Causes_of_Death__United_States_8.csv";
	string a9 = "NCHS_-_Leading_Causes_of_Death__United_States_9.csv";
	string a10 = "NCHS_-_Leading_Causes_of_Death__United_States_10.csv";
	string index[] = { a1,a2,a3,a4,a5,a6,a7,a8,a9,a10 };

	// file handling
	ifstream inFile(a1);
	string line;
	ofstream outFile("note_new.txt");
	int h = 1;
	/*
	while (getline(inFile, line)) {
		outFile << line << endl;
		if (h >= 2) {
			myfun(line);
		}
		h = 2;
	}*/

	//inFile.close();
	/*outFile.close();*/
	if (table == 0) {
		for (int i = 0; i < 10; i++) {
			fstream inFile1(index[i]);
			h = 1;
			while (getline(inFile1, line)) {
				if (h >= 2) {
					myfun(line);
				}
				h = 2;
			}
			inFile1.close();
		}

		outFile.close();
	}
	else {
		fstream inFile1(index[table-1]);
		h = 1;
		while (getline(inFile1, line)) {
			if (h >= 2) {
				myfun(line);
			}
			h = 2;
		}
		inFile1.close();


	}

	return 0;
}
void P_Search() {

	cout << "Data Base Mangement System" << endl;
t:
	cout << endl;
	cout << "Press 1 to sort by ID" << endl;
	cout << "Press 2 to sort by Year" << endl;
	cout << "Press 3 to sort by Deaths" << endl;
	cout << "Press 4 to sort by Age_factor" << endl;
	cout << "Press 5 to sort by State" << endl;
	cout << "Press 6 to sort by Cause Name" << endl;
	cout << "Press 7 to sort by Cause 113" << endl;
	cout << "Press 8 to Use WHERE CLAUSE " << endl;
	cout << endl;
	cin >> prince;
	if (prince != 8) {
		menu();
	}
	else {
		clause();
		return;
	}
	int key = 0, search = 0;
	cout << "LOADING  .";
	for (int i = 0; i < 2; i++) {
		Sleep(700);
		cout << "  .";

	}
	system("cls");
	if (prince == 1) {
		// ID
	id:
		cout << "Press 1 for the Point Search " << endl;
		cout << "Press 2 for Range Search" << endl;
		cout << "Press 3 Update the Node by ID" << endl;
		cout << "Press 4 to Delete the Node by ID" << endl;
		cout << "Press 5 to Terminate the Program" << endl;
		cout << "Press 6 to sort on Different Choice" << endl;
		cin >> search;
		if (search == 1) {
			cout << "Enter key to search" << endl;
			cin >> know;
			tree.search_id(tree.root, know);
		}
		else if (search == 2) {
			int i = 0, j = 0, range_1 = 0, range_2 = 0;
			cout << "Enter first key " << endl;
			cin >> range_1;
			i = range_1;
			cout << "Enter last key " << endl;
			cin >> range_2;
			j = range_2;
			for (i; i < j; i++) {
				tree.search_id(tree.root, i);
			}

		}
		else if (search == 3) {
			update_id = true;
			tree.update(tree.root);
			update_id = false;
		}
		else if (search == 4) {
			cout << "Enter key to Delete" << endl;
			cin >> know;
			tree.delete_id(tree.root, know);
			goto id;
		}
		else if (search == 5) {
			tree.levelorder_newline();
		}
		else if (search == 6) {
			delete(tree.root->left);
			delete(tree.root->right);
			tree.root = NULL;
			goto t;
		}
		else {
			goto id;
		}



		//=========================================================================================//		
	}
	if (prince == 2) {
	year:
		cout << "Press 1 for the Point Search " << endl;
		cout << "Press 2 for Range Search" << endl;
		cout << "Press 3 Update the Node by Year" << endl;
		cout << "Press 4 to Delete the Node by Year" << endl;
		cout << "Press 5 to Terminate the Program" << endl;
		cout << "Press 6 to sort on Different Choice" << endl;
		cin >> search;
		if (search == 1) {
			cout << "Enter Year to search" << endl;
			cin >> key;
			tree.search_year(tree.root, key);
		}
		else if (search == 2) {
			int i = 0, j = 0, range_1 = 0, range_2 = 0;
			cout << "Enter first key " << endl;
			cin >> range_1;
			i = range_1;
			cout << "Enter last key " << endl;
			cin >> range_2;
			j = range_2;
			for (i; i < j; i++) {
				tree.search_year(tree.root, i);
			}
		}
		else if (search == 3) {
			update_year = true;
			tree.update(tree.root);
			update_year = false;
		}
		else if (search == 4) {
			cout << "Enter key to Delete" << endl;
			cin >> know;
			tree.delete_year(tree.root, know);
			goto year;
		}
		else if (search == 5) {
			tree.levelorder_newline();
		}
		else if (search == 6) {
			delete(tree.root->left);
			delete(tree.root->right);
			tree.root = NULL;
			goto t;
		}
		else {
			goto year;
		}




		//==============================================================================//

	}


	if (prince == 3) {
	death:
		cout << "Press 1 for the Point Search " << endl;
		cout << "Press 2 for Range Search" << endl;
		cout << "Press 3 Update the Node by Death" << endl;
		cout << "Press 4 to Delete the Node by Death" << endl;
		cout << "Press 5 to Terminate the Program" << endl;
		cout << "Press 6 to sort on Different Choice" << endl;
		cin >> search;
		if (search == 1) {
			cout << "Enter death to search" << endl;
			cin >> key;
			tree.search_death(tree.root, key);
		}
		else if (search == 2) {
			int i = 0, j = 0, range_1 = 0, range_2 = 0;
			cout << "Enter first key " << endl;
			cin >> range_1;
			i = range_1;
			cout << "Enter last key " << endl;
			cin >> range_2;
			j = range_2;
			for (i; i < j; i++) {
				tree.search_death(tree.root, i);
			}
		}
		else if (search == 3) {
			update_death = true;
			tree.update(tree.root);
			update_death = false;
		}
		else if (search == 4) {
			cout << "Enter key to Delete" << endl;
			cin >> know;
			tree.delete_death(tree.root, know);
			goto death;
		}
		else if (search == 5) {
			tree.levelorder_newline();
		}
		else if (search == 6) {
			delete(tree.root->left);
			delete(tree.root->right);
			tree.root = NULL;
			goto t;
		}
		else {
			goto death;
		}



		//===============================================================================//
	}
	if (prince == 4) {
	age:
		cout << "Press 1 for the Point Search " << endl;
		cout << "Press 2 for Range Search" << endl;
		cout << "Press 3 Update the Node by Age" << endl;
		cout << "Press 4 to Delete the Node by Age" << endl;
		cout << "Press 5 to Terminate the Program" << endl;
		cout << "Press 6 to sort on Different Choice" << endl;
		cin >> search;
		if (search == 1) {
			cout << "Enter key to search" << endl;
			cin >> ratio;
			tree.search_age(tree.root, ratio);
		}
		else if (search == 2) {
			float i = 0, j = 0, range_1 = 0, range_2 = 0;
			cout << "Enter first key " << endl;
			cin >> range_1;
			i = range_1;
			cout << "Enter last key " << endl;
			cin >> range_2;
			j = range_2;
			for (i; i < j; i = i + 0.1) {
				tree.search_age(tree.root, i);
			}
		}
		else if (search == 3) {
			update_age = true;
			tree.update(tree.root);
			update_age = false;
		}
		else if (search == 4) {
			float fp;
			cout << "Enter key to Delete" << endl;
			cin >> fp;
			tree.delete_age(tree.root, fp);
			goto age;
		}
		else if (search == 5) {
			tree.levelorder_newline();
		}
		else if (search == 6) {
			delete(tree.root->left);
			delete(tree.root->right);
			tree.root = NULL;
			goto t;
		}
		else {
			goto age;
		}


		//=================================================================//
	}
	if (prince == 5) {
	state:
		cout << "Enter 1 for state to search" << endl;
		cout << "Press 2 Update the Node by state" << endl;
		cout << "Press 3 to Delete the Node by state" << endl;
		cout << "Press 4 to Terminate the Program" << endl;
		cout << "Press 5 to sort on Different Choice" << endl;
		cin >> search;
		if (search == 1) {
			cout << "Enter state to search" << endl;
			cin >> giga;
			tree.search_state(tree.root, giga);
		}
		else if (search == 2) {
			update_state = true;
			tree.update(tree.root);
			update_state = false;
		}
		else if (search == 3) {
			string y;
			cout << "Enter key to Delete" << endl;
			cin >> y;
			tree.delete_state(tree.root, y);
			goto state;
		}
		else if (search == 4) {
			tree.levelorder_newline();
		}
		else if (search == 5) {
			delete(tree.root->left);
			delete(tree.root->right);
			tree.root = NULL;
			goto t;
		}
		else {
			goto state;
		}
		//===============================================================================//
	}
	if (prince == 6) {
		//Unintentional injuries
		//Heart disease
		//Alzheimer's disease
		//All causes
	cause_name:
		giga = "\0";
		cout << "Enter 1 to cause name to search" << endl;
		cout << "Enter 2 Update the Node by Cause name" << endl;
		cout << "Press 3 to Delete the Node by Cause Name" << endl;
		cout << "Press 4 to Terminate the Program" << endl;
		cout << "Press 5 to sort on Different Choice" << endl;
		cin >> search;

		if (search == 1) {
			cout << "Enter cause name to search" << endl;
			cin >> giga;
			tree.search_cause_name(tree.root, giga);
		}
		else if (search == 2) {
			update_cause_name = true;
			tree.update(tree.root);
			update_cause_name = false;
		}
		else if (search == 3) {
			cout << "Enter key to Delete" << endl;
			cin >> giga;
			tree.delete_cause_name(tree.root, giga);
			goto cause_name;
		}
		else if (search == 4) {
			tree.levelorder_newline();
		}
		else if (search == 5) {
			delete(tree.root->left);
			delete(tree.root->right);
			tree.root = NULL;
			goto t;
		}
		else {
			goto cause_name;
		}
	}
	if (prince == 7) {
	cause_113:
		giga = "\0";
		cout << "Enter 1 for cause 113 to search" << endl;
		cout << "Enter 2 Update the Node by Cause 113" << endl;
		cout << "Press 3 to Delete the Node by Cause 113" << endl;
		cout << "Press 4 to Terminate the Program" << endl;
		cout << "Press 5 to sort on Different Choice" << endl;
		cin >> search;
		if (search == 1) {
			cout << "Enter cause 113 to search" << endl;
			cin >> giga;
			tree.search_cause_113(tree.root, giga);
		}
		else if (search == 2) {
			update_cause_113 = true;
			tree.update(tree.root);
			update_cause_113 = false;
		}
		else if (search == 3) {
			cout << "Enter key to Delete" << endl;
			cin >> giga;
			tree.delete_cause_113(tree.root, giga);
			goto cause_113;
		}
		else if (search == 4) {
			tree.levelorder_newline();
		}
		else if (search == 5) {
			delete(tree.root->left);
			delete(tree.root->right);
			tree.root = NULL;
			goto t;
		}
		else {
			goto cause_113;
		}

	}
	else if (prince == 8) {
		tree.levelorder_newline();
	}
	else {
		PlaySound(TEXT("error.wav"), NULL, SND_SYNC);
		goto t;
	}


	return;

}

//=============================================================================================//
void clause() {
	system("cls");
	cout << "		##      ## ##     ## ######## ########  ########     ######     ###    ##     ##  ######  ########" << endl;
	cout << "		##  ##  ## ##     ## ##       ##     ## ##          ##    ##   ## ##   ##     ## ##    ## ##" << endl;
	cout << "		##  ##  ## ##     ## ##       ##     ## ##          ##        ##   ##  ##     ## ##       ##" << endl;
	cout << "		##  ##  ## ######### ######   ########  ######      ##       ##     ## ##     ##  ######  ######" << endl;
	cout << "		##  ##  ## ##     ## ##       ##   ##   ##          ##       ######### ##     ##       ## ##" << endl;
	cout << "		##  ##  ## ##     ## ##       ##    ##  ##          ##    ## ##     ## ##     ## ##    ## ##" << endl;
	cout << "	         ###  ###  ##     ## ######## ##     ## ########     ######  ##     ##  #######   ######  ########" << endl;

	cout << endl;
	cout << "Welcome to the where clause " << endl;
	cout << "-------===============----------------=============-----------==============--------" << endl;
	cout << "For the Selection of the Table" << endl;
	cout << "-------===============----------------=============-----------==============--------" << endl;
	cout << "You should remember that there are 10 tables. Form 1 - 10" << endl;
	string a, b;

	lol:
	PlaySound(TEXT("details.wav"), NULL, SND_SYNC);
	cout << "SELECT THE TABLE NUMBER FROM 1 -  10  "<<endl ;
	cout << "OR" << endl;
	cout << "PRESS 0 TO SELECT ALL THE FILES       ";
	cin >> table;
	if (table > 10 || table < 0) {
		goto lol;
	}
	cout << "Select the column first" << endl;
	cout << "     SELECT	:  ";
	cin >> a;
	cout << endl;
	cout << "     WHERE	    :  ";
	cin >> b;
	cout << endl;
	cout << "   IS EQUAL TO =  :";
	cin >> a;
	if (b == "ID" || b == "id" || b == "Id") {
		prince = 1;
		menu();
		int val = stoi(a);
		tree.search_id(tree.root, val);
	}
	else if (b == "State" || b == "STATE" || b == "state") {
		prince = 5;
		menu();
		tree.search_state(tree.root, a);
	}
	else if (b == "Cause Name" || b == "cause name") {
		prince = 6;
		menu();
		tree.search_cause_name(tree.root, a);
	}
	else if (b == "YEAR" || b == "year" || b == "Year") {
		prince = 2;
		menu();
		int val = stol(a);
		tree.search_year(tree.root, val);
	}
	else if (b == "DEATHS" || b == "deaths" || b == "Deaths") {
		prince = 3;
		menu();
		int val = stol(a);
		tree.search_death(tree.root, val);
	}
	else if (b == "CAUSE 113" || b == "Cause 113" || b == "cause 113") {
		prince = 7;
		menu();
		tree.search_cause_113(tree.root, a);
	}
	else if (b == "AGE FACTOR" || b == "Age Factor" || b == "age factor") {
		prince = 4;
		menu();
		float val = stol(a);
		tree.search_age(tree.root, val);
	}
	else {
		cout << "WRONG INPUT"<<endl;
		goto lol;
	}
	PlaySound(TEXT("end.wav"), NULL, SND_SYNC);
}
