# Week 12 Solutions

## Contents
- [Intro](#intro)
- [Questions](#questions)
  - [Problems](#problems)

### Intro
This hosts the solutions to the worksheet set for this week's SI sessions.

__There are many ways to solve a problem__. 
My solutions might not always be the most efficient, however I write my solutions in a way to 
explain concepts and to allow others to optimize them however they wish.

### Questions
For the prompt, look at the worksheet file (the .docx file in the file listing above).

If you see any errors or parts are confusing please let me know (via email or in class) and I'll fix them.

#### Problems
Below are the questions for each section of the worksheet.

##### Syntax Questions
1) TBD

2) __NOTE__: I changed the inputs to doubles so there would be decimal values 

__Regular solution__:
```C++
  double recur_power(double m, double n)
  {
    if(n == 0)    //base case: m^0 = 1
      return 1;
    else          //recursive case: m^n = m^n * m^(n-1)
      return m * recur_power(n-1);
  }
```

__Bonus solution__:
```C++
  double recur_power(double m, double n)
  {
    if(n == 0)       //base case: m^0 = 1
      return m;
    else if (n > 0)  //recursive case: m^n = m^n * m^(n-1)
      return m * recur_power(n-1);
    else             //recursive case: m^-n = (1/m^n), so same as other except divide over and over 
      return recur_power(n+1) / m;
  }
```

##### Concept Questions
1) Class Hierarchy (sorry for the horrible text art):

```
                  ___________________________[Enemy]_____________________
                 /                              |                        \
                /                               |                         \
      ______[Covenant]____              _____[Flood]_________          [Sentinel]
     /     |       |      \            /         |           \
    /      |       |       \          /          |            \
[Grunt] [Elite] [Jackal]  [Hunter] [Infection] [Combat]   [Carrier]
```

__BONUS__:
```C++
  //You must make a pointer to the class in order to make the list work correctly.
  //Without making it a pointer, the program will assume the inserted object is of 
  //what the vector is defined with.
  
  vector< Enemy* > enemy_list;
```

To better understand the bonus portion, try playing around with the following code:
```C++
  #include <iostream>
  #include <vector>

  using std::cout;
  using std::vector;

  class Parent
  {
    public:
      void parent_print(){ cout << "Nope"; }
  };

  class Child : public Parent
  {
    public:
      void child_print(){ cout << "Nope2"; }
  };

  int main() {
    //Test vector of Parent pointers and child pointer to use
    vector< Parent* > plist;
    Child* c = new Child;
	
    //Add child pointer to the vector
    plist.push_back(c);
	
    //Call the parent method
    plist[0]->parent_print();
	
    //The static_cast attempts to have the Parent pointer be seen as a Child pointer
    //More info on this page: http://www.cplusplus.com/doc/tutorial/typecasting/
    static_cast<Child*>(plist[0])->child_print();
	
    //Clean up after ourselves (since we dynamically made memory)
    delete plist[0];
	  
    /* 
      //BAD CODE BELOW
      vector<Parent> blist;
      Child c;
      
      //This works fine actually
      blist.push_back(c);
      
      //This works fine as well
      blist.parent_print();
      
      //This part has an issue (cannot use static_cast without a pointer/reference type)
      static_cast<Child>(blist[0]).child_print();
      
      //NOTE: "blist[0].child_print();" does not work either since the vector sees the Child as a Parent
    */
    return 0;
  }
```

2. Types of inheritance.

For these ones I really just wanted to see what your guys' input would be. Most of the time, you'll be using `public` inheritance.

I couldn't come up with any true scenarios other than the ones presented [here](http://stackoverflow.com/questions/374399/why-do-we-actually-need-private-or-protected-inheritance-in-c), 
and on the C++ faq-lite page in the top response on that page.

-------------------------------------------------------------------------------

Copyright &copy; 2015 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/2015-Spring-CS-121>
