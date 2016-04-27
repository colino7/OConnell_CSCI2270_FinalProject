# OConnell_CSCI2270_FinalProject
Final Project for Data Structures at CU Boulder Spring 2016
I will be taking the Binary Search Tree assignment from class and modifying it to have different data and also I will be adding methods to it. I will not be doing this with a partner.

Project Summary: 
The program is a binary search tree that starts empty. The basic idea is that there is an inventory of items that you can perform different operations on including: adding an item, finding an item, checking out an item, printing the inventory, deleting an item, counting the total inventory, counting the amount of a certain type, calculating the average age of the inventory, editing an item, and deleting the entire inventory. When adding an item, the user inputs its type and year and it is automatically added to the tree with a quantity of 1. If an item is added that has the same type and year as a pre-existing item in the tree, the quantity of the pre-existing item is just incremented. If an item is added that has the same type but a different year, it is added as a unique item in the tree. If an item is checked out and its quantity is now 0, the item is automatically deleted from the tree. When the program quits, the destructor calls the delete method and the memory for the tree is freed. The other methods perform as would be expected.

How to Run: 
You will need the following files: main.cpp, Tree.h, and Tree.cpp. These are the 3 files that make up the program. I have also included the other files included for a project on Code::Blocks. Simply run the program (no file is read in and there is no command line argument) and the menu will pop up with 11 options including the option to quit. After each option is performed, the menu will keep coming back until the option to quit is selected. When the menu comes up, simply enter the number corresponding to the option you want to perform, such as 5 for deleting an item. It will prompt you for a type and then hit enter and it will then prompt for a year and then you hit enter and it will delete that item if it exists in the tree. Each option has different inputs needed and some do not require any inputs such as 4 for printing the inventory which it will do automatically after entering 4.

Dependencies: 
No real dependencies. The project files (.cbp) are for Code::Blocks but if the user does not want to use Code::Blocks they just need the 3 files mentioned in the How to Run section.

System Requirements: 
Built the program on Linux (virtual machine) but I believe it should work on any operating system.

Group Members: 
None

Contributors: 
None

Open Issues/Bugs: 
No known bugs. If no bugs are found (which I bet bugs will be found) I would be open to other better methods to perform on the tree.
