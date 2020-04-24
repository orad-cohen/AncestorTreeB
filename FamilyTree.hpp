#pragma once

#include <iostream>

using namespace std;
typedef struct node
{
    string *name;
    int *level;
    bool sex;
    node *mother;
    node *father;
} node;

namespace family
{
    
   
        class Tree
        {
           
            public:
                node *head;
                Tree(string t);
                ~Tree();
                bool AddFather(node *root, string son, string pop, int deepest);
                bool AddMother(node *root, string son, string pop, int deepest);
                void print2DUtil(node *root, int space);
                Tree &addFather(string c, string x);
                Tree &addMother(string c , string x);
                string relation(string c);
                Tree &display();
                string find(string c);
                node* relation(int level,string name, node *tmp);
                Tree &remove(string c);
                bool remove(node *root, string son);
                void FreeNode(node *tmp);
                string  find(node *tmp, int level, int sex);
                };
                }; // namespace Tree
