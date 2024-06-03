Contact Book Application
Description
This project is a comprehensive console-based Contact Book application developed in C++. The application provides functionality to manage contacts, addresses, groups, and search history efficiently. The project is structured into several classes to encapsulate the different functionalities:

Contact
Group
Address
ContactBook
search_history
date_timee
Features
Add New Contact:

Input and store contact details including first name, last name, number, and email.
Input and store address details including street address, city, and country.
Manage Contacts:

Update existing contacts.
Delete contacts.
Merge duplicate contacts.
Display the total number of contacts.
Group Management:

Create and manage groups.
Add and remove group members.
Display group details.
Search Functionality:

Search contacts by name, number, email, or address.
View recent search history.
File Operations:

Load contacts and groups from files at startup.
Store updated contacts and groups into files.
Date and Time Handling:

Record the date and time for search operations.
Classes and Methods
Contact Class:

Manages individual contact details.
Provides setters and getters for contact information.
Overloads input and output stream operators for easy I/O operations.
Group Class:

Manages groups of contacts.
Provides methods to add and remove group members.
Displays group information.
Address Class:

Manages address details for contacts.
Provides setters and getters for address information.
Overloads input and output stream operators for easy I/O operations.
ContactBook Class:

Central class managing all contacts, groups, and operations.
Provides a menu-driven interface for user interaction.
Handles adding, updating, deleting, and searching contacts.
Manages file operations for persisting contact and group data.
search_history Class:

Records and displays search history along with date and time.
date_timee Class:

Handles date and time recording for operations.
Dependencies
Windows.h: For handling console colors and clearing the screen.
How to Use
Compile and Run:

Ensure you have a C++ compiler installed.
Compile the code using a command like g++ -o ContactBook main.cpp contact.cpp address.cpp search.cpp contactbook.cpp -std=c++11.
Run the executable ./ContactBook.
Navigate the Menu:

The application starts with a menu displaying various options.
Input the corresponding number to perform an action (e.g., add a new contact, search contacts, etc.).
File Persistence:

Contact data is loaded from text.txt and group data from group.txt on startup.
Any changes made are saved back to these files.
Project Structure
main.cpp: Entry point for the application.
Contact.h and Contact.cpp: Defines and implements the Contact class.
Address.h and Address.cpp: Defines and implements the Address class.
Group.h and Group.cpp: Defines and implements the Group class.
ContactBook.h and ContactBook.cpp: Defines and implements the ContactBook class.
search.h and search.cpp: Defines and implements the search_history and date_timee classes.
Developers
M.Mursaleen Mustafvi
