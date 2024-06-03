#include"search.h"

date_timee::date_timee()
{
	year = 0;
	month = 0;
	day = 0;
	min = 0;
	secound = 0;
	hours = 0;
}

void date_timee::set_date_time()
{
	time_t now = time(nullptr);
	tm timeinfo;
	if (localtime_s(&timeinfo, &now) == 0)
	{
		year = timeinfo.tm_year + 1900;
		month = timeinfo.tm_mon + 1;
		day = timeinfo.tm_mday;
		hours = timeinfo.tm_hour;
		min = timeinfo.tm_min;
		secound = timeinfo.tm_sec;
	}
}

void date_timee::print_date_time()
{
	cout<<"    DATE: "<< day << "-" << month << "-" << year
		<<"    TIME: "<< hours << ":" << min << ":" << secound << endl; 
}

date_timee::~date_timee()
{
}

search_history::search_history()
{
	name = "";
	date_time;
}


void search_history::set_history(string s)
{
	name = s;
	date_time.set_date_time();
	
}
void search_history::print_history()
{
	cout <<"|NAME: " << name; 
	date_time.print_date_time();
}

search_history::~search_history()
{

}
