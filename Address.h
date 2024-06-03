#include<iostream>
#include<string>
using namespace std;
class Address
{
private:
	string street_address;
	string city;
	string country;

public:
	Address(string street = "", string city_ = "", string countr = "") : street_address(street), city(city_), country(countr) {}
	void set_street_address(string street);
	void set_city(string city_);
	void set_country(string postal);
	void input_address();
	string get_street_address() const;
	string get_city() const;
	string get_country() const;
	void display() const;
	friend ostream &operator<<(ostream &output, Address &obj);
	friend istream& operator >> (istream &input, Address &obj);
};