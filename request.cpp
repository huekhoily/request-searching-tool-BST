//Author: Hue Khoi Ly
//Email address: huekhoily@gmail.com
//Description: This .cpp file defines function of the request class

#include "request.h"
using namespace std;


//Constructor
request::request(){
	id = nullptr;
	type = nullptr;
	district = nullptr;
	street = nullptr;
	priority = nullptr;
	status = nullptr;
	date = nullptr;
	department = nullptr;
	description = nullptr;
}


//Destructor
request::~request(){
	clear_all();
}


//This function to help delete dynamic memory in the request'
int request::clear_all(){
	if(id){
		delete [] id;
		id = nullptr;
	}	
	if (district){
		delete [] district;
		district = nullptr;
	}
	if (type){
		delete [] type;
		type = nullptr;
	}
	if (street){
		delete [] street;
		street = nullptr;
	}
	if (priority){
		delete [] priority;
		priority = nullptr;
	}
	if (status){
		delete [] status; 
		status = nullptr;
	}
	if (date){
		delete [] date;
		date = nullptr;
	}
	if (department){
		delete [] department;
		department = nullptr;
	}
	if (description){
		delete [] description;
		description = nullptr;
	}
	return 1;
}


//Create function to create the request class by input all of data into the request data type.
//input: string char i, t, d, s, p, st, da,de, and ds
//output: 1 or 0
int request::create(char * i, char * t, char * d, char * s, char * p, char * st, char * da, char * de, char * ds){
	if (!i || !t || !d || !s || !p || !st || !da || !de || !ds){
		return 0;
	}
	if ( id || type || district || street || priority || status || date || department || description){
	       clear_all();
	}
	id = new char [strlen(i) +1];
	type = new char [strlen(t) + 1];
	district = new char [strlen(d) + 1];
	street = new char [strlen(s) + 1];
	priority = new char [strlen(p) + 1];
	status = new char [strlen(st) + 1];
	date = new char [strlen(da) + 1];
	department = new char [strlen(de) + 1];
	description = new char [strlen(ds) + 1];
	strcpy(id, i);
	strcpy(type, t);
	strcpy(district, d);
	strcpy(street, s);
	strcpy(priority, p);
	strcpy(status, st);
	strcpy(date, da);
	strcpy(department, de);
	strcpy(description, ds);
	return 1;
	
}


//This function copy request to another
//input: og as request type
//output: 1 or 0
int request::copy(const request& og){
	return create(og.id, og.type, og.district, og.street, og.priority, og.status, og.date, og.department, og.description);
}


//This function display the request
//input: none
//output: 1 or 0
int request::display() const{
	cout << "ID: " << id << endl;
	cout << "Type: " << type << endl;
	cout << "District: " << district << endl;
	cout << "Street: " << street << endl;
	cout << "Priority: " << priority << endl;
	cout << "Status: " << status << endl;
	cout << "Date: " << date << endl;
	cout << "Department: " << department << endl;
	cout << "Desciption: " << description << endl;
	cout << "-------------------------------------" << endl;
	return 1;
}


//This function compares and retrive one request that matches with the id user input
//input : key as string char, and found as request data type
//output: 1 or 0
int request::retrieve(char * key, request & found)const{
	if (strcmp(key,id) == 0){
		found.create(id,type,district,street,priority,status,date,department, description);
		return 1;
	}
	return 0;
}

int request::islargerthan(const request & r2){
	return strcmp(type,r2.type);
}

int request::isClosed() const{
	if (strcmp(status,"Closed")==0){
		return 1;
	}
	return 0;
}

int request::compare(const char* t){
	char * type_c; //this string contains type after we lowercase all of elements
	type_c = new char [strlen(type)+1];
	int size_type = strlen(type);
	for (int i = 0; i < size_type; i++){
		type_c [i] = tolower(type[i]);
	}
	type_c[size_type] = '\0';

	int result = strcmp(type_c,t);
	delete [] type_c;
	return result;
}
