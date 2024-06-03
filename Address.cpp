#include "Address.h"
//setter
void Address::set_street_address(string street)
{
	street_address = street;
}
void Address::set_country(string postal)
{
	country = postal;
}
void Address::set_city(string city_)
{
	city = city_;
}
void Address::input_address()
{
	cin.ignore();
	cout << "|STREET ADDRESS:";
	getline(cin, street_address);
	cout << "|CITY:";
	getline(cin, city);
	cout << "|COUNTRY:";
	cin >> country;
	cout << "*------------------------*" << endl;
}
//getter
string Address::get_street_address() const
{
	return street_address;
}
string Address::get_city() const
{
	return city;
}

string Address::get_country() const
{
	return country;
}


void Address::display() const
{
	cout << "|STREET ADDRESS: " << get_street_address() << endl;
	cout << "|CITY: " << get_city() << endl;
	cout << "|COUNTRY: " << get_country() << endl;
}

ostream &operator<<(ostream &output, Address &obj)
{
	output << "|STREET ADDRESS: " << obj.street_address << endl;
	output << "|CITY: " << obj.city << endl;
	output << "|COUNTRY: " << obj.country << endl;
	return output;
}
istream& operator >> (istream &input, Address &obj)
{
	cin.ignore();
	cout << "|STREET ADDRESS:";
	getline(input, obj.street_address);
	cout << "|CITY:";
	getline(input, obj.city);
	cout << "|COUNTRY:";
	input >> obj.country;
	cout << "------------------------" << endl;
	return input;
}