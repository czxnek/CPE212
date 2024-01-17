/*
Program Chapter 3
CS 214-03
Caleb Keller
Description: Performs Factorial and Fibonacci calculations recursively
*/

#include <iostream>
#include <string>
#include <stdlib.h> // to use exit function

using namespace std;

void menu();
void factorial(int& num1, int& factnum);
void fibonacci(int& num2);


int main()
{
	bool endLoop;
	endLoop = false; // test for ending loop
	int cho; // selection function paramter
	int n1; // catch for num1 from function
	int n2; // catch for num2 from function
	int numfact; // catch for factnum from function

	do {

		menu(); // prompting menu
		cout << "Please enter your selection: ";
		cin >> cho;
		cout << endl;

		while (cho > 2) // test for valid selection 
		{
			cout << "ERROR! Please select 0, 1, or 2!" << endl;
			menu();
			cout << "Please enter your selection: ";
			cin >> cho;
			cout << endl;
		}
		while (cho < 0) // test for valid selection
		{
			cout << "ERROR! Please select 0, 1, or 2!" << endl;
			menu();
			cout << "Please enter your selection: ";
			cin >> cho;
			cout << endl;
		}

		if (cho == 1) // factorial selection
		{
			factorial(n1, numfact);		
		}

		if (cho == 2) // fibonacci selection
		{
			fibonacci(n2);
			
		}
		
		if (cho == 0) // exit selection
		{
			cout << "Exiting program.................." << endl << endl;

			endLoop = true;
			break; // endLoop is true, breaks out of loop and exits program
		}

	} while (endLoop != true);

	exit(0); // kills program
}

void menu()
{
	cout << endl << "********* Factorial and Fibonacci Calculator *********" << endl;
	cout << "Please make a selection." << endl;
	cout << "=> 1) Factorial Calculator" << endl;
	cout << "=> 2) Fibonacci Calculator" << endl;
	cout << "=> 0) Exit Program" << endl;
	cout << "******************************************************" << endl << endl;
}

void factorial(int& num1, int& factnum)
{
	cout << "Please enter a positive number: ";
	cin >> num1;

	while (num1 < 0)
	{
		cout << endl << "ERROR! NEGATIVE NUMBER!" << endl << endl;
		cout << "Please enter a positive number: ";
		cin.clear(); // clearing buffer to prevent infinite loop
		cin >> num1;
		cout << endl;
	}
	while (num1 >= 12) // anything above 12! is too large 
	{
		cout << endl << "ERROR! Resulting number too large for 32-bits!" << endl << endl;
		cout << "Please enter a smaller number: ";
		cin.clear();
		cin >> num1;
		cout << endl;
	}

	factnum = 1;

	cout << "Factorial for " << num1 << " is ";
	for (int n = 1; n <= num1; n++)
	{
		// check to make sure factnum does not over flow 4294967295
		factnum = factnum * n;
		cout << factnum << " ";

	}
	
	cout << endl;
	

}

void fibonacci(int& num2)	// pass by reference
{
	cout << "Please enter a positive number: ";
	cin >> num2;

	while (num2 < 0)
	{
		cout << endl << "ERROR! NEGATIVE NUMBER!" << endl << endl;
		cout << "Please enter a positive number: ";
		cin >> num2;
	}

	unsigned long curr = 1, next = 1, prev = 0;

	cout << endl << "Fibonacci sequence for " << num2 << " is " << prev << " "; // 0  before the calculations are started
	cout << curr << " "; // 1

	while (next <= num2) // calculate until the integer that the user typed in is reached
	{
		cout << next << " ";
		prev = curr; // set the next and previous nums
		curr = next; // set the next and previous nums
		next = prev + curr;	// add the previous 2 nums together

	}
	cin.clear(); 
	cout << endl;
	
}