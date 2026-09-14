//Author: Hue Khoi Ly
//Email address: huekhoily@gmail.com
//Description: This is .h file to set the request data entry class.

#include <iostream>
#include <cctype>
#include <cstring>

class request{
	public:
		request();
		~request();
		int create(char * i, char * t, char * d, char * s, char * p, char * st, char * da, char * de, char * ds);
		int copy(const request& original);
		int display() const;
		int retrieve(char * key, request & found) const;
		int islargerthan(const request& r2);
		int isClosed () const;
		int compare(const char* t);
	private:
		char * id;
		char * type;
		char * district;
		char * street;
		char * priority;
		char * status;
		char * date;
		char *department;
		char * description;

		int clear_all();
};

