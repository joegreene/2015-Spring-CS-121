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

`CRectangle.h`:
```C++
  #include <iostream>
  
  class CRectangle
  {
    private:
      //
    public:
     //
  };
```

`CRectangle.cpp`:
```C++
  //TODO
  CRectangle::CRectangle()
  {
    //
  }
```
`main.cpp`:
```
  //TODO
  #include "CRectangle.h"
  
  int main()
  {
    //TODO
    return 0;
  }
```
-------------------------------------------------------------------------------

Copyright &copy; 2015 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/2015-Spring-CS-121>
