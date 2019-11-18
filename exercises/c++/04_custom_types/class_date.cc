#include <iostream>
#include <string>

enum months {jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};

// return string corresponding to month enum
std::string month_name(months m) {
  std::string marray[12] = {"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};
  return marray[m-1];
}


// how many days in a month?
unsigned int how_many_days(months month) {
  switch (month){
  	case nov: case apr: case jun: case sep:
  		return 30;
  		break;
	  case feb:
  		return 28;
	  	break;
	  default:
	  	return 31;
	  	break;
  }

}

class Date {
  unsigned int day;
  months month;
  unsigned int year;
public:
  Date(unsigned int d, months m, unsigned int y) {      // constructor
    day = d;
    month = m;
    year = y;
  }
  unsigned int give_day() {
    return day;
  }
  months give_month() {
    return month;
  }
  unsigned int give_year() {
    return year;
  }
  void add_day();
  void add_days(const unsigned int n);
};

void Date::add_day() {
  if(day != how_many_days(month))
    day++;
  else if (month != dec) {
    day = 1;
    month=(months)(month+1);
  }
  else {
    day = 1;
    year++;
    month = jan;
  }
}

void Date::add_days(const unsigned int n) {
  for(int i=1; i<=n; i++)
    this->add_day();
}

// print a Date object
void print_date(Date d) {
  std::cout << d.give_day() << " " << month_name(d.give_month()) << " " << d.give_year();
}

// compare two dates
bool operator== (Date& lhs, Date& rhs)  {
  return (lhs.give_day()==rhs.give_day() && lhs.give_month()==rhs.give_month() && lhs.give_year()==rhs.give_year());
}

bool operator!= (Date& lhs, Date& rhs)  {
  return !(lhs==rhs);
}

int main() {
  Date mydate(20, nov, 2019);
  print_date(mydate);
  mydate.add_days(5);
  std::cout << "\nafter adding 5 days:\n"; 
  print_date(mydate);
  Date today(19, nov, 2019);
  Date yesterday(18, nov, 2019);
  bool answ = today==yesterday;
  std::cout << "\nis today equal to yesterday? " << answ;
  answ = today!=yesterday;
  std::cout << "\nis today different from yesterday? " << answ << "\n";
  return 0;
}
