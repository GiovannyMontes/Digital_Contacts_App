//
//  phonebook.hpp
//  phonebook
//
//  Created by Gio Montes on 4/23/20.
//  Copyright © 2020 Gio Montes. All rights reserved.
//

#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include <stdio.h>
#include <string>
using namespace std;

class ContactList{
private:
    struct ContactNode
    {
        string firstName;
        string lastName;
        string phoneNumber;
       struct ContactNode *next;
    };
    
    ContactNode *head;
public:
    ContactList()
    { head = nullptr; }
    ~ContactList();
    
    void insertNode(string, string, string);
    void deleteNode(string);
    void printNode() const;
 
};

#endif /* CONTACTLIST_H */
