//***************************************************************************************************************
//Name: Montana Merkle
//Project Number: 4
//File Name: MerkleMontana_CS255_P4.cpp
//Project Description: This project will utilize a linked list to represent homes visited over a thanksgiving
//Course: CS255
//Instructor: Dr.Jenkins
//***************************************************************************************************************

#include "Thanks.h"

//--------------------------------------------------------------------------------------------------------------
//FUNCTION DECLARATIONS
//--------------------------------------------------------------------------------------------------------------

void PrintMenu();
int GetChoice();
void GetStuff(int &coursenum,string &coursename,string foodlist[],string drinklist[],string &host);

//***************************************************************************************************************
//DRIVER
//***************************************************************************************************************

int main(){
    //define variables
	int coursenum = 0;
    string coursename;
    string foodlist[FSIZE];
    string drinklist[DSIZE];
	string host;
	int choice = 0;	
	int remove = 0;
	string searchhost;
	int searchnum;
	int count;
	
	//create object in course list
	CourseList obj;
	
    //outputs menu and gets choice of user
    PrintMenu();
	choice = GetChoice();

    //*loop taken from project 3*
    while(choice != 7){
        if(choice == 1)
            obj.Print();
            
        if(choice == 2){
			//get user input for the variables
            GetStuff(coursenum,coursename,foodlist,drinklist,host);
			//use the changed variables to insert a new node in list      
			obj.Insert(coursenum,coursename,foodlist,drinklist,host);    
        }
        
        if(choice == 3){
            cout << "Enter a course number you would like to remove: ";
            cin >> remove;
        	obj.Remove(remove);
    	}
    	
        if(choice == 4){
            cout << "Enter a host name you would like to find: ";
            cin >> searchhost;
            if (obj.FindName(searchhost) == nullptr)     
				//if the search item was not found in the list print not found                
				cout << searchhost << " was not found" << endl;
			else
				cout << searchhost << " was found" << endl;
    	}
    	
        if(choice == 5){
            cout << "Enter a course number you would like to find: ";
            cin >> searchnum;
            if (obj.FindNum(searchnum) == nullptr)
				//if the search item was not found in the list print not found
				cout << searchnum << " was not found" << endl;          
			else
				cout << searchnum << " was found" << endl;
		}
		
        if(choice == 6){
        	count = obj.Count();
			//output return of Count()
            cout << "There are currently " << count << " courses in the course list"; cout << endl;     
    	}
			
        //prints menu and gets new choice for menu
        PrintMenu();
        choice = GetChoice();
    }
    
    cout << endl; cout << endl;
    cout << "Done. Happy Thanksgiving!" << endl; cout << endl;
    
    return 0;
}

//--------------------------------------------------------------------------------------------------------------
//FUNCTION DEFINITIONS
//--------------------------------------------------------------------------------------------------------------

//______________________________________________________________________________________________________________
//Function/method Name: GetStuff
//Function/method Description: allows variables of the parameters to be changed by the user
//Return Value: n/a
//Incoming Parameters: parameters representing data in the node that need to be changed from empty
//Outgoing Parameters: changed parameters
//______________________________________________________________________________________________________________

void GetStuff(int &coursenum,string &coursename,string foodlist[],string drinklist[],string &host){
    cout << endl;
	cout << "Enter the Course Number: ";
    cin >> coursenum;

    cout << "Enter the Course Name: ";
    cin >> coursename; 
    
    cout << "Enter your food descriptions: ";
    cout << endl;
    //while loop that gets the food descriptions
	string choicef;
    for(int i = 0; i < FSIZE; i++){
    	cin >> choicef;
		foodlist[i] = choicef;
	}
	
	cout << "Enter your drink descriptions: ";
	cout << endl;
    //while loop that gets the drink descriptions
	string choiced;
	for(int i = 0; i < DSIZE; i++){
		cin >> choiced;
		drinklist[i] = choiced;
	}
    
	cout << "Enter the Host Name: ";
    cin >> host;
    cout << endl;
}

//______________________________________________________________________________________________________________
//Function/method Name: PrintMenu
//Function/method Description: Outputs the selection menu
//Return Value: n/a
//Incoming Parameters: n/a
//Outgoing Parameters n/a
//*taken from project 3*
//______________________________________________________________________________________________________________


void PrintMenu(){
	cout << endl;
	cout << "----------------------Menu----------------------" << endl;
	cout << "1 - Print Course List" << endl;
	cout << "2 - Insert a Course" << endl;
	cout << "3 - Remove a Course" << endl;
	cout << "4 - Search for Course list - Host Name" << endl;
	cout << "5 - Search for Course List - Course Number" << endl;
	cout << "6 - Print Number of Courses" << endl;
    cout << "7 - QUIT" << endl;
    cout << "------------------------------------------------" << endl;
}

//______________________________________________________________________________________________________________
//Function/method Name: GetChoice
//Function/method Description: allows the user to input a selection for the menu and returns it
//Return Value: int representing selection by user
//Incoming Parameters: n/a
//Outgoing Parameters n/a
//*taken from project 3*
//______________________________________________________________________________________________________________

int GetChoice(){
    int choice;
    cout << "Enter a Menu Choice: ";
    cin >> choice;
    while(choice < 0 || choice > 7){
        cout << "INVALID - Enter again: ";
        cin >> choice;
    } 
    return choice;
}