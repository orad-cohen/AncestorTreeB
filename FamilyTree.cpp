#include <iostream>
#include "FamilyTree.hpp"
using namespace std;

typedef family::Tree tree;

tree &tree::addFather(string t, string a)
{
    return *this;
}
tree &tree::addMother(string t, string x)
{
    return *this;
}
string tree::relation(string)
{
    return "placeholder";
}
tree &tree::display()
{
    return *this;
}
string tree::find(string)
{
    return "placeholder";
}
tree &tree::remove(string t)
{
    return *this;
}
