Readme for Telephone Directory Linked List
This repository contains a C program that implements 
a simple telephone directory using a linked list data structure. 
The program allows users to perform various operations such as 
sorting the directory by number or name, inserting new entries, 
searching for entries by name, and deleting entries by number.

Getting Started
To compile and run the program, you will need a C compiler, such as 
GCC (GNU Compiler Collection). If you don't have GCC installed, you 
can download and install it from the official 
website: https://gcc.gnu.org/

Follow these steps to compile and run the program:

Save the code in a file, e.g., telephone_directory.c.
Open a terminal or command prompt and navigate to the 
directory containing the telephone_directory.c file.

Compile the code using the following command:
gcc -o telephone_directory telephone_directory.c
Run the compiled program:

bash
./telephone_directory

Features
The telephone directory program offers the following features:

Ascending Sort:

Sort the directory by telephone number in ascending order.
Sort the directory by full name (first name and last name) 
in ascending order.
Insertion:

Add a new entry to the directory.
Search:

Find an entry in the directory by providing the first name and last name.
Deletion:

Remove an entry from the directory by specifying the telephone number.
Usage
Once the program is running, you will be presented with a menu of 
operations you can perform on the telephone directory. 
Follow the on-screen instructions to select an option.

To perform ascending sort (by number or name), 
choose option 1 or 2 respectively. The sorted directory will 
be displayed on the screen.
To insert a new entry, choose option 3, and enter 
the telephone number, first name, and last name when prompted.
To search for an entry, choose option 4, and enter the first 
name and last name to find the corresponding telephone number.
To delete an entry, choose option 5, and enter the telephone 
number of the entry you wish to remove from the directory.

File Input
The program reads input data from a file named telephone.txt, 
which should be placed in the same directory as the executable. 
The telephone.txt file should contain entries in the following format:

php
<telephone_number> <first_name> <last_name>
For example:

C
123456 John Doe
789012 Jane Smith
...

Each entry should be on a separate line.

Note
The program uses a linked list data structure to manage 
the telephone directory. As a limitation, the program doesn't 
persist the sorted directory after each operation. Consequently, 
if you perform multiple operations in succession, 
the original directory will be reloaded from the telephone.
txt file before each operation. For a more permanent storage solution, 
consider adding file handling functions to save the sorted directory 
back to the telephone.txt file after each operation.

Conclusion
This C program provides a simple telephone directory management 
system using a linked list. It allows users to sort, insert, 
search, and delete entries efficiently. Feel free to explore, 
modify, and extend the code to meet your specific needs. Happy coding!