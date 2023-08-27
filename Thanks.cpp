//***************************************************************************************************************
//Name: Montana Merkle
//Project Number: 4
//File Name: Thanks.cpp
//Project Description: This project will utilize a linked list to represent homes visited over a thanksgiving
//Course: CS255
//Instructor: Dr.Jenkins
//***************************************************************************************************************

#include "Thanks.h"

//*****************************************************************************************************************
//CLASS DEFINITIONS
//*****************************************************************************************************************

//------------------------------------------------------------------------------------------------------------------
//Constructor Definitions
//------------------------------------------------------------------------------------------------------------------

//constructor for node with no parameters
Node::Node(){
	next = nullptr;
}

//constructor for node with data, course, food, drink, and host
Node::Node(int d, string c, string f[], string liquids[], string h):data(d),cname(c),hname(h),next(nullptr){
	for(int i = 0; i < FSIZE; i++)
		food[i] = f[i];
		
	for(int i = 0; i < DSIZE; i++)
		drink[i] = liquids[i];
}

//constructor for node with data, course, food, drink, host, and next location in parameter
Node::Node(int d, string c, string f[], string liquids[], string h, Node* n):data(d),cname(c),hname(h),next(n){
	for(int i = 0; i < FSIZE; i++)
		food[i] = f[i];
		
	for(int i = 0; i < DSIZE; i++)
		drink[i] = liquids[i];
}

//friend class definition
CourseList::CourseList(){
	//sets default to empty list
	head = nullptr;
}

//------------------------------------------------------------------------------------------------------------------
//Destructor Definition
//------------------------------------------------------------------------------------------------------------------

//*taken from LinkedList files from class*
CourseList::~CourseList(){ 
	
	//while the list is not empty keep going through and deallocating    
    while(head != nullptr){
       Node* temp = head;
       temp->data;
       head = head -> next;
       delete temp;
    }
}

//------------------------------------------------------------------------------------------------------------------
//Copy Constructor Definition
//------------------------------------------------------------------------------------------------------------------

//*taken from LinkedList files from class with minor changes*
CourseList::CourseList(const CourseList& right){
	
	//if list in parameter is empty than set the list to empty
	if(right.head == nullptr)
        head = nullptr;
    
	else{
        Node* curRight = right.head;
        Node* curLeft = nullptr;
        
		//sets the head to point to a new node that has the data from the node the parameter head points to
        head = new Node(curRight->data, curRight->cname, curRight->food, curRight->drink, curRight->hname);
        curLeft = head; 
        curRight = curRight->next;
        
        //while the parameter list is not at the end - continue the list
        while(curRight != nullptr){
           curLeft->next = new Node(curRight->data, curRight->cname, curRight->food, curRight->drink, curRight->hname);
           curRight = curRight->next;
           curLeft = curLeft->next;
        }
    }
}

//------------------------------------------------------------------------------------------------------------------
//Assignment Operator Definition
//------------------------------------------------------------------------------------------------------------------

//*taken from LinkedList files from class with minor changes*
CourseList& CourseList::operator=(const CourseList& right){
	
	//checks that the lists are not the same
	if(this != &right){
		
		//while the list is not empty keep deallocating
		while(head != nullptr){                                  
			Node* temp = head;                                   
			temp->data;                                         
			head = head -> next;                               
			delete temp;                                        
		}
		
		//if the list in the parameter is empty set list to empty
		if(right.head == nullptr)                             
        	head = nullptr;                                      

	   	else{           
        	Node* curRight = right.head;                         
        	Node* curLeft = nullptr;                             
        	
			//sets the head to point to a new node that has the data from the node the parameter head points to
        	head = new Node(curRight->data, curRight->cname, curRight->food, curRight->drink, curRight->hname);                     
    	    curLeft = head;                                     
  		    curRight = curRight->next;                           
  		    
			//while the parameter list is not at the end - continue the list
			while(curRight != nullptr){                          
    	    	//creates a new node following the head of the list to be assigned to the value of the first node in parameter list
    	       curLeft->next = new Node(curRight->data, curRight->cname, curRight->food, curRight->drink, curRight->hname);         
        	   curRight = curRight->next;                       
        	   //setting the node pointer for the assignment list to the node just created
    		   curLeft = curLeft->next;                          
       		}                                                   
   	    }	
    }
    //returns node pointer
	return *this;
	
}

//------------------------------------------------------------------------------------------------------------------
//Method Definitions
//------------------------------------------------------------------------------------------------------------------

//______________________________________________________________________________________________________________
//Function/method Name: Remove
//Function/method Description: allows a node to be removed from the list
//Return Value: true or false
//Incoming Parameters: item representing course number of the node to be removed
//Outgoing Parameters n/a
//*taken from LinkedList files from class with minor changes*
//______________________________________________________________________________________________________________

bool CourseList::Remove(int item){
    //sets automatic return to true
	bool success = true;
	
	//if the list is empty; print error and return false
    if(head == nullptr){
        cout << "INVALID - empty list" << endl;
        success = false;
    }   
	
	//if the node to be removed is the first node in the list than delete
    else if(item == head->data){
        Node* temp = head;
        //moves head to where the node points to (next node)
        head = head->next;
        //deletes node to be removed
        delete temp;
    }    
    
    else{
        Node* temp = head;
        Node* prev = nullptr;
        //while the list is not empty and the node to be removed is not where head points
        while(temp != nullptr && item != temp->data){
            //moves through the list and ends up with temp at the location of the node to be removed if in list
			prev = temp;
            temp = temp->next;
        }
        
        //if the item is not in the list than print error and set return to false
        if(temp == nullptr){
            cout << "INVALID - item not found" << endl;
            success = false;
        }
        
        else{
            //deletes node to be removed if found in the middle or end of the list
			prev->next = temp->next;
            delete temp;
        } 
    } 
    
    //return true or false
    return success;
}

//______________________________________________________________________________________________________________
//Function/method Name: Insert
//Function/method Description: allows a new node to be inserted into the list
//Return Value: true or false
//Incoming Parameters: item representing data in the new node
//Outgoing Parameters n/a
//*taken from LinkedList files from class with minor changes*
//______________________________________________________________________________________________________________

bool CourseList::Insert(int item, string c, string f[], string liquids[], string h){
    //sets automatic return to true
	bool success = true;
	
	//if list is empty or item to be inserted is less than first node than insert at front
    if (head == nullptr || item < head->data){
       head = new Node(item, c, f, liquids, h,head);
    }
    
    else{
        Node *temp = head;
        Node *prev = nullptr;
        //while list is not empty and item to be inserted is greater than next node
        while (temp != nullptr && item > temp->data){
        	//sets prev to the location of the node directly before where the new node should be inserted
            prev = temp;
            temp = temp->next;
        }
	
		//creates new node with the data and sets it to point to the next node in the list
        prev->next = new Node(item, c, f, liquids, h,temp);
    }
	
	//return true or false
    return success;
}

//______________________________________________________________________________________________________________
//Function/method Name: FindName
//Function/method Description: searches through the list for a specific course name
//Return Value: Node pointer or nullptr
//Incoming Parameters: string representing course name to be searched for
//Outgoing Parameters n/a
//*taken from LinkedList files from class with minor changes*
//______________________________________________________________________________________________________________

Node* CourseList::FindName(string item)const{
    Node* temp = head;
    //while the head is not at the end of the list keep searching the list
    while (temp != nullptr){
       if (temp -> cname == item)
          return temp; //item found in the list
        temp = temp -> next;
    }
    return nullptr; //item not found in the list
}

//______________________________________________________________________________________________________________
//Function/method Name: FindNum
//Function/method Description: searches through the list for a specific course number
//Return Value: Node pointer or nullptr
//Incoming Parameters: item representing course number to be searched for
//Outgoing Parameters n/a
//*taken from LinkedList files from class with minor changes*
//______________________________________________________________________________________________________________

Node* CourseList::FindNum(int item)const{
    Node* temp = head;
    //while the head is not at the end of the list keep searching the list
    while (temp != nullptr){
       if (temp -> data == item)
          return temp; //item found in the list
        temp = temp -> next;
    }
    return nullptr; //item not found in list
}

//______________________________________________________________________________________________________________
//Function/method Name: Print
//Function/method Description: prints the current course list
//Return Value: n/a
//Incoming Parameters: n/a
//Outgoing Parameters n/a
//______________________________________________________________________________________________________________

void CourseList::Print()const{                                         
    //sets a node pointer to the beginning of the list
	Node* temp = head;   
	
	//loops until the list is empty
    while(temp!=nullptr){  
    	cout << endl;
		//prints the current data in the node and moves to next
        cout << "Course Number: " << temp->data; cout << endl;
        cout << "Course Name: " << temp->cname; cout << endl;
        
		cout << "Food Descriptions: ";
        //for loop that prints contents of food descriptions
        for(int i = 0; i < FSIZE; i++)
        	cout << temp->food[i] << ", ";
        cout << endl;
        
        cout << "Drink Descriptions: ";
        //for loop that prints contents of drink descriptions
        for(int i = 0; i < DSIZE; i++)
        	cout << temp->drink[i] << ", ";
        cout << endl;
        
        cout << "Host Name: " << temp->hname; cout << endl;
        cout << "____________________________________________________________________________________"; cout << endl;
        
        //moves temp to the next node in the list
        temp = temp->next;           
    }
}

//______________________________________________________________________________________________________________
//Function/method Name: Count
//Function/method Description: counts the number of nodes in the list
//Return Value: int with number of nodes
//Incoming Parameters: n/a
//Outgoing Parameters n/a
//______________________________________________________________________________________________________________

int CourseList::Count()const{
	int count = 0;
	
	//if list is empty than count is 0
	if(head==nullptr)
		count = 0;
		
	else{
		Node* temp = head;
		//while the list is not at the end/empty than add to the count and move temp to next node in list
		while(temp != nullptr){
	        temp = temp -> next;
			count++;
	    }
	}
	
	//return count int
	return count;
}