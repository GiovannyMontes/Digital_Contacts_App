/******************************************************
 CIS 22B

   Lab1: [This program allows the user to store contact

        information, allowing the user to

        manipulate by adding, deleting, and printing
        
        contacts.]

 Author: [Giovanny Montes]

 Date: [4-30-20]
 *******************************************************/



#include <iostream>
#include <string>
#include "contactlist.h"

using namespace std;


void UserInterface(ContactList);

int main()
{
    ContactList PhoneBook;
    UserInterface(PhoneBook);
}



/*********************************************
 This function adds, deletes, and prints
 contacts based on the users input
 *********************************************/

void UserInterface(ContactList phoneBook)
{
    int choice;
    string fname, lname, numbr;
    
    do
    {
        cout << "\n\n1. Insert Contact \n";
        cout << "2. Delete Contact \n";
        cout << "3. Print Contacts \n";
        cout << "4. Quit \n\n";
        cout << "Please enter your choice: ";
        cin >> choice;
        
        while(choice < 1 || choice > 4)
        {
            cout << "Please enter valid choice: ";
            cin >> choice;
        }
        
        if(choice == 1)
        {
            cout << "\nPlease enter first name: " << endl;
            cin >> fname;
            cout << "\nPlease enter last name: " << endl;
            cin >> lname;
            cout << "\nPlease enter phone number: " << endl;
            cin >> numbr;
            phoneBook.insertNode(fname, lname, numbr);
        }
        else if(choice == 2)
        {
            cout << "\nEnter First name of contact you would like to delete: ";
            cin >> fname;
            phoneBook.deleteNode(fname);
        }
        else if(choice == 3)
        {
            cout << endl;
            phoneBook.printNode();
        }
        
    } while (choice != 4);
}


/**************************************
 -------------------------------------------
 |            Program Output             |
 -------------------------------------------
 
 1. Insert Contact
 2. Delete Contact
 3. Print Contacts
 4. Quit

 Please enter your choice: 1

 Please enter first name:
 gio

 Please enter last name:
 montes

 Please enter phone number:
 8675978687


 1. Insert Contact
 2. Delete Contact
 3. Print Contacts
 4. Quit

 Please enter your choice: 1

 Please enter first name:
 julie

 Please enter last name:
 smith

 Please enter phone number:
 6500078695


 1. Insert Contact
 2. Delete Contact
 3. Print Contacts
 4. Quit

 Please enter your choice: 2

 Enter First name of contact you would like to delete: gio


 1. Insert Contact
 2. Delete Contact
 3. Print Contacts
 4. Quit

 Please enter your choice: 3

 Name: julie smith
 Phone Number: 6500078695


 1. Insert Contact
 2. Delete Contact
 3. Print Contacts
 4. Quit

 Please enter your choice: 4
 Program ended with exit code: 0
 
 ***************************************/
