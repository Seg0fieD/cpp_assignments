# 1. List 8 built-in types provided by C++. (2 P.)
Ans- 
    **1. int=**  integers representation (whole numbers) || ``int num = 32``
    **2. float=**  smallest, single-precision  floating-point numbers || `float num1 = 3.141`   
    **3. double=** larger, double-precision floating-point numbers   || `double num2 =  3.14159265` 
    **4. char=** representation of single character || `char single_charter = 'A';`
    **5. boolean=** boolean vaue representation either true and false || `bool value = true`
    **6. long=**  representation integer-type number  || `long num4 = 7587596475L`
    **7. void=** return type of function that don't return any value || `void funck (){}`
    **8. wchat_t:**   representation of wide characters || `wchar-t wide_charter = L'a';`


# 2. What is the difference between an expression and a statement? Provide an example for each. (1 P.)
Ans-
**Expression** = it is a combination of variables, values, operators, literals and called function that are evaluated 
                 by the compiler to provide certain result. In general an expression does not have any particular order 
                 of execution.
    example:
    `int variable  = pow(a,2) - pow(b,2);`
                    

**Statement** = it can be viewed as a complete line of code that perform a particular action. It can be composed of 
                variable declarations, assignments, flow-control statements as well as function call. Statements imply a particular sequence of execution, which may be influenced by preceding statements in the code.
    example:
        `int main()                                                                                     `
        `{                                                                                              `
        `        int variable = 2;                              // declaration and assignment statement `    
        `        variable += 2;                                         // expression statement         `             
        `        std::cout << "variable value = " << variable << '\n';  //  expression statement        `
        `        return 0;                                              // return statement             `
        `}                                                                                               `


# 3. What is type safety and why is it important? (1 P.)
ANS- 
    Type safety is refered to a control ablity in programming language which allow to check or prevent any error
    at the time of compilation or runtime. A type error arises when an operation is performed on a value that is
    incompatible with that particular operation of that  data type . It aslo ensures that a variable access its authorised memory location which is allowed in a well-defined manner. The importance of Type safety can be  
    recognised as it can catch error in the code in the early phase of development. As C++ being a static and strict type system, it enables the prevention of programming  errors without any performance loss at rumtime. 

# 4. When would a programmer prefer a switch-statement over an if-statement?(0.5 P.)
Ans-
    When there are multiple condition or cases to be checked, then switch case statement is used as its performance is much faster during execution where as if-statement will have reduced performance during execution if there are multiple conditions or case. The switch-statement create a "jump-table" during compilation by inspecting the each case constants and depending on the expression's value a particular path is decided during execution.

# 5. What is a common problem with switch statements? Provide an example. (1P.)
Ans-
    Disadvantage of Switch statement:
        1. unlike if-else statement, switch case statement does not support complex logicical expression which might require additional nested logic or condition within one single case.
        2. No type-safety as it cannot ensure that all cases are of same type or expression matches with the cases, thus leadind to error or bugs in the code. 
        3. Limited gloabal scope as it cannot be used swith on strings or class types directly.  


# 6. Name one operation available for strings but not for integers and one operation available for integers but not for strings. (1 P.)
Ans-
One operation available for strings but not for integers is **string concatination**, which is joining for two string 
        example: 
        `std::string str1 = "Darth";    `
        `std::string str2 = "Vader";    `
        `std::string name = str1 + str2;`

        Output
        __________

        Darth Vader

One operation available for integer but not for string is **Arithmetic operation**, which are mathemetic operation such as addition, substration, multiplication and division. 
    example: 
    `int num1 = 5;`
    `int num2 = 7;`
    `int sum = num1 + num2;`

    Output
    _________

    12


# 7. Explain what are references and pointers. Provide examples for each. (2 P.)
Ans-
**Pointer:**    > it is a variable that holds a memory address of another variable.
                > it can be initilized during declaration or later in the program.
                > pointer can be nullpointer or have null values or uninitilized.
                > it requires dereference operator to access the values.
                > it can be reassign to point to a different variable. 
                > it is majorly use in dynamic memory allocation and manipulation.
            example:

`            #include <iostream>                                               `
`            using namespace std;                                              `
`            int main()                                                        `
`            {                                                                 `
`                int num = 5;                                                  `

`                int& ref_num = num;                                           `

`                cout << "Num: " << num << '\n;                                ` 
`                cout << "Value of num by referencing: " << ref_num << '\n';   `
`                                                                              `
`                ref_num = 50; // changing the value of num by referencing     `

`                cout << "Altered value of Num:"  <<  num << '\n';             `
`                                                                              `
`                return 0;                                                     `
`            }                                                                 `



**Reference:**  > it is aliasing for variable that already exists.
                > it must be initilized during declaration.
                > values cannot be null or remain uninitilized 
                > it cannot be reassigned to refer another variable.
                > it is mostly used in the function parameter to avoid the need to duplicate large objects.
                example:

`            #include <iostream>                                                `
`            using namespace std;                                               `
`            int main()                                                         `
`            {                                                                  `
`                int num2 = 7;                                                  `

`                int* pNum = &num2;                                             `

`                cout << "Num: " << num2 << '\n;                                `
`                                   // pointer dereferencing                    `
`                cout << "Value of num by referencing: " << *pNum << '\n';      `
`                                                                               `
`                ref_num = 35; // changing the value of num by using pointer    `

`                cout << "Altered value of Num:"  <<  num2 << '\n';             `
`                                                                               `
`                return 0;                                                      `
`            }                                                                  `



# 8. Explain the relationship between pointers and arrays (and C-strings). Provide examples. (2 P.)
Ans-
The relationship between pointer and arrays(and C-string):
 array can be considered as contigious block of memory and  array itself act as pointer  to the first element. Where as pointer also address of a storag location with a defined type. However, pointer variable store an address of only one variable at a time. Whereas array can store a number of elements the same size as the size of the array variable. 

 example:
 `int number[7] = {'1','2','3','4','5','6','7'};                    `
 `int *ptr = number; // array name as pointer                         `
`
 `// using pointer arithmetic  to access element of array               `
 `int element = *(ptr + 2);                                               `
`
 `// relationship with C-string                                          `
 `char string1[] = "Numbers";                                               `
 `char *chrPtr =  string1;  // array name as a pointer to character's first   `


# 9. Explain the pass by value and pass by reference concepts. Provide examples. (1 P.)
Ans-
**Pass-by-value:** passing a copy of the variable  to the method. More specifically, value  of actual argument is copied and passed to the function parameter. Also it allows simplicity and safety. 
    
**Pass-by-reference:** passing access of the variable to the method. Specifically, the address of the actual argument is passed to the function parameter. It adds efficiency to large data structure and ablity to modify original data.   
    
example: 
`           #include <iostream>                                          `
`           using namespace std;                                         `
`           void swaping(&s1, &s2)                                       `
`           int main()                                                   `
`           {                                                            ` 
`           string s1 = "Cool";                                          `
`           string s2 = "Super";                                         `
`                                                                        `
`           swaping(s1, s2);    // pass-by-value                         `
`                                                                        `
`           cout << s1 << '\n';                                          `
`           cout << s2 << '\n';                                          `
`                                                                        `
`           return 0;                                                    ` 
`           }                                                            `
`                                                                        `
`           void swaping(string &s1, string &s2)  // pass-by-reference   `
`           {                                                            `
`               string ch_t;                                             `
`                                                                        `
`               ch_t = s1;                                               `
`               s1 = s2;                                                 `
`               s2 = ch_t;                                               `
`           }                                                            `


# 10. Explain the terms declaration and definition. (1 P.)
Ans- 
**Declaration:**    It is generally announcing the existance of an entity with a specific name alongwith its data type and other characterstic  for variable, function, classes without any memmory allocation or detalis of implementation. It is usually visible to compiler and it is needed to accept the reference to the identifier.  

**Definition:** It generally instanties and implementation for variable. Also allows details for fucntion and classes 
about how they should work in the program.

Every definition is a declaration but every declartoin is not a definition. 


# 11. What is a namespace and what is its typical use? (1 P.)
Ans-
Namespace is a defined/declarative area containing identifier, such as name type, function and variables which provide a scope for identifiers. The  prime purpose  of namespace is to organize our code in systemic manner and also allows us to prevent naming conflicts while including multiple libraries in large project.   

# 12. Why should you avoid using directives in a header? (0.5 P.)
Ans-
It is best to avoid using directives in a header file due to namespace pollution.Also when a file  includes a header then it will inherite the entire namespace into the scope. This will result in  ambiguity and collison in names which will he tough to debug. Therefore it is recommended to use specified or qualified names in the head file, and if the names are lenghthy then we should consider using  aliasing for proper representation.  

# 13. List four kinds of errors and provide an example for each. (2 P.)
Ans- 
Four types of errors:
**1. Syntax Error:** This error mostly occures when the rule of writing a code/programming is voilated. It is also referred to as compile-time error. These type of error are indicated by compiler before compilation. 
    example:
`            #include <iostream>                                               `
`            using namespace std;                                              `
`            int main()                                                        `
`            {                                                                 `
`                int a = 2                                                      `
`                int b = 3;                                                     `
`                cout << a + b                                                  `
`               return 0;                                                       `
`               }                                                               `
        -->missing semicolon at the end of expression int a = 2  and cout will cause syntax error.

**2.Runtime Error:** This error occurs during when the program is running. Since the compilation work succussfully this error won't arise during compilation. Runtime error occurs due to various reason such as using a modulus operator during a division, incorrect capitilization or mispelled name of function and variables. 
    example:
`            #include <iostream>                                               `
`            using namespace std;                                              `
`            int main()                                                        `
`            {                                                                 `
`                char array[2];                                                 `
`                array = {'A', 'B', 'C', 'D', 'E'};                              `
`                cout << a + b                                                  `
`                return 0;                                                       `
`               }                                                               `
            --> here the array length is declared to be 2  whereas the element that are being stored is 5

**3. Logical Error:** Logical error arise due undesire result due to wrong use of logic in the programming, even though we used a correct syntax. Suppose we included a semicolon at the end of a loop which might be syntactically correct, but it might display a output a blank loop which was not what we intended. 
    example:
`            #include <iostream>                                                `
`            using namespace std;                                               `
`            int main()                                                         `
`            {                                                                  `
`                int num = 4;                                                   `
`                if(num %2 != 0 )                                               `
`                {                                                              `
`                   cout <<"The number is odd." <<'\n';                         `
`                }                                                              `
`                else                                                           `
`                {                                                              `
`                   cout <<"The number is Even." <<'\n';                        `
`                 }                                                             `
`                return 0;                                                      `
`               }                                                               `
             --> here the if condition should be if the number is even it should be if num % 2 == 0 not the other way


**4. Semantic Error:** Semantic error occurs when the meaning of the statement in the code is wrong even though it is syntactically correct statement or expression. This error can aslo be viewed as grammatical error.
    example:
`            #include <iostream>                                                `
`            using namespace std;                                               `
`            int main()                                                         `
`            {                                                                  `
`                int num1 = 4, int b = 5, c;                                  `
`                a + b + 9.80 = c;                                                     `
`                cout << c << '\n';                                             `
`                return 0;                                                      `
`               }                                                               `
            
       --> here the expression a + b + 9.80 = c is semantically incorrect (correct way : c = a + b + 9.80), also since the data type of c is int therefore the output won't consider the decimal postion of the number 9.80


# 14. What is the free store and for what reasons might one use it? (1 P.)
Ans-
The free store can also be referred as a pool of memory that can used to dyanmically allocate memory for object in C++ during the code's execution.
One can use free store for reasons as follows:
    1. Dynamic memory allocation - allows free store to dynamically allocate memory during runtime.
    2. Variable lifetime beyond scope- memory allocated on the free store exists untill deallocated.
    3. Data structure with dyanamic size- free store allow to duanmic allocate memory to accomodate varying structure of resiazable array
    4. Resourse Management- allow to manage resourse for object size and enable for good clean up when such objects are deleted. 

# 15. How do you allocate memory and about what do you need to be careful? Provide an example. (1 P.)
Ans-
In C++ memory can be allocated dynammically using the operator *new* as it returns a pointer to the memory it is allocatd to. 
`            #include <iostream>                                          `
`            using namespace std;                                                    `
`                int main()                                                                          `
`                {                                                                                   `           
`                    int dyanmicNumber = new int;  // memmory allocation for number on free store    `
`                    *dynamicNumber = 75;           // assigning a value to dynamic memory           `
`                    cout << *dynamicNumber << '\n';  // using the allocated memory                  `
`                    delete *dynamicNumber;  // deleting the allocated memory to prevent memory leak `
`                    return 0;                                                                       `
`                }                                                                                   `
Thing need to be taken care of while allocating memory allocation are:
    > avoding memory leaks, therefore use of delete operator after using the new operator to free the allocated memory.
    > using a pointer to deallocate memory should be used with caution as a pointer pointing to a freed memory space can lead to an undesired behaviour.
    > memory allocation using array can lead to error therefore if we use new[] operator we need to be carefully match with  delete[] operator to free up the memory space. 


# 16. How do you safely allocate/manage memory? (1 P.)
Ans-
We can safely allocate and manage memory in following ways:
    1. Using smart pointers, such as "std::unique_ptr" and "std::shared_ptr" ratther than using raw pointer for input.As smart pointer automatically manages memory spaces while taking care of deallocation when a object is not need anymore. 
    2. as mentioned before, using the the raw pointer as less as possible to avoid errors, even if a raw pointer is used it is better to use it with conjuction with a smart pointers that can efficiently perform memory managment.
    3. Using containersuch as "std::vector", "std::list" , "std::map" when dealing with collection of objects as these container can perform memory management efficiently. 


# 17. What is RAII? (1 P.)
Ans-
RAII: Resource Acquisition in Initialization  in C++ allows realiable memory management. It links the line-spane of resources that is required to be acquired before use, such as heap memory, socket, threads, files disk spaces or data base connection. RAII also ensures that a resource is accessible to any function which is accessing that object, thereby eliminiating the requirement for unnecessary runtime tests. In addtion, RAII also ensure that all resources are released  in the reverse order of acquisition. 






# **References**
1. https://en.cppreference.com/
2. https://learn.microsoft.com/en-us/cpp/cpp/cpp-language-reference?view=msvc-170
3. https://www.geeksforgeeks.org/c-plus-plus/?ref=shm_outind
4. https://stackoverflow.com/
5. https://coders-corner.net/




