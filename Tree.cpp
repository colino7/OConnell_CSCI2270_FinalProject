#include "Tree.h"

Tree::Tree()
{
    //ctor
    root=NULL;
}

Tree::~Tree()
{
    //dtor
    if(root!=NULL){
        DeleteAll(root);
    }
}

void Tree::edit(string title1,int year1,string title2,int year2){
    deleteNode(title1,year1);
    addNode(title2,year2,1);
}

void Tree::DeleteAllPublic(){
    if(root!=NULL)
        DeleteAll(root);
    root=NULL;
}

void Tree::deleteNode(string title,int year){
    if(root==NULL){
        cout<<"Inventory empty"<<endl;
        return;
    }
    bool foundroot=false;
    //cout<<"before"<<endl;
    Node *node=search(title,year);
    //cout<<"after"<<endl;
    if(node!=NULL){
        if(node!=root){
            if(node->rightChild==NULL and node->leftChild==NULL){
                if(node->parent->leftChild==node){ //true when node is leftChild
                    node->parent->leftChild=NULL;
                    //cout<<"1"<<endl;
                }
                else{
                    node->parent->rightChild=NULL;
                    //cout<<"2"<<endl;
                }
            }
            else if(node->leftChild!=NULL and node->rightChild!=NULL){
                Node *tmin=new Node;
                tmin=treeMinimum(node->rightChild);
                if(tmin==node->rightChild){
                    if(node->parent->rightChild==node){
                        node->parent->rightChild=tmin;//node->parent->leftChild=tmin;
                        tmin->parent=node->parent;
                        node->leftChild->parent=tmin;
                        tmin->leftChild=node->leftChild;
                        //cout<<"3"<<endl;
                    }
                    else{
                        node->parent->leftChild=tmin;
                        tmin->parent=node->parent;
                        node->leftChild->parent=tmin;
                        tmin->leftChild=node->leftChild;
                        //cout<<"4"<<endl;
                    }
                }
                else{
                    if(node->parent->rightChild==node){
                        tmin->parent->leftChild=tmin->rightChild;
                        tmin->parent=node->parent;
                        tmin->rightChild->parent=tmin->parent;
                        node->parent->rightChild=tmin;//node->parent->leftChild=tmin;
                        tmin->leftChild=node->leftChild;
                        tmin->rightChild=node->rightChild;
                        node->rightChild->parent=tmin;
                        node->leftChild->parent=tmin;
                        //cout<<"5"<<endl;
                    }
                    else{
                        tmin->parent->leftChild=tmin->rightChild;
                        tmin->parent=node->parent;
                        tmin->rightChild->parent=tmin->parent;
                        node->parent->leftChild=tmin;
                        tmin->leftChild=node->leftChild;
                        tmin->rightChild=node->rightChild;
                        node->rightChild->parent=tmin;
                        node->leftChild->parent=tmin;
                        //cout<<"6"<<endl;
                    }
                }
            }
            else{
                if(node->parent->leftChild==node){
                    Node *x=node->leftChild;
                    node->parent->leftChild=x;
                    x->parent=node->parent;
                    //cout<<"7"<<endl;
                }
                else{
                    Node *x=node->leftChild;
                    node->parent->rightChild=x;
                    x->parent=node->parent;
                    //cout<<"8"<<endl;
                }
            }
        }
        else{
            if(node->rightChild==NULL and node->leftChild==NULL){
                node=root;
                foundroot=true;
            }
            else if(node->leftChild!=NULL and node->rightChild!=NULL){
                Node *tmin=new Node;
                tmin=treeMinimum(node->rightChild);
                if(tmin==node->rightChild){
                    tmin->parent=NULL;
                    node->leftChild->parent=tmin;
                    tmin->leftChild=node->leftChild;
                    root=tmin;
                }
                else{
                    if(tmin->rightChild!=NULL){
                        tmin->parent->leftChild=tmin->rightChild;
                        tmin->parent=NULL;//node->parent;
                        //cout<<"yup"<<endl;
                        tmin->rightChild->parent=tmin->parent;
                        //node->parent->rightChild=tmin;//node->parent->leftChild=tmin;
                        tmin->leftChild=node->leftChild;
                        tmin->rightChild=node->rightChild;
                        node->rightChild->parent=tmin;
                        node->leftChild->parent=tmin;
                        root=tmin;
                    }
                    else{
                        tmin->parent->leftChild=NULL;//tmin->rightChild;
                        tmin->parent=NULL;//node->parent;
                        //cout<<"yup"<<endl;
                        //tmin->rightChild->parent=tmin->parent;
                        //node->parent->rightChild=tmin;//node->parent->leftChild=tmin;
                        tmin->leftChild=node->leftChild;
                        tmin->rightChild=node->rightChild;
                        node->rightChild->parent=tmin;
                        node->leftChild->parent=tmin;
                        root=tmin;
                    }
                }
            }
            else{
                if(node->leftChild!=NULL){
                    Node *x=node->leftChild;
                    //node->parent->leftChild=x;
                    x->parent=NULL;//node->parent;
                    root=x;
                }
                else{
                    Node *x=node->rightChild;
                    x->parent=NULL;
                    root=x;
                }
            }
        }
        delete node;
        if(foundroot){
            root=NULL;
        }
    }
    else
        cout<<"Item not found."<<endl;
}

Node* Tree::treeMinimum(Node *node){
    while(node->leftChild!=NULL){
        node=node->leftChild;
    }
    return node;
}

void Tree::DeleteAll(Node* node){
    if(node->leftChild!=NULL)
        DeleteAll(node->leftChild);
    if(node->rightChild!=NULL)
        DeleteAll(node->rightChild);
    cout<<"Deleting: "<<node->title<<" "<<node->year<<endl;
    delete node;
}

float Tree::averageAge(){
    if(root==NULL){
        return 0;
    }
    float sum=0;
    averagePriv(root,sum);
    int c=0;
    countNodes(root,c);
    sum=float(sum/c);
    return sum;
}

void Tree::averagePriv(Node *node,float &sum){
    if(node->leftChild!=NULL)
        averagePriv(node->leftChild,sum);
    if(node->rightChild!=NULL)
        averagePriv(node->rightChild,sum);
    sum+=(node->quantity*node->year);
}

int Tree::countNodes(){
    if(root==NULL){
        return 0;
    }
    int c=0;
    countNodes(root,c);
    return c;
}

void Tree::countNodes(Node *node,int &nodeCount){
    if(node->leftChild!=NULL)
        countNodes(node->leftChild,nodeCount);
    if(node->rightChild!=NULL)
        countNodes(node->rightChild,nodeCount);
    nodeCount+=node->quantity;
}

int Tree::countSpecific(string name){
    if(root==NULL){
        return 0;
    }
    int c=0;
    countSpecific(root,c,name);
    return c;
}

void Tree::countSpecific(Node *node,int &nodeCount,string name){
    if(node->leftChild!=NULL)
        countSpecific(node->leftChild,nodeCount,name);
    if(node->rightChild!=NULL)
        countSpecific(node->rightChild,nodeCount,name);
    if(node->title==name){
        nodeCount+=node->quantity;
    }
}

void Tree::printInventory(){
    if(root!=NULL)
        printInventory(root); //calls the private printMovieInventory method
    else
        cout<<"Inventory empty"<<endl;
}

void Tree::printInventory(Node *node){ //traverses through the tree recursively
    if(node->leftChild!=NULL){
        printInventory(node->leftChild);
    }
    cout<<"Item: "<<node->title<<", Year: "<<node->year<<", Quantity: "<<node->quantity<<endl;
    if(node->rightChild!=NULL){
        printInventory(node->rightChild);
    }
}

Node* Tree::search(string title,int year){ //searches for a particular value
    Node *node=root;
    while(node!=NULL){
        if(node->title.compare(title) > 0){
            node=node->leftChild;
        }
        else if(node->title.compare(title) < 0){
            node=node->rightChild;
        }
        else{
            while(node->year!=year){
                node=node->rightChild;
                if(node==NULL){
                    return NULL;
                }
            }
            return node;
        }
    }
    return NULL; //otherwise it didn't find it so it returns NULL
}

void Tree::addNode(string title, int releaseYear, int quantity){
    Node *tester=search(title,releaseYear);
    if(tester!=NULL and tester->year==releaseYear){
        tester->quantity++;
        return;
    }
    Node *node=new Node(title,releaseYear,quantity); //initializes the new node's values
    node->leftChild=NULL;
    node->rightChild=NULL;
    node->parent=NULL;
    Node *tmp=root;
    Node *parent=new Node;
    while(tmp!=NULL){ //loops through to find the parent of the node to be added
        parent=tmp;
        if(node->title.compare(tmp->title) < 0){
            tmp=tmp->leftChild;
        }
        else if(node->title.compare(tmp->title) > 0){
            tmp=tmp->rightChild;
        }
        else if(tmp->title==node->title){
            tmp=tmp->rightChild;
        }
    }
    if(root==NULL){
        root=node; //if the root is NULL, the node becomes the root
    }
    else if(node->title.compare(parent->title) < 0){ //add as left child of parent
        parent->leftChild=node;
        node->parent=parent;
    }
    else{ //add as right child
        parent->rightChild=node;
        node->parent=parent;
    }
}

void Tree::findNode(string title,int year){
    if(root==NULL){
        cout<<"Inventory empty"<<endl;
        return;
    }
    Node *node=search(title,year); //calls the search method
    if(node!=NULL){
        cout<<"Item Info:"<<endl;
        cout<<"==========="<<endl;
        cout<<"Type:"<<node->title<<endl;
        cout<<"Year:"<<node->year<<endl;
        cout<<"Quantity:"<<node->quantity<<endl;
    }
    else
        cout<<"Item not found."<<endl;
}

void Tree::rent(string title,int year){
    if(root==NULL){
        cout<<"Inventory empty"<<endl;
        return;
    }
    Node *node=search(title,year); //calls the search method
    if(node!=NULL){
        if(node->quantity!=0){ //does this if there are still movies in stock
            node->quantity--;
            cout<<"Item has been checked out."<<endl;
            cout<<"Item Info:"<<endl;
            cout<<"==========="<<endl;
            cout<<"Type:"<<node->title<<endl;
            cout<<"Year:"<<node->year<<endl;
            cout<<"Quantity:"<<node->quantity<<endl;
            if(node->quantity==0){
                cout<<"Deleting "<<node->title<<" "<<node->year<<endl;
                deleteNode(node->title,node->year);
            }
        }
        else //otherwise the node->quantity is 0 so it is out of stock
            cout<<"Item out of stock."<<endl;
    }
    else
        cout<<"Item not found."<<endl;
}
