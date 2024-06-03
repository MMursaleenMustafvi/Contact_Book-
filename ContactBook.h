#include<iostream>
#include "Contact.h"
#include"Address.h"
#include"search.h"
#include<string>
#include<ctime>
#include<fstream>
#include<windows.h>
using namespace std;
const int temp_capacity = 1000;//temerary memory used for sort contact and history
class ContactBook :public Contact, public Address
{
	int preious_size = 1;//use to increase size of book
	int size_of_history=0;
	int group_size;
	static int count_contact;
	static int count_group;
	int contact_size;//contact book size
	Contact *contact;
	Address *address;
	Group   *group;
	search_history history[temp_capacity];
	Contact sort_contact[temp_capacity];
	Address sort_address[temp_capacity];
	string menu;
	string line;
	string user_size;
	string add_new_contact;
	string merge_duplicate;
	string print_contact_sort;
	string print_contacts;
	string search_contacts;
	string display_count_contact;
	string delete_any_contact;
	string manage_contacts;
	string recent_search;
	string groups;
	string exit;
	
public:
	ContactBook();
	void check_dob(Contact obj);
	void contact_list_size();
	void display_menu();
	void add_new_contacts();
	void store_into_contact_file();
	void load_contact_from_file();
	void store_into_group_file();
	void load_group_from_file();
	void merge_duplicates();
	void print_all_contacts();
	void print_contact_sorted();
	static void display_count_contacts();
	void operator=(ContactBook ob);
	void update_contact_size();
	void search_contact();
	void contact_delete(int indx);
	void find_and_delete_contact();
	void contact_list();
	void  manage_contact();
	void update_delete_contact(int i);
	void print_search_history();
	void print_search_history_frequently();

	void group_detail();
	~ContactBook();
};