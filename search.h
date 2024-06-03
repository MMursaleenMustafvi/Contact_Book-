#include<iostream>
#include<ctime>
#include<string>
using namespace std;
class date_timee
{
	int year;
	int month;
	int day;
	int hours;
	int min;
	int secound;
public:
	date_timee();
	void set_date_time();
	void print_date_time();
	~date_timee();
};
class search_history
{
protected:
	string name;
	date_timee date_time;
	string s;
public:
	search_history();
	void set_dobb();
	void set_history(string s);
	void print_history();
	void print_frequently();
	~search_history();
};