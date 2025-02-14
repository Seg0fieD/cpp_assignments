
# Task 1 (8 P.):
## 1. What is the difference between the keywords typedef and using? Also, state one usage example for both. (0.5 P.)
Ans:       
Both **typedef** and **using** are used for creating type aliasing, however, both differs in a few functionality and syntax 

**usage:**
>>**typedef** 
>>>syntax: 
`typedef existing_type new`

>>>example: 
`typedef std::string str;`
`str word = "Wort";`

>>**using**
>>>syntax: 
`using new_type = existing_type`

>>>example:
`using num = int;`
`num x = 15;`


## 2. What are iterators? Name at least 3 different types of iterators and explain their functionalities. (1 P.)
Ans:     
An **iterator** is an object, resembling a pointer, used to iterate over a container's elements. It serves as a crucial link 
between algorithms and containers, facilitating data manipulation. While iterators share similarities with pointers, not 
all iterators have the same functionality. They can be categorized into five types based on their capabilities, such as 
input iterators, output iterators, forward iterators, bidirectional iterators, random-access iterators, such as with the 
outermost being the most powerful and the innermost being the least powerful. 
>3 different types of iterators:-
>>**Random-access Iterator:** It is the most potent iterator in functionality, and goes beyond sequentional movement.
Contrary to their name, they offer the ability to access any element within the container in a non-sequential manner, 
similar to pointers.  

>>**Bidirectional Iteratos:** It is built upon the forward iterators, not only inherits their features but also overcomes 
the limitation of moving in only one direction. Consequently, they can iterate over elements in both directions. 

>>**Forward Iterator:** It is positioned above input and output iterators in the hierarchy and comprises the features of 
both. However, their movement is restricted to a single step in the forward direction. 


## 3. What is a crucial difference between an input and a forward iterator? (0.5 P.)
Ans:     
Crucial difference between an **input** and **forward iterator** is that a forward iterator allows multiple passes over the same 
range, while an input iterator allows only a single pass. Forward iterators support multiple increments and can revisits 
elements, providing more flexibility compared to input interators. 


## 4. Why are iterators to a std::vector invalided by insert, push_back or erase? (0.5 P.)
Ans:    
Iterators to `std::vector` are invalidated by operation like `insert()`, `push_back()` or `erase()` because these operation 
may potentially reallocate memory to accommodate the new elements. When reallocation aoccurs, the existing iterators may no 
longer point to valid memory locations or may point to different elements than intitially intended, which lead to undefined 
behaviour. 


## 5. Which container would you choose and why if
> ####   (a) you need to do sorted traversal and no duplicates are allowed (0.5 P.)
> Ans:     
> `std::set` would be my preferred choice for the task, since it doesn't allow any duplicate keys, and the set is sorted 
> container which allows interating over it efficiently.  
> 
> ####   (b) the order is not important and no duplicates are allowed (0.5 P.)
> Ans:     
> `std::unordered_set` would be my preferred choice in this case, as the unordered set containers don't bother about the 
> order of the set and in addition, it also allows any duplicate keys
> 
> ####   (c) you only need to add elements at the end and want fast traversal (0.5 P.)
> Ans:     
> `std::vector` would be the preferred choice for this task as `std::vector` allows to insertion an element at the end of the 
> container using the `puch_back()` function which allows to storing of the elements in continuous memory blocks enabling a 
> contiguous memory that improve the traversal performance concerning other containers.  
>  
> ####   (d) you need to provide a dictionary that can associate multiple values with the same key (0.5 P.)
> Ans:     
> To store multiple values with one key the best choice would be `std::unordered_multimap` which would store elements in a 
> dictionary-like container. It allows efficient unordered hashing, insertion, and deletion where several values are mapped 
> to one single key. 


## 6. How does an STL algorithm usually indicate "not found" or "failure"? (0.5 P.)
Ans:     
STL algorithm usually indicates **"not found"** or **"failure"** by returning an iterator that points to the end of the 
searched range. The `end()` function points to the **end** and returns the end iterator when a search is performed and the 
desired element is not found. 


## 7. What does std::sort(b,e) use as its sorting criterion? (0.5 P.)
Ans:     
`std::sort(b,e)` uses `<` **less-than operator** as its default sorting criterion, this means that the elements are sorted 
in **ascending order** as the comparison is defined between the first and last element by a less-than operator.


## 8. Why is the STL container set missing a [] (subscript) operator? (0.5 P.)
Ans:    
Container **Set** in STL doesn't have a `[]` subscript because **Set** itself contains elements that are ordered and 
unique by nature, i.e. doesn't hold any duplicates, and direct access with index is not present in its definition.


## References:
1. https://www.w3schools.com
2. https://www.geeksforgeeks.org
3. https://stackoverflow.com 
4. https://quizlet.com/ 
5. https://en.cppreference.com/w/
6. https://cplusplus.com/ 
