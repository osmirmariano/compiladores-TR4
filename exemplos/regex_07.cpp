#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main(){
    string input = "123";
    //string int_num = "^0$|^[1-9][0-9]*$";

    regex pattern("^ *([0-9]*[0-9])$");

    if(regex_match(input, pattern))
        cout << "matched\n";
    else
        cout << "not matched\n";

    return 0;
}