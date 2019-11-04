#pragma once
#define  _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<time.h>
#include<math.h>

using namespace std;


class Date
{
public:
	Date();
	Date(int year, int month, int day);
	Date(const Date& d);
	~Date();
public:
	void GetCurDateTime();
	void DateShow();

protected:
	bool IsLeap(int year);
	int GetMDayByYM(int year, int month);
public:
	int GetWeekByYMD(int year, int month, int day);
	int countDays();//计算一年中的第几天
public:
	Date& operator=(const Date& d);//赋值操作符重载

	Date operator+(int days);//日期对象加上一个天数
	Date operator-(int days);//日期对象减去一个天数

	int operator-( Date& d);//两个对象相减求天数

	Date& operator++();//日期前置++
	Date operator++(int);//日期后置++

	Date& operator--();//日期前置--
	Date operator--(int);//日期后置--

	bool operator<(const Date& d)const;
	bool operator>(const Date& d)const;//比较*this对象是否比d对象大
	bool operator>=(const Date& d)const;//比较*this对象是否比d对象大于等于
	bool operator<(const Date& d)const;//比较*this对象是否比d对象小
	bool operator<=(const Date& d)const;//比较*this对象是否比d对象小于等于
	bool operator==(const Date& d)const;//比较*this对象是否比d对象相等
	bool operator!=(const Date& d)const;//比较*this对象是否比d对象不相等

private:
	int _year;
	int _month;
	int _day;
};