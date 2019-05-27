/*
8. String to Integer (atoi)			(medium)

	Implement atoi which converts a string to an integer.
	
	The function first discards as many whitespace characters as necessary until the first non-whitespace 
	character is found. Then, starting from this character, takes an optional initial plus or minus sign 
	followed by as many numerical digits as possible, and interprets them as a numerical value.

	The string can contain additional characters after those that form the integral number, which are 
	ignored and have no effect on the behavior of this function.

	If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such 
	sequence exists because either str is empty or it contains only whitespace characters, no conversion is 
	performed.

	If no valid conversion could be performed, a zero value is returned.

Note:

	Only the space character ' ' is considered as whitespace character.
	Assume we are dealing with an environment which could only store integers within the 32-bit signed 
	integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, 
	INT_MAX (231 − 1) or INT_MIN (−231) is returned.

Example 1:

	Input: "42"
	Output: 42

Example 2:

	Input: "   -42"
	Output: -42
	Explanation: The first non-whitespace character is '-', which is the minus sign.
	             Then take as many numerical digits as possible, which gets 42.

Example 3:

	Input: "4193 with words"
	Output: 4193
	Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.

Example 4:

	Input: "words and 987"
	Output: 0
	Explanation: The first non-whitespace character is 'w', which is not a numerical 
	             digit or a +/- sign. Therefore no valid conversion could be performed.

Example 5:

	Input: "-91283472332"
	Output: -2147483648
	Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
	             Thefore INT_MIN (−231) is returned.
*/

#include <iostream>
#include <string>

using namespace std;

int myAtoi(string str) {

	cout << "1 " << str << endl;

	int res = 0; 						// Result of the function
	int size, limit;
	int counter = 0;					// Auxiliar counter
	int i=0;							// Counter for indexes
	
	bool flag = false;					// Flag to end program of functions
	bool positive = true;				// To know if number is positive or negative

	// Delete initial blankspaces 
	while (str[i] == ' ') {
		flag = true;
		counter++;
		i++;
	} if (flag) str.erase(0, counter);

	cout << "2 " << str << endl;

	// If the beggining of the string is alphanumeric end function
	if (isalpha(str[0]) && str[0] != '-') return 0;

	//Get if number is positive or negative
	positive = (str[0] != '-') ? 
		true : false;

	i = (positive) ? 1 : 0;		// To verify if num is negative
	flag = false;						// Restart flag
	counter = 0;						// Restart counter 

	// Get the first numbers, delete the aplhanumeric numbers
	while(isdigit(str[i])) {
		flag = true;
		counter++;
		i++;
	} if (flag) str.erase(counter, str.length()-1);

	cout << "3 " << str << endl;

	// Get size of number in consideration of the '-' char
	size = (positive) ?
		str.length()-1 : str.length();

	// Get when is the string going to count depending of its sign
	limit = (positive) ?
		0 : 1;	

	//Restart counter
	counter = 1;	

	// Case in which is a positive number
	if (positive) {		

		// Construct number
		for (int i=str.length()-1; i>=0; i--) {
			res += (str[i]-48)*counter;
			counter *= 10;
		}
	}

	// Case in which is a negative number
	else {
		for (int i=str.length(); i>0; i--) {
			res += (str[i]-48)*counter;
			counter *= 10;

			cout << i << " ";
			cout << str[i] << endl;
		}
	}

	// Return the value
	return res;
}

int main() {

	string str = "   -42 asddd";

	int number = myAtoi(str);
	cout << endl << endl << number << endl;

	return 0;
}
