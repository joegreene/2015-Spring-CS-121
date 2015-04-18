# Week 13

## Contents
- [Intro](#intro)
- [Topics](#topics)
  - [Tuesday](#tuesday)
  - [Wednesday](#wednesday)
    - [Extra Notes on Inheritance](#extra-notes-on-inheritance)
    - [Factory Functions](#factory-functions)
    - [`virtual` Keyword](#virtual-keyword)
  
### Intro

This hosts the activities we worked on during the SI class on Tuesday and Wednesday, 4/14 & 4/15.

Check out the `Worksheet Material` folder above (in the file listing) for the worksheet we worked on.

### Topics

Below is a list of the Tuesday & Wednesday session notes. 

#### Tuesday
We talked about the same stuff each session, so all the notes are beneath "Wednesday" notes.

#### Wednesday
Topics we discussed:
- Extra Notes on Inheritance
- Factory Functions
- `virtual` Keyword

##### Extra Notes on Inheritance
Two important notes regarding class inheritance:

1) __Classes only know of other classes in their branch.__ For instance with an `Animal` hierarchy, a `Dog` knows of `Animal` but doesn't know of a `Cat`. A `Poodle` knows of a `Dog` but not of a `Persian` cat. Classes only go above or below themselves, not across branches.

2) __How constructors/destructors are called__. Before creating an object of a class, it first checks if it has a parent. If so, it tries to invoke its parent constructor. Same goes with the parent's parent, and so on until it reaches the top. The default constructor of each is called (unless specified by an initialization list).


##### Factory Functions
A factory function is a function that is supposed to create and return instances of a class based off of parameters it is given.

For instance assume we have an `Employee` parent class, and its children are `Accountant`, `HR`, and `Executive`. An example implementation may look like the following: 

```C++
  class Employee 
  {
    protected: //we use this so children may inherit it but it is still inaccessible outside of the class
      string name;
      int id;
    public:
      Employee( string name, int id )
      {
        this->name = name;  //use "this->" to specify where "name" comes from on left side
        this->id = id;      //alternatively, change name and id in param list to "n, i" and use "this->name = n" or "name = n"
      }
      //NOTE: This overload is just an example of how to make one, if for reason you needed to have some comparison check.
      //      between two types of Employees
      bool operator==( const Employee& rhs) const  //first constant for unchanging 'rhs', second to prevent editing anything inside method
      {
        //alternatively, name == rhs.name && id == rhs.id, but using "this->" is more readable
        return (this->name == rhs.name) && (this->id == rhs.id);
      }
      void yell_job()
      {
        std::cout << "I AM AN EMPLOYEE!\n";
      }
  };
  
  class Accountant : public Employee  //we use "public" to inherit all protected and public members of Employee as they are
  {
    protected:
      string boss_name;  //couldn't think of a good member specific to Account other than their boss's name
    public:
      Accountant( string name, int id, string boss_name ) : Employee(name, id) //use initialization list to specify call to parent constructor
      {
        this->boss_name = boss_name;
      }
      void yell_job()
      {
        std::cout << "I AM AN ACCOUNTANT!\n";
      }
  };
  //..HR and Executive follow the same format as Accountant, differing with implementation of "yell_job"...
```

If we wanted to have a function generate each type of Employee (and put them into a list), an example of the function may look like:

```C++
  Employee* make_emp( string name, int id, string boss_name, int emp_type)
  {
    Employee* e = nullptr;
    
    //Assume we set it up so: 0 = Accountant, 1 = HR, 2 = Executive
    switch(emp_type)
    {
      case 0:
        e = new Accountant(name, id, boss_name);
        break;
      case 1:
        e = new HR(name, id, boss_name);
        break;
      case 2:
        e = new Executive(name, id, boss_name);
        break;
      default:
        cout << "ERROR: INVALID EMPLOYEE TYPE. RETURNING NULL";
    }
    return e;
  }
```

Adding new employees to a list would look something like:
```C++
  vector< Employee* > emp_list;
  
  Employee* e = make_emp("Bob", 00001, "NONE", 2);
  emp_list.push_back(e);
  
  e = make_emp("Jill", 21133, "Bob", 0); //we can reuse this because emp_list[0] is keeping track of the previous employee now
  emp_list.push_back(e);
  //..etc...
```

If, however, we plan to call "yell_job" from each employee, we come to an issue. As "emp_list" sees each position as a
`Employee*`, the following would output for four employees (in a `for` loop):
```
  I AM AN EMPLOYEE
  I AM AN EMPLOYEE
  I AM AN EMPLOYEE
  I AM AN EMPLOYEE
```

Which is not what we want because we want to print `I AM AN ACCOUNTANT` for an `Accountant`, and so on for the others. This can be fixed by two methods:

1) Using "static_cast" to convert the `Employee*` to another type (which doesn't help so much in our case):
```C++
  //This unfortunately doesn't help since we want to have different types of Employees in the list
  static_cast<Accountant*>(emp_list[i]).yell_job();
```

2) Using the `virtual` keyword.

##### `virtual` keyword
The `virtual` keyword allows you to have polymorphic, meaning "many forms", code. For our case referring to methods, 
it tells the compiler to check for other versions of a created method.

Specifically, to fix the `I AM AN EMPLOYEE` error from the previous section, we need to tweak the classes a bit:
```C++
  class Employee 
  {
      //...everything else in the class is the same as before...
      virtual void yell_job()
      {
        std::cout << "I AM AN EMPLOYEE!\n";
      }
  };
  
  class Accountant : public Employee  //we use "public" to inherit all protected and public members of Employee as they are
  {
    //...everything else in the class is the same as before...
      virtual void yell_job()
      {
        std::cout << "I AM AN ACCOUNTANT!\n";
      }
  };
  //...HR and Executive follow the same format as Accountant, differing with implementation of "yell_job"...
```

This now tells the program to check if any derived classes have different implementations of the "yell_job" method, and will 
use their implementations if available.

Note also we can have pure virtual methods, which means derived classes __must__ implement the inherited method:
```C++
  virtual void yell_job() = 0;
```

If a class has a pure virtual method in itself, the class itself cannot be instantiated or made as a `new` instance dynamically. 
Children that implement the method can still, which is good for us. This is a good technique to pick up, especially in this case 
since there is no such thing as a generic `Employee`.

-------------------------------------------------------------------------------

Copyright &copy; 2015 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/2015-Spring-CS-121>
