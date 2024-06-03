#include<iostream>
#include<string>
using namespace std;
//contact class

class Contact
{
	string first_name;
	string last_name;
	string number;
	string email;
	string d;
	string m;
	string y;
public:

	Contact(string fnam = "", string lnam = "", string num = "", string mail = "") :first_name(fnam), last_name(lnam), number(num), email(mail) {}
	void set_first_name(string nam);
	void set_last_name(string nam);
	void set_email(string mail);
	void set_number(string num);
	void input_contact();
	string get_first_name()const;
	string get_last_name()const;
	string get_number()const;
	string get_email()const;
	void display()const;
	friend ostream &operator<<(ostream &output, Contact &obj);
	friend istream& operator >> (istream &input, Contact &obj);
	string get_d();
	string get_m();
	string get_y();
	void set_d(string x);
	void set_m(string x);
	void set_y(string x);
	~Contact();
};

const int t_member = 10;
class Group
{
	int m_count = 0;
	string name;
	Contact *group_member;
public:
	Group();
	void set_group_name(string n);
	string get_group_name();
	void display_group();
	int get_member_count();
	string get_member(int i);
	void set_member_name(string s);
	void add_group_member(Contact obj);
	~Group();
};


