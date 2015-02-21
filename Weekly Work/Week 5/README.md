# Week 5

## Contents
- [Intro](#intro)
- [Topics](#topics)
  - [Tuesday](#tuesday)
  - [Wednesday](#wednesday)
    - [Vectors](#vectors)
    - [Input Text Files](#input-text-files)
    
### Intro
This hosts the activities we worked on during the SI class on Tuesday and Wednesday, 02/17 & 2/18.

### Topics
Below is a directory for the Tuesday and Wednesday notes from this week.

#### Tuesday
N/A

#### Wednesday
We talked about the following topics:
- Vectors and Various Applications of Vectors
- Input Text Files

##### Vectors
Vectors are simply resizable arrays.  Unlike the static arrays we're used to, their lengths are 
determined dynamically (that is, the amount of space they take up can change while the program is 
running).

If you wanted to make a vector of vectors (which works similarly to two-dimensional arrays, declare 
the type of vector inside of the vector's body. Example:
```C++
  vector< vector<int> > two_dim_int; //makes a two-dimensional int array
```

Note that vector of vectors are sometimes referred to as "jagged-arrays". This is because each position of the vector is a vector, 
and each vector at each position doesn't have to be the same size as other positions (which, if drawn out, can give a "jagged" effect).

For more dimensions just add more "vector <...>" inside. Just make sure to match-up the angled brackets (i.e. amount of `<` and `>` must be equal).
```
  vector<vector<vector<vector<vector<int>>>>> this_is_out_of_control;
```

Next, we talked about adding and removing elements to a vector. Check [here](http://www.cplusplus.com/reference/vector/vector/push_back/) for 
adding values, and [here](http://www.cplusplus.com/reference/vector/vector/pop_back/) for removing values.

Last thing we talked about was accessing positions of a (multidimensional) vector, which is just like a multi-dimensional array:
```C++
  cout << example_vector[0];     //print to console the first position (index 0) of example_vector
  cout << two_dim_vector[2][3];  //"                  " row 3, column 4 (index 2,3) position of two_dim_vector
  cout << example_vector.at(2);  //"                  " another way to print the third (index 2) position of example_vector
```

There is plenty of information of how to use vectors on [the cplusplus page](http://www.cplusplus.com/reference/vector/vector/). 
Scroll down and scavenge around for anything you need. Other websites and tutorials, and the power point notes, work as well.

From experience, these are the the vector functions I use most:
- push_back
- pop_back
- size
- empty
- clear
- at

##### Input Text Files
This section was a recap of last week, so nothing new is here. Check last week's notes if you want to learn about these.

-------------------------------------------------------------------------------

Copyright &copy; 2015 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/2015-Spring-CS-121>
