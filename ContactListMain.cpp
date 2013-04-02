#include "stdafx.h"
#include "ContactList.h"

int _tmain(int argc, _TCHAR* argv[])
{
	ContactList contacts;
	bool stop = false;
	int option = 0; 
	char optionTemp[80]; 
	char charTemp[80];
	contacts.loadFile();

	cout << "Welcome to the Contact List App" << endl << endl; 

	do
	{
		cout << "Please choose an option from the menu: \n" 
			<< "1 to Add a Contact\n" 
			<< "2 to Print the Full Contact List\n"
			<< "3 to Select a Contact by Last Name\n" 
			<< "4 to Select a Contact by Email\n"
			<< "5 to Select a Contact by Zip Code\n"
			<< "6 to Save and Exit\n\n" ;

		do 
		{

			cout << "What would you like to do (enter 1 - 6)? ";
			cin.getline( optionTemp, 80 ); 
			option = atoi( optionTemp );

		} while( option < 1 || option > 6 );

		switch( option )
		{
		case 1: 
			contacts.addContact();
			break;
		case 2: 
			contacts.printFullList();
			break;
		case 3: 
			cout << "Enter a Last Name: ";
			cin.getline( charTemp, 80 );
			contacts.retrieveContact( "last", charTemp );
			break;
		case 4: 
			cout << "Enter a Email: ";
			cin.getline( charTemp, 80 );
			contacts.retrieveContact( "email", charTemp );
			break;
		case 5: 
			cout << "Enter a Zip Code: ";
			cin.getline( charTemp, 80 );
			contacts.retrieveContact( "zip", charTemp );
			break;
		case 6: 
			contacts.saveFile();
			stop = true; 
			cout << "Goodbye!" << endl; 
			break; 

		}

	} while( stop == false );

	system("pause");
	return 0;
}
