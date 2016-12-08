#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main(){
    string input = "==";
    //string int_num = "^0$|^[1-9][0-9]*$";

    regex pattern("^ *(>|<|>=|<=|!=|==)$");
    if(regex_match(input, pattern))
        cout << "IDT\n";
    else
        cout << "ERRO\n";

    return 0;
}