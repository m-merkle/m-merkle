//***************************************************************************************************************
//Name: Montana Merkle
//Project Number: 4
//File Name: Thanks.h
//Project Description: This project will utilize a linked list to represent homes visited over a thanksgiving
//Course: CS255
//Instructor: Dr.Jenkins
//***************************************************************************************************************

#include <iostream>
#include <cstring>
using namespace std;

#ifndef _THANKS_H
#define _THANKS_H

//********************************************************************************************************************
//CLASS DECLARATIONS
//********************************************************************************************************************

//constant size of the array for food and drinks
const int FSIZE = 5;
const int DSIZE = 3;

class Node{
    //data members
    int data;                    //represents course number
    string cname;                //represents course name
    string food[FSIZE];          //represents array of food descriptions
    string drink[DSIZE];         //represents array of drink descriptions
    string hname;                //represents host name
    Node* next;                  //points to the next node
    //constructors
public:
    Node();
    Node(int d, string c, string f[], string liquids[], string h, Node* n);
    Node(int d, string c, string f[], string liquids[], string h);
    friend class CourseList;
};

class CourseList{
    Node* head;
public:
	//destructor
	~CourseList();  
	//copy constructor
	CourseList(const CourseList& right);
	//assignment operator
	CourseList& operator=(const CourseList& right);
	//methods
    CourseList();
    bool Insert(int item, string c, string f[], string liquids[], string h);
    bool Remove(int item);
    Node* FindNum(int item)const;
    Node* FindName(string item)const;
    void Print()const;
    int Count()const;
};


#endif