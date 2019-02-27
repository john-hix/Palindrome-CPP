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

// Print the passed string in reverse
// Pre: inString holds a value
// Post: Display passed string in reverse
void PrintReverseString(string inString);

// Return a reversed version of inString
// Pre: inString conatins a value
// Post: return a reversed version of inString
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

   getline(inData, inString); // Priming read

   // While data in file
   while(inData) {

      // Print forward string
      cout << inString;

      // Call PrintReverseString
      PrintReverseString(inString);

      // Normalize string
      normalized = NormalizeString(inString);

       if ( IsPalindrome(normalized) )
          cout << "yay";
       else
          cout << "boo";

      // Read next line
      getline(inData, inString);
   }

    return 0;
}


// Prompt user for file name and return ifstream
// Pre: inData declared
// Post: inData contains valid ifstream for data file
void  GetFileInfo(ifstream &inData) {
    string fileName;    // Name of file to open
//    prompt user for file name
//    echo back file name
//    attempt to open file

    while (!inData) {
//        echo "failed to open [filename]"
//        Reprompt for file name
//        attempt to open file
    }
//    echo "Successfully opened [filename]"

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

//    Loop through inString from its end and append to rev.

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






