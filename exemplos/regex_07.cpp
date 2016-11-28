#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main(){
    string input = "float";
    //string int_num = "^0$|^[1-9][0-9]*$";

    regex pattern("^ *(int|float|char|bool)$");

    if(regex_match(input, pattern))
        cout << "FLOAT\n";
    else
        cout << "ERRO\n";

    return 0;
}