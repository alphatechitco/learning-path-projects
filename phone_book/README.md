# Phone Book Management System

This is a simple Phone Book Management System built using C++. The application allows the user to create, read, update, and delete phone records. The records are stored in a file called `PhoneBook.dat`, making it a basic file-based application for managing contact information.

## Features

- **Add New Phone Record**: Create a new phone book entry with details such as Serial Number, Name, Mobile Number, Email ID, and Group.
- **View All Records**: Display all the saved phone records.
- **Search by Serial Number**: Search for a specific record by its serial number and display its details.
- **Delete a Record**: Delete a specific phone record by its serial number.
- **Modify Existing Record**: Update the details of an existing phone record.

## Technologies Used

- C++
- File I/O for data storage
- OpenGL (Optional dependencies for GUI, not used in this implementation)
- GLUT (Optional dependencies for GUI, not used in this implementation)

## Files

- **PhoneBook.dat**: The data file where phone records are stored.
- **PhoneBook.cpp**: Main source file containing the PhoneBook class and implementation logic.

## Installation

1. Make sure you have a C++ compiler (like GCC or Clang) installed.
2. To compile the program, use the following command:

   ```bash
   g++ -o PhoneBook PhoneBook.cpp
