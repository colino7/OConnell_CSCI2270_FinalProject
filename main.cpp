//Colin O'Connell, Rhonda Hoenigman, CSCI 2270, TA Yang Li, Final Project

#include <iostream>
#include "Tree.h"
#include <cstdlib>

using namespace std;

void displayMenu();

int main(){//(main setup used from Professor Hoenigman's solution to assignment 10)
    // Creates a tree
    Tree t;

    // Flag used for exiting menu
    bool quit = false;

    // Used for input
    string inputString1;
    string inputString2;
    string inputString3;
    string inputString4;
    int inputforinsert;
    int inputforinsert2;
    int input;

    while(!quit){
        displayMenu();
        cin >> input;

        //clear out cin
        cin.clear();
        cin.ignore(10000,'\n');

        switch (input){
            //Insert an item
            case 1:
                cout << "Enter type: ";
                getline(cin,inputString1);
                cout << "Enter year: ";
                cin>>inputforinsert;
                t.addNode(inputString1,inputforinsert,1);
                break;
            //Find an item
            case 2:
                cout << "Enter type: ";
                getline(cin,inputString1);
                cout << "Enter year: ";
                cin>>inputforinsert;
                t.findNode(inputString1,inputforinsert);
                break;
            //Check out an item
            case 3:
                cout << "Enter type: ";
                getline(cin,inputString1);
                cout << "Enter year: ";
                cin>>inputforinsert;
                t.rent(inputString1,inputforinsert);
                break;
            //Print the tree contents
            case 4:
                t.printInventory();
                break;
            //Delete an item
            case 5:
                cout << "Enter type: ";
                getline(cin,inputString1);
                cout << "Enter year: ";
                cin>>inputforinsert;
                t.deleteNode(inputString1,inputforinsert);
                break;
            //Count the items
            case 6:
                cout<<"Inventory contains "<<t.countNodes()<<" items"<<endl;
                break;
            //Count amount of a specific type
            case 7:
                cout << "Enter type: ";
                getline(cin,inputString1);
                cout<<"Inventory contains "<<t.countSpecific(inputString1)<<" of type "<<inputString1<<endl;
                break;
            //Calculate average age of inventory items
            case 8:
                cout<<"The average age of the inventory items is "<<t.averageAge()<<endl;
                break;

            case 9:
                cout<<"Enter info for item to edit"<<endl;
                cout<<"Enter type: ";
                getline(cin,inputString1);
                cout<<"Enter year: ";
                getline(cin,inputString2);
                cout<<"Enter edited info"<<endl;
                cout<<"Enter type: ";
                getline(cin,inputString3);
                cout<<"Enter year: ";
                getline(cin,inputString4);
                inputforinsert=atoi(inputString2.c_str());
                inputforinsert2=atoi(inputString4.c_str());
                t.edit(inputString1,inputforinsert,inputString3,inputforinsert2);
                break;
            //Delete all items
            case 10:
                t.DeleteAllPublic();
                break;
            //Display all items of the same type
            case 11:
                t.displayItemsOfCertianType();
                break;
            //Quit
            case 12:
                cout << "Goodbye!" << endl;
                quit = true;
                break;
            // invalid input
            default:
                cout << "Invalid Input" << endl;
                //cin.clear();
                //cin.ignore(10000,'\n');
                break;
        }
    }

    return 0;
}

void displayMenu(){
    cout<<"==============Main Menu=============="<<endl;
    cout<<"1. Add an item"<<endl;
    cout<<"2. Find an item"<<endl;
    cout<<"3. Check out an item"<<endl;
    cout<<"4. Print the inventory"<<endl;
    cout<<"5. Delete an item"<<endl;
    cout<<"6. Count the total inventory"<<endl;
    cout<<"7. Count the amount of a certain type"<<endl;
    cout<<"8. Calculate average age of inventory"<<endl;
    cout<<"9. Edit an item"<<endl;
    cout<<"10. Delete the entire inventory"<<endl;
    cout<<"11. Print all items of same type"<<endl;
    cout<<"12 Quit"<<endl;
    return;
}
