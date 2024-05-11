
#include "Date.h"

Date::Date(){
	setDate(1901,1,1);
}

Date::Date(int y, int m, int d){
	//cout<<endl<<"in Date ctor"<<endl;
	setDate(y,m,d);
}

Date::Date(const Date& d){
	setDate(d.year,d.month,d.day);
	//cout<<endl<<"in Date COPY ctor"<<endl;
}

bool Date::lessThan(const Date& other) const {
    // First compare years
    if (year < other.year) return true;
    if (year > other.year) return false;

    // Years are the same, now compare months
    if (month < other.month) return true;
    if (month > other.month) return false;

    // Years and months are the same, now compare days
    return day < other.day;
}


//setters
void Date::setDay(int d){
	int max = getMaxDay();
	if (d>max) d=max;
	if (d<1) d=1;
	day = d;
}

void Date::setMonth(int m){
	if (m > 12) m = 12;
	if (m < 1) m = 1;
	month = m;
}

void Date::setYear(int y){
	if (y < 1901) y = 1901;
	year = y;
}

void Date::setDate(int y, int m, int d){
	setMonth(m);
	setDay(d);
	setYear(y);
}

void Date::setDate(Date& d){
	setDate(d.year, d.month, d.day);
}


//getters
int Date::getDay() const{ return day; }
int Date::getMonth() const{ return month; }
int Date::getYear() const{ return year; }
string Date::getMonthName() const{
	string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	return months[month-1];
}

//other
void Date::print() const{
	cout << getMonthName()<<" "<<day<<", "<<year;
}


int Date::getMaxDay() const{
	switch(getMonth()){
		case 4:
		case 6:
		case 9:
		case 11: 			return 30;
		case 2:				return 28;
		default:			return 31;
	}
}

