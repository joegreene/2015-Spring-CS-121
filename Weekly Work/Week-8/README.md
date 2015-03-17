# Week 8

## Contents
- [Intro](#intro)
- [Topics](#topics)
  - [Tuesday](#tuesday)
    - [`cctype` and ASCII Value](#cctype-and-ascii-value)
    - [Array Insertion Via `char`](#array-insertion-via-char)
    - [By-Reference vs By-Value](#by-reference-vs-by-value)
  - [Wednesday](#wednesday)
  - [Examples from Class Thursday](#examples-from-class-thursday)
  
### Intro

Sorry guys that this took forever to complete. Most of the material here is stuff that was mentioned either in lab or in lecture, 
so at least not too much is lost from the delay.

This hosts the activities we worked on during the SI class on Tuesday and Wednesday, 3/10 & 3/11.

### Topics

Below is a list of the Tuesday & Wednesday session notes. 

If there are any issues with the below work please let me know.

Also, because a lot of material discussed this week was repeated from last week, I decided not to add those notes here. 
Check out last week's page if you would like to cover that material as well.

#### Tuesday

Topics we discussed:
- `isalpha` and ASCII Value
- Array Insertion Via `char`
- By-Reference vs By-Value

##### `cctype` and ASCII Value

For the following two sections, it's best to have [this chart](http://www.asciitable.com/) open in another tab, especially when looking at hexadecimal values .

Two ways to determine what type of character you have is either by use of the `cctype` library, or by directly referring to the character's ASCII value. 

For instance, two ways to determine if some `char ch` is a letter is to do the following:
```C++
  //cctype way
  if(isalpha(ch))
    //...do something...
  
  //ASCII-value way (first the upper-case range, then lower-case range)
  if((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)
    //...do something...
```

For checking if `char ch` is a ["C"-locale white-space character](http://www.cplusplus.com/reference/cctype/isspace/):
```C++
  //cctype way
  if(isspace(ch))
    //...do something...
    
  //ASCII-value way
  if(ch == 32 || ch == 9  || ch == 10 || 
     ch == 11 || ch == 12 || ch == 13) //if ch is ' ' or '\t' or '\n' or '\v' or '\f' or '\r'
    //...do something...
```

The latter can be cumbersome, especially since we already have functions from `cctype` to do the long boolean expression work for us. Main thing to get here is that it is important to recognize  
`char` can be evaluated as `int`, which proves to be quite helpful in the next section of these notes.

At the bottom of [this page](http://www.cplusplus.com/reference/cctype/) is a reference of how the `cctype` functions use ASCII values to determine their outputs.

Note however that, on the side, the ASCII values are given in hexadecimal format. It might be a good idea to use either a number base converter (base 16, hexadecimal, to 
base 10, decimal) or simply refer to the ASCII value chart noted previously and look at the corresponding values from there.

For future reference: The '0x' portion is just standard notation for signifying that you're writing in hexadecimal format. For instance, `0x42` is the hexadecimal 
value for `66` in decimal since `4 * 16^1 + 2 * 16^0 = 64 + 2 = 66`.

##### Array Insertion Via `char`

Through your current knowledge on ASCII values, try to determine what the following code does:
```C++
  vector<string> lists[26];         //we set each index up as "a = first index, b = second index, ... , z = last index"
  string str;
  cin >> str;
  
  char index = tolower(str[0]);
  lists[index-'a'].push_back(str);  //note that each index of lists is a vector of strings
```

First four lines are (hopefully) simple: 
1. We first make an array of 26 slots, where each slot is a vector of strings (i.e. a dynamic array of strings per slot). The comment of this line above refers specifically to its usage in this application.
2. Create `string` variable named `str`
3. Grab a string from console input
4. Set a char called index to the *lower case* version of the first character in `str`

The fifth line is a little funky, but if we think of `index` and `a` as integers, it makes perfect sense.

Recall that the ASCII value for `a` is `97`. If we subtract whatever .

Make sense? If not, take a look at the examples below:
```
  1. str = "Anteater"
     index = a (this is the lower case version of the first character in str)
     lists[index-'a'] = lists['a' - 'a'] = lists[97 - 97] = lists[0] //we push a string into this position, as mentioned in the above code
  
  2. str = "IAmCool";
     index = i (lower case version of first character in str)
     lists[index-'a'] = lists['i'-'a'] = lists[105 - 97] = lists[8] //we push a string into this position, known as position 9 or index 8
     
  3. str = "Supercalifragilisticexpialidocious" 
```

Try out the third one first on your own. Remember to refer to the ASCII chart (unless you've for some reason calculated/memorized the value).

Click the area below this text for the solution.
>! index = s

>! lists[index-'a'] = lists['s'-'a'] = lists[115-97] = lists[18] //push str into the 19th vector of strings in lists


##### By-Reference vs By-Value

Firstly, [here is a great real-life example](http://stackoverflow.com/questions/373419/whats-the-difference-between-passing-by-reference-vs-passing-by-value).

Secondly, I pretty much restated what the notes and [this page](http://www.cs.fsu.edu/~myers/c++/notes/references.html) mention in the session, so take a look at them 
if you'd like review on them.

#### Wednesday

If I recall correctly, everything discussed Wednesday for this week was already mentioned in the Tuesday lecture.

#### Examples from Class Thursday

Below are four examples that were roughly similar to what was discussed in class on Thursday of this week. 
The errors of each are located below each segment (hover to view solution).

1) PROBLEM:
   ```C++
     int sum = 1;
     int arr[] = {5, 2, 3, 4, 9, 6, 7};
     for(i = 1; i < arr.length(); i+=1) 
     {
       sum+=arr[i];
     }
     cout << sum << endl; //what is sum with/without change to i?
   ```
   
   SOLUTION (Hover/Click to view):
   
   >! Errors: - starting sum should be 0, 
   
   >!         - undeclared i in for loop, 
   
   >!         - no "length" function for arrays

2) PROBLEM:
   ```C++
     void print_menu()
     {
       cout << "Select a movie:\n1. Spider man\n2. Hello World\n3. Shawshank Redemption\n4. Exit\n";
       cout << "Enter option: ";
     }

     int main()
     {
       int choice;
       do 
       {
         print_menu;
         cin << choice;

         switch(choice)
         {
           case '1':
             cout << "Spider man";
           case '2':
             cout << "Hello World";
           case '3':
             cout << "Shawshank Redemption";
           case '4':
              cout << "Exiting program...";
           default:
              cout << "Invalid option";
         }
         cout << endl;  

       }while(choice != 4);
       return 0;
     }
   ```
   
   SOLUTION (Hover/Click to view):
   
   >! Errors:- Missing '( )' for call to print_menu
   >!        - cin using insertion operator (should be extraction)
   >!        - Using single quotes for cases (i.e. don't use quotes if checking integer)
   >!        - Missing break statements (every case requires except default)

3) PROBLEM:
   ```C++
     struct Employee {
       string name;
       int ssn;
     }
     
     void init_employee(struct e)
     {
       cout << "Enter employee name (use hyphens for spaces): "
       cin >> name;
       cout << "Enter employee's ssn: ";
       cin >> ssn
     }

     int main()
     {
       Employee emp
       init_employee(emp);    

       cout << emp;
       cout << employee;
       cout << ssn;

       return 0;
     }
   ```
   
   SOLUTION (Hover/Click to view):
   
   >! Errors: - Invalid parameter in struct version of init_employee (should be Employee e)
   
   >!         - struct is missing semi-colon at end of it
   
   >!         - Must call by-reference/pointer for both init_employee
   
   >!         - Two missing semi-colons in both init_employee (first cout, second cin)
   
   >!         - Can't directly call "cout << emp;" in main (emp is an Employee)

4) PROBLEM:
   ```C++
     vector<double> dbl_list;

     dbl_list.add(3.14);
     dbl_list.add(2.718);
     dbl_list.add(33.4412312);

     int i = dbl_list.length() - 1; //set equal to last index of dbl_list

     while(dbl_list.empty())
     {
       cout << dbl_list[--i] << " ";
       dbl_list.pop_back();
     }
   ```
   
   SOLUTION (Hover/Click to view):
   
   > Errors: - No "add" function in vector (use push_back)
   >         - No "length" function with vectors. Use "size()"
   >         - "--i" gives erroneous results (and not even necessary as we can call ".back()")

-------------------------------------------------------------------------------

Copyright &copy; 2015 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/2015-Spring-CS-121>
