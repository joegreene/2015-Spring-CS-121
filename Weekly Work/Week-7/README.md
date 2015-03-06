# Week 7

## Contents
- [Intro](#intro)
- [Topics](#topics)
  - [Tuesday](#tuesday)
    - [Classes and `main` in Same File](#classes-and-main-in-same-file)
    - [`pointers`](#pointers)
      - [Why Use Pointers?](#why-use-pointers)
  - [Wednesday](#wednesday)
    - [Recursion](#recursion)
    - [`argc` and `**argv`](#argc-and-argv)
    
### Intro

This hosts the activities we worked on during the SI class on Tuesday and Wednesday, 3/3 & 3/4.

### Topics

Below is a list of the Tuesday & Wednesday session notes. 

If there are any issues with the below work please let me know. I'm typing this quickly so you guys can have it before the project is due.

__NOTE__: I put a lot of information on this page, so use the links above to skip around to places you would like to review.

#### Tuesday

Topics we discussed:
- Classes and `main` in Same File
- Pointers
- Recursion (moved to Wednesday to spread out topics for this week)

##### Classes and `main` in Same File

As mentioned briefly in class, you can have whatever class blueprints (typically the header file; `Class.h`) and the implementation of the blue prints (typically located in the class's source file; 
`Class.cpp`) all inside the file with `main`.

Example syntax (note that this is all in `main.cpp`):

```C++
  //  Put includes and usings on top, like usual
  #include <iostream>
  
  using std::cout;
  
  // Constant used for CCircle class
  const double PI = 3.141592;
  
  //  Minimal circle class
  class CCircle {
    //  on default, the variable below is private
    double radius;
    
    public:
      CCircle() {  //  example of defining a function of a class inline
        radius = 7;
      }
      double getRadius() { return radius; } //  another inline example
      double computeArea();                 //  method prototype (to be defined outside of the class blueprints)
  }
  
  //  Defining a method of a class outline (like before in the class source, .cpp, file)
  double CCircle::computeArea() {
    return PI * radius * radius;            //  formula = pi * r^2
  }
  
  int main() {
    CCircle test_obj;  //creating an object of the class CCircle
    
    // miscellaneous test output, which should be 7.0 and something like 153.93804
    cout << test_obj.getRadius() << " " << test_obj.computeArea() << endl;
    
    return 0;
  }
```

Although it's not much, the above code creates a CCircle, prints its radius, then prints its area. You can run and test 
the above code in visual studio, or an online compiler such as www.ideone.com to see its output.

##### Pointers

If there's anything that students get the most mixed up with when it comes to working with pointers, is knowing the 
distinction between pointer variables and variables. A __pointer variable__ is a variable that holds an address (to a location 
in RAM where memory already exists), whereas a __variable__ in most cases is anything along the lines of something like `double var;`.

Some key notes I don't believe the power point

Because the power point slides have some pretty good information on how to use these, I left it to those that went to the SI to take a 
look at them. 

There's one key note that I don't believe the power point notes mention, which is the following:
- Pointer variables (themselves) are always of size four bytes (if you're compiling your program as 32 bit), or 8 bytes (if 64 bit)
  - Note the distinction of 32 bit and 64 bit: 1 byte = 8 bits, four bytes = 32 bits, eight bytes = 64 bits.
  - [This too](http://www.cplusplus.com/forum/beginner/78115/) makes the distinction I just made as well.

No one really had any questions about pointers during the SI, more or less "why" we are even bothering learning about them. Although I failed 
to mention this in the Tuesday session, in the Wednesday session we went over the reasons (which are in the following section).

###### Why Use Pointers?

From what I could come up with, there are three main points on why to bother working with pointers:
- __Efficiency__: Make your programs more memory efficient (thus, giving compatibility to older systems or low-RAM devices like the typical smart phone)
  - ex) Although the same can be accomplished with calling `by-reference`, `by-pointer` is a way you can send an address as an argument versus copying the entire thing (i.e. without `&` or `*`
  - ex) Take for instance a program that must load a gigabyte of data in it to compute some figures, and it only needs to do that at the beginning of the program. By usage of pointers, you can create the vector (or whatever other type needed) to store the data through a pointer using __new__. After you're done with it, just __delete__ it (so you're not using any RAM you might need to use later on).
- __Concept vs. Syntax__:
  - Although it's required in CS 121/131 to apply your knowledge of pointer syntax (i.e. how to type code with pointers), it's much more important to understand how they work
    - As anyone in this class should be able to tell you: __Pointers are addresses__. They __refer__ to memory already allocated (such as the 4 bytes allocated for `int num`).
- __Experience & Application__: You won't have a necessity for using pointers in this class, however you will when you reach 131. Best to prepare yourself sooner than later.
  - Assuming we'll all be working with code (not necessarily C++) in some way outside college, it'll be highly improbable to never see/use a pointer
    - This holds especially true if you're working on something that requires access to low level components (such as an operating system)
    - This also applies to making programs that require serious amounts of optimization (i.e. making your program in a low level language like C or an Assembly language)
    - Another thing, mentioned previously, is working on low-RAM devices (such as a phone), where a process might require 2 GB RAM but the device only has half that
      - In this case, pointers are necessary to create and delete memory while the program is running.

#### Wednesday

Topic discussed:
- Pointers (in previous notes)
- Recursion
- `argc` and `**argv`

##### Recursion

Firstly: I don't advise searching on google `recursion`. If you know what recursion is, you'll understand why.

After you're done being "corrected" by Google for the 50th time, know that __recursion__ just means to repeat something 
in a self-similar way. In our case, we talk about __recursive functions__. Things that you might know already that are considered recursive are the
__factorial function__ and _fibonacci sequence__.

__All__ recursive functions __must have__ these two characteristics to them:
- __Recursive call(s)__: A function call to itself but with an updated argument of some sort.
- __Base case(s)__: A condition to reach to after all necessary recursive calls have been made.

Example of a recursive function (factorial):
```C++
  //  NOTE: 'long' is just a bigger version of an integer (i.e. can hold more values)
  long fact(long n) {
    if(n==1 || n==0)
      return 1;
    else
      return n * fact(n-1);
  }
```

(Example) thought process of achieving above:
```
  If f(n) = n!, then 
    f(4) = (4)! = 4 * 3 * 2 * 1 
         = 4 * 3!
  From here, we can determine that:
    f(n) = n * f(n-1)         (our recursive call)

  The smallest factorial we can compute (ignoring the fact there are fractional factorials and negative factorials are complex infinity):
    0! = 1! = 1               (our base case)
```

Example run of the above (this shows that the program must first evaluate the innermost function call before :
```
  cout << fact(4);       //assume we wanted to compute this
             |
             --> fact(4) = 4 * fact(3)
                                  ---> 3 * fact(2)
                                             ----> 2 * fact(1)   
                                                          -----> 1 (from this point the program gets 
                                                                      fact(2) = 2 * 1 = 2
                                                                      fact(3) = 3 * 2 = 6
                                                                      fact(4) = 4 * 6 = 24
                                                                      ... and now we're finished.

  Note that the program must first dig down to the last function call before computing the previous calls. 
    This can get pretty bad when it comes to computing large factorials, such as 
```

Another recursive function example (fibonacci sequence):
```C++
  /*
    Fibonacci sequence: Defined as...
         f(n) = f(n-1) - f(n-2)    where f(0) = f(1) = 1

    Example: Fib Number: 1, 1, 2, 3, 5, 8, 13, ...
             Index:      0  1  2  3  4  5   6
  */
  long fib(long n1, long n2) {
    if(n == 0 || n == 1)   //base case, where f(0) = f(1) = 1
      return 1;
    else
      return fib(n-1) + fib(n-2);
  }
```

Example run:
```
   fib(4) = fib(3)        +       fib(2)
            /     \               /   \
      fib(2)  +  fib(1)      fib(1) + fib(0)
      /    \       (1)        (1)       (1)
   fib(1)  fib(0)
    (1)      (1)

  Adding the ones at the bottom yields: 1 + 1 + 1 + 1 + 1 = 5, which is the fourth fibonacci number

  Note that, for each function call made, you're making two more function calls (except for 0 and 1). 
    This can have a nasty number of function calls depending on your start value, e.g. fib(1000).

```

Recursion is a looping process, just like __iterative__ processes (i.e. ones developed with a for/while loop).

Example of iterative solution for the factorial problem:
```C++
  // NOTE: This function assumes n is an integer greater than or equal to 0
  long fact(long n) {
    long factorial_value = 1; //the value that will hold the value of the factorial

    for(long i = n; i > 1; --i) { //we don't need to compute 'factorial_val *= 1 or' lower
      factorial_value *= i;
    }
    
    return factorial_value;
  }
```

There are key differences between recursive and iterative solutions (the below are also in your notes):

Recursive solution:
- Typically are inherently easier to understand
- Can cause a stack overflow (which can be caused by too many function calls).

Iterative solution:
- Might be harder to come up with (e.g. factorial requires an accumulator, which doesn't fit how we normally view a factorial)
- Less prone to crashing (no extra function calls required means less of a chance of a stack overflow error)

Lastly: __All recursive calls have an iterative version of them, and vice-versa__.

##### `argc` and `**argv`

We discussed a line of C++ syntax in the project for this weekend that people were curious about in the SI session:
```C++
  int main(int argc, char** argv)
```

I don't know if Professor Frick mentioned this during either lab, but the `argc` and `**argv` parts refer to opening your executable file 
(in this case the one you compile your C++ code into from your IDE, be it Visual Studio, XCode, or whatever else).

Some definitions before continuing on:
- `argc` means "argument count"
- `**argv` is a list of argument c-strings. Remember how pointers can make arrays? `**` means to make an array of arrays, or in this case a list of c-strings (character arrays).

To actually use these parameters to something useful, you need to run your executable through command prompt (Windows) or terminal (Mac OSX/Linux).

An example of how this may look in Linux (which should be similar to Mac OSX); (The below was run on my laptop):
```
  joe@joe-Lenovo-IdeaPad-Y580 ~/Desktop/Week 7 $ cd ~/Desktop/program_test/
  joe@joe-Lenovo-IdeaPad-Y580 ~/Desktop/program_test $ dir
  main.cpp  prgm.exe
  joe@joe-Lenovo-IdeaPad-Y580 ~/Desktop/program_test $ ./prgm.exe
  Argument Count: 1

  Argument list: 
  --------------
  (0):./prgm.exe

  joe@joe-Lenovo-IdeaPad-Y580 ~/Desktop/program_test $ ./prgm.exe test arg3 etc
  Argument Count: 4

  Argument list: 
  --------------
  (0):./prgm.exe
  (1):test
  (2):arg3
  (3):etc

  joe@joe-Lenovo-IdeaPad-Y580 ~/Desktop/program_test $ 

```

Parts to note (just to help you understand the above example):
- `joe@joe-Lenovo-IdeaPad-Y580`: The name of the user, which is me (`joe`), and the name of the system (in this case it's my name plus my laptop's name)
- `$`: Marks where the user begins typing their commands to

Here's what I did per line: 
- `cd ~/Desktop/program_test/`: This means I changed my directory over to wherever my executable exists (for me, it was on my Linux system's desktop in a folder called `program_test`).
  - Note that the beginning part changes to where your executable is located.
  - Second note: If your directory has spaces in it (e.g. if my folder was instead "program test" without the underscore) you would type: `cd ~/Desktop/program\ test/`, where `\` lets the terminal know that there is a space in the directory name
- `dir`: This was to help me see what files were in the current directory I was at. In this case, it was my source file (`main.cpp`) and my executable file I compiled previously (`prgm.exe`).
- `./prgm.exe`: This is how you run an executable program (my executable's name is `prgm.exe`, compile from the source code below this section)
  - Right below this is the output of the program (which is similar to how Visual Studio works, as it outputs stuff to command prompt)
- `./prgm.exe test arg3 etc`: This is me showing off how you can give more than one argument when running an executable. The output below shows which index each 
- Last line (` ~/Desktop/program_test $ `) is empty since the terminal is waiting for another command.

For Windows you do the same process, except some of the commands differ:
- Open up cmd.exe (through the search bar)
- Use `cd` to change to wherever your program's executable is located (e.g. `cd "C:\Users\Joe\Documents\Visual Studio 2012\program_test\program_test\release"`) where quotations are used when there is a space in the directory.
  - If you aren't sure where you are with `cd`, you can use `dir` to list all the files in the current directory you're viewing (like I did in my example).
- To run an executable, just type the name of the executable (e.g. for mine I would type `prgm.exe`).
  - To add arguments, type then straight after the first argument (e.g. `prgm.exe 12 13 third_argument etc`).
- The output will be right below (just like when Visual Studio outputs your code to console).

Code for `prgm.exe` (which I encourage you to compile and test on your own):
```C++
  #include <iostream>
  #include <cstring>     //required for 'strlen' used later

  //  More efficient way of "using namespace std" since we're specifying what we're using, 
  //  not including the entire namespace
  using std::cout;
  using std::endl;

  int main(int argc, char** argv) 
  {
  
    //  For formatting and tidying-up the output:
    cout << "Argument Count: " << argc << endl << endl
         << "Argument list: "  << endl 
         << "--------------"   << endl;
  
    //  For each argument we have given
    for(int i = 0; i < argc; ++i)
    {
      cout << "(" << i << "):";
    
      //  Since we're working with char arrays, we have to use a for loop to print it out
      //  Also, 'strlen(char *)' is a way to get the length of the char array
      for(int j = 0; j < strlen(argv[i]); ++j)
      {
        //  Treat this like a 2-dimensional array. We first go to the position of the 
        //  i-th argument, then the inner for-loop takes care of each character in the argument
        cout << argv[i][j];
      }
      cout << endl;
    }

    cout << endl;  

    return 0;
  }
```

For usefulness (and I'm assuming this is how your project will be tested), Frick will run your program as something like:
```
  your_program.exe datafile.txt
```

Which, given the above, would have a program like the following handle the argument correctly:
```C++
  //  includes, class definition, and other stuff up here

  int main(int argc, char** argv) 
  {
    if(argc > 1) //if we know there's a second argument at least
    {
      //  We assume that the second argument (located in argv[1]) is the file name
      //  Note that we can directly use 'argv[1]', since it's a c-string (which is what ifstream uses to get a file name)
      ifstream infile(argv[1]);
      
      //  Do whatever else you need to do, and make sure to close the file after you open it
    }
    else 
    {
      //invalid amount of arguments
      cout << "ERROR: Did not supply file name!";
    }
    return 0;
  }
```

Last note (and I swear, since this page is getting too long): As the arguments above are "executable_to_run" then anything after that, the example Frick gave:
```
  iwconfig wlan0
```

is an example of running a command `iwconfig` and an argument `wlan0`.

-------------------------------------------------------------------------------

Copyright &copy; 2015 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/2015-Spring-CS-121>
