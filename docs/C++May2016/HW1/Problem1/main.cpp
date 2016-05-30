/*	Lecture 1, 27-May-2016
	Home Work 1, Problem 1
1. Make a program that reads line from the keyboard
and checks how many upper and lower case letters 
and other characters are available in the string.
*/
//That source: Language standard (-std)  ISO C++11 
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool isSmall (char) ;
bool isCapital (char) ;

class StrCounters
{
private:
	string myStr ;

	int countSmall () ;
	int countCapital () ;	

	
public:
	StrCounters () 
	{
		getline(cin, myStr, '\n') ;
	}
	
	int getSmallLettres() ;
	int getCapitalLettres() ;
	int getSize() ;

	~StrCounters()
	{
	}
} ;

int main ()
{
	int countSmallLetters, countBigLetters, countOthers;
	
	StrCounters * countChar = new StrCounters() ;
	countSmallLetters = countChar->getSmallLettres() ; 
	countBigLetters = countChar->getCapitalLettres() ;
	countOthers = countChar->getSize() -(countSmallLetters+countBigLetters) ;
	cout <<countSmallLetters <<' ' ;
	cout <<countBigLetters <<' ' <<countOthers;
	
	delete countChar ;
	return 0;
}

bool isSmall (char c)
	{ return c>='a' && c<='z' ; } ;
bool isCapital (char c)
	{ return c>='A' && c<='Z' ; } ;
int StrCounters::countSmall ()
	{
		return count_if(this->myStr.begin(), this->myStr.end(), isSmall) ;
	}
int StrCounters::countCapital ()
	{
		return count_if(this->myStr.begin(), this->myStr.end(), isCapital) ;
	}
int StrCounters::getSmallLettres()
	{
		return this->countSmall() ;
	}
int StrCounters::getCapitalLettres()
	{
		return this->countCapital() ;
	}
int StrCounters::getSize()
	{
		return this->myStr.length() ;
	}

