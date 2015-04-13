# Week 12

## Contents
- [Intro](#intro)
- [Topics](#topics)
  - [Tuesday](#tuesday)
  - [Wednesday](#wednesday)
    - [Class Inheritance](#class-inheritance)
    - [Invoke Parent Constructor Explicitly](#invoke-parent-constructor-explicitly)
  
### Intro

This hosts the activities we worked on during the SI class on Tuesday and Wednesday, 4/7 & 4/8.

Check out the `Worksheet Material` folder above (in the file listing) for the worksheet we worked on.

### Topics

Below is a list of the Tuesday & Wednesday session notes. 

#### Tuesday
N/A

#### Wednesday
Topics we discussed:
- Class Inheritance
- Invoke Parent Constructor Explicitly

There isn't too much to the notes for this week since the topics for this week are noted quite well in the power point notes and are widespread online.

##### Class Inheritance
There are tons of resources for this material online that help well, such as [this link](http://www.tutorialspoint.com/cplusplus/cpp_inheritance.htm).

You'll also want to note how constructors/destructors of a class hierarchy are called:

__Constructors__: Highest class in the hierarchy is called, then second-highest, all the way down to the class's parent, then its own constructor is called.

__Destructors__: Own destructor is called, then parent, then parent's parent, etc.

##### Invoke Parent Constructor Explicitly
You mainly need to do this if you want to call a specific constructor of a base/parent class. Otherwise, the default constructor is called automatically.

I think [this stackoverflow link](http://stackoverflow.com/questions/120876/c-superclass-constructor-calling-rules) explains how to do so very well already, so here you go.

-------------------------------------------------------------------------------

Copyright &copy; 2015 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/2015-Spring-CS-121>
