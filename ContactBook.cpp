#include "ContactBook.h"
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
//contact list size
void ContactBook::contact_list_size()
{
	
	SetConsoleTextAttribute(color, 10);
	cout << "*---------------------------*" << endl;
	cout << "|        WELL-COME          |" << endl;
	cout << "*---------------------------*" << endl;
	string size = "INPUT SIZE OF CONTACT LIST:";
	int siz;
	
	cout << size << endl;
	cin >> siz;
	if (siz > preious_size)
	{
		preious_size = siz;
		contact_size = siz;
		group_size = siz;
		contact = new Contact[contact_size];
		address = new Address[contact_size];
		group = new Group[group_size];
		cout << "HOW MANY GROUP IN YOUR CONTACT BOOK" << endl;
		cin >> siz;
		group_size = siz;
		system("cls");
		load_contact_from_file();
		load_group_from_file();
		cout << "NEW SIZE IS UPDATED!" << endl;
	}
	else
		cout << "PLEASE INCREASE SIZE OF CONTACT BOOK" << endl;
	
}

//constructor
ContactBook::ContactBook()
{
	
	menu = "|              MENU                  |";
	line = "*------------------------------------*";
	user_size = "|1.CREATE A CONTACT LIST GIVEN SIZE  |";
	add_new_contact = "|2.ADD NEW CONTACT                   |";
	merge_duplicate = "|3.MERGE DUPLICATE                   |";
	print_contact_sort = "|4.PRINT CONTACT SORTED              |";
	print_contacts = "|5.PRINT CONTACTS                    |";
	search_contacts = "|6.SEARCH CONTACTS                   |";
	display_count_contact = "|7.DISPLAY COUNT OF CONTACTS         |";
	delete_any_contact = "|8.DELETE CONTACT                    |";
	manage_contacts = "|9.MANAGE CONTACTS                   |";
	recent_search = "|10.VIEW SEARCH HISTORY              |";
	groups = "|11.GROUPS DETAIL                    |";
	exit = "|0.TO EXIT                           |";
	
}
//display contact 
void ContactBook::display_menu()
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, 12);
	cout << line << endl;
	SetConsoleTextAttribute(color, 14);
	cout << menu << endl;
	SetConsoleTextAttribute(color, 12);
	cout << line << endl;
	SetConsoleTextAttribute(color, 11);
	cout << user_size << endl;
	cout << add_new_contact << endl;
	cout << merge_duplicate << endl;
	cout << print_contact_sort << endl;
	cout << print_contacts << endl;
	cout << search_contacts << endl;
	cout << display_count_contact << endl;
	cout << delete_any_contact << endl;
	cout << manage_contacts << endl;
	cout << recent_search << endl;
	cout << groups << endl;
	cout << exit << endl;
	cout << line << endl;
	cout << "|";
	SetConsoleTextAttribute(color, 13);
	cout << "DEVELOPER:";
	SetConsoleTextAttribute(color, 14);
	cout << "M.MURSALEEN MUSTAFVI      ";
	SetConsoleTextAttribute(color, 11);
	cout<<"|" << endl;
	SetConsoleTextAttribute(color, 11);
	cout << line << endl;
}

//add new contact
void ContactBook::add_new_contacts()
{
	system("cls");
	SetConsoleTextAttribute(color, 14);
	if (count_contact >= contact_size)
	{
		cout << "CONTACTBOOK IS FULL PLEASE ADD NEW SIZE" << endl;
	}
	else
	{
		cin>>contact[count_contact];
		cin>>address[count_contact];
		++count_contact;
		store_into_contact_file();
	}
	
}

//merge duplicate contacts
void ContactBook::merge_duplicates()
{
	SetConsoleTextAttribute(color, 13);
	for (int i = 0; i < count_contact; i++)
	{
		for (int j = i + 1; j < count_contact;)
		{
			if (contact[i].get_first_name() == contact[j].get_first_name() || contact[i].get_number() == contact[j].get_number())
			{
				for (int k = j; k < count_contact - 1; k++)
				{
					contact[k] = contact[k + 1];
					address[k] = address[k + 1];
				}
				count_contact--;
			}
			else
				j++;
		}
	}
	system("cls");
	cout << "DUPLICATE CONTACTS MERGED SUCCESSFULLY!" << endl;
}
//print sorted contact
void ContactBook::print_contact_sorted()
{
	if (count_contact == 0)
	{
		cout << "NO CONTACT FOUND!" << endl;
		return;
	}

	cout << "CONTACT SORT" << endl;
	cout << "1. BY FIRST NAME" << endl;
	cout << "2. BY LAST NAME" << endl;

	int choice;
	cout << "Enter a valid option: ";
	cin >> choice;
	while (choice < 1 || choice > 2)
	{
		cout << "INVALID INPUT!" << endl;
		cin >> choice;
	}

	for (int i = 0; i < count_contact; i++)
	{
		sort_contact[i] = contact[i];
		sort_address[i] = address[i];
	}

	if (choice == 1)
	{
		// Sort by first name
		for (int i = 0; i < count_contact - 1; i++)
		{
			for (int j = 0; j < count_contact - i - 1; j++)
			{
				if (sort_contact[j].get_first_name() > sort_contact[j + 1].get_first_name())
				{
					// Swap contacts and addresses
					Contact tempContact = sort_contact[j];
					Address tempAddress = sort_address[j];
					sort_contact[j] = sort_contact[j + 1];
					sort_address[j] = sort_address[j + 1];
					sort_contact[j + 1] = tempContact;
					sort_address[j + 1] = tempAddress;
				}
			}
		}
	}
	else
	{
		// Sort by last name
		for (int i = 0; i < count_contact - 1; i++)
		{
			for (int j = 0; j < count_contact - i - 1; j++)
			{
				if (sort_contact[j].get_last_name() > sort_contact[j + 1].get_last_name())
				{
					// Swap contacts and addresses
					Contact tempContact = sort_contact[j];
					Address tempAddress = sort_address[j];
					sort_contact[j] = sort_contact[j + 1];
					sort_address[j] = sort_address[j + 1];
					sort_contact[j + 1] = tempContact;
					sort_address[j + 1] = tempAddress;
				}
			}
		}
	}

	// Print sorted contacts
	system("cls");
	SetConsoleTextAttribute(color, 15);
	for (int i = 0; i < count_contact; i++)
	{
		cout << line << endl;
		cout << "|            CONTACT NO." << i + 1 << "            |" << endl;
		cout << line << endl;
		cout << sort_contact[i];
		sort_address[i].display();
		cout << line << endl;
	}
}


//print all contacts
void ContactBook::print_all_contacts()
{
	system("cls");
	SetConsoleTextAttribute(color, 15);
	for (int i = 0; i < count_contact; i++)
	{

		cout << line << endl;
		cout << "|            CONTACT NO." << i + 1 << "            |" << endl;
		cout << line << endl;
		cout << contact[i];
		cout << address[i];
		cout << line << endl;
		check_dob(contact[i]);
	}
	if (count_contact == 0)
	{
		cout << "NO CONTACT FOUND!" << endl;
		return;
	}
}


//total numbe rof contacts
void ContactBook::display_count_contacts()
{
	system("cls");
	SetConsoleTextAttribute(color, 13);
	cout << "TOTAL CONTACTS IN CONTACT BOOK:" << count_contact << endl;
}

void ContactBook::store_into_group_file()
{
	ofstream file("group.txt");
	if (file.is_open())
	{
		for (int i = 0; i <count_group; i++)
		{
			file << group[i].get_group_name() << endl;
			for (int j = 0; j < group[i].get_member_count(); j++)
			{
				file << group[i].get_member(j) << endl;
			}
			file << endl;
		}
		file.close();
		cout << "CONTACT DATA IS STORED!" << endl;
	}
	else
		cout << "File Not Found" << endl;
}
//conatacts store to file
void ContactBook::store_into_contact_file()
{
	ofstream file("text.txt");
	if (file.is_open())
	{
		for (int i = 0; i < count_contact; i++)
		{
			file << contact[i].get_first_name()<<endl;
			file << contact[i].get_last_name() << endl;
			file << contact[i].get_number() << endl;
			file << contact[i].get_email() << endl;
			file << contact[i].get_d() << endl;
			file << contact[i].get_m() << endl;
			file << contact[i].get_y() << endl;
			file << address[i].get_street_address()<<endl;
			file << address[i].get_city() << endl;
			file << address[i].get_country() << endl;
		}
		file.close();
		cout << "CONTACT DATA IS STORED!" << endl;
	}
	else
		cout << "File Not Found" << endl;
}

void ContactBook::load_group_from_file()
{
	ifstream file("group.txt");
	if (file.is_open())
	{
		string line;
		while (getline(file, line))
		{
			group[count_group].set_group_name(line);
			while (getline(file, line) && !line.empty()) 
			{
				group[count_group].set_member_name(line);
			}
			count_group++;
		}
		file.close();
		cout << "GROUP DATA IS LOADED!" << endl;
	}
	else 
	{
		cout << "GROUP File Not Found" << endl;
	}
}
//contacts load from file
void ContactBook::load_contact_from_file()
{
	ifstream file("text.txt");
	if (file.is_open())
	{
		while (!file.eof())
		{
			string temp;
			getline(file, temp); 
			contact[count_contact].set_first_name(temp);
			getline(file, temp);
			contact[count_contact].set_last_name(temp);
			getline(file, temp);
			contact[count_contact].set_number(temp);
			getline(file, temp);
			contact[count_contact].set_email(temp);
			getline(file, temp);
			contact[count_contact].set_d(temp);
			getline(file, temp);
			contact[count_contact].set_m(temp);
			getline(file, temp);
			contact[count_contact].set_y(temp);
			address[count_contact].set_street_address(temp);
			getline(file, temp);
			address[count_contact].set_city(temp);
			getline(file, temp);
			address[count_contact].set_country(temp);
			count_contact++;
		}
		count_contact--;
		file.close();
		cout << "CONTACT DATA IS LOADED!" << endl;
	}
	else {
		cout << "CONTACT File Not Found" << endl;
	}
}

//overloader to assign value
void ContactBook::operator=(ContactBook ob)
{
	set_first_name(ob.get_first_name());
	set_last_name(ob.get_last_name());
	set_number(ob.get_number());
	set_email(ob.get_email());
	set_street_address(ob.get_street_address());
	set_city(ob.get_city());
	set_country(ob.get_country());
}

//date detail of contact
void ContactBook::update_contact_size()
{
	int old_size;
	old_size = contact_size;
	Contact *temp_contact;
	Address *temp_address;
	temp_contact = new Contact[old_size];
	temp_address = new Address[old_size];
	for (int i = 0; i < old_size; i++)
	{
		temp_contact[i] = contact[i];
		temp_address[i] = address[i];
	}
	contact_list_size();
	for (int i = 0; i < old_size; i++)
	{
		contact[i] = temp_contact[i];
		address[i] = temp_address[i];
	}
	delete[] temp_contact;
	delete[] temp_address;
	temp_contact = nullptr;
	temp_address = nullptr;
}

void ContactBook::search_contact()
{
	system("cls");
	string s;
	SetConsoleTextAttribute(color, 15);
	cout << "SEARCH CONTACT:";
	cin.ignore();
	getline(cin, s);
	history[size_of_history].set_history(s);
	size_of_history++;

	if (count_contact == 0)
	{
		cout << "NO CONTACT FOUND!" << endl;
		return;
	}

	bool contactFound = false;
	bool multiplePhoneMatches = false;
	int phoneMatchesCount = 0;

	for (int i = 0; i < count_contact; i++)
	{
		if (contact[i].get_number().find(s) != string::npos)
		{
			if (phoneMatchesCount == 0)
			{
				system("cls");
			}

			SetConsoleTextAttribute(color, 15);
			cout << line << endl;
			cout << "|            CONTACT NO." << i + 1 << "            |" << endl;
			cout << line << endl;
			cout << contact[i];
			cout << address[i];
			cout << line << endl;
			contactFound = true;
			phoneMatchesCount++;
			if (phoneMatchesCount > 1)
			{
				SetConsoleTextAttribute(color, 13);
				cout << "FOUND IN MULTIPLE CONTACT PHONE NUMBERS" << endl;
				multiplePhoneMatches = true;
				break;
			}
		}
	}

	if (multiplePhoneMatches)
	{
		return;
	}

	for (int i = 0; i < count_contact; i++)
	{
		if (contact[i].get_first_name().find(s) != string::npos ||
			contact[i].get_last_name().find(s) != string::npos ||
			contact[i].get_email().find(s) != string::npos ||
			address[i].get_street_address().find(s) != string::npos ||
			address[i].get_city().find(s) != string::npos ||
			address[i].get_country().find(s) != string::npos)
		{
			if (!contactFound)
			{
				system("cls");
			}

			SetConsoleTextAttribute(color, 15);
			cout << line << endl;
			cout << "|            CONTACT NO." << i + 1 << "            |" << endl;
			cout << line << endl;
			cout << contact[i];
			cout << address[i];
			cout << line << endl;
			contactFound = true;
		}
	}

	if (!contactFound)
	{
		SetConsoleTextAttribute(color, 13);
		cout << "CONTACT NOT FOUND!" << endl;
	}
}

//delete contact and reduce size of total contact
void ContactBook::contact_delete(int indx)
{
	for (int i = indx; i < count_contact - 1; i++)
	{
		contact[i] = contact[i + 1];
		address[i] = address[i + 1];
	}
	contact[count_contact - 1];
	address[count_contact - 1];
	--count_contact;
	
}

//find the contact in all contacts to delete
void ContactBook::find_and_delete_contact()
{
	
	SetConsoleTextAttribute(color, 14);
	int index = 10000;
	cout << line << endl;
	cout << "1.CONTACT NAME" << endl;
	cout << "ELSE.DELETE CONTACT BY LIST NUMBER" << endl;
	cout << line << endl;
	int x;
	cin >> x;
	if (x == 1)
	{

		cout << "INPUT CONTACT TO DELETE:";
		string d;
		cin.ignore();
		getline(cin, d);
		for (int i = 0; i < count_contact; i++)
		{
			if (contact[i].get_first_name() == d)
			{
				index = i;
				contact_delete(i);
			}
			else if (contact[i].get_number() == d)
			{
				index = i;
				contact_delete(i);
			}
		}
		if (index == 10000)
		{
			cout << "CONTACT NOT FOUND!" << endl;
		}
		else
			cout << "CONTACT DELETED SUCESSFULLY!" << endl;
	}
	else
	{
		cout << "INPUT LIST NUMBER YOU WANT TO DELETE CONTACT:";
		cin >> x;
		if (x > count_contact)
		{
			cout << "CONTACT NOT FOUND!" << endl;
		}
		else
		{
			cout << "CONTACT DELETED SUCESSFULLY!" << endl;
			contact_delete(--x);
		}
	}
	store_into_contact_file();
}

//view contact detail update and delete 
void ContactBook::update_delete_contact(int i)
{
	cout << line << endl;
	cout << "|         MANAGE CONTACT              |" << endl;
	cout << line << endl;
	cout << "|1.UPDATE CONTACT                     |" << endl;
	cout << "|2.DELETE CONTACT                     |" << endl;
	cout << "|3.EXIT                               |" << endl;
	cout << line << endl;
	int x;
	cin >> x;
	if (x == 1)
	{
		cout << "*--------------------------*" << endl;
		cout << "|        UPDATE CONTACT   |" << endl;
		cin>>contact[i];
		cin>>address[i];
	}
	else if (x == 2)
	{
		contact_delete(i);
	}
	cout << "CONTACT LIST IS UPDATED!" << endl;
	store_into_contact_file();
}
void ContactBook::contact_list()
{
	SetConsoleTextAttribute(color, 15);
	cout << line << endl;
	cout << "|            CONTACT LIST             |" << endl;
	cout << line << endl;
	for (int i = 0; i < count_contact; i++)
	{
		cout << i + 1 << ".|" << contact[i].get_first_name() << endl;
	}
	cout << line << endl;
}
//manage contact 
void ContactBook::manage_contact()
{
	system("cls");
	if (count_contact == 0)
	{
		cout << "NO CONTACT FOUND!" << endl;
	}
	else
	{
		contact_list();
		cout << "1.CONTACT NAME TO VIEW DETAIL" << endl;
		cout << "ELSE.VIEW CONTACT BY LIST NUMBER" << endl;
		int c;
		cin >> c;
		if (c == 1)
		{
			cout << "INPUT CONTACT TO VIEW DETAIL:";
			string d;
			cin.ignore();
			getline(cin, d);
			for (int i = 0; i < count_contact; i++)
			{
				if (contact[i].get_first_name() == d)
				{
					SetConsoleTextAttribute(color, 15);
					cout << line << endl;
					cout << "|            CONTACT NO." << i + 1 << "            |" << endl;
					cout << line << endl;
					cout << contact[i];
					cout << address[i];
					update_delete_contact(i);
				}
			}
		}
		else
		{
			cout << "INPUT LIST NUMBER YOU WANT TO SEE DETAIL CONTACT:";
			int x;
			cin >> x;
			if (x > count_contact)
			{
				cout << "CONTACT NOT FOUND!" << endl;
			}
			else
			{
				SetConsoleTextAttribute(color, 15);
				cout << line << endl;
				cout << "|            CONTACT NO." << x << "            |" << endl;
				cout << line << endl;
				--x;
				cout << contact[x];
				cout << address[x];
				update_delete_contact(x);
				
			}
		}
	}
}
//destructor
ContactBook::~ContactBook()
{
	
	delete[] contact;
	delete[] address;
	address = nullptr;
	contact = nullptr;
}

void ContactBook::print_search_history()
{
	system("cls");
	if (size_of_history != 0)
	{
		SetConsoleTextAttribute(color, 15);
		cout << "*-------------------------------------------*" << endl;
		cout << "|                SEARCH-HISTORY             |" << endl;
		cout << "*-------------------------------------------*" << endl;
		int c = 0;
		for (int i = size_of_history-1; i >=0; i--)
		{
			history[i].print_history();
		}
		cout << "*-------------------------------------------*" << endl;
	}
	else
	{
		cout << "NO SEARCH HISTORY FOUND" << endl;
	}
}
void ContactBook::print_search_history_frequently()
{
	system("cls");
	if (size_of_history != 0)
	{
		SetConsoleTextAttribute(color, 15);
		cout << "*-------------------------------------------*" << endl;
		cout << "|        FREQUENTLY SEARCH-HISTORY          |" << endl;
		cout << "*-------------------------------------------*" << endl;
		int c = 0;
		for (int i = size_of_history - 1; i > size_of_history - 6 && i >= 0; i--)
		{
			history[i].print_history();
		}
		cout << "*-------------------------------------------*" << endl;
	}
	else
	{
		SetConsoleTextAttribute(color, 13);
		cout << "NO SEARCH HISTORY FOUND" << endl;
	}
}

void ContactBook::group_detail()
{
	system("cls");
	SetConsoleTextAttribute(color, 14);
	string g = "|             GROUP MENU            |";
	
	string c;
	do
	{
		cout << line << endl;
		cout << g << endl;
		cout << line << endl;
		cout << "|1.CREATE GROUP                      |" << endl;
		cout << "|2.VIEW GROUP DETAIL                 |" << endl;
		cout << "|3.ADD MEMBER IN GROUP               |" << endl;
		cout << "|4.DELETE GROUP                      |" << endl;
		cout << "|0.EXIT                              |" << endl;
		cout << line << endl;
		cin >> c;
		if (c == "1")
		{
			if (count_group < group_size)
			{
				string m;
				cin.ignore();
				cout << "ENTER GROUP NAME:";
				getline(cin, m);
				group[count_group].set_group_name(m);
				count_group++;
				cout << "GROUP IS CREATED" << endl;
			}
			else
				cout << "MAXIMUM GROUPS ARE CREATED!" << endl;
		}
		else if (c == "2")
		{
			system("cls");
			if (count_group == 0)
			{
				cout << "NO GROUP FOUND!" << endl;
			}
			else
			{
				cout << line << endl;
				cout << "|               GROUPS               |" << endl;
				cout << line << endl;
				for (int i = 0; i < count_group; i++)
				{
					cout << i + 1 << "|" << group[i].get_group_name() << endl;
				}
				cout << line << endl;
				cout << "VIEW GROUP DETAIL" << endl;
				cout << "1.BY NAME" << endl;
				cout << "2.BY GROUP ID" << endl;
				string x;
				cin >> x;
				if (x == "1")
				{
					string name;
					cout << "INPUT NAME OF GROUP TO SEE MEMBERS:";
					cin.ignore();
					getline(cin, name);
					for (int i = 0; i < count_group; i++)
					{
						if (group[i].get_group_name() == name)
						{
							group[i].display_group();
						}
					}
				}
				else if (x == "2")
				{
					int i;
					cout << "ENTER GROUP NUMBER TO SEE MEMBERS:";
					cin >> i;
					--i;
					group[i].display_group();
				}
				else
					cout << "INVALID INPUT" << endl;
			}
		}
		else if (c == "3")
		{
			string s;
			cout << "SEARCH GROUP  TO ADD MEMBER" << endl;
			cout << "1.BY NAME" << endl;
			cout << "2.BY GROUP ID" << endl;
			cin >> s;
			if (s == "1")
			{
				string t;
				cout << "GROUP NAME TO ADD MEMBER:";
				cin.ignore();
				getline(cin, t);
				for (int i = 0; i < count_group; i++)
				{
					if (group[i].get_group_name()==t)
					{
						int x;
						cout << "CONTACT ID TO ADD IN GROUP" << endl;
						cin >> x;
						--x;
						if (x >= count_contact)
						{
							cout << "NO CONTACT FOUND!" << endl;
						}
						else
						{
							group[i].add_group_member(contact[x]);
						}
					}
				}
			}
			else if (s == "2")
			{
				int x,id;
				cout << "ENTER GROUP ID TO ADD MEMBER:";
				cin >> id;
				id--;
				cout << "CONTACT ID TO ADD IN GROUP" << endl;
				cin >> x;
				--x;
				if (x >= count_contact)
				{
					cout << "NO CONTACT FOUND!" << endl;
				}
				else
				{
					group[id].add_group_member(contact[x]);
				}
			}
		}
		else if (c == "4")
		{
			cout << "INPUT GROUP ID TO DELETE:";
			int temp;
			cin >> temp;
			for (int i = temp - 1; i < count_group; i++)
			{
				group[i] = group[i + 1];
			}
			count_group--;
			cout << "GROUP IS DELETED!" << endl;
		}
		else
			cout << "INVALID INPUT!" << endl;
			
	} while (c != "0");
	if (count_group != 0)
	{
		store_into_group_file();
	}
}
//static initialized
int ContactBook::count_contact = 0;
int ContactBook::count_group = 0;
void ContactBook::check_dob(Contact obj)
{
	int month, day,yr;
	time_t now = time(nullptr);
	tm timeinfo;
	string s;
	if (localtime_s(&timeinfo, &now) == 0)
	{
		month = timeinfo.tm_mon + 1;
		day = timeinfo.tm_mday;
		s = to_string(timeinfo.tm_year + 1900);
	}
	yr = stoi(s);
	int age;
	age = yr - stoi(obj.get_y());
	if (obj.get_d() == to_string(day) && obj.get_m() == to_string(month))
	{
		cout << "AGE IS :" << age << endl;
		cout << "TODAY IS " << obj.get_first_name() << " BIRTHDAY!" << endl;
	}
}