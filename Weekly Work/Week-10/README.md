# Week 10

## Contents
- [Intro](#intro)
- [Topics](#topics)
  - [Tuesday](#tuesday)
    - [`this` pointer and Constant Methods](#this-pointer-and-constant-methods)
    - [`friend` classes](#friend-classes)
    - [`static` keyword](#static-keyword)
  - [Wednesday](#wednesday)
    - [Copy Constructors](#copy-constructors)
    - [Operator Overloading](#operator-overloading)
  
### Intro

This hosts the activities we worked on during the SI class on Tuesday and Wednesday, 3/24 & 3/25.

Check out the `Worksheet Material` folder above (in the file listing) for the worksheet we worked on.

### Topics

Below is a list of the Tuesday & Wednesday session notes. 

#### Tuesday
Topics we discussed:
- `this` pointer and Constant Methods
- `friend` classes
- `static` keyword

And, although we did discuss the two topics from Wednesday's session, I split the notes up for page cleanliness.

##### `this` pointer and Constant Methods
Used inside a class method, the `this` pointer refers to the object that called the method (i.e. itself). Sounds weird, but a few reasons for using `this` are:
- Copy constructor
- Assignment operator (overload)
- Improving readability of your code

Whenever you use a class member variable or method within a class, `this->` is implied. For instance, two ways to implement a getter method (for getting the radius) for a `Circle` class:

One way:
```C++
  double Circle::getRadius()
  {
    return radius;
  }
```

Second way:
```C++
  double Circle::getRadius()
  {
    return this->radius;
  }
```

Both examples above do exactly the same operation. The first implies `this->`, and the second (which is more readable in my opinion) uses `this->` explicitly.

[Here's](http://stackoverflow.com/questions/993352/when-should-i-make-explicit-use-of-the-this-pointer) a good reference for this as well as the powerpoint notes.



A `const` method is pretty straightforward: You cannot edit anything inside of the method. This is useful for making sure you do not edit anything within, for instance, a getter method.

More info on constant methods:  http://stackoverflow.com/questions/751681/meaning-of-const-last-in-a-c-method-declaration

##### `friend` classes
A `friend` of a class has access to all of its member variables and methods. Think of it like allowing someone to look at a diary (or whatever you hold dear to yourself). You wouldn't want just anyone looking at it (e.g. not made `public`), rather those you trust (e.g. a `friend` class).

Although there are times where you will need to make a class a `friend` of another, I find myself using a lot for the `ostream` and `istream` classes, namely to use the `<<` and `>>` operator overloads properly (which is noted in this week's worksheet). 
[This page](http://stackoverflow.com/questions/17434/when-should-you-use-friend-in-c) has a few notes on applications of `friend`, although it's mainly about GUI design so watch out for technical jargon.

Plenty of notes on [this page](http://www.programiz.com/cpp-programming/friend-function-class) about `friend` classes.

##### `static` keyword
[This page](http://stackoverflow.com/questions/15235526/the-static-keyword-and-its-various-uses-in-c) helps a lot.

#### Wednesday
Topics we discussed:
- Copy Constructors
- Operator Overloading

##### Copy Constructors
Working very similarly to the assignment operator, a copy constructor allows you to define an instance of a class with a pre-existing one.

The general format is as follows:
```C++
  YourClass(const YourClass& other_to_define_with)
  {
    //...do copying here...
  }
```

Remember that we pass by `const` because we do not wish to change the passed object in any way, and `&` lets us pass-by-reference, or more specifically send a pointer to the original object we're passing through.

[Here's](http://www.tutorialspoint.com/cplusplus/cpp_copy_constructor.htm) a good example of a copy constructor.

If you're not working with pointers in classes, making a copy constructor is generally useless (as the assignment operator does that work for you already, on default). Otherwise, it's crucial (as long as you need the pointers to be deep-copied, not shallow-copied).

[Here](http://stackoverflow.com/questions/184710/what-is-the-difference-between-a-deep-copy-and-a-shallow-copy) on reference to deep/shallow copy. 

##### Operator Overloading
Gist of this is that we can define how an operator works on a class.

Example of operator overloading:

If we had a `Dog` class with the `+` operator overloaded (i.e. we want to add two `Dog` instances together):
```C++
  int Dog::operator+(const Dog& left, const Dog& right)
  {
    return 5; //as defined above, for this example I want to return an integer after adding two Dog instances.
  }
```

If both `husky` and `retriever` were `Dog` instances, doing the following:
```C++
  cout << "A husky and a golden retriever added yields: " << husky + retriever << endl;
```

Will display:
```
  A husky and a golden retriever added yields: 5
```

Jokes aside, there are practical uses to operator overloading. For a few examples:
- Defining a `MathVector` class and doing operations with it (e.g. dot product, crossproduct, addition, etc.)
- Creating your own array class, so you can do operators like appending two arrays (`+` operator, naturally)
- etc.

Two operators I overload a lot are the `<<` (insertion) operator, which allows for printing objects easily, and the `>>` (extraction) operator, for defining a class instance by user input. An example of each is in this week's worksheet's notes/solutions.

The most useful resource I've found regarding operator overloading is [this StackOverflow page](stackoverflow.com/questions/4421706/operator-overloading/4421719). Especially under "Common operators to overload", the page hosts a ton of examples regarding operator overloading.

Another resource that might seem useful: http://www.thegeekstuff.com/2013/09/cpp-operator-overloading/

-------------------------------------------------------------------------------

Copyright &copy; 2015 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/2015-Spring-CS-121>
