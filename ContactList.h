#include "Contact.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class ContactList
{
	private: 
		vector<Contact> contacts;

	public:
		void addContact();
		void retrieveContact( char type[80], char value[80] );
		void printFullList();
		void loadFile();
		void saveFile();
};

void ContactList::addContact()
{
	Contact contactTemp; 
	char fName[80], lName[80], sAddress[80], zCode[80], email[80], pNumber[80], notes[80];

	cout << "Enter First Name: " ;
	cin >> fName;
	contactTemp.setFirstName( fName );

	cout << "Enter Last Name: " ;
	cin >> lName;
	contactTemp.setLastName( lName );

	cout << "Enter Street Address: " ;
	cin >> sAddress;
	contactTemp.setStreetAddress( sAddress );

	cout << "Enter Zip Code: " ;
	cin >> zCode;
	contactTemp.setZipCode( zCode );

	cout << "Enter Email: " ;
	cin >> email;
	contactTemp.setEmail( email );

	cout << "Enter Phone Number: " ;
	cin >> pNumber;
	contactTemp.setPhoneNumber( pNumber );

	cout << "Enter Notes: " ;
	cin >> notes;
	contactTemp.setNotes( notes );

	cout << endl; 

	contacts.push_back( contactTemp );	
}

void ContactList::retrieveContact( char type[80], char value[80] )
{
	int count = contacts.size(); 

	if( count == 0 )
	{
		cout << "No Contacts Found." << endl << endl;
	} else 
	{

		for( int i = 0; i < count; i++ )
		{
			if( type == "last" )
			{
				if( value == contacts[i].getLastName()  )
				{
					contacts[i].outputContact();
				}
			} else if( type == "email" )
			{
				if( value == contacts[i].getEmail() )
				{
					contacts[i].outputContact();
				}
			} else if( type == "zip" ) 
			{
				if( value == contacts[i].getZipCode() )
				{
					contacts[i].outputContact();
				}
			}
		}
	}
}

void ContactList::printFullList()
{
	int count = contacts.size();

	if( count == 0 )
	{
		cout << "No Contacts Found" << endl << endl; 
	} else 
	{
		for( int i = 0; i < count; i++ )
		{
			contacts[i].outputContact();
		}
	}
}

void ContactList::loadFile()
{
	ifstream inFile;
	inFile.open("contactList.dat", ios::in);

	if( !inFile.fail() )
	{
		int count = 0; 
		Contact contact; 
		string stringTemp;
		string newlineTemp;
		int checkEOF = 0;
		
		do
		{
			getline(inFile, stringTemp, ',' );
			contact.setFirstName( stringTemp );

			getline(inFile, stringTemp, ',' );
			contact.setLastName( stringTemp );

			getline(inFile, stringTemp, ',' );
			contact.setStreetAddress( stringTemp );

			getline(inFile, stringTemp, ',' );
			contact.setZipCode( stringTemp );

			getline(inFile, stringTemp, ',' );
			contact.setEmail( stringTemp );

			getline(inFile, stringTemp, ',' );
			contact.setPhoneNumber( stringTemp );

			getline(inFile, stringTemp, ',' );
			contact.setNotes( stringTemp );

			getline(inFile, newlineTemp, '\n');

			contacts.push_back( contact );
			
			checkEOF = inFile.peek();
			
		}while( checkEOF != EOF );
	} 

	inFile.close();
}

void ContactList::saveFile()
{
	ofstream outFile;
	outFile.open("contactList.dat", ios::app);

	if( outFile.fail() )
	{
		cout << "Failed to open Output File, contactList.dat.  Contacts were not saved." << endl; 
	} else 
	{
		int count = contacts.size();
		for( int i = 0; i < count; i++ )
		{
			outFile  << contacts[i].getFirstName() << "," 
				<< contacts[i].getLastName() << "," 
				<< contacts[i].getStreetAddress() << "," 
				<< contacts[i].getZipCode() << "," 
				<< contacts[i].getEmail() << "," 
				<< contacts[i].getPhoneNumber() << "," 
				<< contacts[i].getNotes() << "," 
				<< "\n"; 
		}

		cout << "Contact List has been saved." << endl; 
	}

	outFile.close();
}