
#include "MyDateTime.h"

MyDateTime::MyDateTime()
{
	day = 01;
	month = 01;
	year = 1970;
	hour = 0;
	min = 0;
	sec = 0;
}

MyDateTime::MyDateTime(int day, int month, int year, int hour, int min, int sec)
{
	this->day = day;
	this->month = month;
	this->year = year;
	this->hour = hour;
	this->min = min;
	this->sec = sec;
}

MyDateTime::MyDateTime(const MyDateTime& other)
{
	day = other.day;
	month = other.month;
	year = other.year;
	hour = other.hour;
	min = other.min;
	sec = other.sec;
}



MyDateTime::~MyDateTime()
{

}

void MyDateTime::print()
{
	printf("%02d-%02d-%4d %02d:%02d:%02d\n\n",
		day, month, year, hour, min, sec);
}

short MyDateTime::compareTo(MyDateTime& date)
{
	if (!compare(year, date.year)) {
		if (!compare(month, date.month)) {
			if (!compare(day, date.day)) {
				if (!compare(hour, date.hour)) {
					if (!compare(min, date.min)) {
						if (!compare(sec, date.sec)) {
							return 0;
						}
						else return compare(sec, date.sec);
					}
					else return compare(min, date.min);
				}
				else return compare(hour, date.hour);
			}
			else return compare(day, date.day);
		}
		else return compare(month, date.month);
	}
	else return compare(year, date.year);

	return 0;
}

MyDateTime& MyDateTime::operator=(const MyDateTime& other)
{
	if (this == &other)
		return *this;
	day = other.day;
	month = other.month;
	year = other.year;
	hour = other.hour;
	min = other.min;
	sec = other.sec;
	return *this;
}

MyDateTime& MyDateTime::operator++()
{
	day++;
	if (day > 30)
	{
		month++;
		day = 1;

	}

	if (month > 12)
	{
		year++;
		month = 1;
	}

	return *this;
}

MyDateTime& MyDateTime::operator--()
{
	day--;
	if (day == 0)
	{
		day = 30;
		month--;
	}

	if (month == 0)
	{
		month = 12;
		year--;
	}

	return *this;
}

MyDateTime MyDateTime::operator++(int)
{
	MyDateTime tmp = MyDateTime(*this);
	this -> operator++();
	return tmp;
}

MyDateTime MyDateTime::operator--(int)
{
	MyDateTime tmp = MyDateTime(*this);
	this -> operator--();
	return tmp;
}



short MyDateTime::compare(int on, int tw)
{
	return on > tw ? 1 : on < tw ? -1 : 0;
}

bool MyDateTime::operator>=(MyDateTime& other)
{
	return (this->compareTo(other)) >= 0;
}
bool MyDateTime::operator==(MyDateTime& other)
{
	return (this->compareTo(other)) == 0;
}
bool MyDateTime::operator<=(MyDateTime& other)
{
	return (this->compareTo(other)) <= 0;
}
bool MyDateTime::operator!=(MyDateTime& other)
{
	return (this->compareTo(other)) != 0;
}
bool MyDateTime::operator<(MyDateTime& other)
{
	return (this->compareTo(other)) < 0;
}
bool MyDateTime::operator>(MyDateTime& other)
{
	return (this->compareTo(other)) > 0;
}

std::ostream& operator<<(std::ostream& os, const MyDateTime& dt)
{
	os << dt.day << "." << dt.month << "." << dt.year << " " << dt.hour << ":" << dt.min << ":" << dt.sec;
	return os;
}
