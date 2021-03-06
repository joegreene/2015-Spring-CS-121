# Week 10 Solutions

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
1) Using the given `==` and `<` operator overloads, we can do the following (remember that `this` is a pointer!):

```C++
  bool Dog::operator>  (const Dog& rhs)  { return !(*this < rhs) || (*this == rhs)); }
  
  bool Dog::operator<= (const Dog& rhs) { return !(*this > rhs); }  //alternatively, (*this < rhs || *this == rhs)
  
  bool Dog::operator>= (const Dog& rhs) { return !(*this < rhs); }  //alternatively, (*this > rhs || *this == rhs)
                                                                    //alternatively, (*this >= rhs)
  bool Dog::operator!= (const Dog& rhs) { return !(*this == rhs); }
```

Hooray for reusability!

__NOTE 1__: To understand how to get these answers, think of how the logic works (this part's isn't too hard, especially 
if you've taken a circuits class or any sort of logic course):

```
  1. "greater than" is equivalent to saying "not less than or equal to"
  2. "less than or equal to" is the same as saying "not greater than" OR saying "less than OR equal to"
  3. "greater than or equal to" is the same as saying "not less than" OR saying "greater than OR equal to"
  4. The last one in the above list is trivial.
```

Main idea is to know that you can define other operators with ones you have already have defined.

__NOTE 2__: If you want to be super safe with the comparison operators, you can enforce nothing gets edited 
inside of the method by making the method `const`, like so:

```C++
  bool Dog::operator== (const Dog& rhs) const //<--- const here!
  {
    return ((this->age == rhs.age) && (this->name && rhs.name));
  }
```

2) I apologize if the instructions for this were a bit confusing, but here's an example solution of what I was looking for:

```C++
  //more efficient way than `using namespace std;`
  using std::istream;
  
  //Class
  class Pokemon
  {
    private:
      int health;
      int attack;
      int defense;
      int speed;
      //...etc....
    public:
      //...etc....
      friend istream& operator>>(istream& input, Pokemon& pkmn);
  };
  
  //We're reading from the input stream 'input' and are referring to the Pokemon class instance 'pkmn'
  istream& operator>>(istream& input, const Pokemon& pkmn)
  {
    //lazy example, assumes integers are separated by spaces
    input >> pkmn.health  >> pkmn.attack
          >> pkmn.defense >> pkmn.speed;
    
    //the operation expects the istream object to be returned
    return input;
  }
```

-------------------------------------------------------------------------------

Copyright &copy; 2015 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/2015-Spring-CS-121>
