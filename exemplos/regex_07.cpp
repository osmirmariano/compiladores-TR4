#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main(){
    string input = "wdad";
    //string int_num = "^0$|^[1-9][0-9]*$";

    regex pattern("^((?!( *(if|else|do|while|for|int|float|char|bool)))( *[_a-zA-Z][\\w]*))$");
    if(regex_match(input, pattern))
        cout << "IDT\n";
    else
        cout << "ERRO\n";

    return 0;
}