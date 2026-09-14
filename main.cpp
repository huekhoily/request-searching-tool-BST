//Author: Hue Khoi Ly
//Email address: huekhoily@gmail.com
//Description: The client program interact with the public functions, and testing the code

#include "BST.h"
#include <fstream>

using namespace std;

const int SIZE = 100;

int main(){
	cout << "Welcome to the request searching program!!" << endl;
	ifstream inFile; //helps to read the file
	request add; //this request variable help us to put it into the table or retrive it
	tree table; //This table stores the data according to the request id
	char filename[SIZE]; //This string holds the file name to help us open the file
	char i[SIZE]; //Those string holds input that the input will come into the request class
	char t[SIZE];
	char d[SIZE];
	char s[SIZE];
	char p[SIZE];
	char st[SIZE];
	char da[SIZE];
	char de[SIZE];
	char ds[SIZE];
	int count = 0; //This variable contains the number of requests in each function
	int h = 0; //This variable contains the numbers of request from the leaf to the root
	int opt = 0; //This variable contains the option of user when they interact with the menu

	cout << "Please enter the filename: " << flush;
	cin.get(filename,SIZE,'\n'); cin.ignore(SIZE, '\n');
	inFile.open(filename);
	if (!inFile){
		cout << "Could not open the file " << filename << endl;
		return 0;
	}
	while(inFile.get(i,SIZE,'|')){
		inFile.ignore();
		inFile.get(t,SIZE,'|'); inFile.ignore();
		inFile.get(d,SIZE,'|'); inFile.ignore();
		inFile.get(s,SIZE,'|'); inFile.ignore();
		inFile.get(p,SIZE,'|'); inFile.ignore();
		inFile.get(st,SIZE,'|'); inFile.ignore();
		inFile.get(da,SIZE,'|'); inFile.ignore();
		inFile.get(de,SIZE,'|'); inFile.ignore();
		inFile.get(ds,SIZE,'\n'); inFile.ignore(SIZE, '\n');
		if (!add.create(i,t,d,s,p,st,da,de,ds)){
			cout << "cannot create the request!" << endl;
		}
		if (!table.insert(add)){
			cout << "Cannot add into the table 1!!!" << endl;
		}
	}
	inFile.close();
	cout << "Already input file into the program!!" << endl;
	do{
		cout << "Please chose from 1 - 6 to interact with the program" <<
			"\n1. Put more request into the system!" <<
			"\n2. Display the request according to request type" <<
			"\n3. Remove a particular request type based on if the status was Closed" <<
			"\n4. Retrieve the information for a particular request id" <<
			"\n5. Display all requests of a particular type" <<
			"\n6. Determine the height of the tree" <<
			"\n7. Quit" << endl;
		cout << ">> " << flush;
		cin >> opt;
		cin.ignore(SIZE,'\n');
		while (!cin){
			cin.clear();
			cin.ignore(SIZE,'\n');
			cout << "Please enter the integer number to choose" << endl;
			cout << ">> " << flush; 
			cin >> opt;
			cin.ignore(SIZE, '\n');
		}
		switch(opt){
			case 1:
				cout << "Please enter ID: " << flush;
				cin.get(i,SIZE, '\n'); cin.ignore(SIZE,'\n');
				cout << "Please enter type of request: " << flush;
				cin.get(t,SIZE,'\n'); cin.ignore(SIZE, '\n');
			
				cout << "Please enter the district: " << flush;
				cin.get(d,SIZE,'\n'); cin.ignore(SIZE, '\n');
				cout << "Please enter the street: " << flush;
				cin.get(s,SIZE,'\n'); cin.ignore(SIZE, '\n');
				cout << "Please enter the level of priority(1-5): " << flush;
				cin.get(p,SIZE,'\n'); cin.ignore(SIZE, '\n');
				cout << "Please enter the status of the request: " << flush;
				cin.get(st,SIZE,'\n'); cin.ignore(SIZE, '\n');
				cout << "Enter the date of the request: " << flush;
				cin.get(da,SIZE,'\n'); cin.ignore(SIZE, '\n');
				cout << "Enter the relevant department: " << flush;
				cin.get(de,SIZE,'\n'); cin.ignore(SIZE, '\n');
				cout << "Enter short description: " << flush;
				cin.get(ds,SIZE,'\n'); cin.ignore(SIZE, '\n');
				if (!add.create(i,t,d,s,p,st,da,de,ds)){
						cout << "Cannot create request!" << endl;
				}
				if (!table.insert(add)){
					cout << "Cannot add into the table!!!" << endl;
				}
				break;
			case 2:
				if (!table.display_all()){
					cout << "Cannot print the table" << endl;
				}
				break;
			case 3:
				cout << "Please enter the request type you would liek to delete: " << flush;
				cin.get(t,SIZE,'\n'); cin.ignore(SIZE,'\n');
				
				count = table.remove_closed(t);
				if (count == 0){
					cout << "Cannot find any matches to delete!!" << endl;
				}
				else{
					cout << "Already deleted " << count << " request(s)" << endl;
				}
				break;
			case 4:
				cout << "Please enter the id that you would like to search: " << flush;
				cin.get(i,SIZE,'\n'); cin.ignore(SIZE,'\n');
				if (!table.peek(i,add)){
					cout << "Cannot find it in this table" << endl;
				}
				else{
					cout << "Already retrieved " << endl;
					cout << "The request you retrive: " << endl;
					add.display();
					cout << "you could do more with this request by call functions with /add.function/" << endl;
					cout << "-------------------------------------------------------------------------" << endl;
				}
				break;
			case 5:
				cout << "Please enter the request type you would like to see: " << endl;
				cin.get(t,SIZE,'\n'); cin.ignore(SIZE,'\n');
				if (!table.display_t(t)){
					cout << "Cannot display!!!" << endl;
				}
				break;
			case 6:
				h = table.height();
				if (h == 0){
					cout << "Cannot measure the height!!" << endl;
				}
				else{
					cout << "This is the height of the tree: "<< h << endl;
				}
				break;
			default:
				break;
		}
	}while (opt == 1 || opt == 2 || opt == 3 || opt == 4 || opt == 5 || opt == 6);
	cout << "Thank you for using our program !!" << endl;
	return 0;
}


