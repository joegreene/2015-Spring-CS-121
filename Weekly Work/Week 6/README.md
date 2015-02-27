# Week 6

## Contents
- [Intro](#intro)
- [Topics](#topics)
  - [Tuesday](#tuesday)
    - [`enum`](#enum)
  - [Wednesday](#wednesday)
    - [Classes](#classes)
    
### Intro
This hosts the activities we worked on during the SI class on Tuesday and Wednesday, 02/24 & 2/25.

### Topics
Below is a directory for the Tuesday and Wednesday notes from this week.

#### Tuesday
Topics discussed 
- `enum`
- Classes (I moved the notes for these into the Wednesday portion)

##### `enum`
The top two comments on [this link](http://stackoverflow.com/questions/4564322/some-good-example-for-using-enums) explain enumeration really well. I suggest checking it out to understand them better.

These are used infrequently, so I wouldn't worry too much about remembering them in typical practice. They're still 
good to have in your "bag of tricks" though.

Another example of `enum` I thought up of while typing this is a menu-driven program, which takes a choice through a menu such as the following:

```
  Please choose a movie from the list below:
  ------------------------------------------
  1. Fifty Shades of Grey
  2. Imitation Game
  3. Hot Tub Time Machine 2
  4. Up
  5. Finding Nemo
  6. Exit Program
  ------------------------------------------
  Enter choice: 
```

You can have C++ syntax similar to the following for the above output:
```C++
  //list of choices we want to test for; Start at 1 for choice 1
  enum{FIFTYSHADES = 1, IMITGAME, HOTTUB, UP, NEMO, EXIT};
  
  //...code...
  output_menu();         //custom function to print menu
  
  choice = get_input();  //custom function to grab input
  
  switch(choice)
  {
    case FIFTYSHADES:
      //...code...
      break;
    case IMITGAME:
      //...code...
      break;
    case HOTTUB:
      //...code...
      break;
    case UP:
      //...code...
      break;
    case NEMO:
      //...code...
      break;
    case EXIT:
      //...code...
      break;
    default:
      std::cout << "Invalid choice.\n";
  }
```

#### Wednesday
We talked about the following topics:
- Classes


##### Classes
When defining classes, we typically use two files to do it: A header file, and a source file. We also have a third file, which is the file that uses and makes an instance (or instances) of this class (the client code).

Typically, the format will be:
- `ClassName.h`: The "blueprints" of the class (that is, this file has plans for what you want to implement)
- `ClassName.cpp`: The "implementation" of the class (that is, the actual definition of the class's blueprints)
- `main.cpp`: The "client" file (I normally call my source file with main as `main.cpp`, to keep track of things)

Done sometimes is you can put your implementations within the header (`.h`) file, either below or inside the `class { ... };` portion.

Starting off with a simple example (which is pretty similar to the one in the worksheet):

__NOTE__: Some clarifications about parts of the code are made after the test run portion below.

`CRectangle.h`:
```C++
  #include <iostream>
  
  //NOTE: Below is an alternate (and safer version) of "using namespace std". In this case, you're only 
  //      applying "std::" to "cout" and "cin". If you want to use strings, you can do "std::string" 
  //      (of course, you need to include the string library before doing so).
  //      
  //      The namespace "std" is really large, and is frowned from in real world applications to include. 
  //      The below is used commonly, although still a lot of programmers manually use "std::" as well.
  //
  
  using std::cout;                         //all "cout" found will have "std::" appended to them automatically
  using std::endl;                         //all "endl" found will have "std::" appended to them automatically
  
  class CRectangle
  {
    private:
      double width, height;                //member variables
    public:
      //Constructors
      CRectangle();                        //Default constructor
      CRectangle(double w, double h);      //Overloaded constructor
      
      //Destructor
      ~CRectangle();                       //Destructor
      
      //Getters
      double getWidth();                   //return the width
      double getHeight();                  //return the height
      
      //Setters
      void setWidth(double w);             //set the width from a given double
      void setHeight(double h);            //set the height from a given double
      
      //Misc. Functions
      double computeArea();                //return the area of the rectangle
  };
```

`CRectangle.cpp`:
```C++
  #include "CRectangle.h"              //do this to let the compiler know where the actual class is
  
  //NOTE: Any "cout" you see later do not need "std::" on them. This is because, when we include "CRectangle.h" 
  //      above, we include anything else it has too (i.e. the "using std::cout" statement)
  
  //Constructors
  CRectangle::CRectangle()
  {
    width = height = 1;                //set as default value for sake of simplicity
  }
  CRectangle::CRectangle(double w, double h)
  {                                    //Moral: Don't trust the user
    width = height = 1;                //Initially, set width and height to default values (like in default constructor)
    setWidth(w);                       //Afterwards, use our setter functions to safely assign the width and height
    setHeight(h);                      
  }
      
  //Destructors
  CRectangle::~CRectangle()            //this function is called when the object is destroyed (i.e. the program leaves the 
  {                                    //object's scope)
    cout << "Destroyed instance of class CRectangle." << endl;
  }
  
  //Getters
  double CRectangle::getWidth()
  {
    return width;
  }
  double CRectangle::getHeight()
  {
    return height;
  }
  //Setters (NOTE: setters assume, before calling them, that your member variables are already set)
  void CRectangle::setWidth(double w)
  {
    if(w > 0)                          //set width to w as long as w is greater than zero (a valid range)
    {
      width = w;
    }
    else                               //this can be implemented in any other way you want. I chose to print an error.
    {
      cout << "Invalid width given: " << w << ". Retaining old value (default is 1.0).";
    }
  }
  void CRectangle::setHeight(double h)
  {
    if(h > 0)                          //same idea as setWidth
    {
      height = h;
    }
    else                               //same idea as setWidth
    {
      cout << "Invalid height given: " << h << ". Retaining old value (default is 1.0).";
    }
  }
  
  //Misc. Functions
  double CRectangle::computeArea()
  {
    return (width * height);           //pretty straightforward as long as you know area_of_rectangle = width * height
  }
```

`main.cpp` (try to make sense of this section by comparing the output window below):
```
  #include "CRectangle.h"
  
  //NOTE: The include rule (stated under "CRectangle.cpp") applies to this file as well. No need to type "std::" for 
  //      "cout" and "endl". We didn't have "cin" above, so it's stated below.
  
  using std::cin;                      //all "cin" found will have "std::" appended to them automatically
  
  int main()
  {
    CRectangle first_rect;
    CRectangle second_rect(-2.0, 12.0);
    
    first_rect.setWidth(14.0);
    double height;                       //this name was intentional
    cout << "Please enter a height: ";
    cin  >> height;                      //assume user inputs 17.0
    
    cout << first_rect.computeArea() << endl;
    cout << second_rect.getHeight()  << endl;
    
    first_rect.setWidth(height);
    
    cout << second_rect.computeArea() << endl << endl;
    
    return 0;
  }
```

Test run:
```
  Invalid height given: -2.0. Retaining old value (default is 1.0).
  Please enter a height: 17.0          <-------- This is user input
  14.0
  12.0
  204.0
  
  Destroyed instance of class CRectangle.
  Destroyed instance of class CRectangle.
```

The above is similar to an example we did in the Wednesday session. Try to go through it and understand why the output is the way it is. 

__NOTE__: The last two lines will pop up very quickly (right before the program closes) if you decide to compile the code above. That means, to see the messages, you'll want to run the executable (made from the above code) via a terminal or command prompt.

Some key parts to notice:
- The files (`CRectangle.h`, `CRectangle.cpp`, and `main.cpp` must be in the same project folder.
  - In visual studio, right-click the folder "Headers" to add a new header file (the `.h`) and "Source" to add a new source file  (`.cpp`). They don't actually need to be in those folders (you can have the `.h` in "Sources", but it's nice for organization).
  - Keep the names of the class's header file and source file the same, or else it'll be hard to keep track of your work.
- __Constructors__ are called when an instance of a class is made.
  - The default constructor is called either implicitly or explicitly
    - Ex: `string str;` has an implicit call to its default constructor, which sets its c-str member (the actual text) to "\0" (null) and its length to 0.
    - Ex: `string str2()` has an explicit call to its default constructor, which does the same as the implicit call.
  - The overloaded constructor works like overloaded functions, and must be called explicitly
    - Ex: `ifstream infile("data.txt");` has an explicit call to ifstream's overloaded constructor (which takes a c-string as its parameter)
- `CRectangle::` is required to define the bodies of each method in the `CRectangle` class
  - Without this, the compiler won't know if you're creating some random function called "computeArea", or implementing `CRectangle`'s "computeArea".
  - This is generally the same idea with `using namespace std;` and specifying where objects like `cout` exist
    - What I mean in this case is using `std::cout` (and likewise) versus `using namespace std;`
- Keep your constructors and destructors as `public`, or else you can never create/delete your object outside of your class (which makes no sense anyways)

-------------------------------------------------------------------------------

Copyright &copy; 2015 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/2015-Spring-CS-121>
