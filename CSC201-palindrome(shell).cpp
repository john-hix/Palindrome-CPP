#include <iostream>
#include <fstream>

using namespace std;

void GetFileInfo(ifstream &inData);

// Reads a string from a file and returns it
// Pre: inData is linked to a valid input file
// Post: Returns next line read from a file
string GetString(ifstream &inData);

// Takes a string and removes all spaces and special characters, and converts
// to upper case, returning the result
// Pre: inString contains a string
// Post: Returns a string with all spaces and special characters removed and
//       converted to upper case
string NormalizeString(string inString);

// Takes a string and reverses its order
// Pre: inString contains a string
// Post: Returns inString in reversed order
string ReverseString(string inString);

// Test to see if a passed string is a palindrome
// Pre: normalString has all spaces and special characters removed and is in
//      upper case
// Post: Rerturns true if normalString is a palindrome, false otherwise.
bool isPalindrome(string normalString);

int main()
{
    ifstream inData;      // Hold link to file
    string inString;      // Hold string read from file
    string normalString;  // Hold normalized string

    // Get filename and open file
    GetFileInfo(inData);

    // Priming read
    inString = GetString(inData);

    // Loop as long as there's data in file
    while (inData) {

        // Echo string read from file
        cout << inString;

        // Reverse string and echo to string as specified
        cout << ReverseString(inString);

        // Normalize the string
        normalString = NormalizeString(inString);

        // Test normalized string
        if (isPalindrome(normalString))
            cout << "Yay!\n";
        else
            cout << "Boo!\n";

        // Get next string from file
        inString = GetString(inData);
    }

    // Close input file
    inData.close();
}

string GetString(ifstream &inData){
    cout << "GetString\n";

    // declare string to hold data from file

    // get string from file

    // return string

    return ""; // Placeholder to make shell run
}

string NormalizeString(string inString){
    cout << "NormalizeString\n";

    // Declare local variable to hold normalized string

    // Loop through each character of inString
       // If character is a letter
           // Convert to uppercase
           // Keep in string

    // Return normalized string

    return ""; // Placeholder to make shell run
}

string ReverseString(string inString){
    cout << "ReverseString\n";

    // Declare local variable to hold reversed string

    // Loop through each character of inString from last to first
       // Add character to reversed string

    // Return reversed string

    return ""; // Placeholder to make shell run
}

bool isPalindrome(string normalString){
    cout << "isPalindrome\n";

    // Loop through each character in normalString from first to last (ch1) and last to first (ch2)
       // If ch1 != ch2 then not a Palindrome (return false)

    // If full string tested then must be a palindrome (return true)
    return true;
}

// Prompt user for file name and return ifstream
// Pre: inData declared
// Post: inData contains valid ifstream for data file
void GetFileInfo(ifstream& inData){
    string filename;

    do {
        // Prompt user for file name and open file
        cout << "Enter file containing input values: ";
        cin >> filename;

        inData.open(filename.c_str());

        if (!inData)
            cout << "Invalid file!\n\n";


    } while (!inData); // Loop until valid file name provided
}
