//
//  phonebook.cpp
//  phonebook
//
//  Created by Gio Montes on 4/23/20.
//  Copyright © 2020 Gio Montes. All rights reserved.
//

#include "contactlist.h"
#include <string>
#include <iostream>
using namespace std;

/***************************************************************************************
     This function creates a new node with the information give as a parameter and looks
     for the right place to insert it in order to keep the list organized
****************************************************************************************/

void ContactList::insertNode(string first_name, string last_name, string phoneNumber)
{
    ContactNode *newNode;
    ContactNode *nodePtr;
    ContactNode *previousNode = nullptr;

    newNode = new ContactNode;
    
    // inserting data in new node
    newNode->firstName = first_name;
    newNode->lastName = last_name;
    newNode->phoneNumber = phoneNumber;

    if (!head)  // head points to nullptr meaning list is empty
    {
        head = newNode;  // head now points to the new node
        newNode->next = nullptr;
    }
    else // otherwise look for the right place to insert node
    {
        nodePtr = head;
        previousNode = nullptr;
        while (nodePtr != nullptr && nodePtr->firstName < first_name)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if (previousNode == nullptr) // if the new node is to be the first in the list
        {
            head = newNode;
            newNode->next = nodePtr;
        }
        else // otherwise insert after the previous node
        {
            previousNode->next = newNode;
            newNode -> next = nodePtr;
        }
    }
}

/***************************************************************************************
   Delete the node whose information is given as a parameter. If not found, just returns.
****************************************************************************************/

void ContactList::deleteNode(string name)
{
   ContactNode *nodePtr;
    ContactNode *previousNode = nullptr;

   if (!head) // if the list is empty, do nothing
      return;

   if (head->firstName == name)
   {
      nodePtr = head->next;
      delete head;
      head = nodePtr;
   }
   else
   {
      nodePtr = head;
      // skip all nodes whose values don't match
      while (nodePtr != nullptr && nodePtr->firstName != name)
      {
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }
      if (nodePtr) // if nodePtr is not at the end
      {
         previousNode->next = nodePtr->next; // link the previous node to the node after
         delete nodePtr;  // delete the node
      }
   }
}

void ContactList::printNode() const
{
    // to move through list
    ContactNode *nodePtr;
    // position at head of list
    nodePtr = head;
    
    while(nodePtr)
    {
        cout << "Name: " << nodePtr->firstName << " "
        << nodePtr->lastName << endl;
        cout << "Phone Number: " << nodePtr->phoneNumber << endl;
    
    nodePtr = nodePtr->next;
    }
    
    
    /***************************************************************************************
            This function destroys a linked list one one node at a time
       ****************************************************************************************/
    
}
ContactList::~ContactList()
{
        ContactNode *nodePtr;
        ContactNode *nextNode;
        nodePtr = head;

        while (nodePtr != nullptr)
        {
            nextNode = nodePtr->next; // save the pointer to the next node
            delete nodePtr;  // delete the current node
            nodePtr = nextNode; // move on the next node on the list
        }
}
