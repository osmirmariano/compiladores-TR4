
#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
	string input;
	regex integer("^ *([0-9]*[0-9].[0-9]*[0-9])$");
	//As long as the input is correct ask for another number
	while(true)	{
		cout<<"Give me a number!"<<endl;
		cin>>input;
		//Exit when the user inputs q
		if(input=="q")
			break;
		if(regex_match(input,integer))
			cout<<"integer"<<endl;
		else
		{
			cout<<"Invalid input"<<endl;
		}
	}
}
