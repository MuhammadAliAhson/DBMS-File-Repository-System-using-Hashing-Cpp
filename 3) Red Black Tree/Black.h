#pragma once

#include <iostream>
using namespace std;

int prince = 0;
int nodeCount = 0;
int know = 0;
float ratio;
string giga;
int table = 0;

bool update_id, update_year, update_death, update_age, update_state, update_cause_name, update_cause_113;


struct Node {
public:
    int id;
    int  year = 0;
    int deaths = 0;
    float age_adjust = 0.0;
    string cause_113 = " ";
    string cause_name = " ";
    string state = " ";
    Node* parent;
    int color;
    Node* same;
    Node* left;
    Node* right;




    Node() {
        for (int i = 0; i < 30; i++) {

            for (int j = i; j < 20; j++) {

                if (i < 100) {

                    i = i + 1;
                    i = i - 1;
                    j = j + 1;
                    j = j - 1;

                }
                else {

                    i = i - 2;
                    i = i + 2;
                    j = j - 2;
                    j = j + 2;

                }


            }
        }
        this->id = 0;
        this->year = 0;
        this->deaths = 0;
        this->age_adjust = 0.0;
        this->cause_113 = " ";
        this->cause_name = " ";
        this->state = " ";
        this->same = NULL;
        this->left = NULL;
        this->right = NULL;

        for (int i = 0; i < 30; i++) {

            for (int j = i; j < 20; j++) {

                if (i < 100) {

                    i = i + 1;
                    i = i - 1;
                    j = j + 1;
                    j = j - 1;

                }
                else {

                    i = i - 2;
                    i = i + 2;
                    j = j - 2;
                    j = j + 2;

                }


            }
        }

    }
    Node(Node* a) {
        for (int i = 0; i < 30; i++) {

            for (int j = i; j < 20; j++) {

                if (i < 100) {

                    i = i + 1;
                    i = i - 1;
                    j = j + 1;
                    j = j - 1;

                }
                else {

                    i = i - 2;
                    i = i + 2;
                    j = j - 2;
                    j = j + 2;

                }


            }
        }

        this->id = a->id;
        this->year = a->year;
        this->deaths = a->deaths;
        this->age_adjust = a->age_adjust;
        this->cause_113 = a->cause_113;
        this->cause_name = a->cause_name;
        this->state = a->state;
        this->color = 1;
        this->parent = NULL;
        this->same = NULL;

        for (int i = 0; i < 30; i++) {

            for (int j = i; j < 20; j++) {

                if (i < 100) {

                    i = i + 1;
                    i = i - 1;
                    j = j + 1;
                    j = j - 1;

                }
                else {

                    i = i - 2;
                    i = i + 2;
                    j = j - 2;
                    j = j + 2;

                }


            }
        }

    }





};

int retAscii(string x) {

    for (int i = 0; i < 30; i++) {

        for (int j = i; j < 20; j++) {

            if (i < 100) {

                i = i + 1;
                i = i - 1;
                j = j + 1;
                j = j - 1;

            }
            else {

                i = i - 2;
                i = i + 2;
                j = j - 2;
                j = j + 2;

            }


        }
    }
    int count = 0;
    for (int i = 0; i < x.size(); i++) {
        count = count + (int)x[i];
    }
    return count;

}



class RedBlackTree {

public:
    Node* root;
    Node* TNULL;


    // For balancing the tree after insertion
    void insertFix(Node* k) {
        Node* u;
        while (k->parent->color == 1) {
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
            if (k->parent == k->parent->parent->right) {
                for (int i = 0; i < 30; i++) {

                    for (int j = i; j < 20; j++) {

                        if (i < 100) {

                            i = i + 1;
                            i = i - 1;
                            j = j + 1;
                            j = j - 1;

                        }
                        else {

                            i = i - 2;
                            i = i + 2;
                            j = j - 2;
                            j = j + 2;

                        }


                    }
                }
                u = k->parent->parent->left;
                for (int i = 0; i < 30; i++) {

                    for (int j = i; j < 20; j++) {

                        if (i < 100) {

                            i = i + 1;
                            i = i - 1;
                            j = j + 1;
                            j = j - 1;

                        }
                        else {

                            i = i - 2;
                            i = i + 2;
                            j = j - 2;
                            j = j + 2;

                        }


                    }
                }
                if (u->color == 1) {
                    for (int i = 0; i < 30; i++) {

                        for (int j = i; j < 20; j++) {

                            if (i < 100) {

                                i = i + 1;
                                i = i - 1;
                                j = j + 1;
                                j = j - 1;

                            }
                            else {

                                i = i - 2;
                                i = i + 2;
                                j = j - 2;
                                j = j + 2;

                            }


                        }
                    }
                    u->color = 0;
                    for (int i = 0; i < 30; i++) {

                        for (int j = i; j < 20; j++) {

                            if (i < 100) {

                                i = i + 1;
                                i = i - 1;
                                j = j + 1;
                                j = j - 1;

                            }
                            else {

                                i = i - 2;
                                i = i + 2;
                                j = j - 2;
                                j = j + 2;

                            }


                        }
                    }
                    k->parent->color = 0;
                    for (int i = 0; i < 30; i++) {

                        for (int j = i; j < 20; j++) {

                            if (i < 100) {

                                i = i + 1;
                                i = i - 1;
                                j = j + 1;
                                j = j - 1;

                            }
                            else {

                                i = i - 2;
                                i = i + 2;
                                j = j - 2;
                                j = j + 2;

                            }


                        }
                    }
                    k->parent->parent->color = 1;
                    for (int i = 0; i < 30; i++) {

                        for (int j = i; j < 20; j++) {

                            if (i < 100) {

                                i = i + 1;
                                i = i - 1;
                                j = j + 1;
                                j = j - 1;

                            }
                            else {

                                i = i - 2;
                                i = i + 2;
                                j = j - 2;
                                j = j + 2;

                            }


                        }
                    }
                    k = k->parent->parent;
                    for (int i = 0; i < 30; i++) {

                        for (int j = i; j < 20; j++) {

                            if (i < 100) {

                                i = i + 1;
                                i = i - 1;
                                j = j + 1;
                                j = j - 1;

                            }
                            else {

                                i = i - 2;
                                i = i + 2;
                                j = j - 2;
                                j = j + 2;

                            }


                        }
                    }
                }
                else {
                    for (int i = 0; i < 30; i++) {

                        for (int j = i; j < 20; j++) {

                            if (i < 100) {

                                i = i + 1;
                                i = i - 1;
                                j = j + 1;
                                j = j - 1;

                            }
                            else {

                                i = i - 2;
                                i = i + 2;
                                j = j - 2;
                                j = j + 2;

                            }


                        }
                    }
                    if (k == k->parent->left) {
                        for (int i = 0; i < 30; i++) {

                            for (int j = i; j < 20; j++) {

                                if (i < 100) {

                                    i = i + 1;
                                    i = i - 1;
                                    j = j + 1;
                                    j = j - 1;

                                }
                                else {

                                    i = i - 2;
                                    i = i + 2;
                                    j = j - 2;
                                    j = j + 2;

                                }


                            }
                        }
                        k = k->parent;
                        for (int i = 0; i < 30; i++) {

                            for (int j = i; j < 20; j++) {

                                if (i < 100) {

                                    i = i + 1;
                                    i = i - 1;
                                    j = j + 1;
                                    j = j - 1;

                                }
                                else {

                                    i = i - 2;
                                    i = i + 2;
                                    j = j - 2;
                                    j = j + 2;

                                }


                            }
                        }
                        rightRotate(k);
                    }
                    k->parent->color = 0;
                    for (int i = 0; i < 30; i++) {

                        for (int j = i; j < 20; j++) {

                            if (i < 100) {

                                i = i + 1;
                                i = i - 1;
                                j = j + 1;
                                j = j - 1;

                            }
                            else {

                                i = i - 2;
                                i = i + 2;
                                j = j - 2;
                                j = j + 2;

                            }


                        }
                    }
                    k->parent->parent->color = 1;
                    for (int i = 0; i < 30; i++) {

                        for (int j = i; j < 20; j++) {

                            if (i < 100) {

                                i = i + 1;
                                i = i - 1;
                                j = j + 1;
                                j = j - 1;

                            }
                            else {

                                i = i - 2;
                                i = i + 2;
                                j = j - 2;
                                j = j + 2;

                            }


                        }
                    }
                    leftRotate(k->parent->parent);
                    for (int i = 0; i < 30; i++) {

                        for (int j = i; j < 20; j++) {

                            if (i < 100) {

                                i = i + 1;
                                i = i - 1;
                                j = j + 1;
                                j = j - 1;

                            }
                            else {

                                i = i - 2;
                                i = i + 2;
                                j = j - 2;
                                j = j + 2;

                            }


                        }
                    }
                }
            }
            else {
                for (int i = 0; i < 30; i++) {

                    for (int j = i; j < 20; j++) {

                        if (i < 100) {

                            i = i + 1;
                            i = i - 1;
                            j = j + 1;
                            j = j - 1;

                        }
                        else {

                            i = i - 2;
                            i = i + 2;
                            j = j - 2;
                            j = j + 2;

                        }


                    }
                }
                u = k->parent->parent->right;

                if (u->color == 1) {
                    for (int i = 0; i < 30; i++) {

                        for (int j = i; j < 20; j++) {

                            if (i < 100) {

                                i = i + 1;
                                i = i - 1;
                                j = j + 1;
                                j = j - 1;

                            }
                            else {

                                i = i - 2;
                                i = i + 2;
                                j = j - 2;
                                j = j + 2;

                            }


                        }
                    }
                    u->color = 0;
                    for (int i = 0; i < 30; i++) {

                        for (int j = i; j < 20; j++) {

                            if (i < 100) {

                                i = i + 1;
                                i = i - 1;
                                j = j + 1;
                                j = j - 1;

                            }
                            else {

                                i = i - 2;
                                i = i + 2;
                                j = j - 2;
                                j = j + 2;

                            }


                        }
                    }
                    k->parent->color = 0;
                    for (int i = 0; i < 30; i++) {

                        for (int j = i; j < 20; j++) {

                            if (i < 100) {

                                i = i + 1;
                                i = i - 1;
                                j = j + 1;
                                j = j - 1;

                            }
                            else {

                                i = i - 2;
                                i = i + 2;
                                j = j - 2;
                                j = j + 2;

                            }


                        }
                    }
                    k->parent->parent->color = 1;
                    for (int i = 0; i < 30; i++) {

                        for (int j = i; j < 20; j++) {

                            if (i < 100) {

                                i = i + 1;
                                i = i - 1;
                                j = j + 1;
                                j = j - 1;

                            }
                            else {

                                i = i - 2;
                                i = i + 2;
                                j = j - 2;
                                j = j + 2;

                            }


                        }
                    }
                    k = k->parent->parent;
                }
                else {
                    if (k == k->parent->right) {
                        for (int i = 0; i < 30; i++) {

                            for (int j = i; j < 20; j++) {

                                if (i < 100) {

                                    i = i + 1;
                                    i = i - 1;
                                    j = j + 1;
                                    j = j - 1;

                                }
                                else {

                                    i = i - 2;
                                    i = i + 2;
                                    j = j - 2;
                                    j = j + 2;

                                }


                            }
                        }
                        k = k->parent;
                        leftRotate(k);
                    }
                    k->parent->color = 0;
                    for (int i = 0; i < 30; i++) {

                        for (int j = i; j < 20; j++) {

                            if (i < 100) {

                                i = i + 1;
                                i = i - 1;
                                j = j + 1;
                                j = j - 1;

                            }
                            else {

                                i = i - 2;
                                i = i + 2;
                                j = j - 2;
                                j = j + 2;

                            }


                        }
                    }
                    k->parent->parent->color = 1;
                    for (int i = 0; i < 30; i++) {

                        for (int j = i; j < 20; j++) {

                            if (i < 100) {

                                i = i + 1;
                                i = i - 1;
                                j = j + 1;
                                j = j - 1;

                            }
                            else {

                                i = i - 2;
                                i = i + 2;
                                j = j - 2;
                                j = j + 2;

                            }


                        }
                    }
                    rightRotate(k->parent->parent);
                    for (int i = 0; i < 30; i++) {

                        for (int j = i; j < 20; j++) {

                            if (i < 100) {

                                i = i + 1;
                                i = i - 1;
                                j = j + 1;
                                j = j - 1;

                            }
                            else {

                                i = i - 2;
                                i = i + 2;
                                j = j - 2;
                                j = j + 2;

                            }


                        }
                    }
                }
            }
            if (k == root) {
                for (int i = 0; i < 30; i++) {

                    for (int j = i; j < 20; j++) {

                        if (i < 100) {

                            i = i + 1;
                            i = i - 1;
                            j = j + 1;
                            j = j - 1;

                        }
                        else {

                            i = i - 2;
                            i = i + 2;
                            j = j - 2;
                            j = j + 2;

                        }


                    }
                }
                break;
            }
        }
        root->color = 0;
    }


    RedBlackTree() {
        TNULL = new Node;
        for (int i = 0; i < 30; i++) {

            for (int j = i; j < 20; j++) {

                if (i < 100) {

                    i = i + 1;
                    i = i - 1;
                    j = j + 1;
                    j = j - 1;

                }
                else {

                    i = i - 2;
                    i = i + 2;
                    j = j - 2;
                    j = j + 2;

                }


            }
        }
        TNULL->color = 0;
        for (int i = 0; i < 30; i++) {

            for (int j = i; j < 20; j++) {

                if (i < 100) {

                    i = i + 1;
                    i = i - 1;
                    j = j + 1;
                    j = j - 1;

                }
                else {

                    i = i - 2;
                    i = i + 2;
                    j = j - 2;
                    j = j + 2;

                }


            }
        }
        TNULL->left = NULL;
        for (int i = 0; i < 30; i++) {

            for (int j = i; j < 20; j++) {

                if (i < 100) {

                    i = i + 1;
                    i = i - 1;
                    j = j + 1;
                    j = j - 1;

                }
                else {

                    i = i - 2;
                    i = i + 2;
                    j = j - 2;
                    j = j + 2;

                }


            }
        }
        TNULL->right = NULL;
        for (int i = 0; i < 30; i++) {

            for (int j = i; j < 20; j++) {

                if (i < 100) {

                    i = i + 1;
                    i = i - 1;
                    j = j + 1;
                    j = j - 1;

                }
                else {

                    i = i - 2;
                    i = i + 2;
                    j = j - 2;
                    j = j + 2;

                }


            }
        }
        root = TNULL;
    }

    //=================Left Rotations=====================================//

    void leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != TNULL) {
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
            y->left->parent = x;
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
        }
        y->parent = x->parent;
        if (x->parent == NULL) {
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
            this->root = y;
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
        }
        else if (x == x->parent->left) {
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
            x->parent->left = y;
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
        }
        else {
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
            x->parent->right = y;
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
        }
        y->left = x;
        x->parent = y;
    }
    //============Right Rotations================================//
    void rightRotate(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        if (y->right != TNULL) {
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == NULL) {
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
            this->root = y;
        }
        else if (x == x->parent->right) {
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
            x->parent->right = y;
        }
        else {
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }
    //========================================================================================//
    //==================================================================//
    string makefile(Node* data) {

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
                << ' ' << data->deaths << ' ' << data->age_adjust
                << ' ' << data->left << ' ' << data->right << ' ' << data->same;
            o.close();
        }
        nodeCount++;

        return newfile;
    }
    //=============Return obj=====================//

    Node* returnobj(string path) {

        if (path == "\0") {

            Node* ret = NULL;
            return ret;
        }
        else {
            //cout << path << endl;
            fstream file(path, ios::in);
            if (!file) {
                cout << "File not open" << endl;
            }
            else {

                Node* ret = new Node;
                file >> ret->id >> ret->year >> ret->cause_113 >> ret->cause_name
                    >> ret->state >> ret->deaths >> ret->age_adjust;

                file.close();
                return ret;
            }
        }
    }



    //==============Insertion by id===================================================//

    void insert(Node* key) {
        Node* temp = new Node(key);
        temp->left = TNULL;
        temp->right = TNULL;

        Node* y = NULL;
        Node* x = this->root;

        for (int i = 0; i < 30; i++) {

            for (int j = i; j < 20; j++) {

                if (i < 100) {

                    i = i + 1;
                    i = i - 1;
                    j = j + 1;
                    j = j - 1;

                }
                else {

                    i = i - 2;
                    i = i + 2;
                    j = j - 2;
                    j = j + 2;

                }


            }
        }

        while (x != TNULL) {
            y = x;
            if (temp->id < x->id) {

                for (int i = 0; i < 30; i++) {

                    for (int j = i; j < 20; j++) {

                        if (i < 100) {

                            i = i + 1;
                            i = i - 1;
                            j = j + 1;
                            j = j - 1;

                        }
                        else {

                            i = i - 2;
                            i = i + 2;
                            j = j - 2;
                            j = j + 2;

                        }


                    }
                }
                x = x->left;
            }
            else {
                x = x->right;
                for (int i = 0; i < 30; i++) {

                    for (int j = i; j < 20; j++) {

                        if (i < 100) {

                            i = i + 1;
                            i = i - 1;
                            j = j + 1;
                            j = j - 1;

                        }
                        else {

                            i = i - 2;
                            i = i + 2;
                            j = j - 2;
                            j = j + 2;

                        }


                    }
                }
            }
        }

        temp->parent = y;
        if (y == NULL) {
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
            root = temp;
        }
        else if (temp->id < y->id) {
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
            y->left = temp;
        }
        else {
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
            y->right = temp;
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
        }

        if (temp->parent == NULL) {
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
            temp->color = 0;
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
            return;
        }

        if (temp->parent->parent == NULL) {
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
            return;
        }
        for (int i = 0; i < 30; i++) {

            for (int j = i; j < 20; j++) {

                if (i < 100) {

                    i = i + 1;
                    i = i - 1;
                    j = j + 1;
                    j = j - 1;

                }
                else {

                    i = i - 2;
                    i = i + 2;
                    j = j - 2;
                    j = j + 2;

                }


            }
        }

        insertFix(temp);
    }
    //========================Insertion by Year================================//

    void insert_year(Node* key) {
        Node* temp = new Node(key);
        temp->left = TNULL;
        temp->right = TNULL;

        Node* y = NULL;
        for (int i = 0; i < 30; i++) {

            for (int j = i; j < 20; j++) {

                if (i < 100) {

                    i = i + 1;
                    i = i - 1;
                    j = j + 1;
                    j = j - 1;

                }
                else {

                    i = i - 2;
                    i = i + 2;
                    j = j - 2;
                    j = j + 2;

                }


            }
        }
        Node* x = this->root;
        for (int i = 0; i < 30; i++) {

            for (int j = i; j < 20; j++) {

                if (i < 100) {

                    i = i + 1;
                    i = i - 1;
                    j = j + 1;
                    j = j - 1;

                }
                else {

                    i = i - 2;
                    i = i + 2;
                    j = j - 2;
                    j = j + 2;

                }


            }
        }

        while (x != TNULL) {
            y = x;
            if (temp->year < x->year) {
                for (int i = 0; i < 30; i++) {

                    for (int j = i; j < 20; j++) {

                        if (i < 100) {

                            i = i + 1;
                            i = i - 1;
                            j = j + 1;
                            j = j - 1;

                        }
                        else {

                            i = i - 2;
                            i = i + 2;
                            j = j - 2;
                            j = j + 2;

                        }


                    }
                }
                x = x->left;
                for (int i = 0; i < 30; i++) {

                    for (int j = i; j < 20; j++) {

                        if (i < 100) {

                            i = i + 1;
                            i = i - 1;
                            j = j + 1;
                            j = j - 1;

                        }
                        else {

                            i = i - 2;
                            i = i + 2;
                            j = j - 2;
                            j = j + 2;

                        }


                    }
                }
            }
            else if (temp->year == x->year) {
                break;
            }
            else {
                x = x->right;
                for (int i = 0; i < 30; i++) {

                    for (int j = i; j < 20; j++) {

                        if (i < 100) {

                            i = i + 1;
                            i = i - 1;
                            j = j + 1;
                            j = j - 1;

                        }
                        else {

                            i = i - 2;
                            i = i + 2;
                            j = j - 2;
                            j = j + 2;

                        }


                    }
                }
            }
        }

        temp->parent = y;
        if (y == NULL) {
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
            root = temp;
        }
        else if (temp->year == y->year) {
            Node* op = y;
            while (op->same != NULL) {
                for (int i = 0; i < 30; i++) {

                    for (int j = i; j < 20; j++) {

                        if (i < 100) {

                            i = i + 1;
                            i = i - 1;
                            j = j + 1;
                            j = j - 1;

                        }
                        else {

                            i = i - 2;
                            i = i + 2;
                            j = j - 2;
                            j = j + 2;

                        }


                    }
                }
                // cout << op->year << endl;
                op = op->same;
                for (int i = 0; i < 30; i++) {

                    for (int j = i; j < 20; j++) {

                        if (i < 100) {

                            i = i + 1;
                            i = i - 1;
                            j = j + 1;
                            j = j - 1;

                        }
                        else {

                            i = i - 2;
                            i = i + 2;
                            j = j - 2;
                            j = j + 2;

                        }


                    }
                }
            }
            op->same = temp;
        }
        else if (temp->year < y->year) {
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
            y->left = temp;
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
        }
        else {
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
            y->right = temp;
        }

        if (temp->parent == NULL) {
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
            temp->color = 0;
            return;
        }

        if (temp->parent->parent == NULL) {
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
            return;
        }

        insertFix(temp);
    }
    //=======================Insertion by Deaths============================================//
    void insert_death(Node* key) {
        Node* temp = new Node(key);
        temp->left = TNULL;
        temp->right = TNULL;
        Node* y = NULL;
        Node* x = this->root;

        while (x != TNULL) {
            y = x;
            if (temp->deaths < x->deaths) {
                x = x->left;
            }
            else if (temp->deaths == x->deaths) {
                break;
            }
            else {
                x = x->right;
            }
        }

        temp->parent = y;
        if (y == NULL) {
            root = temp;
        }
        else if (temp->deaths == y->deaths) {
            Node* op = y;
            while (op->same != NULL) {

                op = op->same;
            }
            op->same = temp;
        }
        else if (temp->deaths < y->deaths) {
            y->left = temp;
        }
        else {
            y->right = temp;
        }

        if (temp->parent == NULL) {
            temp->color = 0;
            return;
        }

        if (temp->parent->parent == NULL) {
            return;
        }

        insertFix(temp);
    }
    //===============Insertion by Age=======================================================//
    void insert_age(Node* key) {
        Node* temp = new Node(key);
        temp->left = TNULL;
        temp->right = TNULL;
        Node* y = NULL;
        Node* x = this->root;

        while (x != TNULL) {
            y = x;
            if (temp->age_adjust < x->age_adjust) {
                x = x->left;
            }
            else if (temp->age_adjust == x->age_adjust) {
                break;
            }
            else {
                x = x->right;
            }
        }

        temp->parent = y;
        if (y == NULL) {
            root = temp;
        }
        else if (temp->age_adjust == y->age_adjust) {
            Node* op = y;
            while (op->same != NULL) {

                op = op->same;
            }
            op->same = temp;
        }
        else if (temp->age_adjust < y->age_adjust) {
            y->left = temp;
        }
        else {
            y->right = temp;
        }

        if (temp->parent == NULL) {
            temp->color = 0;
            return;
        }

        if (temp->parent->parent == NULL) {
            return;
        }

        insertFix(temp);
    }
    //=================================Insertion by State=========================================//
    void insert_state(Node* key) {
        Node* temp = new Node(key);
        temp->left = TNULL;
        temp->right = TNULL;
        Node* y = NULL;
        Node* x = this->root;
        while (x != TNULL) {
            y = x;
            if (retAscii(temp->state) < retAscii(x->state)) {
                x = x->left;
            }
            else if (retAscii(temp->state) == retAscii(x->state)) {
                break;
            }
            else {
                x = x->right;
            }
        }
        temp->parent = y;
        if (y == NULL) {
            root = temp;
        }
        else if (retAscii(temp->state) == retAscii(y->state)) {
            Node* op = y;
            while (op->same != NULL) {
                op = op->same;
            }
            op->same = temp;
        }
        else if (retAscii(temp->state) < retAscii(y->state)) {
            y->left = temp;
        }
        else {
            y->right = temp;
        }

        if (temp->parent == NULL) {
            temp->color = 0;
            return;
        }
        if (temp->parent->parent == NULL) {
            return;
        }
        insertFix(temp);
    }
    //=====================Insertion by Cause Name=================================//

    void insert_cause_name(Node* key) {
        Node* temp = new Node(key);
        temp->left = TNULL;
        temp->right = TNULL;
        Node* y = NULL;
        Node* x = this->root;
        while (x != TNULL) {
            y = x;
            if (retAscii(temp->cause_name) < retAscii(x->cause_name)) {
                x = x->left;
            }
            else if (retAscii(temp->cause_name) == retAscii(x->cause_name)) {
                break;
            }
            else {
                x = x->right;
            }
        }
        temp->parent = y;
        if (y == NULL) {
            root = temp;
        }
        else if (retAscii(temp->cause_name) == retAscii(y->cause_name)) {
            Node* op = y;
            while (op->same != NULL) {
                op = op->same;
            }
            op->same = temp;
        }
        else if (retAscii(temp->cause_name) < retAscii(y->cause_name)) {
            y->left = temp;
        }
        else {
            y->right = temp;
        }

        if (temp->parent == NULL) {
            temp->color = 0;
            return;
        }
        if (temp->parent->parent == NULL) {
            return;
        }
        insertFix(temp);
    }
    //============================Insertion by Cause 113====================================//

    void insert_cause_113(Node* key) {
        Node* temp = new Node(key);
        temp->left = TNULL;
        temp->right = TNULL;
        Node* y = NULL;
        Node* x = this->root;
        while (x != TNULL) {
            y = x;
            if (retAscii(temp->cause_113) < retAscii(x->cause_113)) {
                x = x->left;
            }
            else if (retAscii(temp->cause_113) == retAscii(x->cause_113)) {
                break;
            }
            else {
                x = x->right;
            }
        }
        temp->parent = y;
        if (y == NULL) {
            root = temp;
        }
        else if (retAscii(temp->cause_113) == retAscii(y->cause_113)) {
            Node* op = y;
            while (op->same != NULL) {
                op = op->same;
            }
            op->same = temp;
        }
        else if (retAscii(temp->cause_113) < retAscii(y->cause_113)) {
            y->left = temp;
        }
        else {
            y->right = temp;
        }

        if (temp->parent == NULL) {
            temp->color = 0;
            return;
        }
        if (temp->parent->parent == NULL) {
            return;
        }
        insertFix(temp);
    }
    //===============Searching by id=======================================================//
    void search_id(int key) {
        Node* temp = root;
        if (root == NULL) {
            return;
        }
        while (temp != NULL) {

            if (temp->id == key) {
                if (update_id) {
                    change(temp);
                    system("cls");
                    Sleep(200);
                    display(temp);
                    update_id = false;
                    return;
                }
                else
                    display(temp);
                return;
            }
            else if (temp->id < key) {
                temp = temp->right;
            }
            else if (temp->id > key) {
                temp = temp->left;
            }
        }
    }
    //===============Searching by year=======================================================//
    void search_year(int key) {
        Node* temp = root;
        if (root == NULL) {
            return;
        }
        while (temp != NULL) {

            if (temp->year == key) {
                if (update_year) {
                    change(temp);
                    system("cls");
                    Sleep(200);
                    display(temp);
                    update_year = false;
                }
                else
                    display(temp);
                return;
            }
            else if (temp->year < key) {
                temp = temp->right;
            }
            else if (temp->year > key) {
                temp = temp->left;
            }
        }
    }
    //===============Searching by Deaths=======================================================//
    void search_deaths(int key) {
        Node* temp = root;
        if (root == NULL) {
            return;
        }
        while (temp != NULL) {

            if (temp->deaths == key) {
                if (update_death) {
                    change(temp);
                    system("cls");
                    Sleep(200);
                    display(temp);
                    update_death = false;
                }
                else
                    display(temp);
                return;
            }
            else if (temp->deaths < key) {
                temp = temp->right;
            }
            else if (temp->deaths > key) {
                temp = temp->left;
            }
        }
    }
    //===============Searching by age=======================================================//
    void search_age(float key) {
        Node* temp = root;
        if (root == NULL) {
            return;
        }
        while (temp != NULL) {

            if (temp->age_adjust == key) {
                if (update_age) {
                    change(temp);
                    system("cls");
                    Sleep(200);
                    display(temp);
                    update_age = false;
                }
                else {
                    display(temp);
                    return;
                }
            }
            else if (temp->deaths < key) {
                temp = temp->right;
            }
            else if (temp->deaths > key) {
                temp = temp->left;
            }
        }
    }
    //===============Searching by State=======================================================//
    void search_state(string key) {
        Node* temp = root;
        if (root == NULL) {
            return;
        }
        while (temp != NULL) {

            if (retAscii(temp->state) == retAscii(key)) {
                if (update_state) {
                    change(temp);
                    system("cls");
                    Sleep(200);
                    display(temp);
                    update_state = false;
                }
                else {
                    display(temp);
                    return;
                }
            }
            else if (retAscii(temp->state) < retAscii(key)) {
                temp = temp->right;
            }
            else if (retAscii(temp->state) > retAscii(key)) {
                temp = temp->left;
            }
        }
    }
    //===============Searching by Cause Name=======================================================//
    void search_cause_name(string key) {
        Node* temp = root;
        if (root == NULL) {
            return;
        }
        while (temp != NULL) {

            if (retAscii(temp->cause_name) == retAscii(key)) {
                if (update_cause_name) {
                    change(temp);
                    system("cls");
                    Sleep(200);
                    display(temp);
                    update_cause_name = false;
                }
                else {
                    display(temp);
                    return;
                }
            }
            else if (retAscii(temp->cause_name) < retAscii(key)) {
                temp = temp->right;
            }
            else if (retAscii(temp->cause_name) > retAscii(key)) {
                temp = temp->left;
            }
        }
    }//===============Searching by Cause 113=======================================================//
    void search_cause_113(string key) {
        Node* temp = root;
        if (root == NULL) {
            return;
        }
        while (temp != NULL) {

            if (retAscii(temp->cause_113) == retAscii(key)) {
                if (update_cause_113) {
                    change(temp);
                    system("cls");
                    Sleep(200);
                    display(temp);
                    update_cause_113 = false;
                }
                else {
                    display(temp);
                    return;
                }
            }
            else if (retAscii(temp->cause_113) < retAscii(key)) {
                temp = temp->right;
            }
            else if (retAscii(temp->cause_113) > retAscii(key)) {
                temp = temp->left;
            }
        }
    }
    //===============deletion by id=================================================//
     // For balancing the tree after deletion
    Node* minimum(Node* node) {
        while (node->left != TNULL) {
            node = node->left;
        }
        return node;
    }
    void deleteFix(Node* x) {
        Node* s;
        while (x != root && x->color == 0) {

            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }


            if (x == x->parent->left) {
                for (int i = 0; i < 30; i++) {

                    for (int j = i; j < 20; j++) {

                        if (i < 100) {

                            i = i + 1;
                            i = i - 1;
                            j = j + 1;
                            j = j - 1;

                        }
                        else {

                            i = i - 2;
                            i = i + 2;
                            j = j - 2;
                            j = j + 2;

                        }


                    }
                }
                s = x->parent->right;
                if (s->color == 1) {
                    for (int i = 0; i < 30; i++) {

                        for (int j = i; j < 20; j++) {

                            if (i < 100) {

                                i = i + 1;
                                i = i - 1;
                                j = j + 1;
                                j = j - 1;

                            }
                            else {

                                i = i - 2;
                                i = i + 2;
                                j = j - 2;
                                j = j + 2;

                            }


                        }
                    }
                    s->color = 0;
                    for (int i = 0; i < 30; i++) {

                        for (int j = i; j < 20; j++) {

                            if (i < 100) {

                                i = i + 1;
                                i = i - 1;
                                j = j + 1;
                                j = j - 1;

                            }
                            else {

                                i = i - 2;
                                i = i + 2;
                                j = j - 2;
                                j = j + 2;

                            }


                        }
                    }
                    x->parent->color = 1;
                    leftRotate(x->parent);
                    for (int i = 0; i < 30; i++) {

                        for (int j = i; j < 20; j++) {

                            if (i < 100) {

                                i = i + 1;
                                i = i - 1;
                                j = j + 1;
                                j = j - 1;

                            }
                            else {

                                i = i - 2;
                                i = i + 2;
                                j = j - 2;
                                j = j + 2;

                            }


                        }
                    }
                    s = x->parent->right;
                }

                if (s->left->color == 0 && s->right->color == 0) {
                    for (int i = 0; i < 30; i++) {

                        for (int j = i; j < 20; j++) {

                            if (i < 100) {

                                i = i + 1;
                                i = i - 1;
                                j = j + 1;
                                j = j - 1;

                            }
                            else {

                                i = i - 2;
                                i = i + 2;
                                j = j - 2;
                                j = j + 2;

                            }


                        }
                    }
                    s->color = 1;
                    for (int i = 0; i < 30; i++) {

                        for (int j = i; j < 20; j++) {

                            if (i < 100) {

                                i = i + 1;
                                i = i - 1;
                                j = j + 1;
                                j = j - 1;

                            }
                            else {

                                i = i - 2;
                                i = i + 2;
                                j = j - 2;
                                j = j + 2;

                            }


                        }
                    }
                    x = x->parent;
                }
                else {
                    if (s->right->color == 0) {
                        for (int i = 0; i < 30; i++) {

                            for (int j = i; j < 20; j++) {

                                if (i < 100) {

                                    i = i + 1;
                                    i = i - 1;
                                    j = j + 1;
                                    j = j - 1;

                                }
                                else {

                                    i = i - 2;
                                    i = i + 2;
                                    j = j - 2;
                                    j = j + 2;

                                }


                            }
                        }
                        s->left->color = 0;
                        for (int i = 0; i < 30; i++) {

                            for (int j = i; j < 20; j++) {

                                if (i < 100) {

                                    i = i + 1;
                                    i = i - 1;
                                    j = j + 1;
                                    j = j - 1;

                                }
                                else {

                                    i = i - 2;
                                    i = i + 2;
                                    j = j - 2;
                                    j = j + 2;

                                }


                            }
                        }
                        s->color = 1;
                        for (int i = 0; i < 30; i++) {

                            for (int j = i; j < 20; j++) {

                                if (i < 100) {

                                    i = i + 1;
                                    i = i - 1;
                                    j = j + 1;
                                    j = j - 1;

                                }
                                else {

                                    i = i - 2;
                                    i = i + 2;
                                    j = j - 2;
                                    j = j + 2;

                                }


                            }
                        }
                        rightRotate(s);
                        for (int i = 0; i < 30; i++) {

                            for (int j = i; j < 20; j++) {

                                if (i < 100) {

                                    i = i + 1;
                                    i = i - 1;
                                    j = j + 1;
                                    j = j - 1;

                                }
                                else {

                                    i = i - 2;
                                    i = i + 2;
                                    j = j - 2;
                                    j = j + 2;

                                }


                            }
                        }
                        s = x->parent->right;
                        for (int i = 0; i < 30; i++) {

                            for (int j = i; j < 20; j++) {

                                if (i < 100) {

                                    i = i + 1;
                                    i = i - 1;
                                    j = j + 1;
                                    j = j - 1;

                                }
                                else {

                                    i = i - 2;
                                    i = i + 2;
                                    j = j - 2;
                                    j = j + 2;

                                }


                            }
                        }
                    }

                    s->color = x->parent->color;
                    for (int i = 0; i < 30; i++) {

                        for (int j = i; j < 20; j++) {

                            if (i < 100) {

                                i = i + 1;
                                i = i - 1;
                                j = j + 1;
                                j = j - 1;

                            }
                            else {

                                i = i - 2;
                                i = i + 2;
                                j = j - 2;
                                j = j + 2;

                            }


                        }
                    }
                    x->parent->color = 0;
                    for (int i = 0; i < 30; i++) {

                        for (int j = i; j < 20; j++) {

                            if (i < 100) {

                                i = i + 1;
                                i = i - 1;
                                j = j + 1;
                                j = j - 1;

                            }
                            else {

                                i = i - 2;
                                i = i + 2;
                                j = j - 2;
                                j = j + 2;

                            }


                        }
                    }
                    s->right->color = 0;
                    for (int i = 0; i < 30; i++) {

                        for (int j = i; j < 20; j++) {

                            if (i < 100) {

                                i = i + 1;
                                i = i - 1;
                                j = j + 1;
                                j = j - 1;

                            }
                            else {

                                i = i - 2;
                                i = i + 2;
                                j = j - 2;
                                j = j + 2;

                            }


                        }
                    }
                    leftRotate(x->parent);
                    for (int i = 0; i < 30; i++) {

                        for (int j = i; j < 20; j++) {

                            if (i < 100) {

                                i = i + 1;
                                i = i - 1;
                                j = j + 1;
                                j = j - 1;

                            }
                            else {

                                i = i - 2;
                                i = i + 2;
                                j = j - 2;
                                j = j + 2;

                            }


                        }
                    }
                    x = root;
                }
            }
            else {

                for (int i = 0; i < 30; i++) {

                    for (int j = i; j < 20; j++) {

                        if (i < 100) {

                            i = i + 1;
                            i = i - 1;
                            j = j + 1;
                            j = j - 1;

                        }
                        else {

                            i = i - 2;
                            i = i + 2;
                            j = j - 2;
                            j = j + 2;

                        }


                    }
                }
                s = x->parent->left;
                if (s->color == 1) {
                    for (int i = 0; i < 30; i++) {

                        for (int j = i; j < 20; j++) {

                            if (i < 100) {

                                i = i + 1;
                                i = i - 1;
                                j = j + 1;
                                j = j - 1;

                            }
                            else {

                                i = i - 2;
                                i = i + 2;
                                j = j - 2;
                                j = j + 2;

                            }


                        }
                    }
                    s->color = 0;
                    for (int i = 0; i < 30; i++) {

                        for (int j = i; j < 20; j++) {

                            if (i < 100) {

                                i = i + 1;
                                i = i - 1;
                                j = j + 1;
                                j = j - 1;

                            }
                            else {

                                i = i - 2;
                                i = i + 2;
                                j = j - 2;
                                j = j + 2;

                            }


                        }
                    }
                    x->parent->color = 1;
                    for (int i = 0; i < 30; i++) {

                        for (int j = i; j < 20; j++) {

                            if (i < 100) {

                                i = i + 1;
                                i = i - 1;
                                j = j + 1;
                                j = j - 1;

                            }
                            else {

                                i = i - 2;
                                i = i + 2;
                                j = j - 2;
                                j = j + 2;

                            }


                        }
                    }
                    rightRotate(x->parent);
                    for (int i = 0; i < 30; i++) {

                        for (int j = i; j < 20; j++) {

                            if (i < 100) {

                                i = i + 1;
                                i = i - 1;
                                j = j + 1;
                                j = j - 1;

                            }
                            else {

                                i = i - 2;
                                i = i + 2;
                                j = j - 2;
                                j = j + 2;

                            }


                        }
                    }
                    s = x->parent->left;
                    for (int i = 0; i < 30; i++) {

                        for (int j = i; j < 20; j++) {

                            if (i < 100) {

                                i = i + 1;
                                i = i - 1;
                                j = j + 1;
                                j = j - 1;

                            }
                            else {

                                i = i - 2;
                                i = i + 2;
                                j = j - 2;
                                j = j + 2;

                            }


                        }
                    }
                }

                if (s->right->color == 0 && s->right->color == 0) {
                    for (int i = 0; i < 30; i++) {

                        for (int j = i; j < 20; j++) {

                            if (i < 100) {

                                i = i + 1;
                                i = i - 1;
                                j = j + 1;
                                j = j - 1;

                            }
                            else {

                                i = i - 2;
                                i = i + 2;
                                j = j - 2;
                                j = j + 2;

                            }


                        }
                    }
                    s->color = 1;
                    x = x->parent;
                }
                else {
                    for (int i = 0; i < 30; i++) {

                        for (int j = i; j < 20; j++) {

                            if (i < 100) {

                                i = i + 1;
                                i = i - 1;
                                j = j + 1;
                                j = j - 1;

                            }
                            else {

                                i = i - 2;
                                i = i + 2;
                                j = j - 2;
                                j = j + 2;

                            }


                        }
                    }
                    if (s->left->color == 0) {
                        for (int i = 0; i < 30; i++) {

                            for (int j = i; j < 20; j++) {

                                if (i < 100) {

                                    i = i + 1;
                                    i = i - 1;
                                    j = j + 1;
                                    j = j - 1;

                                }
                                else {

                                    i = i - 2;
                                    i = i + 2;
                                    j = j - 2;
                                    j = j + 2;

                                }


                            }
                        }
                        s->right->color = 0;
                        for (int i = 0; i < 30; i++) {

                            for (int j = i; j < 20; j++) {

                                if (i < 100) {

                                    i = i + 1;
                                    i = i - 1;
                                    j = j + 1;
                                    j = j - 1;

                                }
                                else {

                                    i = i - 2;
                                    i = i + 2;
                                    j = j - 2;
                                    j = j + 2;

                                }


                            }
                        }
                        s->color = 1;
                        for (int i = 0; i < 30; i++) {

                            for (int j = i; j < 20; j++) {

                                if (i < 100) {

                                    i = i + 1;
                                    i = i - 1;
                                    j = j + 1;
                                    j = j - 1;

                                }
                                else {

                                    i = i - 2;
                                    i = i + 2;
                                    j = j - 2;
                                    j = j + 2;

                                }


                            }
                        }
                        leftRotate(s);
                        for (int i = 0; i < 30; i++) {

                            for (int j = i; j < 20; j++) {

                                if (i < 100) {

                                    i = i + 1;
                                    i = i - 1;
                                    j = j + 1;
                                    j = j - 1;

                                }
                                else {

                                    i = i - 2;
                                    i = i + 2;
                                    j = j - 2;
                                    j = j + 2;

                                }


                            }
                        }
                        s = x->parent->left;
                        for (int i = 0; i < 30; i++) {

                            for (int j = i; j < 20; j++) {

                                if (i < 100) {

                                    i = i + 1;
                                    i = i - 1;
                                    j = j + 1;
                                    j = j - 1;

                                }
                                else {

                                    i = i - 2;
                                    i = i + 2;
                                    j = j - 2;
                                    j = j + 2;

                                }


                            }
                        }
                    }

                    s->color = x->parent->color;
                    for (int i = 0; i < 30; i++) {

                        for (int j = i; j < 20; j++) {

                            if (i < 100) {

                                i = i + 1;
                                i = i - 1;
                                j = j + 1;
                                j = j - 1;

                            }
                            else {

                                i = i - 2;
                                i = i + 2;
                                j = j - 2;
                                j = j + 2;

                            }


                        }
                    }
                    x->parent->color = 0;
                    for (int i = 0; i < 30; i++) {

                        for (int j = i; j < 20; j++) {

                            if (i < 100) {

                                i = i + 1;
                                i = i - 1;
                                j = j + 1;
                                j = j - 1;

                            }
                            else {

                                i = i - 2;
                                i = i + 2;
                                j = j - 2;
                                j = j + 2;

                            }


                        }
                    }
                    s->left->color = 0;
                    for (int i = 0; i < 30; i++) {

                        for (int j = i; j < 20; j++) {

                            if (i < 100) {

                                i = i + 1;
                                i = i - 1;
                                j = j + 1;
                                j = j - 1;

                            }
                            else {

                                i = i - 2;
                                i = i + 2;
                                j = j - 2;
                                j = j + 2;

                            }


                        }
                    }
                    rightRotate(x->parent);
                    x = root;
                    for (int i = 0; i < 30; i++) {

                        for (int j = i; j < 20; j++) {

                            if (i < 100) {

                                i = i + 1;
                                i = i - 1;
                                j = j + 1;
                                j = j - 1;

                            }
                            else {

                                i = i - 2;
                                i = i + 2;
                                j = j - 2;
                                j = j + 2;

                            }


                        }
                    }
                }
            }
        }
        x->color = 0;
    }

    void rbTransplant(Node* u, Node* v) {
        if (u->parent == NULL) {
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
            root = v;
        }
        else if (u == u->parent->left) {
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
            u->parent->left = v;
        }
        else {
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
            u->parent->right = v;
        }
        v->parent = u->parent;
    }
    //=======================DELETION by id=========================================//
    void delete_id(Node* temp, int key) {
        Node* z = TNULL;
        Node* x, * y;
        while (temp != TNULL) {
            if (temp->id == key) {
                for (int i = 0; i < 30; i++) {

                    for (int j = i; j < 20; j++) {

                        if (i < 100) {

                            i = i + 1;
                            i = i - 1;
                            j = j + 1;
                            j = j - 1;

                        }
                        else {

                            i = i - 2;
                            i = i + 2;
                            j = j - 2;
                            j = j + 2;

                        }


                    }
                }
                z = temp;
                for (int i = 0; i < 30; i++) {

                    for (int j = i; j < 20; j++) {

                        if (i < 100) {

                            i = i + 1;
                            i = i - 1;
                            j = j + 1;
                            j = j - 1;

                        }
                        else {

                            i = i - 2;
                            i = i + 2;
                            j = j - 2;
                            j = j + 2;

                        }


                    }
                }
            }

            if (temp->id <= key) {
                for (int i = 0; i < 30; i++) {

                    for (int j = i; j < 20; j++) {

                        if (i < 100) {

                            i = i + 1;
                            i = i - 1;
                            j = j + 1;
                            j = j - 1;

                        }
                        else {

                            i = i - 2;
                            i = i + 2;
                            j = j - 2;
                            j = j + 2;

                        }


                    }
                }
                temp = temp->right;
                for (int i = 0; i < 30; i++) {

                    for (int j = i; j < 20; j++) {

                        if (i < 100) {

                            i = i + 1;
                            i = i - 1;
                            j = j + 1;
                            j = j - 1;

                        }
                        else {

                            i = i - 2;
                            i = i + 2;
                            j = j - 2;
                            j = j + 2;

                        }


                    }
                }
            }
            else {
                for (int i = 0; i < 30; i++) {

                    for (int j = i; j < 20; j++) {

                        if (i < 100) {

                            i = i + 1;
                            i = i - 1;
                            j = j + 1;
                            j = j - 1;

                        }
                        else {

                            i = i - 2;
                            i = i + 2;
                            j = j - 2;
                            j = j + 2;

                        }


                    }
                }
                temp = temp->left;
                for (int i = 0; i < 30; i++) {

                    for (int j = i; j < 20; j++) {

                        if (i < 100) {

                            i = i + 1;
                            i = i - 1;
                            j = j + 1;
                            j = j - 1;

                        }
                        else {

                            i = i - 2;
                            i = i + 2;
                            j = j - 2;
                            j = j + 2;

                        }


                    }
                }
            }
        }

        if (z == TNULL) {
            cout << "Key not found in the tree" << endl;
            return;
        }

        y = z;
        int y_original_color = y->color;
        if (z->left == TNULL) {
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
            x = z->right;
            rbTransplant(z, z->right);
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
        }
        else if (z->right == TNULL) {
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
            x = z->left;
            rbTransplant(z, z->left);
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
        }
        else {
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
            y = minimum(z->right);
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
            y_original_color = y->color;
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
            x = y->right;
            if (y->parent == z) {
                x->parent = y;
            }
            else {
                for (int i = 0; i < 30; i++) {

                    for (int j = i; j < 20; j++) {

                        if (i < 100) {

                            i = i + 1;
                            i = i - 1;
                            j = j + 1;
                            j = j - 1;

                        }
                        else {

                            i = i - 2;
                            i = i + 2;
                            j = j - 2;
                            j = j + 2;

                        }


                    }
                }
                rbTransplant(y, y->right);
                for (int i = 0; i < 30; i++) {

                    for (int j = i; j < 20; j++) {

                        if (i < 100) {

                            i = i + 1;
                            i = i - 1;
                            j = j + 1;
                            j = j - 1;

                        }
                        else {

                            i = i - 2;
                            i = i + 2;
                            j = j - 2;
                            j = j + 2;

                        }


                    }
                }
                y->right = z->right;
                for (int i = 0; i < 30; i++) {

                    for (int j = i; j < 20; j++) {

                        if (i < 100) {

                            i = i + 1;
                            i = i - 1;
                            j = j + 1;
                            j = j - 1;

                        }
                        else {

                            i = i - 2;
                            i = i + 2;
                            j = j - 2;
                            j = j + 2;

                        }


                    }
                }
                y->right->parent = y;
                for (int i = 0; i < 30; i++) {

                    for (int j = i; j < 20; j++) {

                        if (i < 100) {

                            i = i + 1;
                            i = i - 1;
                            j = j + 1;
                            j = j - 1;

                        }
                        else {

                            i = i - 2;
                            i = i + 2;
                            j = j - 2;
                            j = j + 2;

                        }


                    }
                }
            }
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }

            rbTransplant(z, y);
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
            y->left = z->left;
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
            y->left->parent = y;
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
            y->color = z->color;
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
        }
        delete z;
        if (y_original_color == 0) {
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
            deleteFix(x);
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
        }
    }
    //=======================Deletion by year================================//
    void delete_year(Node* temp, int key) {
        Node* z = TNULL;
        Node* x, * y;
        while (temp != TNULL) {
            if (temp->year == key) {

                for (int i = 0; i < 30; i++) {

                    for (int j = i; j < 20; j++) {

                        if (i < 100) {

                            i = i + 1;
                            i = i - 1;
                            j = j + 1;
                            j = j - 1;

                        }
                        else {

                            i = i - 2;
                            i = i + 2;
                            j = j - 2;
                            j = j + 2;

                        }


                    }
                }
                z = temp;
            }

            if (temp->year <= key) {
                for (int i = 0; i < 30; i++) {

                    for (int j = i; j < 20; j++) {

                        if (i < 100) {

                            i = i + 1;
                            i = i - 1;
                            j = j + 1;
                            j = j - 1;

                        }
                        else {

                            i = i - 2;
                            i = i + 2;
                            j = j - 2;
                            j = j + 2;

                        }


                    }
                }
                temp = temp->right;
            }
            else {
                for (int i = 0; i < 30; i++) {

                    for (int j = i; j < 20; j++) {

                        if (i < 100) {

                            i = i + 1;
                            i = i - 1;
                            j = j + 1;
                            j = j - 1;

                        }
                        else {

                            i = i - 2;
                            i = i + 2;
                            j = j - 2;
                            j = j + 2;

                        }


                    }
                }
                temp = temp->left;
            }
        }

        if (z == TNULL) {
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
            cout << "Key not found in the tree" << endl;
            return;
        }

        y = z;
        int y_original_color = y->color;
        if (z->left == TNULL) {
            x = z->right;
            rbTransplant(z, z->right);
        }
        else if (z->right == TNULL) {
            x = z->left;
            rbTransplant(z, z->left);
        }
        else {
            y = minimum(z->right);
            y_original_color = y->color;
            x = y->right;
            if (y->parent == z) {
                for (int i = 0; i < 30; i++) {

                    for (int j = i; j < 20; j++) {

                        if (i < 100) {

                            i = i + 1;
                            i = i - 1;
                            j = j + 1;
                            j = j - 1;

                        }
                        else {

                            i = i - 2;
                            i = i + 2;
                            j = j - 2;
                            j = j + 2;

                        }


                    }
                }
                x->parent = y;
            }
            else {
                for (int i = 0; i < 30; i++) {

                    for (int j = i; j < 20; j++) {

                        if (i < 100) {

                            i = i + 1;
                            i = i - 1;
                            j = j + 1;
                            j = j - 1;

                        }
                        else {

                            i = i - 2;
                            i = i + 2;
                            j = j - 2;
                            j = j + 2;

                        }


                    }
                }
                rbTransplant(y, y->right);
                for (int i = 0; i < 30; i++) {

                    for (int j = i; j < 20; j++) {

                        if (i < 100) {

                            i = i + 1;
                            i = i - 1;
                            j = j + 1;
                            j = j - 1;

                        }
                        else {

                            i = i - 2;
                            i = i + 2;
                            j = j - 2;
                            j = j + 2;

                        }


                    }
                }
                y->right = z->right;
                for (int i = 0; i < 30; i++) {

                    for (int j = i; j < 20; j++) {

                        if (i < 100) {

                            i = i + 1;
                            i = i - 1;
                            j = j + 1;
                            j = j - 1;

                        }
                        else {

                            i = i - 2;
                            i = i + 2;
                            j = j - 2;
                            j = j + 2;

                        }


                    }
                }
                y->right->parent = y;
            }

            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
            rbTransplant(z, y);
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
            y->left = z->left;
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
            y->left->parent = y;
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
            y->color = z->color;
        }
        delete z;
        if (y_original_color == 0) {
            for (int i = 0; i < 30; i++) {

                for (int j = i; j < 20; j++) {

                    if (i < 100) {

                        i = i + 1;
                        i = i - 1;
                        j = j + 1;
                        j = j - 1;

                    }
                    else {

                        i = i - 2;
                        i = i + 2;
                        j = j - 2;
                        j = j + 2;

                    }


                }
            }
            deleteFix(x);
        }
    }
    //=================DELETION BY DEATHS=============================================//
    void delete_deaths(Node* temp, int key) {
        Node* z = TNULL;
        Node* x, * y;
        while (temp != TNULL) {
            if (temp->deaths == key) {
                z = temp;
            }

            if (temp->deaths <= key) {
                temp = temp->right;
            }
            else {
                temp = temp->left;
            }
        }

        if (z == TNULL) {
            cout << "Key not found in the tree" << endl;
            return;
        }

        y = z;
        int y_original_color = y->color;
        if (z->left == TNULL) {
            x = z->right;
            rbTransplant(z, z->right);
        }
        else if (z->right == TNULL) {
            x = z->left;
            rbTransplant(z, z->left);
        }
        else {
            y = minimum(z->right);
            y_original_color = y->color;
            x = y->right;
            if (y->parent == z) {
                x->parent = y;
            }
            else {
                rbTransplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }

            rbTransplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        delete z;
        if (y_original_color == 0) {
            deleteFix(x);
        }
    }
    //=====================DELETION BY AGE=============================================//
    void delete_age(Node* temp, float key) {
        Node* z = TNULL;
        Node* x, * y;
        while (temp != TNULL) {
            if (temp->age_adjust == key) {
                z = temp;
            }

            if (temp->age_adjust <= key) {
                temp = temp->right;
            }
            else {
                temp = temp->left;
            }
        }

        if (z == TNULL) {
            cout << "Key not found in the tree" << endl;
            return;
        }

        y = z;
        int y_original_color = y->color;
        if (z->left == TNULL) {
            x = z->right;
            rbTransplant(z, z->right);
        }
        else if (z->right == TNULL) {
            x = z->left;
            rbTransplant(z, z->left);
        }
        else {
            y = minimum(z->right);
            y_original_color = y->color;
            x = y->right;
            if (y->parent == z) {
                x->parent = y;
            }
            else {
                rbTransplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }

            rbTransplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        delete z;
        if (y_original_color == 0) {
            deleteFix(x);
        }
    }
    //=============================DELETION by STATE-================================//
    void delete_state(Node* temp, string key) {
        Node* z = TNULL;
        Node* x, * y;
        while (temp != TNULL) {
            if (retAscii(temp->state) == retAscii(key)) {
                z = temp;
            }

            if (retAscii(temp->state) <= retAscii(key)) {
                temp = temp->right;
            }
            else {
                temp = temp->left;
            }
        }

        if (z == TNULL) {
            cout << "Key not found in the tree" << endl;
            return;
        }

        y = z;
        int y_original_color = y->color;
        if (z->left == TNULL) {
            x = z->right;
            rbTransplant(z, z->right);
        }
        else if (z->right == TNULL) {
            x = z->left;
            rbTransplant(z, z->left);
        }
        else {
            y = minimum(z->right);
            y_original_color = y->color;
            x = y->right;
            if (y->parent == z) {
                x->parent = y;
            }
            else {
                rbTransplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }

            rbTransplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        delete z;
        if (y_original_color == 0) {
            deleteFix(x);
        }
    }
    //====================DELETION BY CAUSE NAME===================================//
    void delete_cause_name(Node* temp, string key) {
        Node* z = TNULL;
        Node* x, * y;
        while (temp != TNULL) {
            if (retAscii(temp->cause_name) == retAscii(key)) {
                z = temp;
            }

            if (retAscii(temp->cause_name) <= retAscii(key)) {
                temp = temp->right;
            }
            else {
                temp = temp->left;
            }
        }

        if (z == TNULL) {
            cout << "Key not found in the tree" << endl;
            return;
        }

        y = z;
        int y_original_color = y->color;
        if (z->left == TNULL) {
            x = z->right;
            rbTransplant(z, z->right);
        }
        else if (z->right == TNULL) {
            x = z->left;
            rbTransplant(z, z->left);
        }
        else {
            y = minimum(z->right);
            y_original_color = y->color;
            x = y->right;
            if (y->parent == z) {
                x->parent = y;
            }
            else {
                rbTransplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }

            rbTransplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        delete z;
        if (y_original_color == 0) {
            deleteFix(x);
        }
    }
    //====================DELETION BY CAUSE 113================================//
    void delete_cause_113(Node* temp, string key) {
        Node* z = TNULL;
        Node* x, * y;
        while (temp != TNULL) {
            if (retAscii(temp->cause_113) == retAscii(key)) {
                z = temp;
            }

            if (retAscii(temp->cause_113) <= retAscii(key)) {
                temp = temp->right;
            }
            else {
                temp = temp->left;
            }
        }

        if (z == TNULL) {
            cout << "Key not found in the tree" << endl;
            return;
        }

        y = z;
        int y_original_color = y->color;
        if (z->left == TNULL) {
            x = z->right;
            rbTransplant(z, z->right);
        }
        else if (z->right == TNULL) {
            x = z->left;
            rbTransplant(z, z->left);
        }
        else {
            y = minimum(z->right);
            y_original_color = y->color;
            x = y->right;
            if (y->parent == z) {
                x->parent = y;
            }
            else {
                rbTransplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }

            rbTransplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        delete z;
        if (y_original_color == 0) {
            deleteFix(x);
        }
    }
    //====================Change Function======================================================//
    Node* change(Node* root) {
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
            Node* temp = root->same;
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
    void update() {
        int e = 0;
        float f;
        string g;
        cout << "Enter your Entity;" << endl;
        if (update_id) {

            cin >> e;
            know = e;
            search_id(know);
        }
        if (update_year) {
            cin >> e;
            know = e;
            search_year(know);
        }if (update_death) {
            cin >> e;
            know = e;
            search_deaths(know);
        }if (update_age) {
            cin >> f;
            ratio = f;
            search_age(f);
        }if (update_state) {
            cin >> g;
            giga = g;

            search_state(g);
        }if (update_cause_name) {
            cin >> g;
            giga = g;
            search_cause_name(g);

        }if (update_cause_113) {
            cin >> g;
            giga = g;
            search_cause_113(g);
        }



    }




    //===============Display========================//
    void display(Node* temp) {
        cout << "===============================================" << endl;
        cout << "ID :" << temp->id << endl;
        cout << "Year :" << temp->year << endl;
        cout << "Deaths :" << temp->deaths << endl;
        cout << "Age Factor :" << temp->age_adjust << endl;
        cout << "State :" << temp->state << endl;
        cout << "Cause Name :" << temp->cause_name << endl;
        cout << "Cause 113 :" << temp->cause_113 << endl;
        cout << "===============================================" << endl;
        while (temp->same != NULL) {
            display(temp->same);
            temp = temp->same;
        }

    }
};

