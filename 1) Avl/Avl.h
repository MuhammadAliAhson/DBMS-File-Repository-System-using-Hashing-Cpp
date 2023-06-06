#pragma once
#pragma once
#include <iostream>
//#include "database.cpp"
#include <fstream>
#include <Windows.h>
#include "string"
#include <queue>
using namespace std;
int prince;
int know = 0;
float ratio;
string giga;
bool update_id, update_year, update_death, update_age, update_state, update_cause_name, update_cause_113;
// update_id = update_year = update_death = update_age = update_state = update_cause_name = update_cause_113 = false;
int nodeCount = 0;





int retAscii(string x) {
	int count = 0;
	for (int i = 0; i < x.size(); i++) {
		count = count + (int)x[i];
	}
	return count;

}
class node {
public:
	int id;
	int  year = 0;
	int deaths = 0;
	float age_adjust = 0.0;
	string cause_113 = " ";
	string cause_name = " ";
	string state = " ";
	int treeHeight;
	node* same;
	node* left;
	node* right;
	node() {
		this->id = 0;
		this->year = 0;
		this->deaths = 0;
		this->age_adjust = 0.0;
		this->cause_113 = " ";
		this->cause_name = " ";
		this->state = " ";
		this->treeHeight = 1;
		this->same = NULL;
		this->left = nullptr;
		this->right = nullptr;

	}
	node(int data) {
		this->id = data;
		this->same = NULL;
		this->left = nullptr;
		this->right = nullptr;
	}
	node(node* a) {
		this->id = a->id;
		this->year = a->year;
		this->deaths = a->deaths;
		this->age_adjust = a->age_adjust;
		this->cause_113 = a->cause_113;
		this->cause_name = a->cause_name;
		this->state = a->state;
		this->treeHeight = 1;
		this->left = nullptr;
		this->right = nullptr;
	}

};

class node_s {
public:
	int id;
	int  year = 0;
	int deaths = 0;
	float age_adjust = 0.0;
	string cause_113 = " ";
	string cause_name = " ";
	string state = " ";
	int treeHeight;
	string same;
	string left;
	string right;
	node_s() {
		this->id = 0;
		this->year = 0;
		this->deaths = 0;
		this->age_adjust = 0.0;
		this->cause_113 = " ";
		this->cause_name = " ";
		this->state = " ";
		this->treeHeight = 1;
		this->same = "\0";
		this->left = "\0";
		this->right = "\0";

	}
	node_s(int data) {
		this->id = data;
		this->same = "\0";
		this->left = "\0";
		this->right = "\0";
	}
	node_s(node* a) {
		this->id = a->id;
		this->year = a->year;
		this->deaths = a->deaths;
		this->age_adjust = a->age_adjust;
		this->cause_113 = a->cause_113;
		this->cause_name = a->cause_name;
		this->state = a->state;
		this->treeHeight = a->treeHeight;
		this->same = "\0";
		this->left = "\0";
		this->right = "\0";
	}

};

class Avl {
public:
	node* root;
	Avl() {
		this->root = NULL;
	}
	//=========For Deletion of the same =====================//
	node* MinValue(node* nod) {
		node * current = nod;
		while (current->left != NULL)
			current = current->left;
		return current;
	}

	//----------------------Balancing Factor------------------------//
	int balFac(struct node* n) {
		if (n->left && n->right) {
			return n->left->treeHeight - n->right->treeHeight;
		}
		else if (n->left && n->right == NULL) {
			return n->left->treeHeight;
		}
		else if (n->left == NULL && n->right) {
			return -n->right->treeHeight;
		}
	}
	//---------Right Rotation------------------------------//
	node* rightRotate(node* y) {
		node* x = y->left;
		node* T2 = x->right;
		x->right = y;
		y->left = T2;
		y->treeHeight = max(height(y->left),
			height(y->right)) +
			1;
		x->treeHeight = max(height(x->left),
			height(x->right)) +
			1;
		return x;
	}

	//------------Rotate left---------------------------------//
	node* leftRotate(node* x) {
		node* y = x->right;
		node* T2 = y->left;
		y->left = x;
		x->right = T2;
		x->treeHeight = max(height(x->left),
			height(x->right)) +
			1;
		y->treeHeight = max(height(y->left),
			height(y->right)) +
			1;
		return y;
	}
	//=================Height=========================//
	int height(node* root) {

		if (!root)
			return 0;
		else {

			int left_height = height(root->left);
			int right_height = height(root->right);
			if (left_height >= right_height)
				return left_height + 1;
			else
				return right_height + 1;
		}
	}
	//=================Make Files=======================================//
	string makefile(node* data) {
		
		if (data != NULL) {


			string directory = "F:\\Data Project\\Code\\Data Project VS\\Data Project VS\\NodeFiles\\node";
			string newfile = directory + to_string(nodeCount) + ".txt";
		//	cout << newfile << endl;
			fstream o(newfile, ios::out);
			if (!o) {
				cout << "Not file is being made" << endl;
			}
			else {
				o << data->id << ' ' << data->year << ' ' << data->cause_113
					<< ' ' << data->cause_name << ' ' << data->state
					<< ' ' << data->deaths << ' ' << data->age_adjust << ' ' << data->treeHeight
					<< ' ' ;
				o.close();
			}
			nodeCount++;
			if (data->same != NULL) {
				makefile(data->same);
			}
			return newfile;
		}
		
		return "";
	}

	//---------------------------------------//
	// 
	string makefile_s(node_s* data) {

	string directory = "F:\\Data Project\\Code\\Data Project VS\\Data Project VS\\NodeFiles\\node";
	string newfile = directory + to_string(nodeCount) + ".txt";
	//out << newfile << endl;
	fstream o(newfile, ios::out);
	if (!o) {
		cout << "Not file is being made" << endl;
	}
	else {
		o << data->id << ' ' << data->year << ' ' << data->cause_113
			<< ' ' << data->cause_name << ' ' << data->state
			<< ' ' << data->deaths << ' ' << data->age_adjust << ' ' << data->treeHeight
			<< ' ' << data->left << ' ' << data->right << ' ';
		o.close();
	}
	nodeCount++;

	return newfile;
}

	// 
	// 
	











	//====================Displaying================//
	void levelorder_newline() {
		if (this->root == NULL) {
			cout << "\n" << "Empty tree" << "\n";
			return;
		}
		levelorder_newline(this->root);
	}
	void levelorder_newline(struct node* v) {
		queue<node*> q;
		struct node* cur;
		q.push(v);
		q.push(NULL);

		while (!q.empty()) {
			cur = q.front();
			q.pop();
			if (cur == NULL && q.size() != 0) {
				cout << "\n";

				q.push(NULL);
				continue;
			}
			if (cur != NULL) {
				if (prince == 1) {
					cout << " " << cur->id;
				}
				else if (prince == 2) {
					cout << " " << cur->year;
				}
				else if (prince == 3) {
					cout << " " << cur->deaths;
				}
				else if (prince == 4) {
					cout << " " << cur->age_adjust;
				}
				else if (prince == 5) {
					cout << " " << cur->state;
				}
				else if (prince == 6) {
					cout << " " << cur->cause_name << "   ";
				}
				else if (prince == 7) {
					cout << " " << cur->cause_113 << "   ";
				}
				/*else if (prince == 8) {*/
					node_s* temp = new node_s(cur);
					temp->left = makefile(cur->left);
					temp->right = makefile(cur->right);
					makefile_s(temp);
					delete temp;
				//}
				if (cur->left != NULL) {
					q.push(cur->left);
				}
				if (cur->right != NULL) {
					q.push(cur->right);
				}
			}


		}
		PlaySound(TEXT("end.wav"), NULL, SND_SYNC);
	}
	//------------ID Insertion -----------------------//
	node* insert_Id(node* root, node* data) {
		// Find the correct postion and insert the node
		if (root == NULL) {
			node* nop = new node(data);
			return nop;
		}
		if (data->id < root->id) {
			root->left = insert_Id(root->left, data);
		}
		else if (data->id > root->id) {
			root->right = insert_Id(root->right, data);
		}
		else {
			return root;
		}

		// Update the balance factor of each root and
		// balance the tree
		root->treeHeight = 1 + max(height(root->left),
			height(root->right));

		int balanceFactor = balFac(root);

		if (balanceFactor > 1) {
			if (data->id < root->left->id) {
				return rightRotate(root);
			}
			else if (data->id > root->left->id) {
				root->left = leftRotate(root->left);
				return rightRotate(root);
			}
		}
		if (balanceFactor < -1) {
			if (data->id > root->right->id) {
				return leftRotate(root);
			}
			else if (data->id < root->right->id) {
				root->right = rightRotate(root->right);
				return leftRotate(root);
			}
		}
		return root;
	}
	//------------------Year Insertion---------------------------//
	node* insert_year(node* root, node* data) {
		// Find the correct postion and insert the node
		if (root == NULL) {
			node* nop = new node(data);
			return nop;
		}
		if (data->year < root->year) {
			root->left = insert_year(root->left, data);
		}
		else if (data->year > root->year) {
			root->right = insert_year(root->right, data);
		}
		else if (data->year == root->year) {

			node* temp = root;
			if (temp == NULL) {
				temp->same = data;
				return temp;
			}

			while (temp->same != NULL) {
				temp = temp->same;
				//	cout << "pol" << endl;
			}
			temp->same = data;

			return root;
		}
		else {
			return root;
		}

		// Update the balance factor of each root and
		// balance the tree
		root->treeHeight = 1 + max(height(root->left),
			height(root->right));

		int balanceFactor = balFac(root);

		if (balanceFactor > 1) {
			if (data->year < root->left->year) {
				return rightRotate(root);
			}
			else if (data->year > root->left->year) {
				root->left = leftRotate(root->left);
				return rightRotate(root);
			}
		}
		if (balanceFactor < -1) {
			if (data->year > root->right->year) {
				return leftRotate(root);
			}
			else if (data->year < root->right->year) {
				root->right = rightRotate(root->right);
				return leftRotate(root);
			}
		}
		return root;
	}

	//==========Death Insertion====================================//
	node* insert_deaths(node* root, node* data) {
		// Find the correct postion and insert the node
		if (root == NULL) {
			node* nop = new node(data);
			return nop;
		}
		if (data->deaths < root->deaths) {
			root->left = insert_deaths(root->left, data);
		}
		else if (data->deaths > root->deaths) {
			root->right = insert_deaths(root->right, data);
		}
		else if (data->deaths == root->deaths) {
			node* temp = root;
			if (temp == NULL) {
				temp->same = data;
				return temp;
			}

			while (temp->same != NULL) {
				temp = temp->same;
				//	cout << "pol" << endl;
			}
			temp->same = data;

			return root;

		}
		else {
			return root;
		}

		// Update the balance factor of each root and
		// balance the tree
		root->treeHeight = 1 + max(height(root->left),
			height(root->right));

		int balanceFactor = balFac(root);

		if (balanceFactor > 1) {
			if (data->deaths < root->left->deaths) {
				return rightRotate(root);
			}
			else if (data->deaths > root->left->deaths) {
				root->left = leftRotate(root->left);
				return rightRotate(root);
			}
		}
		if (balanceFactor < -1) {
			if (data->deaths > root->right->deaths) {
				return leftRotate(root);
			}
			else if (data->deaths < root->right->deaths) {
				root->right = rightRotate(root->right);
				return leftRotate(root);
			}
		}
		return root;
	}
	//=============Age_Adjust Insertion=====================================//
	//node* insert_age_adjust(node* root, node* data) {
		// Find the correct postion and insert the node
	node* insert_age_adjust(node* root, node* data) {
		if (root == NULL) {
			node* nop = new node(data);
			return nop;
		}
		if (data->age_adjust < root->age_adjust) {
			root->left = insert_age_adjust(root->left, data);
		}
		else if (data->age_adjust > root->age_adjust) {
			root->right = insert_age_adjust(root->right, data);
		}
		else if (data->age_adjust == root->age_adjust) {
			node* temp = root;
			if (temp == NULL) {
				temp->same = data;
				return temp;
			}

			while (temp->same != NULL) {
				temp = temp->same;
				//	cout << "pol" << endl;
			}
			temp->same = data;

			return root;

		}
		else {
			return root;
		}

		// Update the balance factor of each root and
		// balance the tree
		root->treeHeight = 1 + max(height(root->left),
			height(root->right));

		int balanceFactor = balFac(root);

		if (balanceFactor > 1) {
			if (data->age_adjust < root->left->age_adjust) {
				return rightRotate(root);
			}
			else if (data->age_adjust > root->left->age_adjust) {
				root->left = leftRotate(root->left);
				return rightRotate(root);
			}
		}
		if (balanceFactor < -1) {
			if (data->age_adjust > root->right->age_adjust) {
				return leftRotate(root);
			}
			else if (data->age_adjust < root->right->age_adjust) {
				root->right = rightRotate(root->right);
				return leftRotate(root);
			}
		}
		return root;
	}

	//==================State Insertion===========================================================//
	//	// Find the correct postion and insert the node
	node* insert_state(node* root, node* data) {
		if (root == NULL) {
			node* nop = new node(data);
			return nop;
		}
		//retAscii(data->state)
		//retAscii(root->state)
		if (retAscii(data->state) < retAscii(root->state)) {
			root->left = insert_state(root->left, data);
		}
		else if (retAscii(data->state) > retAscii(root->state)) {
			root->right = insert_state(root->right, data);
		}
		else if (retAscii(data->state) == retAscii(root->state)) {
			node* temp = root;
			if (temp == NULL) {
				temp->same = data;
				return temp;
			}

			while (temp->same != NULL) {
				temp = temp->same;
				//	cout << "pol" << endl;
			}
			temp->same = data;

			return root;

		}
		else {
			return root;
		}

		// Update the balance factor of each root and
		// balance the tree
		root->treeHeight = 1 + max(height(root->left),
			height(root->right));

		int balanceFactor = balFac(root);

		if (balanceFactor > 1) {
			if (retAscii(data->state) < retAscii(root->left->state)) {
				return rightRotate(root);
			}
			else if (retAscii(data->state) > retAscii(root->left->state)) {
				root->left = leftRotate(root->left);
				return rightRotate(root);
			}
		}
		if (balanceFactor < -1) {
			if (retAscii(data->state) > retAscii(root->right->state)) {
				return leftRotate(root);
			}
			else if (retAscii(data->state) < retAscii(root->right->state)) {
				root->right = rightRotate(root->right);
				return leftRotate(root);
			}
		}
		return root;
	}
	//=========Cause_Name_Insertion============================================================================//

	node* insert_cause_name(node* root, node* data) {
		if (root == NULL) {
			node* nop = new node(data);
			return nop;
		}
		//retAscii(data->cause_name)
		//retAscii(root->cause_name)
		if (retAscii(data->cause_name) < retAscii(root->cause_name)) {
			root->left = insert_cause_name(root->left, data);
		}
		else if (retAscii(data->cause_name) > retAscii(root->cause_name)) {
			root->right = insert_cause_name(root->right, data);
		}
		else if (retAscii(data->cause_name) == retAscii(root->cause_name)) {
			node* temp = root;
			if (temp == NULL) {
				temp->same = data;
				return temp;
			}

			while (temp->same != NULL) {
				temp = temp->same;
				//	cout << "pol" << endl;
			}
			temp->same = data;

			return root;

		}
		else {
			return root;
		}

		// Update the balance factor of each root and
		// balance the tree
		root->treeHeight = 1 + max(height(root->left),
			height(root->right));

		int balanceFactor = balFac(root);

		if (balanceFactor > 1) {
			if (retAscii(data->cause_name) < retAscii(root->left->cause_name)) {
				return rightRotate(root);
			}
			else if (retAscii(data->cause_name) > retAscii(root->left->cause_name)) {
				root->left = leftRotate(root->left);
				return rightRotate(root);
			}
		}
		if (balanceFactor < -1) {
			if (retAscii(data->cause_name) > retAscii(root->right->cause_name)) {
				return leftRotate(root);
			}
			else if (retAscii(data->cause_name) < retAscii(root->right->cause_name)) {
				root->right = rightRotate(root->right);
				return leftRotate(root);
			}
		}
		return root;
	}


	//---------------------Cause_113 Insertion======================================//

	node* insert_cause_113(node* root, node* data) {
		if (root == NULL) {
			node* nop = new node(data);
			return nop;
		}
		//retAscii(data->cause_113)
		//retAscii(root->cause_113)
		if (retAscii(data->cause_113) < retAscii(root->cause_113)) {
			root->left = insert_cause_113(root->left, data);
		}
		else if (retAscii(data->cause_113) > retAscii(root->cause_113)) {
			root->right = insert_cause_113(root->right, data);
		}
		else if (retAscii(data->cause_113) == retAscii(root->cause_113)) {
			node* temp = root;
			if (temp == NULL) {
				temp->same = data;
				return temp;
			}

			while (temp->same != NULL) {
				temp = temp->same;
				//	cout << "pol" << endl;
			}
			temp->same = data;

			return root;

		}
		else {
			return root;
		}

		// Update the balance factor of each root and
		// balance the tree
		root->treeHeight = 1 + max(height(root->left),
			height(root->right));

		int balanceFactor = balFac(root);

		if (balanceFactor > 1) {
			if (retAscii(data->cause_113) < retAscii(root->left->cause_113)) {
				return rightRotate(root);
			}
			else if (retAscii(data->cause_113) > retAscii(root->left->cause_113)) {
				root->left = leftRotate(root->left);
				return rightRotate(root);
			}
		}
		if (balanceFactor < -1) {
			if (retAscii(data->cause_113) > retAscii(root->right->cause_113)) {
				return leftRotate(root);
			}
			else if (retAscii(data->cause_113) < retAscii(root->right->cause_113)) {
				root->right = rightRotate(root->right);
				return leftRotate(root);
			}
		}
		return root;
	}

	//===================Search by ID======================//
	node* search_id(node* root, int key) {
		// If root is NULL
		if (root == NULL)
			return root;

		// If found, return true
		else if (root->id == key) {
			if (update_id) {
				change(root);
				system("cls");
				Sleep(200);
				display(root);
				update_id = false;
				return root;
			}
			else
				display(root);
			return root;
		}
		// Recur to the left subtree if
		// the current node's value is
		// greater than key
		else if (root->id > key) {
			search_id(root->left, key);
			return root;
		}

		// Otherwise, recur to the
		// right subtree
		else {
			search_id(root->right, key);
			return root;
		}
		return root;
	}
	//================Search by Year=======================//
	void search_year(node* root, int key) {
		// If root is NULL
		if (root == NULL)
			return;

		// If found, return true
		else if (root->year == key) {
			if (update_year) {
				change(root);
				system("cls");
				Sleep(200);
				display(root);
				update_year = false;
			}
			else
				display(root);
			return;
		}
		// Recur to the left subtree if
		// the current node's value is
		// greater than key
		else if (root->year > key) {
			search_year(root->left, key);
			return;
		}

		// Otherwise, recur to the
		// right subtree
		else {
			search_year(root->right, key);
			return;
		}
	}
	//==============Search by Death======================//
	void search_death(node* root, int key) {
		// If root is NULL
		if (root == NULL)
			return;

		// If found, return true
		else if (root->deaths == key ) {
			if (update_death) {
				change(root);
				system("cls");
				Sleep(200);
				display(root);
				update_death = false;
			}
			else
				display(root);
			return;
		}

		// Recur to the left subtree if
		// the current node's value is
		// greater than key
		else if (root->deaths > key) {
			search_death(root->left, key);
			return;
		}

		// Otherwise, recur to the
		// right subtree
		else {
			search_death(root->right, key);
			return;
		}
	}
	//===================Search Age Factor=====================//
	void search_age(node* root, float key) {
		// If root is NULL
		if (root == NULL)
			return;

		// If found, return true
		else if (root->age_adjust == key ) {
			if (update_age) {
				change(root);
				system("cls");
				Sleep(200);
				display(root);
				update_age = false;
			} 
			else {
				display(root);
				return;
			}
		}
		// Recur to the left subtree if
		// the current node's value is
		// greater than key
		else if (root->age_adjust > key) {
			search_age(root->left, key);
			return;
		}

		// Otherwise, recur to the
		// right subtree
		else {
			search_age(root->right, key);
			return;
		}
	}
	//========================Search by Cause Name==============//
	void search_cause_name(node* root, string key) {
		// If root is NULL
		//cout << key;
		if (root == NULL) {

			return;
		}
		// If found, return true
		else if (retAscii(root->cause_name) == retAscii(key) ) {
			if (update_cause_name) {
				change(root);
				system("cls");
				Sleep(200);
				display(root);
				update_cause_name = false;
			}
			else {
				display(root);
				return;
			}
		}
		// Recur to the left subtree if
		// the current node's value is
		// greater than key
		else if (retAscii(root->cause_name) > retAscii(key)) {
			search_cause_name(root->left, key);
			return;
		}

		// Otherwise, recur to the
		// right subtree
		else {
			search_cause_name(root->right, key);
			return;
		}
	}
	//===============Search by state==========================//
	void search_state(node* root, string key) {
		// If root is NULL
		if (root == NULL)
			return;

		// If found, return true
		else if (root->state == key ) {
			if (update_state) {
				change(root);
				system("cls");
				Sleep(200);
				display(root);
				update_state = false;
			}
			else {
				display(root);
				return;
			}
			}
		// Recur to the left subtree if
		// the current node's value is
		// greater than key
		else if (retAscii(root->state) > retAscii(key)) {
			search_state(root->left, key);
			return;
		}

		// Otherwise, recur to the
		// right subtree
		else {
			search_state(root->right, key);
			return;
		}
	}

	//================Search by Cause 113======================//
	void search_cause_113(node* root, string key) {
		// If root is NULL
		if (root == NULL)
			return;

		// If found, return true
		else if (root->cause_113 == key) {
			if (update_cause_113) {
				change(root);
				system("cls");
				Sleep(200);
				display(root);
				update_cause_113 = false;
			}
			else {
				display(root);
				return;
			}
		}
		// Recur to the left subtree if
		// the current node's value is
		// greater than key
		else if (retAscii(root->cause_113) > retAscii(key)) {
			search_cause_113(root->left, key);
			return;
		}

		// Otherwise, recur to the
		// right subtree
		else {
			search_cause_113(root->right, key);
			return;
		}
	}


	//===================Display Function=============================//

	void display(node* print) {
		cout << "Your ID is " << print->id << endl;
		cout << "Your Year is " << print->year << endl;
		cout << "Your State is " << print->state << endl;
		cout << "Your Cause 113 is " << print->cause_113 << endl;
		cout << "Your Cause Name is " << print->cause_name << endl;
		cout << "Your Deaths is " << print->deaths << endl;
		cout << "Your Age Factor is " << print->age_adjust << endl;
		cout << endl;
		cout << "========================================" << endl;
		if (print->same == NULL) {
			return;
		}
		else {
			display(print->same);

			return;
		}

	}
	//=========Deletion Function=====================================//

// Delete a node
	node* delete_id(node* root, int key) {
		// Find the node and delete it
		if (root == NULL)
			return root;
		if (key < root->id)
			root->left = delete_id(root->left, key);
		else if (key > root->id)
			root->right = delete_id(root->right, key);
		else {
			if ((root->left == NULL) ||
				(root->right == NULL)) {
				node* temp;
				if (root->left) {
					temp = root->left;
				}
				else {
					temp = root->right;
				}
				if (temp == NULL) {
					temp = root;
					root = NULL;
				}
				else
					*root = *temp;
				free(temp);
			}
			else {
				node* temp = MinValue(root->right);
				root->id = temp->id;
				root->right = delete_id(root->right,
					temp->id);
			}
		}

		if (root == NULL)
			return root;

		// Update the balance factor of each node and
		// balance the tree
		root->treeHeight = 1 + max(height(root->left),
			height(root->right));
		int balanceFactor = balFac(root);
		if (balanceFactor > 1) {
			if (balFac(root->left) >= 0) {
				return rightRotate(root);
			}
			else {
				root->left = leftRotate(root->left);
				return rightRotate(root);
			}
		}
		if (balanceFactor < -1) {
			if (balFac(root->right) <= 0) {
				return leftRotate(root);
			}
			else {
				root->right = rightRotate(root->right);
				return leftRotate(root);
			}
		}
		return root;
	}
	//======Deletion by Year=====================================//
	 node* delete_year(node* root, int key) {
		// Find the node and delete it
	if (root == NULL)
		return root;
	if (key < root->year)
		root->left = delete_year(root->left, key);
	else if (key > root->year)
		root->right = delete_year(root->right, key);
	else {
		if ((root->left == NULL) ||
			(root->right == NULL)) {
			node* temp;
			if (root->left) {
				temp = root->left;
			}
			else {
				temp = root->right;
			}
			if (temp == NULL) {
				temp = root;
				root = NULL;
			}
			else
				*root = *temp;
			free(temp);
		}
		else {
			node* temp = MinValue(root->right);
			root->year = temp->year;
			root->right = delete_year(root->right,
				temp->year);
		}
	}

	if (root == NULL)
		return root;

	// Update the balance factor of each node and
	// balance the tree
	root->treeHeight = 1 + max(height(root->left),
		height(root->right));
	int balanceFactor = balFac(root);
	if (balanceFactor > 1) {
		if (balFac(root->left) >= 0) {
			return rightRotate(root);
		}
		else {
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
	}
	if (balanceFactor < -1) {
		if (balFac(root->right) <= 0) {
			return leftRotate(root);
		}
		else {
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}
	}
	return root;
	}
	 //========Deletion By death===========================//
	 node* delete_age(node* root,float key) {
		 // Find the node and delete it
		 if (root == NULL)
			 return root;
		 if (key < root->age_adjust)
			 root->left = delete_age(root->left, key);
		 else if (key > root->age_adjust)
			 root->right = delete_age(root->right, key);
		 else {
			 if ((root->left == NULL) ||
				 (root->right == NULL)) {
				 node* temp;
				 if (root->left) {
					 temp = root->left;
				 }
				 else {
					 temp = root->right;
				 }
				 if (temp == NULL) {
					 temp = root;
					 root = NULL;
				 }
				 else
					 *root = *temp;
				 free(temp);
			 }
			 else {
				 node* temp = MinValue(root->right);
				 root->age_adjust = temp->age_adjust;
				 root->right = delete_age(root->right,
					 temp->age_adjust);
			 }
		 }

		 if (root == NULL)
			 return root;

		 // Update the balance factor of each node and
		 // balance the tree
		 root->treeHeight = 1 + max(height(root->left),
			 height(root->right));
		 int balanceFactor = balFac(root);
		 if (balanceFactor > 1) {
			 if (balFac(root->left) >= 0) {
				 return rightRotate(root);
			 }
			 else {
				 root->left = leftRotate(root->left);
				 return rightRotate(root);
			 }
		 }
		 if (balanceFactor < -1) {
			 if (balFac(root->right) <= 0) {
				 return leftRotate(root);
			 }
			 else {
				 root->right = rightRotate(root->right);
				 return leftRotate(root);
			 }
		 }
		 return root;
	 }
	 //===================Delete by Age=========================//
	 node* delete_death(node* root, int key) {
		 // Find the node and delete it
		 if (root == NULL)
			 return root;
		 if (key < root->deaths)
			 root->left = delete_death(root->left, key);
		 else if (key > root->deaths)
			 root->right = delete_death(root->right, key);
		 else {
			 if ((root->left == NULL) ||
				 (root->right == NULL)) {
				 node* temp;
				 if (root->left) {
					 temp = root->left;
				 }
				 else {
					 temp = root->right;
				 }
				 if (temp == NULL) {
					 temp = root;
					 root = NULL;
				 }
				 else
					 *root = *temp;
				 free(temp);
			 }
			 else {
				 node* temp = MinValue(root->right);
				 root->deaths = temp->deaths;
				 root->right = delete_death(root->right,
					 temp->deaths);
			 }
		 }

		 if (root == NULL)
			 return root;

		 // Update the balance factor of each node and
		 // balance the tree
		 root->treeHeight = 1 + max(height(root->left),
			 height(root->right));
		 int balanceFactor = balFac(root);
		 if (balanceFactor > 1) {
			 if (balFac(root->left) >= 0) {
				 return rightRotate(root);
			 }
			 else {
				 root->left = leftRotate(root->left);
				 return rightRotate(root);
			 }
		 }
		 if (balanceFactor < -1) {
			 if (balFac(root->right) <= 0) {
				 return leftRotate(root);
			 }
			 else {
				 root->right = rightRotate(root->right);
				 return leftRotate(root);
			 }
		 }
		 return root;
	 }
	 //================Delete  by state========================//
	 node* delete_state(node* root, string key) {
		 // Find the node and delete it
		 if (root == NULL)
			 return root;
		 if (retAscii(key) < retAscii(root->state))
			 root->left = delete_state(root->left, key);
		 else if (retAscii(key) > retAscii(root->state))
			 root->right = delete_state(root->right, key);
		 else {
			 if ((root->left == NULL) ||
				 (root->right == NULL)) {
				 node* temp;
				 if (root->left) {
					 temp = root->left;
				 }
				 else {
					 temp = root->right;
				 }
				 if (temp == NULL) {
					 temp = root;
					 root = NULL;
				 }
				 else
					 *root = *temp;
				 free(temp);
			 }
			 else {
				 node* temp = MinValue(root->right);
				 root->state = temp->state;
				 root->right = delete_state(root->right,
					 temp->state);
			 }
		 }

		 if (root == NULL)
			 return root;

		 // Update the balance factor of each node and
		 // balance the tree
		 root->treeHeight = 1 + max(height(root->left),
			 height(root->right));
		 int balanceFactor = balFac(root);
		 if (balanceFactor > 1) {
			 if (balFac(root->left) >= 0) {
				 return rightRotate(root);
			 }
			 else {
				 root->left = leftRotate(root->left);
				 return rightRotate(root);
			 }
		 }
		 if (balanceFactor < -1) {
			 if (balFac(root->right) <= 0) {
				 return leftRotate(root);
			 }
			 else {
				 root->right = rightRotate(root->right);
				 return leftRotate(root);
			 }
		 }
		 return root;
	 }
//==============Deletion by Cause Name==================//
	 node* delete_cause_name(node* root, string key) {
		 // Find the node and delete it
		 if (root == NULL)
			 return root;
		 if (retAscii(key) < retAscii(root->cause_name))
			 root->left = delete_cause_name(root->left, key);
		 else if (retAscii(key) > retAscii(root->cause_name))
			 root->right = delete_cause_name(root->right, key);
		 else {
			 if ((root->left == NULL) ||
				 (root->right == NULL)) {
				 node* temp;
				 if (root->left) {
					 temp = root->left;
				 }
				 else {
					 temp = root->right;
				 }
				 if (temp == NULL) {
					 temp = root;
					 root = NULL;
				 }
				 else
					 *root = *temp;
				 free(temp);
			 }
			 else {
				 node* temp = MinValue(root->right);
				 root->cause_name = temp->cause_name;
				 root->right = delete_cause_name(root->right,
					 temp->cause_name);
			 }
		 }

		 if (root == NULL)
			 return root;

		 // Update the balance factor of each node and
		 // balance the tree
		 root->treeHeight = 1 + max(height(root->left),
			 height(root->right));
		 int balanceFactor = balFac(root);
		 if (balanceFactor > 1) {
			 if (balFac(root->left) >= 0) {
				 return rightRotate(root);
			 }
			 else {
				 root->left = leftRotate(root->left);
				 return rightRotate(root);
			 }
		 }
		 if (balanceFactor < -1) {
			 if (balFac(root->right) <= 0) {
				 return leftRotate(root);
			 }
			 else {
				 root->right = rightRotate(root->right);
				 return leftRotate(root);
			 }
		 }
		 return root;
	 }
//===========Delete by Cause 113========================//
	 node* delete_cause_113(node* root, string key) {
		 // Find the node and delete it
		 if (root == NULL)
			 return root;
		 if (retAscii(key) < retAscii(root->cause_113))
			 root->left = delete_cause_113(root->left, key);
		 else if (retAscii(key) > retAscii(root->cause_113))
			 root->right = delete_cause_113(root->right, key);
		 else {
			 if ((root->left == NULL) ||
				 (root->right == NULL)) {
				 node* temp;
				 if (root->left) {
					 temp = root->left;
				 }
				 else {
					 temp = root->right;
				 }
				 if (temp == NULL) {
					 temp = root;
					 root = NULL;
				 }
				 else
					 *root = *temp;
				 free(temp);
			 }
			 else {
				 node* temp = MinValue(root->right);
				 root->cause_113 = temp->cause_113;
				 root->right = delete_cause_113(root->right,
					 temp->cause_113);
			 }
		 }

		 if (root == NULL)
			 return root;

		 // Update the balance factor of each node and
		 // balance the tree
		 root->treeHeight = 1 + max(height(root->left),
			 height(root->right));
		 int balanceFactor = balFac(root);
		 if (balanceFactor > 1) {
			 if (balFac(root->left) >= 0) {
				 return rightRotate(root);
			 }
			 else {
				 root->left = leftRotate(root->left);
				 return rightRotate(root);
			 }
		 }
		 if (balanceFactor < -1) {
			 if (balFac(root->right) <= 0) {
				 return leftRotate(root);
			 }
			 else {
				 root->right = rightRotate(root->right);
				 return leftRotate(root);
			 }
		 }
		 return root;
	 }



	//====================Change Function======================================================//
	node* change(node* root) {
		string ki = " ";
		cout << "Updating Procedure.." << endl;
		cout << "|  A very Important  notice for you							|" << endl;
		cout << "|  If you dont want to Update Something just put 'Not' into it |" << endl;
		cout << endl;
		system("cls");

		cout << "Enter ID (Enter ''Not'' if you dont want to update)" << endl;
		cin >> ki;
		if (ki != "Not" && ki != "NOT" && ki != "NOt" && ki != "not" && ki != "nOT" && ki != "noT") {
			root->id = stoi(ki);
		}
		system("cls");


		////////////////////////////////////////////////////////////////
		cout << "Enter Year (Enter ''Not'' if you dont want to update)" << endl;
		cin >> ki;
		if (ki != "Not" && ki != "NOT" && ki != "NOt" && ki != "not" && ki != "nOT" && ki != "noT") {
			root->year = stoi(ki);
		}
		system("cls");
		///////////////////////////////////////////////////////////////
		cout << "Enter Deaths (Enter ''Not'' if you dont want to update)" << endl;
		cin >> ki;
		if (ki != "Not" && ki != "NOT" && ki != "NOt" && ki != "not" && ki != "nOT" && ki != "noT") {
			root->deaths = stoi(ki);
		}
		system("cls");
		/////////////////////////////////////////////////////////////

		cout << "Enter Age_factor (Enter ''Not'' if you dont want to update)" << endl;
		cin >> ki;
		if (ki != "Not" && ki != "NOT" && ki != "NOt" && ki != "not" && ki != "nOT" && ki != "noT") {
			root->age_adjust = stof(ki);
		}
		system("cls");
		/////////////////////////////////////////////////////////////

		cout << "Enter State (Enter ''Not'' if you dont want to update)" << endl;
		cin >> ki;
		if (ki != "Not" && ki != "NOT" && ki != "NOt" && ki != "not" && ki != "nOT" && ki != "noT") {
			root->state.assign(ki);
		}
		system("cls");
		////////////////////////////////////////////////////////////////

		cout << "Enter Cause Name (Enter ''Not'' if you dont want to update)" << endl;
		cin >> ki;
		if (ki != "Not" && ki != "NOT" && ki != "NOt" && ki != "not" && ki != "nOT" && ki != "noT") {
			root->cause_name.assign(ki);
		}
		system("cls");
		//////////////////////////////////////////////////////////////////////////////////////////////////////////



		cout << "Enter Cause 113 (Enter ''Not'' if you dont want to update)" << endl;
		cin >> ki;
		if (ki != "Not" && ki != "NOT" && ki != "NOt" && ki != "not" && ki != "nOT" && ki != "noT") {
			root->cause_113.assign(ki);
		}
		system("cls");

		///===========================================================================//
		cout << "Loading .";
		for (int i = 0; i < 3; i++) {
			Sleep(500);
			cout << " .";
		}
		system("cls");
		cout << " Updated Succesfully" << endl;
		//PlaySound(TEXT("victory.wav"), NULL, SND_SYNC);

		if (root->same != NULL) {
			node* temp = root->same;
			while (temp != NULL) {
				temp->id = root->id;
				temp->deaths = root->deaths;
				temp->age_adjust = root->age_adjust;
				temp->cause_113 = root->cause_113;
				temp->cause_name = root->cause_name;
				temp->state = root->state;
				temp->year = root->year;
				temp = temp->same;
			}
		}



		return root;

	}

	//====================Update Function=========================================//
	void update(node* root) {
		int e = 0;
		float f;
		string g;
		cout << "Enter your Entity;" << endl;
		if (update_id) {

			cin >> e;
			know = e;
			search_id(root, know);
		}
		if (update_year) {
			cin >> e;
			know = e;
			search_year(root, know);
		}if (update_death) {
			cin >> e;
			know = e;
			search_death(root, know);
		}if (update_age) {
			cin >> f;
			ratio = f;
			search_age(root, f);
		}if (update_state) {
			cin >> g;
			giga = g;

			search_state(root, g);
		}if (update_cause_name) {
			cin >> g;
			giga = g;
			search_cause_name(root, g);

		}if (update_cause_113) {
			cin >> g;
			giga = g;
			search_cause_113(root, g);
		}



	}



};
