#pragma once

#include <iostream>

using namespace std;
typedef struct node
{
    string name;
    int *level;
    bool sex;
    node *mother;
    node *father;
} node;

class family
{
    family();
    ~family();
    public:
        class Tree
        {
           
            public:
                node *head;
                Tree(string t);
                ~Tree();
                node AddFather(node *root, string son, string pop, int deepest);
                node AddMother(node *root, string son, string pop, int deepest);
                void print2DUtil(node *root, int space);
                Tree &addFather(string c, string x);
                Tree &addMother(string c , string x);
                string relation(string c);
                Tree &display();
                string find(string c);
                node* relation(int level,string name, node *tmp);
                Tree &remove(string c);
                void FreeNode(node *tmp);
                };
                }; // namespace Tree
