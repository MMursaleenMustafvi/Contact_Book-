#include<iostream>
#include "ContactBook.h"
#include<Windows.h>

using namespace std;
int main()
{
	ContactBook contacts;
	string check;
	contacts.contact_list_size();//size of book from user
	do
	{
		contacts.display_menu();
		cin >> check;
		if (check == "1")//for new size
		{
			contacts.update_contact_size();
			
		}
		else if (check == "2")//add new contact
		{
			contacts.add_new_contacts();
		}
		else if (check == "3")//merge duplicate
		{
			contacts.merge_duplicates();
		}
		else if (check == "4")//print sorted contact
		{
			contacts.print_contact_sorted();
		}
		else if (check == "5")//print all contacts
		{
			contacts.print_all_contacts();
		}
		else if (check == "6")
		{
			contacts.search_contact();//search contact
		}
		else if (check == "7")
		{
			contacts.display_count_contacts();//display total number of contacts
		}
		else if (check == "8")
		{
			contacts.find_and_delete_contact();//contact delete
		}
		else if (check == "9")
		{
			contacts.manage_contact();//contact manage
		}
		else if (check == "10")
		{
			string s;
			cout << "1.ALL SEARCH HISTORY" << endl;
			cout << "2.FREQUENTLY SEARCH HISTORY" << endl;
			cin >> s;
			if (s == "1")
			{
				contacts.print_search_history();
			}
			else
				contacts.print_search_history_frequently();
		}
		else if (check == "11")
		{
			contacts.group_detail();
		}
		else if (check == "0")//exit
		{
			cout << "THANK YOU!" << endl;
		}
		else
			cout << "Invalid Input Again!" << endl;
	} while (check != "0");
	system("pause");
	return 0;
}
