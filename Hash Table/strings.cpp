/*Intro to ASCII
- converting between types 
- getting the ASCII value of a string 
- getting the string of a ASCII value array 
*/

#include <iostream>
#include <string>
using namespace std;

int string_to_int(string s){
    //a string is already represented as an array of characters 
    //characters are stored as integers in memory

    int i = s[0];

    return i;
}

int main(){
    cout << string_to_int("hello") << endl;

    return 0;
}