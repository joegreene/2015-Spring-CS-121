# Week 4

## Contents
- [Intro](#intro)
- [Topics](#topics)
  - [Tuesday](#tuesday)
    - [Functions](#functions)
    - [Reading in a Text File](#reading-in-a-text-file)
    - [Case Insensitivity](#case-insensitivity)
    - [Ignoring Input](#ignoring-input)
    
### Intro
This hosts the activities we worked on during the SI class on Tuesday, 02/10/15.

Note that, since we didn't work on a worksheet this week, there's no folder for it 
in this directory.

### Topics
Below is a directory for the Tuesday notes from this week.

#### Tuesday
We went over the following topics:
- Functions
- Reading in a text file
- Case Insensitivity
- Ignoring Input

##### Functions
Since I've made posts from my last semester work on this before, go ahead and check [this page](https://github.com/joegreene/Spring-2014-CS-Lab--SI-/blob/master/Week%2015/functions.md) 
out (from my 120 SI) for info if you'd like review it. We talked about the same thing as the information in the link during the session.

##### Reading in a Text File
Although we went a little more specific with this in regards to the project, we first worked on the 
[pseudo-code](http://www.unf.edu/~broggio/cop2221/2221pseu.htm) of understanding how this works.

The basic format of it is as follows:

1. Open the file
2. If file was opened successfully
  1. Do whatever you need
  2. Close the file (possible program hangs or corruption of file if step is skipped)
3. Else (the file was not successfully opened), produce an error message

Moving slightly closer to C++ syntax, we have:

1. Create an input file stream (ifstream) object (let's call it `infile`) to take care of reading a file
2. Use a given string with `infile` to __open__ a file (there's a slight trick to this)
3. Verify that the file was opened
  1. If the file was opened, do whatever you need with it, treating `infile` like `cin` (next section explains this more)
  2. Close the file using `infile`
4. If the file did not open, produce an error message to the screen (and stop the program in some way)

Translating this closer to what was required of us in the project, we have the following:
```
  void open_file(string s)
  {
    ifstream infile;                              //Step 1, create ifstream
    
    infile.open(s.c_str());                       //Step 2, open file using string s; We have to use "c_str" because 
                                                  //the function "open" uses a char array (c-string) as its argument.
    
    if(infile.is_open())                          //Step 3, verify the file was opened)
    {
      infile >> s;                                //Step 3i, do whatever you want (I just grabbed the first word found)
                                                  //and put it into s for no apparent reason
                                                  
      infile.close();                             //Step 3ii, close the file when finished (always important!)
    }
    else
    {
      cout << "Error: Could not open file " << s << endl; //Step 4: produce error message
    }
  }
```

The above can be done in other ways. For instance, `ifstream infile(s.c_str());` is another way to both create a ifstream object and 
open a file at the same time. If you want a headstart, this is called using ifstream's [constructor](http://www.tutorialspoint.com/cplusplus/cpp_constructor_destructor.htm), 
which is a topic we'll talk about when working with classes and Object Oriented Programming (OOP).

Of course some tweaks needs to be made, such as it's a requirement to __pass the ifstream object by-reference through the function__. We didn't go over passing 
by-reference in the SI, but if you need help understanding how it works then either the PowerPoint slides or a site like [this](http://www.learncpp.com/cpp-tutorial/73-passing-arguments-by-reference/)
 can help you out.

One big reminder when working with `c_str()`: __Do not forget the file extension!__. Typing `data` into the string versus `data.txt` are two very 
different things, and C++ won't correct you either.

For a more in-depth example, you can check out [this link](https://github.com/joegreene/CS_121_Fall_2014/tree/master/References/General%20IO#text-file-io). 
It's an example I gave to my previous-semester students, riddled with comments, to help them understand a bit more 
and see how file I/O (input/output) is similar to (text) file I/O.

##### Case Insensitivity
Although this was required with the first project, you can ignore case by using the functions `toupper(char c)` and `tolower(char c)`. As noted by `char c`, these 
read in a single character and return the upper or lower-case version of the character sent through the function.

If you want to set an entire C++ string to lower case for instance, you can do something like the following:
```C++
  string str = "HeLLo WorLd111";
  for(int i = 0; i < str.length(); ++i)       //read until end of string (which is a special character array)
  {
    str[i] = tolower(str[i]);                 //get the lower case version of the current position and set the current
                                              //position equal to that
  }
  cout << str << "\n";                        //output edited string
```

The above should output:
```
  hello world111
```

__NOTE__: If you're curious as to why I typed `++i`, it's because I'm used to doing that, and in a way it's technically more correct. Since the update (that is, incrementing `i`) 
is meant to be done after the for-loop is finished, I do a post-increment. Ultimately, it doesn't matter with a for-loop, although it'll matter later in other things, like 
doing `str[++i]` versus `str[i++]` (which is something in your PowerPoint notes).

##### Ignoring Input
Since I've made posts from my last semester work on this before, go ahead and check [this link](https://github.com/joegreene/CS_121_Fall_2014/tree/master/Weekly%20Work/Week%203#friday) 
out for info if you'd like review on it. Specifically, look at the example code and "Major components" information below it. Although the code there is about validating user input, 
it also talks about `cin.ignore`, which is a way to skip specific characters in the console input stream.

By the way, if you haven't noticed it yet, `cin` stands for console input.

-------------------------------------------------------------------------------

Copyright &copy; 2015 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/2015-Spring-CS-121>
