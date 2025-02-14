# Task 1 (8 P.):
## 1. What is the difference between a struct and a class? (0.5 P.)
Ans:    
    Both **struc**t and **class** are types of classes. However, the struct's default access type is **public** and the class's default type is **private**.

## 2. Why should the public interface to a class be as small as possible? (1 P.)
Ans:    
    The public interface to a class be as small as possible because (1) a small public interface allows a high level of abstraction which lets the user interact with the class interfaces easily. (2) limits access to the internal details of the code by enabling encapsulation, thereby preventing risk of unintended use and any external modification. (3) allows flexibility to modify the implementation of classes. 

## 3. What is the difference between const and static? (0.5 P.)
Ans:    
**Constant Function** is declared using **"const"** keyword. It prevents any object modification or non-constant function call. It states that a function is a read-only function and does not allow any objection alteration when it is called. 

**Static Function** is declared using **"static"** keyword. It only allows access for only static data members, therefore it cannot access any non-static data member or call a non-static function. It can be invoked independently of the existence of the object class which helps in maintaining and unifying the instances of the class member function across several class objects.  

## 4. Why should you distinguish between functions that modify objects and those that do not? (1 P.)
Ans:    
    Distinguishing between functions that modify objects and those that do not are necessary because it helps to maintain the code's readability and clarity. Also, the function that modifies an object has a predictable behavior which helps to understand the code and maintains consistency thereby preventing any unintended error or bugs. In addition, separating altering object functions from non-altering object functions allows encapsulation to ensure a structured code.

## 5. What is the concept and effect of inline functions? When would you prefer inline functions over function calls? (0.5 P.)
Ans:    
    The concept of the **inline** function is that when a function is called at any instance of the code, it directly inserts the code of the function at the instance when it is being called. The keyword **"inline"** indicates to the compiler that it should replace the function call with the actual code contained in the function. This results in performance improvement of the program by eliminating the function overhead associated with it when the function is called.  

## 6. What is a destructor and when is it called? What is the typical consequence of its usage? (1 P.)
Ans:    
    **Destructor** are special function that is used to deallocate the memory when the class and its objects and function members are eliminated and not in use anymore. It is usually called when the lifetime of the object ends or when the object passes out of scope or when the object is eliminated. Typical consequences of a destructor are memory deallocation using the keyword "delete", closing files that are already opened, finalizing the state of an object, and customer cleanup of class objects depending on the logic of the object function.    

## 7. In which context are virtual functions used? (1 P.)
Ans:    
    The **virtual function** is mostly used in the case of **object-oriented programming(OOP)**, since it is inheritable and can be overridden and implemented dynamically. These functions or methods are an essential part of runtime polymorphism in OOP. 

## 8. What is the semantic result of combining the keywords friend and virtual for a class function? Explain and state reasons for your observations. (1 P.)
Ans:    
    Combining the keywords **"friend"** and **"virtual"** is usually a conditory as these keywords serve different purposes.    
    **"friend"** is a non-member function that is usually declared outside the scope of the class and can have access to private and protected code segments of the class and its representatives.    
    **"virtual"** is a base class function that can be overridden with the use of a derived class. It makes sure that the function call for an object is correct disregarding the expression to make the function call.   
    Combining these two keywords does not have any specific consequences regarding polymorphism or access control. The implementation of the "friends" keyword does not affect the nature of the virtual function as it still can be overridden by using a derived class if the virtual keyword is declared.  

## 9. When would you make a virtual member function pure? (0.5 P.)
Ans:    
    A **virtual member function** can be declared pure using **"=0"** syntax by declaring it to its base class without providing any implementation in the base class. Creating a virtual member function pure can be the reason for making an abstract class, imposing a common interface for a derived class and dynamic implementation of run-time polymorphism.

## 10. What are pitfalls of multiple inheritance? (0.5 P.)
Ans:    
    Pitfalls of multiple inheritance:
    (1) a class inheriting from two classes that have a common ancestor could lead to ambiguousness as it can complicate the method's resolution, also regarded as a diamond problem.
    (2) the dynamic binding and polymorphism enable the code to be easier and extendable but using multiple inheritance introduces complexity and makes it difficult to track.


# 11. What is the difference between a concrete class and an interface? (0.5 P.)
Ans:    
    The difference between a **concrete class** and an **interface** is that a concrete class comprises both functions and interfaces. Whereas an interface specifies a set of methods without any details about its implementation. Classes can only inherit from one concrete class but can execute multiple interfaces. 





## References:
    1. https://learn.microsoft.com/en-us/cpp/cpp
    2. https://cplusplus.com/
    3. https://en.cppreference.com/w/
    4. https://www.ibm.com/docs
    5. https://stackoverflow.com
    6. https://www.geeksforgeeks.org


