# Task 1
## 1. Why is it dangerous to return a reference when you must return an object? (1 P.)
**Ans:**     
It is because if the reference object goes **out of scope** or is **deleted**, it leads to a **dangling** reference. A dangling reference point to memory that may have been deallocated which might cause some undefined behavior such as access violation at runtime when the reference is dereferenced. Therefore to remedy this issue it is better to return the object by value or use smart pointers to manage the object's lifetime.


## 2. What is an implicit interface in the context of compile-time polymorphism? (1 P.)
**Ans:**     
In **compile-time polymorphism**, an **implicit** interface refers to the shared set of operations(function/ method) among different classes or types. Unlike explicit interfaces, implicit interface is not explicitly declared but is based on the compatibility of function signatures. Classes with a matching implicit interface can be used interchangeably in certain contexts. 


## 3. Why should you prefer range member functions to their single-element counterparts? (1 P.)
**Ans:**     
It is beneficial to use range member function over single-element counterparts because:     
> **(a) Conciseness and Readability:** Rang member functions offer a concise and readable syntax for handling multiple elements, enhancing code clarity.      
> **(b) Performance Optimatiztion:** They can optimize performance through an efficient algorithm  or parallel processing, potentially outperforming single-element operations.       
> **(c) Consistency:** promotes a consistent coding style, aligning with modern C++ standard library conventions for better maintaibability.    
> **(d) Avoiding Redundant Code:** Encapsulates common operations, reducing the need for explicit loops or repetitive code, leading to more concise and error free code.      
> **(e) Support for Different Data Structures:** Designed to seamlessly work with various data structures, making code adaptable to different contexts.  


## 4. Why should you avoid in-place modification of keys in a set? (1 P.)
**Ans:**     
**In-place** modification of keys in a **Set** in c++ should be avoided because **Sets** are **ordered** collections that rely on the integrity of their keys for efficient organization and data retrieval. Modifying a key directly can disrupt the internal structure of the set, potentially leading to incorrect ordering or unexpected behavior. Further, modifying keys can compromise the set's consistency, making it difficult to retieve elements based on their original ordering. It's generally recommended to remove the element with the old key and insert the modified element with the new key to ensure the proper functionin of the set. 


## 5. Why should predicate functions be pure? (1 P.)
**Ans:**     
It is recommended to use  pure predicate functions because:          
> **(a) Deterministic Behavior:** pure function are deterministic, the output is solely determined by their input parameters. The predictability is crucial for maintaining consistent and reliable program logic. 

> **(b) Avoiding side Effects:** pure function don't modify external state or have side effects, making them safer to use in varioius context. Side effects can result in unexpected behaviour, making code harder to reason about and maintain. 

> **(c) Facilitating optimization:**  Pure function are more amenable to optimization by compilers. The absence of side effects allows compilers to perform common optimizations like memoization or reordering function calls, enhancing overall performance. 

> **(d) Ease of Testing:** Pure functions are inherently easier to test because they don't rely on external state. This makes it simpler to isolate and verify their behaviour through unit testing, contributing to more robust and maintainable code. 


## 6. Why should you avoid the default capture modes of lamdbas? (1 P.)
**Ans:**     
Avoiding **default capture** modes in **lambdas** in advised to prevent unintended access to variables. Default captures, spicifically by reference `&`, may lead to dangling references or unexpected modifications outside the lambda's scope. Explicitly specifying captures enhances code's clarity, reduces potential bugs and make the lambda's behaviour more predictable.     


## 7. What do std::move and std::forward do? (2 P.)
**Ans:**     
`std::move()` and `std::forward()` are utility functions that facilitates efficient resource management.

>  **`std::move()`**: it indicates that an object can be safely treated as a **rvalue**, enabling the efficient transfer of ownership or resources. It converts an **lvalue** into a **rvalue** reference, allowing for moves instead of deep copies during assignments or functions call.  
        
**example:**      
`std::vector<int> src = {5, 6, 7}; `        
`std::vector<int> dst = std::move(scr);`         

> **`std::forward`**: it enables perfect forwarding in function templates, preserving the value category (**lvalue** or **rvalue**) of the passed argument. It is typically used in template function to forward arguments, maintaining their original value category(**lvalue** or **rvalue**).    
   
**example:**      
`template <typename T>`        
`void forward(T&& arg)`        
`{`        
`   func(std::forward<T>(arg));`        
`}`        


## 8. How are the strings of a `std::set<std::string*>` sorted? How you would make them sorted lexicographically? Provide the necessary  code. (2 P.)
**Ans:**       
The elements in a `std::set<std::string*>` are sorted by default based on the **lexicographical** order of the string they point to. The comparison in **Set** is done using **less-than operator** `<` for the type pointed to. When `std::set<std::string*>` is used the elements are pointed to `std::string`objects, and sorting is based on the comparison of these pointers.       

> **example:**        
                                   
`#include <iostream>`                                   
`#include <set>`                                   
`#include <string>`                                   
`                    `                                   
`int main()`                                   
`{`                                   
`    std::set<std::string*> setOf_string;`                                   
`                                `                                   
`    std::string str1 = "Audi";`                                   
`    std::string str2 = "BMW";`                                   
`    std::string str3 = "Porsche";`                                   
`                                `                                   
`    setOf_string.insert(&str1);    `                                   
`    setOf_string.insert(&str2);`                                   
`    setOf_string.insert(&str3);`                                   
`                                `                                   
`    for (const auto& ptr : setOf_string)`                                   
`    {`                                   
`        std::cout << *ptr << " ";`                                   
`    }`                                   
`    return 0;`                                   
`                                `                                   
`}`

> in this example above the strings pointed to by the pointer in the `std::set` will be sorted in the **lexicogical** order, and the following will be the result.             
> **output:**                            
>> `Audi BMW Porsche`    
 