/**************************************************
Name: Tenay Barker
Date: 9/13/2017
Class: CSC 331
Description: Will create a array of char pointers that will represent memory locations, as given 
by the instructor. As the programmer I will implement the Add, Remove, and Print methods for the array.
Files: no input files
Output: Sample output below:

	Table created

	-------------------------
	(A)dd to the table.
	(R)emove from the table.
	(D)isplay contents of memory.
	(E)xit program.
	Enter choice: d
	{0:FREE, 1:FREE, 2:FREE, 3:FREE, 4:FREE, 5:FREE, 6:FREE, 7:FREE, 8:FREE, 9:FREE}
	-------------------------
	(A)dd to the table.
	(R)emove from the table.
	(D)isplay contents of memory.
	(E)xit program.
	Enter choice: a
	Enter a string fewer than 100 characters.
	hello world
	-------------------------
	(A)dd to the table.
	(R)emove from the table.
	(D)isplay contents of memory.
	(E)xit program.
	Enter choice: a
	Enter a string fewer than 100 characters.
	another string
	-------------------------
	(A)dd to the table.
	(R)emove from the table.
	(D)isplay contents of memory.
	(E)xit program.
	Enter choice: d
	{0:hello world, 1:another string, 2:FREE, 3:FREE, 4:FREE, 5:FREE, 6:FREE, 7:FREE, 8:FREE, 9:FREE}
	-------------------------
	(A)dd to the table.
	(R)emove from the table.
	(D)isplay contents of memory.
	(E)xit program.
	Enter choice: r
	Which location (index) do you want to free?
	9
	Location is already empty...
	-------------------------
	(A)dd to the table.
	(R)emove from the table.
	(D)isplay contents of memory.
	(E)xit program.
	Enter choice: r
	Which location (index) do you want to free?
	1
	-------------------------
	(A)dd to the table.
	(R)emove from the table.
	(D)isplay contents of memory.
	(E)xit program.
	Enter choice: d
	{0:hello world, 1:FREE, 2:FREE, 3:FREE, 4:FREE, 5:FREE, 6:FREE, 7:FREE, 8:FREE, 9:FREE}
	-------------------------
	(A)dd to the table.
	(R)emove from the table.
	(D)isplay contents of memory.
	(E)xit program.
	Enter choice: e
***************************************************/

#include <iostream>
#include <string>
#include <cstring>

using std::cout;
using std::string;
using std::cin;
using std::endl;

//Implement the functions up here.
void addFile(char *fileTable[], int SIZE);
void removeFile(char *fileTable[], int SIZE);
void printTableContents(char *fileTable[],int SIZE);

//main
int main(int argc, char **argv)
{
	const int SIZE = 10;
	char *filetable[SIZE];
	
	for (int i = 0; i < SIZE; i++)
		filetable[i] = NULL;
	cout << "Table created" << endl;
	bool loop = true;
	char choice;
	do
	{
		cout << "-------------------------\n";
		cout << "(A)dd to the table.\n";
		cout << "(R)emove from the table.\n";
		cout << "(D)isplay contents of memory.\n";
		cout << "(E)xit program.\n";
		cout << "Enter choice: ";
		cin >> choice;
		cin.ignore(1000, '\n');

		switch (choice)
		{
		case 'A':
		case 'a':
			//TODO: Implement this function call
			addFile(filetable, SIZE);
			break;
		case 'R':
		case 'r':
			//TODO: Implement this function call
			removeFile(filetable, SIZE);
			break;
		case 'D':
		case 'd':
			//TODO: Implement this function call
			printTableContents(filetable, SIZE);
			break;
		case 'E':
		case 'e':	
			cout << "{Leaving table}" << endl;
		default:
			loop = false;
			break;
		}
	} while (loop == true);

	return 0;
}

//adds file to array
void addFile(char *fileTable[], int SIZE)
{
	//index for array
	int indx;
	//finds open index in file array
	for(indx = 0; indx < SIZE; indx++)
	{
		if(fileTable[indx] == NULL)
			break;
	}
	//inputs char array into file array
	if(indx < SIZE)
	{
		//creates char array for the user input
		fileTable[indx] = new char[100];
		//prompts user for string
		cout << "Enter a String fewer than 100 characters " << endl;
		//grabs string from console
		cin.getline(fileTable[indx], 100);
	}
	else
	{
		cout << "Array is full, you need to remove a file" << endl;
	}
	
}
//removes file from array
void removeFile(char *fileTable[], int SIZE)
{
	//creates int to hold which space the user wants to free
	int inputRmv = 0;
	cout << "Which location(index) do you want to free?" << endl;
	cin >> inputRmv;
	//checks to see if space is empty or full
	if(fileTable[inputRmv] == NULL)
	{
		cout << "Location is already empty..." << endl;
	}
	else
	{
		//remove file from array
		delete [] fileTable[inputRmv];
		fileTable[inputRmv] = NULL;
	} 
}
//prints out the array
void printTableContents(char *fileTable[], int SIZE)
{
	//prints out what is stored in the array
	for(int x = 0; x < SIZE; x++)
	{
		if(fileTable[x] == NULL)
		{
			cout << x << ":FREE ";
		}
		else
		{	
			cout << x << ":" << fileTable[x] << ", ";
		}
	}
	cout << endl;
}