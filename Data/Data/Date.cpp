#include"Date.h"
#define  _CRT_SECURE_NO_WARNINGS

Date::Date()
{
	_year = 1990;
	_month = 1;
	_day = 1;
}
Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}
Date::~Date()
{

}

void Date::GetCurDateTime()
{
	time_t te;
	time(&te);

	struct tm *ptm = localtime(&te);
	_year = ptm->tm_year + 1900;
	_month = ptm->tm_mon + 1;
	_day = ptm->tm_mday;
}
 
void Date::DateShow()
{
	cout << _year << "年" << _month << "月" << _day << "日" << endl;
}

bool Date::IsLeap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return true;
	return false;
}

int Date::GetMDayByYM(int year, int month)
{
	int days[] = { 29,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2)
	{
		if (IsLeap(year))
			return days[0];
	}
	return days[month];
}


int Date::GetWeekByYMD(int year, int month, int day)
{
	int count = 0;
	for (int i = 1; i < month; ++i)
	{
		count += GetMDayByYM(year, i);
	}
	count += day;

	//蔡勒公式
	int x = (year - 1) + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400 + count;
	return x % 7;
}

Date& Date::operator=(const Date&d)
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}

Date Date::operator+(int days)//日期对象加上一个天数
{
	
	_day += days;
	int mday = GetMDayByYM(_year, _month);
	while (_day > mday)
	{
		_day -= mday;
		if (_month == 12)
		{
			++_year;
			_month = 1;
		}
		else
			++ _month;
	}
	return *this;
}

Date Date::operator-(int days)//日期对象减去一个天数
{
	int mday = GetMDayByYM(_year, _month);
	_day -= days;
	while (_day < 1)
	{
		if (_month == 1)
		{
			--_year;
			_month = 12;
		}
		else
			--_month;
		_day += mday;
	}
	return *this;
}

int Date::countDays()
{
	int dom1[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int dom2[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int days = 0;
	if (IsLeap(_year))
	{
		for (int i = 0; i < _month - 1; ++i)
		{
			days += dom2[i];
		}
		days += _day;
	}
	else
	{
		for (int i = 0; i < _month - 1; ++i)
			days += dom1[i];
		days += _day;
	}
	return days;
}
int Date::operator-( Date& d)//两个对象相减求天数
{
	int subDay = 0;
	if (_year == d._year)
	{
		subDay += abs(this->countDays() - d.countDays());
	}
	else
	{
		if (_year < d._year)
		{//交换两个相减的日期，保证前者在后者之后
			Date temp;
			temp = *this;
			*this = d;
			d = temp;
		}
		if (_year - d._year > 2)
		{
			for (int i = 1; i < _year - d._year; ++i)
			{
				subDay += 365;
				if (IsLeap(d._year + i))
					subDay += 1;
			}
		}
		subDay += 365 - d.countDays() + this->countDays();
		if (IsLeap(d._year))
			subDay++;
	}
	return subDay;

}

bool Date::operator==(const Date& d)const
{
	return _year == d._year && _month == d._month && _day == d._day;
}