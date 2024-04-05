## ABOUT
This was the second half of the C++ Module projects.

Sumarizing:
- Module 05. The debut of the complexities of exception handling. It's all about ensuring robust class designs that can gracefully handle unexpected situations during runtime. From basic exception handling mechanisms to more advanced techniques of managing exceptions within a class hierarchy, the learning curve here is steep but enlightening. The exercises range from straightforward class design alterations to incorporate exception handling to employing this mechanism in inheritance and polymorphism contexts, emphasizing the importance of reliable execution logic in software development.
- Module 06. The spotlight turns to C++ casts, exploring the nuanced world of type conversions in C++. This module demystifies the various casting operators available in C++, including static_cast, reinterpret_cast, and dynamic_cast. Through a set of exercises that challenge my understanding of type safety, type conversion, and polymorphic behaviors, I've gained invaluable insights into the safe and effective use of casts in C++, an essential skill for any software developer aiming to write clean, efficient, and maintainable code.
- Module 07. Delving into the realm of C++ templates, uncovering the power and flexibility of generic programming. Here, the exercises delve into template functions, including swapping, finding minimum and maximum values, and iterating with templates. It's a deep dive into how templating allows for writing more general, reusable code, crucial for efficient algorithm implementation, and creating versatile data structures. This module truly broadened my horizons, teaching me to appreciate the elegance and functionality that templates bring to C++ programming.
- Module 08. Templated containers, iterators, and algorithms, taking a closer look at the sophisticated machinery of the C++ Standard Template Library (STL). The exercises present practical applications of function templates, container manipulation, and the integral use of iterators and algorithms for efficient data management and manipulation. This module stands out by demonstrating the STL's capabilities, from sorting and searching algorithms to custom iterator implementations, reinforcing the versatility and power of C++ in managing complex data structures.
- Module 09. Last focus on the STL. This last module covers practical exercises ranging from implementing a bitcoin exchange calculator, to solving problems with Reverse Polish Notation and applying the Ford-Johnson algorithm for sorting. Through these challenges, I've practiced using various STL containers and algorithms, following the C++98 standard. The exercises aim to deepen understanding of C++ and its application in real-world scenarios.

## HOW TO USE
#### COMPILATION AND EXECUTION
#### 1º - Clone the repository
```bash
git clone https://github.com/lubuper/42cursus
```

#### 2º - Enter the project folder and run `make`
```bash
cd CPP 05-09/CPP0X/ex0X
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
