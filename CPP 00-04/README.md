## ABOUT
This set of small projects was my initiation to C++. For me it was an overly less constrained version of C (in steroids) as I no longer needed to answer to the 42 norm.

Sumarizing:
- Module 00. I dived into the fundamentals, exploring classes, member functions, the standard I/O stream, initialization lists, and the use of static. This lays down the groundwork with exercises like string manipulation and command-line argument handling, all the way to more complex tasks involving classes, object instantiation, and basic file I/O operations.
- Module 01. The focus shifts to memory management — a critical aspect of C++ programming. This includes learning about memory allocation, pointers to members, and file streams, setting the stage for understanding how C++ interacts with computer memory and file systems.
- Module 02. Introduction to ad-hoc polymorphism, operator overload, and canonical classes. This is where fixed-point numbers, the Orthodox Canonical Form, and more nuanced aspects of C++ such as operator overloading for comparison, arithmetic, and increment/decrement operations come into play.
- Module 03. it's all about inheritance. This encompasses class implementations that demonstrate inheritance, constructor and destructor chaining, and how to deal with the complexities of multiple inheritances, such as the diamond problem.
- Module 04. This rounds out the curriculum with discussions on subtype polymorphism, abstract classes, and interfaces. These exercises push me to apply polymorphism more abstractly and thoughtfully, dealing with MEMORY management, deep copies, and the essential concepts of abstract and pure abstract classes.

## HOW TO USE
#### COMPILATION AND EXECUTION
#### 1º - Clone the repository
```bash
git clone https://github.com/lubuper/42cursus
```

#### 2º - Enter the project folder and run `make`
```bash
cd CPP 00-04/CPP0X/ex0X
make
```

#### 3º - Run the executable
```bash
./example
```

#### MAKEFILE RULES

`make` or `make all` - Compile files.

`make clean` - Delete all .o (object files) files.

`make fclean` - Delete all .o (object files) and .a (executable) files.

`make re` - Use rules `fclean` + `all`.
