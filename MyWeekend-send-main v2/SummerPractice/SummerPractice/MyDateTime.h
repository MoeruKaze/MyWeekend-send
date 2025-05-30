
#pragma once
#include <iostream>
class MyDateTime
{
private:
	int day;
	int month;
	int year;

	int hour;
	int min;
	int sec;

public:
	MyDateTime();
	MyDateTime(int day, int month, int year, int hour, int min, int sec);
	MyDateTime(const MyDateTime& other);
	~MyDateTime();

	void print();
	short compareTo(MyDateTime& date);

	MyDateTime& operator=(const MyDateTime& other);

	//prefix
	MyDateTime& operator++();
	MyDateTime& operator--();

	//postfix
	MyDateTime operator++(int);
	MyDateTime operator--(int);

	bool operator>=(MyDateTime& other);
	bool operator==(MyDateTime& other);
	bool operator<=(MyDateTime& other);
	bool operator!=(MyDateTime& other);

	bool operator>(MyDateTime& other);
	bool operator<(MyDateTime& other);

	friend std::ostream& operator<<(std::ostream& os, const MyDateTime& dt);

private:
	short compare(int on, int tw);
};
