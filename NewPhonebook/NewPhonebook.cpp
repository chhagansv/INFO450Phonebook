// NewPhonebook.cpp : Defines the basic functions of a telephone directory.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

#define MAX_CONTACTS 10

struct Contact
{
	char first[20];
	char last[30];
	char number[16];
};

class PhoneBook
{
	Contact contact;
public:
	bool CreateMe() { if (contact.first[0] == '\\') return true; else return false; };
	void Edit();
	void Delete() { contact.first[0] = '\\'; };
	void Print(bool showall);
	bool SearchContact(char SearchThis[60]);
};

void PhoneBook::Edit()
{
	cout << endl << "First Name: ";
	cin >> contact.first;

	cout << endl << "Last Name: ";
	cin >> contact.last;

	cout << endl << "Number: ";
	cin >> contact.number;

	cout << "OK." << endl;
}

void PhoneBook::Print(bool showall)
{
	cout << endl << "First Name: " << contact.first
		<< endl << "Last Name: " << contact.last;
	if (showall) {
		cout << endl << "Number: " << contact.number
			<< endl << "---" << endl << "OK." << endl;
	}
}

bool PhoneBook::SearchContact(char searchThis[60])
{
	if (!strcmp(contact.first, searchThis)) { return true; }
	else if (!strcmp(contact.last, searchThis)) { return true; }
	else if (!strcmp(contact.number, searchThis)) { return true; }
	else { return false; };
}

inline void clearscreen()
{
	system("CLS");
	cout << "Phonebook Directory" << endl
		<< "--------------------------------" << endl << endl;
}

int main()
{
	PhoneBook book[MAX_CONTACTS];
	char Menuoption = '0';
	int i;
	char buff[60];
	bool found;

	for (int j = 0; j<MAX_CONTACTS; j++)
		book[j].Delete();

	clearscreen();

	while (Menuoption != '4')
	{
		found = false;
		i = 0;

		cout << "1. Create New Contact" << endl;
		cout << "2. Search a Contact" << endl;
		cout << "3. Save All Data" << endl;
		cout << "4. Terminate program" << endl;

		cout << endl << "Selection: ";
		cin >> Menuoption;

		switch (Menuoption)
		{
		case '1':

			do
			{
				if (book[i].CreateMe()) {
					book[i].Edit();
					found = true;
				}
				i++;
			} while (i < MAX_CONTACTS && !found);
			break;

		case '2':
			cout << endl << "Search: " << endl;
			cin >> buff;

			if (book[i].SearchContact(buff) && !book[i].CreateMe())
			{
				book[i].Print(true);
				cout << endl;
			}
			else
			{
				i++;
			}
			break;
			cout << endl << "Type a number to continue ";
			cin >> i;

		case '3':
			break;
		}
	}
	cout << endl << endl << "END. " << endl;
	system("PAUSE");
	return 0;
}
