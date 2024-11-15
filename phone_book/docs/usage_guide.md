
### 1. Save New Phone Record

- **Option**: `1`
- **Description**: This option allows you to create and save a new phone record.
- **Inputs**:
  - Serial Number (unique identifier)
  - Name
  - Mobile Number
  - Email ID
  - Group (e.g., Family, Friends, Work, etc.)
- **Action**: After entering the information, the record will be saved to `PhoneBook.dat`.

### 2. Display All Saved Records

- **Option**: `2`
- **Description**: This option displays all the phone records that have been saved to the file.
- **Action**: The system will read and display the records from the `PhoneBook.dat` file.

### 3. Search Specific Record

- **Option**: `3`
- **Description**: This option allows you to search for a specific phone record by its serial number.
- **Inputs**:
  - Serial Number (the number associated with the record you want to search)
- **Action**: The program will search for the record and display its details if found.

### 4. Delete Specific Record

- **Option**: `4`
- **Description**: This option allows you to delete a specific phone record by its serial number.
- **Inputs**:
  - Serial Number (the number associated with the record you want to delete)
- **Action**: If the record is found, it will be deleted from the file, and the remaining records will be preserved.

### 5. Modify Existing Record

- **Option**: `5`
- **Description**: This option allows you to modify the details of an existing phone record by its serial number.
- **Inputs**:
  - Serial Number (the number associated with the record you want to modify)
  - New details (Name, Mobile Number, Email ID, Group)
- **Action**: The record will be updated with the new details, and the file will be updated accordingly.

### Exit Program

- **Option**: `0`
- **Description**: This option exits the program.

---

## Notes:

- **File Persistence**: The data is stored in `PhoneBook.dat`. If the program is run again, the records will be available for viewing, modification, or deletion.
- **Error Handling**: The program will show appropriate messages if the specified serial number for a search, delete, or update operation is not found.

---

Feel free to enhance the program by adding more features like searching by name, sorting the records, or using a more advanced database management system in the future!

If you encounter any issues, check the console for error messages and ensure that the file permissions for `PhoneBook.dat` allow reading and writing.
