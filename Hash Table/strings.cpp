/*Intro to ASCII
- converting between types; string, char, int
- getting the ASCII value of a string 
- getting the string of a ASCII value array 
*/

#include <iostream>
#include <string>
using namespace std;

int string_to_int(string s){
    //a string is already represented as an array of characters 
    //characters are stored as integers in memory
    //ASSUMPTION: The string will be composed of only digits

    int result = 0;
    int length = s.length();

    for (int i = 0 ; i < length ; i++){

        char c = s[i];

        if (c < '0' || c > '9') {
            throw "Invalid character found";
        }

        int digit = c - '0';

        result = result * 10 + digit;
    }

    return result;
}


string int_to_string(int x) {
    string result = "";

    if (x == 0) {
        return result = "0";
    }

    while (x > 0) {
        int digit = x % 10;
        char c = digit + '0';

        result = c + result;
        x = x / 10;
    }

    return result;
}


int main() {
    try {
        cout << string_to_int("1234") << endl;
        cout << string_to_int("0") << endl;
        cout << string_to_int("-1") << endl;
    }
    catch (const char* error) {
        cout << "Error: " << error << endl;
    }

    cout << int_to_string(1234) << endl;
    cout << int_to_string(0) << endl;
    // cout << string_to_int(-1) << endl; //doesnt even compile

    return 0;
}