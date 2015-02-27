# Week 6 Solutions

## Contents
- [Intro](#intro)
- [Questions](#questions)
  - [Syntax Work](#syntax-work)
  - [Questions (True/False)](#questions-truefalse)
  - [Concept Questions](#concept-questions)

### Intro
This hosts the solutions to the worksheet set for this week's SI sessions.

__There are many ways to solve a problem__. 
My solutions might not always be the most efficient, however I write my solutions in a way to 
explain concepts and to allow others to optimize them however they wish.

### Questions
For the prompt, look at the worksheet file (the .docx file in the file listing above).

If you see any errors or parts are confusing please let me know via email and I'll fix them.

#### Syntax Work
For the syntax work portion refer to the completed project version from [this link](../2015-Spring-CS-121/Weekly Work/Week 6/Worksheet Material/FCylinder_Files). 
You can also access this link by viewing the "FCylinder Files" folder from the Week 6 main page.

I strongly urge you to run the code in Visual Studio and to study its output to get a good grasp on class 
functionality.

#### Questions (True/False)
1. True.
2. False. Check [here](http://stackoverflow.com/questions/2750270/c-c-struct-vs-class) and [here](http://stackoverflow.com/questions/4791883/c-struct-vs-class).
3. False. Destructors are called on an object when you leave the scope of the object (i.e. when they are "destroyed").
4. False. You can have many different types (for instance, FCylinder has three).
5. False. They require the same name, except destructors require a tilde (`~`) in front as well.
6. False. Constructors are only called on declaration of an object.
7. False. They are normally private.
8. True. Since structures are public on default, people that use structs typically don't care if its contents are accessible by outside sources.
9. False. Accessor/getter methods should only return the variables (never change).
10. True. Think of "mutator" as "mutate" meaning "change" and "set" is self-explanatory.
11. False. Since inline functions have their contents pasted onto the lines in which they are referred, it's bad for really big functions (and those called 
extremely frequently). Check [this](http://stackoverflow.com/questions/145838/benefits-of-inline-functions-in-c) too.

#### Concept Questions
1) Implementing "getRadius" and "getHeight" as inline :
```C++
  class FCylinder
  {
    private:
      //...code from before...
    public:
      //...code from before...
      double getRadius(){ return radius; }
      double getHeight(){ return height; }
      //...code from before...
  };
```

The above is an example of a function defined inline in a class. You can make any function inline, e.g. the example 
at [this link](http://stackoverflow.com/questions/145838/benefits-of-inline-functions-in-c) (same as one mentioned in question 11).

2) We want to pass an object by reference to have the ability to change its values. If we pass an object by-value 
through a function and call some function in the object to change one of its member variables then we will only affect 
the object in the function (not the one passed as an argument). This is because we've sent a copy.

We call objects by const-reference because classes can be large. As a class (like a struct) is a collection of data (member variables, 
methods, etc.) a class can be large in general (in terms of byte-size). When working with bigger and bigger objects the amount of time 
and resources it would take to pass an object by-value would increase (and we don't want that). To solve this issue, we call using 
a const-reference parameter.

3) I named the class in case of possible conflicts in the future. Since we want to make our code work forever (or at least for a very 
long time before needing to edit it), if we ever include a library into this project that has a class called "Cylinder" already, the 
compiler will not be able to compile your code. This is because it (the compiler) won't know which class to reference (your Cylinder or 
the included library's Cylinder). 

There are ways around this (namely by using namespaces) but for typical code it's a good idea to give your class a prefix of some sort 
to distinguish it (e.g. I used "F" for "FCylinder").

5) Structures are used typically for making small objects, whereas classes are used for more complicated objects. For instance, if I needed 
an object to account for a student's age, id, and gpa (and only those three things) you can use a structure to quickly code the object. If you 
need something more advanced (e.g. a marketing program that takes into account customers, store transactions, etc. or a level with NPCs in a 
video game) then use a class.

-------------------------------------------------------------------------------

Copyright &copy; 2015 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/2015-Spring-CS-121>
