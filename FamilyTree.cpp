#include <iostream>
#include "FamilyTree.hpp"
using namespace std;

#define MALE 1
#define FEMALE 0

typedef family::Tree tree;

node *err_node;

family::Tree::Tree(string t)
{
    head = (node *)malloc(sizeof(node));
    head->name = new string(t);
    head->level = (int *)calloc(1,sizeof(int)) ;
    head->father = NULL;
    head->mother = NULL;
    err_node = (node *)malloc(sizeof(node));
    err_node->name = new string(" ");
    err_node->mother=NULL;
    err_node->father=NULL;
    err_node->level = (int *)calloc(1, sizeof(int));
    *err_node->level = -1;
}
family::Tree::~Tree(){
    FreeNode(head);
    FreeNode(err_node);
}

void family::Tree::FreeNode(node * tmp){

    if(tmp->father==NULL&&tmp->mother==NULL){
        
       
        if(tmp->level!=NULL){
            delete[] tmp->level;
            
            tmp->level=NULL;
        }
        delete tmp->name;
        delete (tmp);
        
        return;
        
        }
    else{
        if (tmp->father != NULL)
        {
            FreeNode(tmp->father);
            tmp->father = NULL;
        }
        if (tmp->mother != NULL)
        {
            FreeNode(tmp->mother);
            tmp->mother = NULL;
        }
    }
   
    
    delete tmp->level;
    delete tmp->name;
    delete tmp;
    
   
    
        
    
}
family::Tree & family::Tree::remove(string nodeToRemove)
{
    bool ans = remove(head, nodeToRemove) ;
    
    if(ans)
    {
        return *this;
    }
    else{
        throw invalid_argument("cannot find family member");
    }

        
}
bool family::Tree::remove(node * node, string nodeToRemove)
{   
    if(node->father==NULL&&node->mother==NULL){
        
        return false;
    }
    bool a = false;
    bool b = false;
    if(node->father!=NULL){
        if (*node->father->name == nodeToRemove)
        {
            FreeNode(node->father);
            node->father = NULL;
            return true;
            
        }
        else{
            a= remove(node->father, nodeToRemove);
        }
    }
    if (node->mother!=NULL){
        if (*node->mother->name == nodeToRemove){
            FreeNode(node->mother);
            node->mother = NULL;
            return true;
        }
        else{
            b = remove(node->mother, nodeToRemove);
        }
            
    }
    return a||b;
   
}
family::Tree & family::Tree::addFather(string son, string pop)
{
    bool ans = AddFather(head, son , pop,0);
    if(ans){
        return *this;
    }
    else{
        throw invalid_argument("cannot find family member");
    }
}

bool family::Tree::AddFather(node *root, string son, string pop, int deepest)
{
    bool a = false;
    bool b = false;
    if(*root->name==son){
        if(root->father!=NULL){
            throw std::invalid_argument("Already has a father");
        }
        int tmp = *head->level;    
        root->father = (node *)malloc(sizeof(node));        
        root = root->father;
        root->level = (int *)calloc(1, sizeof(int));
        *root->level =deepest+1;      
        root->sex = MALE;
        root->name = new string(pop);
        root->father=NULL;
        root->mother=NULL;
        return true;
                }
    
    else{
        if(root->father!=NULL){
           a= AddFather(root->father,son,pop,deepest+1);
        }
        if(root->mother!=NULL){
            b=AddFather(root->mother,son,pop,deepest+1);

        }}
    
    return a||b;
}

family::Tree &family::Tree::addMother(string son, string mom)
{
    bool ans = AddMother(head,son,mom,0);
    if(ans){
        return *this;
    }
    else{
        throw invalid_argument("Not found");
    }
}
bool family::Tree::AddMother(node *root, string son, string mom, int deepest)
{

    bool a = false;
    bool b = false;
    if (*root->name == son)
    {
        if (root->mother!=NULL)
        {
            throw std::invalid_argument("Already has a mother");
        }
        root->mother = (node *)malloc(sizeof(node));
        root = root->mother;
        root->father = NULL;
        root->mother = NULL;
        root->level = (int *)calloc(1, sizeof(int));
        *root->level = deepest + 1;
        root->sex = FEMALE;
        root->name = new string(mom);
        return true;
    }
    
    else
    {
        if (root->father != NULL)
        {
            a = AddMother(root->father, son, mom,deepest+1);
        }
        if (root->mother != NULL)
        {
            b = AddMother(root->mother, son, mom,deepest+1);
        }
    }
    return a||b;
}

string family::Tree::relation(string name)
{
    node *data;
    data = relation(0, name, head);
    string ans;
    int RealLevel = *data->level;
    
    if(RealLevel<0){
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

    if (*tmp->name == name)
    {       
        return tmp;
    }
    else
    {
        if(tmp->father==NULL&&tmp->mother==NULL)
        {       
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
    return err_node;
}

family::Tree &family::Tree::display()
{
    print2DUtil(head,0);
    return *this;
}
void family::Tree::print2DUtil(node *root, int space)
{
    // Base case
    if (root == NULL) return;
    // Increase distance between levels
    space += 10;
    if(root->mother != NULL) print2DUtil(root->mother, space);
    for (int i = 10; i < space; i++) cout << " ";
    cout << root->name << "\n";    
    // Process left child
    if(root->father != NULL) print2DUtil(root->father, space);
}

string family::Tree::find(string name)
{
    string ans;
    if(name == "mother"){
        if(head->mother==NULL){
            throw invalid_argument("Family member does not exist");
        }
        else{
            return *head->mother->name;
        }

    }
    else if (name == "father"){
        if (head->father == NULL)
        {
            throw invalid_argument("Family member does not exist");
        }
        else
        {
            return *head->father->name;
        }
    }
    else if(name=="grandmother"){
        ans = find( head , 2 , 0);
    }
    else if(name=="grandfather"){
        ans = find(head,2,1);
    }
    else{

        int name_len = name.length()-11;
        if (name.substr(name.length() - 11, 11) != "grandfather" && name.substr(name.length() - 11, 11) != "grandmother"){
            throw std::invalid_argument("Invalid relation i");
        }
        int level = name_len / 6;
        int i;
        for(i =0; i<name_len;i+=6){
            if(name.substr(i,6)!="great-"){
                throw std::invalid_argument("Invalid relation b");
            }

        }

        
        if (name.substr(name_len + 5) == "mother"){
            
            ans = find(head, level+2, 0);
        }
        else{
            
            ans = find(head, level+2, 1);
            
        }
        
    }
    
    if(ans=="notfound"){
        throw std::invalid_argument("no such family member");
    }
    
    return ans;
}
string family::Tree::find(node *tmp, int level, int sex){

    if (level ==0){
        
        if(tmp->sex==sex){
            
            return *tmp->name;
        }
        else{
        
            return "notfound";
        }

    }
    else{
        string ans1 = "notfound";
        string ans2 = "notfound";
        if(tmp->father!=NULL){
            ans1= find(tmp->father,level-1,sex);
        }
        if(tmp->mother!=NULL){
            ans2 = find(tmp->mother, level - 1, sex);
        }
        if(ans1=="notfound"&&ans2=="notfound"){
            return "notfound";
        }
        else if(ans1== "notfound"){
            return ans2;
        }
        else{
            return ans1;
        }


    }
}




