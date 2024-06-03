#include "Contact.h"
#include <Windows.h>
//setter

void Contact::set_first_name(string nam)
{
	first_name = nam;
}
void Contact::set_last_name(string nam)
{
	last_name = nam;
}
void Contact::set_email(string mail)
{
	email = mail;
}
void Contact::set_number(string num)
{
	number = num;
}
void Contact::input_contact()
{
	cout << "*------------------------*" << endl;
	cout << "|     INPUT NEW DATA     |" << endl;
	cout << "*------------------------*" << endl;
	cout << "|First NAME:";
	cin.ignore();
	getline(cin, first_name);
	cout << "|Last NAME:";
	getline(cin, last_name);
	cout << "|NUMBER:";
	cin >> number;
	cout << "|EMAIL:";
	cin >> email;
}
//getter
string Contact::get_first_name()const
{
	return first_name;
}
string Contact::get_last_name()const
{
	return last_name;
}
string Contact::get_email()const
{
	return email;
}
string Contact::get_number()const
{
	return number;
}
void Contact::display()const
{
	cout << "|First Name:" << get_first_name() << endl;
	cout << "|Last Name:" << get_last_name() << endl;
	cout << "|Contact Number:" << get_number() << endl;
	cout << "|Email:" << email << "@gmail.com" << endl;
}
ostream &operator<<(ostream &output, Contact &obj)
{
	output << "|First Name:" << obj.first_name << endl;
	output << "|Last Name:" << obj.last_name << endl;
	output << "|Contact Number:" << obj.number << endl;
	output << "|Email:" << obj.email << "@gmail.com" << endl;
	output << "|DATE OF BIRTH:" << obj.d << "-" << obj.m << "-" << obj.y << endl;
	return output;
}
istream& operator >> (istream &input, Contact &obj)
{
	cout << "*------------------------*" << endl;
	cout << "|     INPUT NEW DATA     |" << endl;
	cout << "*------------------------*" << endl;
	cout << "|First NAME:";
	cin.ignore();
	getline(input, obj.first_name);
	cout << "|Last NAME:";
	getline(input, obj.last_name);
	cout << "|NUMBER:";
	input >> obj.number;
	cout << "|EMAIL:";
	input >> obj.email;
	cout << "|DATE OF BIRTH" << endl;
	cout << "|DAY:";
	input >> obj.d;
	cout << "|MONTH:";
	input >> obj.m;
	cout << "|YEAR:";
	input >> obj.y;
	return input;
}
void Contact::set_d(string x)
{
	d = x;
}
void Contact::set_m(string x)
{
	m = x;
}
void Contact::set_y(string x)
{
	y = x;
}
string Contact::get_d()
{
	return d;
}
string Contact::get_m()
{
	return m;
}
string Contact::get_y()
{
	return y;
}

//destructor
Contact::~Contact()
{
}

Group::Group()
{
	name = "";
	group_member = new Contact[t_member];
}
void Group::display_group()
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, 15);
	cout << "*-------" << name << "-GROUP" << "---------*" << endl;
	if (m_count == 0)
	{
		cout << "NO MEMBER IN THIS GROUP" << endl;
		cout << "*------------------------*" << endl;
	}
	else
	{
		for (int i = 0; i < m_count; i++)
		{
			cout << i + 1 << "|" << group_member[i].get_first_name() << endl;
		}
		cout << "*--------------------------------*" << endl;
		cout << "1.REMOVE CONTACT" << endl;
		cout << "ELSE ANY KEY" << endl;
		string x;
		cin >> x;
		if (x == "1")
		{
			int s;
			cout << "INPUT CONTACT ID TO REMOVE FROM GROUP:";
			cin >> s;
			--s;
			for (int i = s; i < m_count; i++)
			{
				group_member[i] = group_member[i + 1];
			}
			m_count--;
			cout << "CONTACT IS DELETED!" << endl;
		}
	}
	
}
void Group::add_group_member(Contact obj)
{
	group_member[m_count] = obj;
	m_count++;
}
void Group::set_member_name(string s)
{
	group_member[m_count].set_first_name(s);
	m_count++;
}
int Group::get_member_count()
{
	return m_count;
}
string Group::get_member(int i)
{
	return group_member[i].get_first_name();
}
void Group::set_group_name(string n)
{
	name = n;
}
string Group::get_group_name()
{
	return name;
}
Group::~Group()
{
	delete group_member;
	group_member = nullptr;
}
