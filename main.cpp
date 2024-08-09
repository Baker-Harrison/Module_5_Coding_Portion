#include <iostream>
#include <string>
#include "include/Die.h"

using namespace std;
// Email Validator
string collectEmail();


// Template function: console log

template <class T>
void consoleLog(T message);


int rollUntilNumberShows(Die &die, int sideChosen);


// Testers

void testEmailValidator();
void testConsoleLog();
void testHowManyRolls();



int main() {
	srand(time(0));
	//testEmailValidator();
	// testConsoleLog();
	testHowManyRolls();
	return 0;
}

string collectEmail()
{
	string emailAddress;
	cout << "Enter an email address: ";
	getline(cin, emailAddress);

	try
	{
		if (emailAddress[0] == '@')
		{
			throw string("Email should not start with @. Please try again");
		}


		else if (emailAddress.find('@') == string::npos)
		{
			throw string("Email does not contain @. Please try again");
		}
		else if (emailAddress.find('.') < emailAddress.find('@'))
		{
			throw string("The '.' was found before the '@' character");
		}

	}
	catch (string exceptionString)
	{
		cout << "ERROR: " << exceptionString << endl;
		return collectEmail();
	}

	cout << "Email address accepted" << endl;
	return emailAddress;


}
template <class T>
void consoleLog(T message)
{
	cout << message << endl;
}


int rollUntilNumberShows(Die &die, int sideChosen)
{
	int sideShowing = die.roll();
	if (sideShowing == sideChosen)
	{
		return die.getNumberOfRolls();
	}

	try
	{
		if (sideChosen > 365 || sideChosen < 0)
		{
			throw string("Invalid side chosen");
		}
	}
	catch (string exceptionString)
	{
		cout << exceptionString << endl;
		exit(-1);
	}

	die.setNumberOfRolls(die.getNumberOfRolls() + 1);
	return rollUntilNumberShows(die, sideChosen);


}


// Tester Implementers

void testEmailValidator()
{
	string emailAddress = collectEmail();
	cout << "Email: " << emailAddress << endl;
}

void testConsoleLog()
{
	Die die ("round", 12);

	consoleLog(12);
	consoleLog(12.5);
	consoleLog("hello world!");
	consoleLog(die);

}

void testHowManyRolls()
{
	int n;
	cout << "Enter an int(1-365): ";
	cin >> n;
	Die die (365);
	int numberOfRolls = rollUntilNumberShows( die, n);
	cout << "It took " << numberOfRolls << " rolls to get the number you wanted" << endl;
}