# Week 15

## Contents
- [Intro](#intro)
- [Topics](#topics)
  - [Tuesday](#tuesday)
    - [Exception Handling](#exception-handling)
    - [`enum`](#enum)
  - [Wednesday](#wednesday)
    - [Recursion](#recursion)
    
### Intro
This hosts the activities we worked on during the SI class on Tuesday and Wednesday, 4/26 & 4/27.

### Topics

Below is a list of the Tuesday & Wednesday session notes. 

#### Tuesday
Topics discussed:
- Exception Handling
- `enum`

##### Exception Handling
[This](http://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm) page and the PowerPoint notes have plenty of information on exception handling.

##### `enum`
Enumerated types allow you to easily create distinct data types, where the value of that data type is a fixed constant value (like '0', '1', etc.).

Example scenarios for usage:
- Menus (each option can be in an enumerated type)
- Calendar (days/months in their own enumerated types)

I can't think of any other examples other than the above two for now. They have a bit of a limited usage, but they still can be useful in specific cases.

For more in-depth information, check out this [cppreference page](http://en.cppreference.com/w/cpp/language/enum) on `enum`.

#### Wednesday
Topics discussed:
- Recursion

##### Recursion
As we have talked about this already there isn't much to add. Below is the gist of recursion and a few examples of where recursion can be applied.

A recursive function is a function that calls itself. Like an iterative process (a looping structure such as a `for` or `while` loop), a recursive function 
repeats until it encounters a stopping condition.

The two parts of a recursive function are its recursive call (the call to itself) and its base case (the condition of where to stop recursively calling).

Examples of recursion: 
- Factorial function: `f(n) = n * f(n-1)`, where `f(0) = f(1) = 1` is the base case.
- Euclidean method of solving for the GCD of two numbers (code example below) (iterative solution and explanation [here](http://people.cis.ksu.edu/~schmidt/301s12/Exercises/euclid_alg.html))
  - NOTE: The page shows both a subtraction (first example) and modulus solution (bottom of page). Both can be converted to a recursive solution.
- Anything else that can be solved iteratively (i.e. with a `for` or `while` loop)

One recursive GCD solution (the subtraction version):

```C++
  long gcd_sub(long m, long n) {
    if(m == n)
      return m;                   //optionally, return n as they're both the same here
    else {
      if(m > n)
        return gcd_sub(m-n, n);   //first recursive call
      else
        return gcd_sub(m, n-m);   //other recursive call
    }
  }
```

Other recursive GCD solution (modulus version):

```C++
  //This function is to make the recursive function easier to write (no need to see which is bigger)
  long gcd_mod(long K, long M) {
    if(k < m) {     //swap the two numbers if m is greater
      long temp = m;
      m = k;
      k = temp;
    }
    //Run the actual recursive function
    return gcd_mod_helper(k, m);
  }
  
  //Actual recursive function; explained iteratively here: http://people.cis.ksu.edu/~schmidt/301s12/Exercises/euclid_alg.html
  long gcd_mod_helper(long k, long m) {
    if(m == 0)
      return k;          //this is explained more on 
    else {
      return gcd_mod_helper(m, k%m);  //use the chart at the bottom of the euclid_alg link to understand this more
    }
  }
  
```

-------------------------------------------------------------------------------

Copyright &copy; 2015 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/2015-Spring-CS-121>
