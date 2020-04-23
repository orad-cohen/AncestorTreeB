#include <iostream>
#include "FamilyTree.hpp"
using namespace std;

typedef family::Tree tree;
node *head;
node *err_node;

family::Tree::Tree(string t)
{
    head = (node *)malloc(sizeof(node));
    head->name=t;
    head->level = (int *)calloc(1,sizeof(int)) ;

    head->father = NULL;
    head->mother = NULL;
    err_node = (node *)malloc(sizeof(node));
    err_node->name = " ";
    err_node-> level = (int *)malloc(sizeof(int));
    *err_node->level = -1;
}
family::Tree::~Tree(){
    FreeNode(head);
    FreeNode(err_node);

}

void family::Tree::FreeNode(node * tmp){

    if(tmp->father==NULL&&tmp->mother==NULL){
        delete tmp->level;
        
        delete tmp;
        return;
    }
    else{
        if(tmp->father!=NULL){
            FreeNode(tmp->father);
        }
        if(tmp->mother!=NULL){
            FreeNode(tmp->mother);
        }
        
    }
    delete tmp->level;
    delete tmp;

}

 family::Tree & family::Tree::addFather(string son, string pop)
{
    AddFather(head, son , pop,0);
    return *this;
}

node family::Tree::AddFather(node *root, string son, string pop, int deepest)
{
    if(root->name==son){
        int tmp = *head->level;
        
        if (tmp < deepest)
        {   
            *head->level=deepest;
        };
       
        root->father = (node *)malloc(sizeof(node));
        
        root = root->father;

        root->level = (int *)malloc(sizeof(int));

        *root->level =deepest+1;
      
        root->sex = 1;
        root->name = pop;
        root->father=NULL;
        root->mother=NULL;
        
                }
    else{
        if(root->father!=NULL){
            AddFather(root->father,son,pop,deepest+1);
        }
        if(root->mother!=NULL){
            AddFather(root->mother,son,pop,deepest+1);

        }}

    return *root;
}

family::Tree &family::Tree::addMother(string son, string mom)
{
    AddMother(head,son,mom,0);
    return *this;
}
node family::Tree::AddMother(node *root, string son, string mom, int deepest)
{

    if (root->name == son)
    {
        if (*head->level < deepest)
        {
            *head->level = deepest;
        };
        root->mother = (node *)malloc(sizeof(node));
        root = root->mother;
        root->father = NULL;
        root->mother = NULL;
        root->level = (int *)malloc(sizeof(int));
        *root->level = deepest + 1;
        root->sex = 0;
        root->name = mom;
        
    }
    else
    {
        if (root->father != NULL)
        {
            AddMother(root->father, son, mom,deepest+1);
        }
        if (root->mother != NULL)
        {
            AddMother(root->mother, son, mom,deepest+1);
        }
    }
    return *root;
}

string family::Tree::relation(string name)
{
   
    node *data;
    data = relation(0, name, head);
    string ans = "";
   
    int RealLevel = *data->level;
    if(RealLevel>20){
        cout << "level :" << RealLevel << endl;
        throw std::invalid_argument("blah");
    }
    if(RealLevel==-1){
        ans += "unrelated";
        return ans;
    }
    while (RealLevel > 2)
    {
        ans+="great-";
        RealLevel--;
    }
    if (RealLevel == 2)
    {
        ans+="grand";
        RealLevel--;
    }
    if (RealLevel == 1)
    {
        if (data->sex == 0)
        {
            return ans += "mother";
        }
        else
        {
            return ans += "father";
        }
    }
    return "me";
}
node * family::Tree::relation(int level, string name, node *tmp)
{

    if (tmp->name == name)
    {       
        
        return tmp;
    }
    else
    {
        if(tmp->father==NULL&&tmp->mother==NULL){
            
            
            return err_node;
        }
        node *lvl1 = err_node;
        node *lvl2 = err_node;
        if(tmp->father!=NULL){
            
            lvl1 = relation(level+1,name,tmp->father);
            
        }
        if(tmp->mother!=NULL){
            lvl2 = relation(level+1, name, tmp->mother);
              
            
        }
        
        if(*(lvl1->level) < *(lvl2->level)){

            
            return lvl2;
        }
        else{
            
            return lvl1;
        }
        

    }
    throw std::invalid_argument("not found");
}

family::Tree &family::Tree::display()
{
    print2DUtil(head,0);
    return *this;
}
void family::Tree::print2DUtil(node *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += 10;
    print2DUtil(root->mother, space);

    for (int i = 10; i < space; i++)
        cout << " ";
    cout << root->name << "\n";
    
    // Process right child first
    

    // Print current node after space
    // count
    cout << endl;
    

    // Process left child
    print2DUtil(root->father, space);
}

string family::Tree::find(string name)
{
    
    return "placeholder";
}


tree &family::Tree::remove(string t)
{
    return *this;
}
