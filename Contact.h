#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

class Contact
{
	private:

		string firstName; 
		string lastName;
		string streetAddress;
		string zipCode;
		string email;
		string phoneNumber;
		string notes;

	public:
		void setFirstName( string fName );
		void setLastName( string lName );
		void setStreetAddress( string sAddress );
		void setZipCode( string zCode );
		void setEmail( string mail );
		void setPhoneNumber( string pNumber );
		void setNotes( string notes );
		string getFirstName();
		string getLastName();
		string getStreetAddress();
		string getZipCode();
		string getEmail();
		string getPhoneNumber();
		string getNotes();
		void outputContact();
};

void Contact::setFirstName( string fName )
{
	firstName = fName;
}
void Contact::setLastName( string lName )
{
	lastName = lName;
}

void Contact::setStreetAddress( string sAddress )
{
	streetAddress = sAddress;
}

void Contact::setZipCode( string zCode )
{
	zipCode = zCode;
}

void Contact::setEmail( string mail )
{
	email = mail;
}

void Contact::setPhoneNumber( string pNumber )
{
	phoneNumber = pNumber;
}

void Contact::setNotes( string note )
{
	notes = note; 
}

string Contact::getFirstName()
{
	return firstName;
}
string Contact::getLastName()
{
	return lastName;
}

string Contact::getStreetAddress()
{
	return streetAddress; 
}

string Contact::getZipCode()
{
	return zipCode;
}

string Contact::getEmail()
{
	return email; 
}

string Contact::getPhoneNumber()
{
	return phoneNumber;
}

string Contact::getNotes()
{
	return notes;
}

void Contact::outputContact()
{
	cout << getFirstName() << " " << getLastName() << endl
	<< getStreetAddress() << ", " << getZipCode() << endl
	<< getEmail() << ", " << getPhoneNumber() << endl
	<< getNotes() << endl << endl; 
}
