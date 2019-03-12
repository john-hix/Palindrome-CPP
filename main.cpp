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

// Takes a string and removes all spaces and special characters, and converts
// to upper case, returning the result
// Pre: inString contains a string
// Post: Returns a string with all spaces and special characters removed and
//       converted to upper case
string NormalizeString(string inString);

// Test if normString is a palindrome and return true or false
// Pre: normString contains a normalized string (meaning whitespace,
//      punctation removed....
// Post: Return true if normString is a palindrome, false otherwise
bool IsPalindrome(string normString);


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
      cout << endl;

      // Normalize string
      normalized = NormalizeString(inString);

       if ( IsPalindrome(normalized) )
          cout << "This is a palindrome!\n";
       else
          cout << "This is NOT a palindrome!\n";

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

// Reads a string from a file and returns it
// Pre: inData is linked to a valid input file
// Post: Returns next line read from a file
string GetString(ifstream &inData){

    string thisLine;            // to hold and return a line of text from inData

    getline(inData, thisLine);  // get line of input from the file

    return thisLine;            // return the line of input
}

// Print the passed string in reverse
// Pre: inString holds a value
// Post: Display passed string in reverse
void PrintReverseString(string inString) {
    char theChar;   // The current character within inString

    // Loop through each character in the string from the end, printing each char
    for (int i = inString.length(); i > 0; i--) {
        theChar = inString.at(i -1);
        cout << theChar;
    }
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


// Takes a string and removes all spaces and special characters, and converts
// to upper case, returning the result
// Pre: inString contains a string
// Post: Returns a string with all spaces and special characters removed and
//       converted to upper case
string NormalizeString(string inString) {
    string clean = "";  // Return value; should only receive alphanumeric characters
    char thisChar;      // To hold current char when looping through inString

    for (int i = 0; i < inString.length(); i++) {

        thisChar = inString.at(i);  // Get current character

        if (isalnum(thisChar)) {    // Only add to clean if character is valid
            thisChar = toupper(thisChar);   // Convert to uppercase
            clean += thisChar;              // Append to normalized string
        }
    }

//    cout << "normalized: " << clean << endl; // DEBUG

    return clean;
}



// Test if normString is a palindrome and return true or false
// Pre: normString contains a normalized string (meaning whitespace,
//      punctation removed....
// Post: Return true if normString is a palindrome, false otherwise
bool IsPalindrome(string normString) {

    bool isPalin = true;                // Whether the has proven to be a palindrome
    int fromBeg = 0;                    // Index of first character in `normString`
    int fromEnd = normString.length();  // Index of last  character in `normString`

    // Check if symmentrical characters match
    // Check if fromBeg and fromEnd have already "met" in the middle. If so, we should know the answer for
    // stillPalin, so we can skip any further tests.
    while(isPalin && fromBeg < fromEnd) {

        if ( normString.at(fromEnd -1) !=  normString.at(fromBeg) ) {
            isPalin = false;
        }

        fromBeg++;
        fromEnd--;
    }

    return isPalin;

}






