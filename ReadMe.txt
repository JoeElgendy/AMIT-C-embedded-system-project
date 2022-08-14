PLEASE READ THIS FILE


This is a description of the project code 

The project consist of two files the first one is header and the second one is the main 

The header :
consist of struct containing the ID and Year of the student and a struct containing array of courses of 3 and another array of three for the grades
the header contains a global variable db which is array of 10 assuming that the maximum entries wouldn't exced 10

all the variables used inside the header is of type "unsigned chara"
and an enum called bool which returns 0 if False and 1 if True 


the header contains 8 functions:
1- bool SDB_IsFull(void):

this function takes no parameters and return bool
the function performs linear search which search whether any id of the array of db equals to 0 ( since the array is a global variable " stored in heaps which gives them a value of 0 by default"
if any member equals to 0 the flag will be turned into 0 and the function would return false
otherwise, the function will return true

2- uint8 SDB_GetUsedSize(void);
the function returns unsigned charachter and takes no parameter.
its working idea is close to the former function which starts with variable of enteries equals to 0 and increments until it encouter id with a value of 0


3- bool SDB_AddEntry(uint8 id,uint8 year , uint8* subjects, uint8* grades);

this function takes id , year, subjects,grades as a parameter and a for loop to check where is the empty place in order to store the values at
the function then stores the first parameter and second parameter (id,year) at the empty place
the function then makes sure that the grades is within the accepted range (0 to 100) if true it would store the value at the empty place and returns true 
otherwise would return false


4- void SDB_DeleteEntry(uint8 id);
this functions first calls the search to search for the place of the id within the array then assign 0 to all the array memebers


5- bool SDB_ReadEntry(uint8 id,uint8* year , uint8* subjects, uint8* grades);
this function calls the search function to determine the place of the id if the place returns -1 then the id is not found
if its within range it would store the ADDRESSES of the student year , subjects and grades 



6- void SDB_GetIdList(uint8* count,uint8* list); 
this function takes the address of count and the address of list as a parameters
this function takes id , year, subjects,grades as a parameter 
this function calls the bubble sorting function first and then compare each id to check whether its equals to 0( not assigned or not) 
and increment count every time its encounters non zero function 

it also stores the location of the first elemenet of the array in the list variable


7- bool SDB_IsIdExist(uint8 id); 

this function perform the binary search in order to find the array returns true if found and false if not found

8- int search(uint8 id);

this function perform the binary search algorithm on the array in order to find the location of the element and returns its location

9- void bubble_sorting(){
this function performs bubble sorting algorithm on the array in order to sort it from smallest to largest

NOW WITH THE MAIN FILE 
the main file consist of two functions 

the first is the choice function

int choice(void);

the void function ensure that the user inputs a number within the allowed range 
and prints the options to user to choose from within 

and the MAIN function

which consist of 7 switch cases 1 to exit the program and the other to perform the required function


CASE 1: calls the SDB_IsFull function if its true prints its false else print its not full
CASE 2 : Calls the SDB_GetUsedSize and store the return value in an variable called Entries
CASE 3: Takes id and year from the user and store it at an array , then sends its address to the SDB_entry function to store its values on the array of db 
CASE 4: takes id from user and then sends it to SDB_DeleteEntry Function
CASE 5: takes id from user and then send it to SDB_ReadEntry Function which search for the id and store the returns the location of year subjects and grades 
then inside the for loop we print the values stored in the locations
CASE 6: calls SDB_GetIdList send 2 address one to the count and the other to the list the function this modifieds the values
CASE 7: takes id and calls SDB_IsIdExist to search wheter the input exists or not!


NOTE : 
in all array elements within the main we adapted the idea that the Array is nothing but A POINTER to the first element 
so, through out the program we access the array by using the pointers 
