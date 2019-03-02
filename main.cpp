// a program that will read each line of text from a file, print it
// out to the screen in forward and reverse order and determine if it
// is a palindrome, ignoring case, spaces, and punctuation. (A
// palindrome is a phrase that reads the same both forwards and
// backwards.)
//
// Author:     John Hicks
// Coauthors:  Prof Davis, Nathalie
// Date:       2/27/2019
// =========================================

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Prompt user for file name and return ifstream
// Pre: inData declared
// Post: inData contains valid ifstream for data file
void GetFileInfo(ifstream &inData);

// Reads a string from a file and returns it
// Pre: inData is linked to a valid input file
// Post: Returns next line read from a file
string GetString(ifstream &inData);

// Print the passed string in reverse
// Pre: inString holds a value
// Post: Display passed string in reverse
void PrintReverseString(string inString);

// Takes a string and reverses its order
// Pre: inString contains a string
// Post: Returns inString in reversed order
string ReverseString(string inString);

// Remove white space and punctuation, and convert all alphabetic
//   characters to upper case and return result
// Pre: inString contains a value
// Post: Return normalized string
string NormalizeString(string inString);

// Test if normString is a palindrome and return true or false
// Pre: normString contains a normalized string (meaning whitespace,
//      punctation removed....
// Post: Return true if normString is a palindrome, false otherwise
bool IsPalindrome(string normString);
   // Is forward string == to reversed string

int main() {
   ifstream inData;     // The file containing possible palindromes on each line
   string inString;     // To hold a line from inData file
   string normalized;   // inString to be normalized for a sentence-length palindrome test

   GetFileInfo(inData);

   inString = GetString(inData); // Priming read

   // While data in file
   while(inData) {

      // Print forward string
      cout << inString << endl;

      // Call PrintReverseString
      PrintReverseString(inString);

      // Normalize string
      normalized = NormalizeString(inString);

       if ( IsPalindrome(normalized) )
          cout << "This is a palindrome!\n";
       else
          cout << "This is NOT a palindrome!";

       // Spacing indicated in example run
       cout << endl;

      // Read next line
      inString = GetString(inData);
   }

    return 0;
}


// Prompt user for file name and return ifstream
// Pre: inData declared
// Post: inData contains valid ifstream for data file
void  GetFileInfo(ifstream &inData) {
    string fileName;    // Name of file to open

    // Prompt user for file name
    cout << "Please enter the name of the file to open: ";
    cin >> fileName;

    // Attempt to open file
    inData.open(fileName.c_str());

    // Handle failure to open file
    while (!inData) {
        // Inform user of failure
        cout << "Failed to open \"" << fileName << "\"." << endl;

        // Reprompt for file name
        cout << "Please a file name: ";
        cin >> fileName;
        cout << endl;   // Clear spacing

        // attempt to open file again
        inData.open(fileName.c_str());
    }
    // Inform user of successful file open
    cout << "Successfully opened " << fileName << endl << endl;

}

string GetString(ifstream &inData){

    string thisLine;            // to hold and return a line of text from inData

    getline(inData, thisLine);  // get line of input from the file

    return thisLine;            // return the line of input
}


void PrintReverseString(string inString) {
    char theChar;   // The current character within inString

    // Loop through each character in the string from the end, printing each char

}

// Return a reversed version of inString
// Pre: inString conatins a value
// Post: return a reversed version of inString
string ReverseString(string inString) {
    string rev = "";    // To hold the reversed string

    // Loop through inString from its end and append characters to rev.
    for (int i = inString.length() - 1; i >= 0; i-- ) {
        rev += inString.at(i);
    }

//    cout << "This is inString: \n  " << inString << endl; // DEBUG
//    cout << "This is rev: \n  " << rev << endl;           // DEBUG

    return rev;
}


// Remove white space and punctuation, and convert all alphabetic
//   characters to upper case and return result
// Pre: inString contains a value
// Post: Return normalized string
string NormalizeString(string inString) {
    string clean = "";  // Return value; should only receive valid palindrome characters
    char thisChar;      // To hold current char when looping through inString

//    Loop through inString
//      make character uppercase
//      call isalnum with theChar
//      if isalnum returns true, append theChar to clean


    return clean;
}



// Test if normString is a palindrome and return true or false
// Pre: normString contains a normalized string (meaning whitespace,
//      punctation removed....
// Post: Return true if normString is a palindrome, false otherwise
bool IsPalindrome(string normString) {
    string reversed = ReverseString(normString);    // normString in reverse

    if (reversed == normString)
        return true;

    return false;
}






