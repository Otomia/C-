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
	int countDays();//����һ���еĵڼ���
public:
	Date& operator=(const Date& d);//��ֵ����������

	Date operator+(int days);//���ڶ������һ������
	Date operator-(int days);//���ڶ����ȥһ������

	int operator-( Date& d);//�����������������

	Date& operator++();//����ǰ��++
	Date operator++(int);//���ں���++

	Date& operator--();//����ǰ��--
	Date operator--(int);//���ں���--

	bool operator<(const Date& d)const;
	bool operator>(const Date& d)const;//�Ƚ�*this�����Ƿ��d�����
	bool operator>=(const Date& d)const;//�Ƚ�*this�����Ƿ��d������ڵ���
	bool operator<(const Date& d)const;//�Ƚ�*this�����Ƿ��d����С
	bool operator<=(const Date& d)const;//�Ƚ�*this�����Ƿ��d����С�ڵ���
	bool operator==(const Date& d)const;//�Ƚ�*this�����Ƿ��d�������
	bool operator!=(const Date& d)const;//�Ƚ�*this�����Ƿ��d�������

private:
	int _year;
	int _month;
	int _day;
};