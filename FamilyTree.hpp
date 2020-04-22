#pragma once

#include <iostream>

using namespace std;

class family{
    family()
    {
        cout << "shiza" << endl;
    }

    public:
        class Tree
        {
        public:
            Tree(string t)
            {
                cout << t << endl;
            };
            Tree& addFather(string t , string a);
            Tree& addMother(string, string);
            string relation(string);
            Tree& display();
            string find(string);
            Tree& remove(string);
        };   
    
        

    } ;// namespace Tree

    
    