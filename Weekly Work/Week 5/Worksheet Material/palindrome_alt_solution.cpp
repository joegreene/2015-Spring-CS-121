/*
  How this code works:
    main:
    - Functions as driver
    - Calls "process_file"
    process_file:
    - Grabs strings from file
    - Calls "print_palindrome"
    print_palindrome:
    - Prints whether or not each phrase is a palindrome
    - Calls "format_string" to help with 
    format_string:
    - Removes white space and sets the entire phrase to lower case to easily
      check if the phrase is a palindrome
*/

//Libraries to include
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Function prototypes
void process_file(string fn);                       //file process function
void print_palindrome(string s);                    //checks and prints if palindrome
string format_string(string s);                     //formats string for palindrome check

//Driver portion of the code
int main()
{
  //Although the prompt never asks for this, this is just another way to set the file name up
  process_file("word_list.txt");

  return 0;
}

void process_file(string fn)
{
  //Set up a string variable to grab word/phrases from the file
  string input;
  
  //Set up an ifstream object to handle the "word_list.txt" input file
  ifstream infile(fn.c_str());
  
  //NOTE: The above is an example of using ifstream's constructor to open a file
  
  //If we have successfully opened the file
  if(infile.is_open())
  {
    //While we can still grab strings from the file
    while(getline(infile, input))
    {
      //Print whether or not it's a palindrome
      print_palindrome(input);
    }
    
    //Close the file once we're done with it
    infile.close();
  }
  else //file could not be opened
  {
    cout << "File \"" << fn << "\" could not be found" << endl;
  }
}

void print_palindrome(string original)
{
  //The string to use for palindrome-checking
  string s = format_string(original);
  
  //Have a boolean flag for whether or not if it's a palindrome; assuming true saves lines of code
  bool is_palindrome = true;
  
  //Do the check until we've checked the whole string, or if we've evidence it's not a palindrome
  for(unsigned int i = 0; i < s.length()/2 && is_palindrome; ++i)
  {
    //Write each iteration of the loop to understand this
    if(s[i] != s[s.length() - 1 - i])
      is_palindrome = false;
  }
  
  if(is_palindrome)
    cout << original << " is a palindrome." << endl;
  else
    cout << original << " is not a palindrome." << endl;
}

string format_string(string s)
{
  //Remove whitespace if found, else change to lower case
  for(unsigned int i = 0; i < s.length(); ++i)
  {
    if(iswspace(s[i]))
      s.erase(i, 1);
    else
      s[i] = tolower(s[i]);
  }
  
  //Note that, because 's' isn't a referenced parameter, it's a copy
  return s;
}