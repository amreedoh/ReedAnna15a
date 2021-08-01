/*
Anna Reed
7/31/2021
CIS 1202
*/

#include <string>
#include <iostream>
#include <cctype>

using namespace std;

char character(char, int);

int main(){

	char start, end;
	int offset;

	cout << "Enter letter: ";
	cin >> start;
	cout << "Enter offset number: ";
	cin >> offset;

	try {
		end = character(start, offset);
		cout << "\nNew letter: " << end;
	}
	catch (double invalidCharacterException) {
		cout << "\nERROR: Invalid Character";
	}
	catch (int invalidRangeException) {
		cout << "\nERROR: Out of Range";
	}

	return 0;
}

char character(char start, int offset) {
	  
	double invalidCharacterException = -9.3;
	int invalidRangeException = -8,
		startDec, validDec;

	//makes sure that offset doesnt push end beyond ASCII limits (0-127)
	startDec = static_cast<int> (start);
	validDec = startDec + offset;

	if (validDec > 127 || validDec < 0) {
		throw invalidRangeException;
	}

	//start of checking the offset for validity
	char end = start + offset;

	//checks for if char is a letter
	if (!isalpha(start)) {
		throw invalidCharacterException;
	}
	//checks if char is a letter
	else if (!isalpha(end)) {
		throw invalidRangeException;
	}
	//checks to make sure there is no transition between upper and lower case
	else if (  islower(start) && isupper(end) ) {
		throw invalidRangeException;
	}
	else if (  isupper(start) && islower(end)  ) {
		throw invalidRangeException;
	}
	//if no exceptions thrown end is returned
	else
		return end;

}