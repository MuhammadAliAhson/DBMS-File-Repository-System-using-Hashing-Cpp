#pragma once
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<list>
#include"B-tree.h"
using namespace std;

BTree tree(7);


int retAscii(string x)
{
	int count = 0;
	for (int i = 0; i < x.size(); i++)
	{
		count = count + (int)x[i];
	}
	return count;

}


Node* FiletoNode(vector<string> v);

//---------------============-------------------------//
vector<string> seperateElements(string str) {

	std::stringstream sstr(str);
	std::vector<std::string> v;
	while (sstr.good())
	{
		std::string substr;
		getline(sstr, substr, ',');
		v.push_back(substr);
	}


	return v;

	//FiletoNode(v);

}

vector<string> seperateElements2(string str) {

	std::stringstream sstr(str);
	std::vector<std::string> v;
	while (sstr.good())
	{
		std::string substr;
		getline(sstr, substr, '$');
		v.push_back(substr);
	}


	return v;

	//FiletoNode(v);

}

Node* FiletoNode(vector<string> v) {
	string a[7];
	if (v.size() == 7) {
		for (int i = 0; i < v.size(); i++) {
			a[i] = v[i];
		}
	}
	if (v.size() == 8) {
		a[0] = v[0];
		a[1] = v[1];
		a[2] = v[2] + v[3];
		a[3] = v[4];
		a[4] = v[5];
		a[5] = v[6];
		a[6] = v[7];
	}
	if (v.size() == 9) {
		a[0] = v[0];
		a[1] = v[1];
		a[2] = v[2] + v[3] + v[4];
		a[3] = v[5];
		a[4] = v[6];
		a[5] = v[7];
		a[6] = v[8];
	}
	else if (v.size() == 10) {
		a[0] = v[0];
		a[1] = v[1];
		a[2] = v[2] + v[3] + v[4] + v[5];
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

	Node* into = new Node;
	into->id = id;
	into->year = year;
	into->cause_113 = cause_113;
	into->cause_name = cause_name;
	into->state = state;
	into->deaths = deaths;
	into->age_adjust = age_adjust;

	return into;

}


void createFile(Node* node, int index, string path)
{
	string fileName = to_string(index);
	fileName += ".txt";

	path += fileName;
	ofstream myfile;

	myfile.open(path); //Opened the file in write mode

	myfile << node->id << "$" << node->year << "$" << node->cause_113 << "$" << node->cause_name << "$" << node->state << "$" << node->deaths << "$" << node->age_adjust << "$";
	
	myfile.close();
}


Node* reObj(string path)
{

	ifstream myFile(path);

	std::vector<std::string> Lines;

	// Temporary buffer
	std::string temp;

	// Get input from the input file until file ends

	while (std::getline(myFile, temp, '$'))
	{
		Lines.push_back(temp);
	}


	int id = 0, year = 0, deaths = 0;
	float age_adjust = 0.0;
	string cause_113 = " ";
	string cause_name = " ";
	string state = " ";

	//=========================================================//

	id = stol(Lines[0]);
	year = stol(Lines[1]);
	cause_113 = Lines[2];
	cause_name = Lines[3];
	state = Lines[4];
	deaths = stoi(Lines[5]);
	age_adjust = stof(Lines[6]);

	cout << endl;

	Node* into = new Node;
	into->id = id;
	into->year = year;
	into->cause_113 = cause_113;
	into->cause_name = cause_name;
	into->state = state;
	into->deaths = deaths;
	into->age_adjust = age_adjust;

	return into;
}

void InsertIntoTree(string str, int choice, int index)
{
	vector<string> v = seperateElements(str);
	Node* into = FiletoNode(v);
	string path;
	if (choice == 1)
	{//ID
		path = "C:/Users/User/Desktop/Project/AllNodes/bID/Node";
		createFile(into, index, path);
		tree.insert(into->id);
	}

	else if (choice == 2)
	{// year
		tree.insert(into->year);

	}
	else if (choice == 3)
	{// deaths
		tree.insert(into->deaths);

	}
	else if (choice == 4)
	{// age-dactor
		tree.insert(into->age_adjust);

	}


	else if (choice == 5)
	{// state
		tree.insert(retAscii(into->state));

	}
	else if (choice == 6)
	{//cause name
		tree.insert(retAscii(into->cause_name));

	}

	else if (choice == 7)
	{//Cause 113
		tree.insert(retAscii(into->cause_113));
	}

}


Node* findNode(int key)
{
	string path;

	path = "C:/Users/User/Desktop/Project/AllNodes/bID/Node";
	path += to_string(key);
	path += ".txt";

	Node* node = reObj(path);

	return node;
}

Node* findNode_year(int key)
{
	string path;
	string line;

	ifstream myFile("BigData.txt", ios::in);

	string id1;
	string year;

	string rubbish;

	int i = 0;

	if (myFile)
	{
		while (myFile)
		{
			// Read an item using $ as a delimiter.
			getline(myFile, id1, ',');

			// While the last read operation
			// was successful, continue.

				// Display the last item read.
			//cout << id1 << endl;

			getline(myFile, year, ',');

			//cout << year << endl << endl;

			getline(myFile, rubbish, '\n');

			if (stol(year) == key)
				break;


		}
		// Close the file.
		myFile.close();

	}

	path = "C:/Users/User/Desktop/Project/AllNodes/bID/Node";
	path += id1;
	path += ".txt";

	Node* node = reObj(path);

	return node;
}

Node* findNode_cause113(int key)
{

	string path;
	string line;

	ifstream myFile("BigData.txt", ios::in);

	string id1;
	string year;
	string cause113;

	string rubbish;

	int i = 0;

	if (myFile)
	{
		while (myFile)
		{
			// Read an item using $ as a delimiter.
			getline(myFile, id1, ',');

			// While the last read operation
			// was successful, continue.

				// Display the last item read.
			//cout << id1 << endl;

			getline(myFile, year, ',');

//			cout << year << endl << endl;

			getline(myFile, cause113, '"');
			getline(myFile, cause113, '"');

	//		cout << cause113<<endl;

			getline(myFile, rubbish, '\n');

			//cout << key << endl;
			cout << retAscii(cause113) << endl;
			if (retAscii(cause113) == key)
			{
				cout << "hiii";
				cout<<retAscii(cause113);
				break;
			}

		}
		// Close the file.
		myFile.close();

	}

	//path = "C:/Users/User/Desktop/Project/AllNodes/bID/Node";
	//path += id1;
	//path += ".txt";

	//Node* node = reObj(path);
	Node* node=new Node;

	return node;
}

Node* findNode_state(int key)
{

	string path;
	string line;

	ifstream myFile("BigData.txt", ios::in);

	string id1;
	string year;
	string cause113;
	string causename;
	string state;
	string rubbish;

	int i = 0;

	if (myFile)
	{
		while (myFile)
		{
			// Read an item using $ as a delimiter.
			getline(myFile, id1, ',');

			// While the last read operation
			// was successful, continue.

				// Display the last item read.
			//cout << id1 << endl;

			getline(myFile, year, ',');

			//			cout << year << endl << endl;

			getline(myFile, cause113, '"');
			getline(myFile, cause113, '"');

			//		cout << cause113<<endl;
			getline(myFile, causename, ',');

			getline(myFile, state, ',');

			getline(myFile, rubbish, '\n');

			cout << key << endl;
			cout << endl << retAscii(state);
			if (retAscii(state) == key)
			{
				break;
			}

		}
		// Close the file.
		myFile.close();

	}

	path = "C:/Users/User/Desktop/Project/AllNodes/bID/Node";
	path += id1;
	path += ".txt";

	Node* node = reObj(path);

	return node;
}


Node* findNode_causename(int key)
{

	string path;
	string line;

	ifstream myFile("BigData.txt", ios::in);

	string id1;
	string year;
	string cause113;
	string causename;
	string state;
	string rubbish;

	int i = 0;

	if (myFile)
	{
		while (myFile)
		{
			// Read an item using $ as a delimiter.
			getline(myFile, id1, ',');

			// While the last read operation
			// was successful, continue.

				// Display the last item read.
			//cout << id1 << endl;

			getline(myFile, year, ',');

			//			cout << year << endl << endl;

			getline(myFile, cause113, '"');
			getline(myFile, cause113, '"');

			//		cout << cause113<<endl;
			getline(myFile, causename, ',');

			getline(myFile, state, ',');

			getline(myFile, rubbish, '\n');

		
			if (retAscii(causename) == key)
			{
				break;
			}

		}
		// Close the file.
		myFile.close();

	}

	path = "C:/Users/User/Desktop/Project/AllNodes/bID/Node";
	path += id1;
	path += ".txt";

	Node* node = reObj(path);

	return node;
}


Node* findNode_deaths(int key)
{

	string path;
	string line;

	ifstream myFile("BigData.txt", ios::in);

	string id1;
	string year;
	string cause113;
	string causename;
	string state;
	string deaths;
	string age_Adjust;
	string rubbish;

	int i = 0;

	if (myFile)
	{
		while (myFile)
		{
			// Read an item using $ as a delimiter.
			getline(myFile, id1, ',');

			// While the last read operation
			// was successful, continue.

				// Display the last item read.
			//cout << id1 << endl;

			getline(myFile, year, ',');

			//			cout << year << endl << endl;

			getline(myFile, cause113, '"');
			getline(myFile, cause113, '"');

			//		cout << cause113<<endl;
			getline(myFile, causename, ',');
			getline(myFile, causename, ',');


			getline(myFile, state, ',');

			getline(myFile, deaths, ',');

			getline(myFile, age_Adjust, '\n');

			//getline(myFile, rubbish, '\n');
		
			if (stol(deaths) == key)
			{
				break;
			}

		}
		// Close the file.
		myFile.close();

	}

	path = "C:/Users/User/Desktop/Project/AllNodes/bID/Node";
	path += id1;
	path += ".txt";

	Node* node = reObj(path);

	return node;
}

Node* findNode_ageAdjusts(int key)
{

	string path;
	string line;

	ifstream myFile("BigData.txt", ios::in);

	string id1;
	string year;
	string cause113;
	string causename;
	string state;
	string deaths;
	string age_Adjust;
	string rubbish;

	int i = 0;

	if (myFile)
	{
		while (myFile)
		{
			// Read an item using $ as a delimiter.
			getline(myFile, id1, ',');

			// While the last read operation
			// was successful, continue.

				// Display the last item read.
			//cout << id1 << endl;

			getline(myFile, year, ',');

			//			cout << year << endl << endl;

			getline(myFile, cause113, '"');
			getline(myFile, cause113, '"');

			//		cout << cause113<<endl;
			getline(myFile, causename, ',');

			getline(myFile, state, ',');

			getline(myFile, deaths, ',');

			getline(myFile, age_Adjust, '\n');

			//getline(myFile, rubbish, '\n');


			if (stol(age_Adjust) == key)
			{
				break;
			}

		}
		// Close the file.
		myFile.close();

	}

	path = "C:/Users/User/Desktop/Project/AllNodes/bID/Node";
	path += id1;
	path += ".txt";

	Node* node = reObj(path);

	return node;
}

Node* findNodes_year(int key)
{
	string path;
	string line;
	int size=0;

	ifstream myFile("BigData.txt", ios::in);

	string id1;
	string year;

	string rubbish;

	int i = 0;

	if (myFile)
	{
		while (!myFile.eof())
		{
			
			// Read an item using $ as a delimiter.
			getline(myFile, id1, ',');

			// While the last read operation
			// was successful, continue.

				// Display the last item read.
			//cout << id1 << endl;

			getline(myFile, year, ',');

			//cout << year << endl << endl;

			getline(myFile, rubbish, '\n');

			if(year == to_string(key))
			{
				size++;
			}
		}
		// Close the file.
		myFile.close();

	}

	myFile.open("BigData.txt", ios::in);

	Node* node = new Node[size];
	int count = 0;

	if (myFile)
	{
		while (myFile)
		{
			if (count == size || !myFile)
				break;
			// Read an item using $ as a delimiter.
			getline(myFile, id1, ',');

			// While the last read operation
			// was successful, continue.

				// Display the last item read.
			//cout << id1 << endl;

			getline(myFile, year, ',');

			//cout << year << endl << endl;

			getline(myFile, rubbish, '\n');

			if (year == to_string(key))
			{
				if (year != to_string(key))
					break;
				/*cout << year;
				cout << key;*/
				if (count == size)
					break;
				path = "C:/Users/User/Desktop/Project/AllNodes/bID/Node";
				path += id1;
				path += ".txt";

				
				node[count] =new Node(reObj(path));
				//node[count].print();
				count++;
				//break;

				
			}
		}
		// Close the file.
		myFile.close();

	}


	return node;
}
void BTreeNode::traverseforFiles(string path, int choice)
{
	// There are n keys and n+1 children, traverse through n keys
	// and first n children
	int i;
	int index = 1;
	for (i = 0; i < n; i++)
	{
		// If this is not leaf, then before printing key[i],
		// traverse the subtree rooted with child C[i].
		if (leaf == false)
			C[i]->traverseforFiles(path, choice);

		cout << " " << keys[i];
		if(choice==2)
			Node* temp = findNode_year(keys[i]);
		else
		{
			Node* temp = findNode(keys[i]);
			createFile(temp, index, path);
			index++;
		}
	}

	// Print the subtree rooted with last child
	if (leaf == false)
		C[i]->traverseforFiles(path, choice);
}


void BTree::traverseFiles(string path, int choice)
{
	if (root != NULL) root->traverseforFiles(path, choice);
}

void MakeFiles(int choice)
{
	string path;

	 if (choice == 2)
	{// year
		path = "C:/Users/User/Desktop/Project/AllNodes/bYear/Node";
		tree.traverseFiles(path, choice);


	}
	 else if (choice == 1)
	 {
		 tree.traverse();
	 }
	else if (choice == 3)
	{// deaths
		path = "C:/Users/User/Desktop/Project/AllNodes/bdeaths/Node";
		tree.traverseFiles(path, choice);


	}
	else if (choice == 4)
	{// age-dactor
		path = "C:/Users/User/Desktop/Project/AllNodes/bAge_adjust/Node";
		tree.traverseFiles(path, choice);

	}


	else if (choice == 5)
	{// state
		path = "C:/Users/User/Desktop/Project/AllNodes/bstate/Node";
		tree.traverseFiles(path, choice);


	}
	else if (choice == 6)
	{//cause name
		path = "C:/Users/User/Desktop/Project/AllNodes/bCauseName/Node";
		tree.traverseFiles(path, choice);

	}

	else if (choice == 7)
	{//Cause 113
		path = "C:/Users/User/Desktop/Project/AllNodes/bCause_113/Node";
		tree.traverseFiles(path, choice);


	}

}

void menu2(int choice);


void menu() {

	int choice;

	cout << "Data base mangemant system" << endl;
	cout << endl;


	cout << "Press 1 to sort by ID" << endl;
	cout << "Press 2 to sort by Year" << endl;
	cout << "Press 3 to sort by Deaths" << endl;
	cout << "Press 4 to sort by Age_factor" << endl;
	cout << "Press 5 to sort by State" << endl;
	cout << "Press 6 to sort by Cause Name" << endl;
	cout << "Press 7 to sort by Cause 113" << endl;
	cout << "Press 8 to Exit..." << endl;

	cout << endl;


	cin >> choice;


	if (choice == 8)
		return;

	string a1 = "C:/Users/User/Desktop/Project/DataSet/NCHS_-_Leading_Causes_of_Death__United_States_1.csv";
	string a2 = "C:/Users/User/Desktop/Project/DataSet/NCHS_-_Leading_Causes_of_Death__United_States_2.csv";
	string a3 = "C:/Users/User/Desktop/Project/DataSet/NCHS_-_Leading_Causes_of_Death__United_States_3.csv";
	string a4 = "C:/Users/User/Desktop/Project/DataSet/NCHS_-_Leading_Causes_of_Death__United_States_4.csv";
	string a5 = "C:/Users/User/Desktop/Project/DataSet/NCHS_-_Leading_Causes_of_Death__United_States_5.csv";
	string a6 = "C:/Users/User/Desktop/Project/DataSet/NCHS_-_Leading_Causes_of_Death__United_States_6.csv";
	string a7 = "C:/Users/User/Desktop/Project/DataSet/NCHS_-_Leading_Causes_of_Death__United_States_7.csv";
	string a8 = "C:/Users/User/Desktop/Project/DataSet/NCHS_-_Leading_Causes_of_Death__United_States_8.csv";
	string a9 = "C:/Users/User/Desktop/Project/DataSet/NCHS_-_Leading_Causes_of_Death__United_States_9.csv";
	string a10 = "C:/Users/User/Desktop/Project/DataSet/NCHS_-_Leading_Causes_of_Death__United_States_10.csv";
	string index[] = { a1,a2,a3,a4,a5,a6,a7,a8,a9,a10 };

	// file handling


	ofstream outFile("BigData.txt");

	int skipLine;   //To skip first line as it contains headers
	string line;
	int countforFirstFileOnly = 1;

	//line by line input from 10 csv files to a new file
	for (int i = 0; i < 10; i++)
	{
		ifstream inFile1(index[i]);
		skipLine = 1;
		while (getline(inFile1, line))
		{
			if (skipLine >= 2) {
				outFile << line << endl;
				InsertIntoTree(line, choice, countforFirstFileOnly);
				countforFirstFileOnly++;
			}
			skipLine = 2;
		}
		inFile1.close();
	}

	outFile.close();

	//tree.traverse();
	MakeFiles(choice);

	system("pause");
	system("cls");

	cout << "Data base mangemant system" << endl;
	cout << endl;


	cout << "Press 1 for Point Search" << endl;
	cout << "Press 2 for Accessing by ID" << endl;
	cout << "Press 3 for Range Search" << endl;
	cout << "Press 4 to Update Fields" << endl;
	cout << "Press 5 to Go Back" << endl;
	cout << "Press 6 to Exit.." << endl;
	cout << endl;


	cin >> choice;

	menu2(choice);


}



string Access_File(string path)
{
	ifstream myFile(path);
	string line;

	getline(myFile, line);

	return line;

}

void Print_File(string path)
{
	Node* node=reObj(path);

	node->print();

}

void Search_Tuple(int key)
{
	string path;
	
	string line;

	ifstream myFile("BigData.txt", ios::in);

	string id1;
	string year;
	string cause113;
	string causename;
	string state;
	string deaths;
	string age_Adjust;
	string rubbish;

	int i = 0;

	if (myFile)
	{
		while (!myFile.eof())
		{
			// Read an item using $ as a delimiter.
			getline(myFile, id1, ',');

			// While the last read operation
			// was successful, continue.

				// Display the last item read.
			//cout << id1 << endl;

			getline(myFile, year, ',');

			//			cout << year << endl << endl;

			getline(myFile, cause113, '"');
			getline(myFile, cause113, '"');

			//		cout << cause113<<endl;
			getline(myFile, causename, ',');
			getline(myFile, causename, ',');


			getline(myFile, state, ',');

			getline(myFile, deaths, ',');

			getline(myFile, age_Adjust, '\n');

			//getline(myFile, rubbish, '\n');


			if (key==stol(year) || key==stol(deaths) || key==stol(age_Adjust))
			{
				cout << id1 << endl;
				cout << year << endl;
				cout << cause113 << endl;
				cout << causename << endl;
				cout << state << endl;
				cout << deaths << endl;
				cout << age_Adjust << endl;

				cout <<endl<< "---------------------------" << endl << endl;
			}

		}
		// Close the file.
		myFile.close();

	}


}
void range_Search(int start, int end)
{
	string path;

	string line;

	ifstream myFile("BigData.txt", ios::in);

	string id1;
	string year;
	string cause113;
	string causename;
	string state;
	string deaths;
	string age_Adjust;
	string rubbish;

	int i = 0;

	if (myFile)
	{
		while (!myFile.eof())
		{
			// Read an item using $ as a delimiter.
			getline(myFile, id1, ',');

			// While the last read operation
			// was successful, continue.

				// Display the last item read.
			//cout << id1 << endl;

			getline(myFile, year, ',');

			//			cout << year << endl << endl;

			getline(myFile, cause113, '"');
			getline(myFile, cause113, '"');

			//		cout << cause113<<endl;
			getline(myFile, causename, ',');
			getline(myFile, causename, ',');


			getline(myFile, state, ',');

			getline(myFile, deaths, ',');

			getline(myFile, age_Adjust, '\n');

			//getline(myFile, rubbish, '\n');


			if ((start <= stol(year) && end >= stol(year)) || (start <= stol(deaths) && end >= stol(deaths)) || (start <= stol(age_Adjust) && end >= stol(age_Adjust)))
			{
				cout << id1 << endl;
				cout << year << endl;
				cout << cause113 << endl;
				cout << causename << endl;
				cout << state << endl;
				cout << deaths << endl;
				cout << age_Adjust << endl;

				cout << endl << "---------------------------" << endl << endl;
			}

		}
		// Close the file.
		myFile.close();


	}

}

void update()
{
	string field;
	int key;

	cout << "Enter the field you want to change:" << endl;
	cin >> field;
	cout << "Enter the Key you want to change: " << endl;
	cin >> key;


	int lines;
	string line;

	fstream myFile("BigData.txt", ios::in | ios::out);

	string id1;
	string year;
	string cause113;
	string causename;
	string state;
	string deaths;
	string age_Adjust;
	string rubbish;

	int i = 0;

	if (myFile)
	{
		while (!myFile.eof())
		{
			// Read an item using $ as a delimiter.
			getline(myFile, id1, ',');

			// While the last read operation
			// was successful, continue.

				// Display the last item read.
			//cout << id1 << endl;

			getline(myFile, year, ',');

			//			cout << year << endl << endl;

			getline(myFile, cause113, '"');
			getline(myFile, cause113, '"');

			//		cout << cause113<<endl;
			getline(myFile, causename, ',');
			getline(myFile, causename, ',');


			getline(myFile, state, ',');

			getline(myFile, deaths, ',');

			getline(myFile, age_Adjust, '\n');

			//getline(myFile, rubbish, '\n');


			if (key == stol(year) || key == stol(deaths) || key == stol(age_Adjust))
			{
				lines = stol(id1);
				break;
			}
		}

		if (field == "year" || field == "Year")
		{
			myFile << id1 << key;
		}

		if (field == "deaths" || field == "Deaths")
		{
			myFile << id1 << year << cause113 << causename << state << key << age_Adjust;

		}

		if (field == "age Adjust" || field == "Age Adjust" || field == "age adjust")
		{
			myFile << id1 << year << cause113 << causename << state << deaths << key;

		}



		// Close the file.
		myFile.close();
	}
}

int main()
{ 
	menu();
	return 0;
}

void menu2(int choice)
{
	if(choice == 6)
	{
		return;
	}
	else if(choice == 1)
	{
		cout << endl << endl;

		int key;
		cout << "Enter Any Key you Please: ";
		cin >> key;

		cout << endl;
		Search_Tuple(key);

		system("pause");
	}
	else if (choice == 2)
	{
		cout << endl << endl;

		int key;
		cout << "Enter Any Id you Please: ";
		cin >> key;

		cout << endl;
		findNode(key)->print();
		cout << endl;
		system("pause");

	}
	else if(choice == 3)
	{
		cout << endl << endl;

		int key1;
		int key2;
		cout << "Enter Starting Value of your Range: ";
		cin >> key1;

		cout << "Enter Ending Value of your Range  : ";
		cin >> key2;



		cout << endl;
		range_Search(key1, key2);

		system("pause");


	}

	else if (choice == 4)
	{
		update();
	}
	else if (choice == 5)
	{
		system("cls");
		menu();
	}
}