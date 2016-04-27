#ifndef TREE_H
#define TREE_H
#include <iostream>

using namespace std;

struct Node{
    string title;
    int year;
    int quantity;
    Node *parent;
    Node *leftChild;
    Node *rightChild;

    Node(){};

    Node(string in_title, int in_year, int in_quantity)
    {
        title = in_title;
        year = in_year;
        quantity = in_quantity;
        parent = NULL;
        leftChild = NULL;
        rightChild = NULL;
    }
};

class Tree
{
    public:
        Tree();
        ~Tree();
        void printInventory();
        int countNodes();
        void deleteNode(string title,int year);
        void addNode(string title, int releaseYear, int quantity);
        void findNode(string title,int year);
        void rent(string title,int year);
        void DeleteAllPublic();
        int countSpecific(string name);
        float averageAge();
        void edit(string title1,int year1,string title2,int year2);
    protected:
    private:
        void DeleteAll(Node * node);
        void printInventory(Node * node);
        void countNodes(Node *node, int &nodeCount);
        void countSpecific(Node *node,int &nodeCount,string name);
        void averagePriv(Node *node,float &sum);
        Node* search(string title,int year);
        Node* treeMinimum(Node *node);
        Node *root;
};

#endif // TREE_H
