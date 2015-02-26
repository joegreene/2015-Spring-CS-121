# Week 6

## Contents
- [Intro](#intro)
- [Topics](#topics)
  - [Tuesday](#tuesday)
    - [`enum`](#`enum`)
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
In a concise way of explaining it: `enum` allows you to create a list of variables that are increments of one another.
 
^---FIX DEF 

You can define the starting list by setting the first value equal to something. Default is `0`.

Although used infrequently, enum is especially helpful when developing a menu-driven program. For instance, 
take a program that has a choice menu such as the following:

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

You can have C++ syntax similar to the following:
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
Starting off with a simple example (which is pretty similar to the one in the worksheet), 

-------------------------------------------------------------------------------

Copyright &copy; 2015 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/2015-Spring-CS-121>
