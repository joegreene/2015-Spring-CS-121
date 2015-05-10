# Week 16 - Pseudo-Exam Solutions

## Contents
- [Intro](#intro)
- [Solutions](#solutions)
  - [Terms](#terms)
  - [Concept](#concept)
  - [Syntax](#syntax)
  
### Intro

This hosts the activities we worked on during the SI class on Tuesday, Wednesday, and Thursday, 5/5 - 5/7.

### Solutions
Below are the solutions per section.

#### Terms
Although this will help you with a chunk of the terms on the exam, the best thing you can do for yourself is 
make flashcards to know these.

__H__ Data Abstraction &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; __E__ Operator overloading

__K__ Derived class &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; __G__ Encapsulation

__N__ Inheritance &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; __L__ Object

__B__ friend &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; __M__ Abstract Function

__F__ Polymorphism &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; __J__ Base class

__I__ Template &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; __C__ Static

__D__ Copy Constructor &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; __A__ this

Note also that there is a difference between `Data Abstraction` and `abstract function`. This can be tricky to remember, but note that 
the first refers to [a characteristic of object-oriented programming](http://www.tutorialspoint.com/cplusplus/cpp_data_abstraction.htm), and the other refers to polymorphism.

#### Concept
1) Recursive call and base case. Two examples: Factorial and Tower of Hanoi game.

2) Classes on default are private, whereas structures are public on default. Also (as an extra note), templates can only use class types.

3) Possible issues include: Corruption of file, program hangs, and conflicts with other programs trying to open the file.

4) This can be summed up in one word: Reusability. Class inheritance helps with being able to define new types without retyping a lot of code 
(e.g. defining a )

5) I could retype this, but I'd rather send you to [this link](http://www.learncpp.com/cpp-tutorial/115-inheritance-and-access-specifiers/). 
`CTRL + F` and search for "To summarize in table form:" for a good visual aid.

6) Both of these refer to polymorphic code (this was a bit of a trick question as a virtual method can also be a pure virtual method):
- A pure virtual method is a method that is polymorphic and has no initial implementation (i.e. setting the method equal to zero). This is also known as an abstract method.
- A virtual method is a method that is polymorphic. This is a more generalized term, and refers to any method that can be overridden in a class inheritance.

#### Syntax
1) Factory function (example solution):

```C++
  enum CarType { PICKUP = 0, SPORTS, MINIVAN };  //enumerated type for convenience
  Car* generate_car(int seats, int numWheels, int type) {
    Car * c = nullptr;
    switch(type) {
      case PICKUP:
        c = new PickupTruck(seats, numWheels);
        break;
      case SPORTS:
        c = new SportsCar(seats, numWheels);
        break;
      case MINIVAN:
        c = new Minivan(seats, numWheels);
        break;
      default: //not required, but always safe to have for error-checking
        cerr << "Invalid car type requested!\nFailed to initialize a car from user specs.\n";
    }
    
    return c;
  }
```

2) Example solution:

```C++
  string do_concat(const vector<char>& ch_list) {
    string upper, lower;  //variables required for end concatenation
    upper = lower = "";   //initializing the strings to be safe, i.e. if no default initialization is made
    
    for( int i = 0; i < ch_list.size(); ++i) {
      if(isalpha(ch_list[i])) {        //first verify if the character is a letter
        if(isupper(ch_list[i])) {      //append to 'upper' if current character is uppercase letter
          upper = upper + ch_list[i];  //strings have '+' overloaded to add strings/char to a string
        }
        else {                         //letter is lowercase and append it to 'lower'
          lower = lower + ch_list[i];
        }
      }
    }
    
    return (upper + lower);            //return both concatenated
  }
```

3) Fixed code (five errors in total):

```C++
  vector<string> init_str_list(string fn) {
    fstream file(fn.c_str());     //this line is fine (when making this I figured 'ios::in' was 
                                  //required but visual studio didn't care)
    vector<string> str_list;      //FIRST ERROR: missing semi-colon
    if(file.is_open()) {          //SECOND ERROR: Method name is 'is_open', not 'open'
      string temp;
      while ( file >> temp ) {    //THIRD ERROR: Grabbing from file, not console input
        str_list.push_back(temp); //FOURTH ERORR: Invalid method name 'add'; should be 'push_back'
      }
      file.close();               //FIFTH ERROR: This is a logic error and should not be forgotten 
                                  //(due to possible file hangs)
    }
    else { cerr << "Could not open file!\nReturning empty vector.\n"; }
    
    return str_list;
  }
```

-------------------------------------------------------------------------------

Copyright &copy; 2015 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/2015-Spring-CS-121>
