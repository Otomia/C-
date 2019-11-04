#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#include<time.h>
#include<Windows.h>
#include<conio.h>


struct Data
{
	int year;
	int month;
	int day;
};

struct Time
{
	int hour;
	int minute;
	int second;
};

class CDataTime {
public:
	CDataTime();
	CDataTime(int year, int month, int day,int hour,int minute,int second);
	~CDataTime();

public:
	void GetCurCDataTime();
	void CDataTimeshow();
	void DataTimeDShow();
	void ShowMenology();
protected:
	bool IsLeap(int year);
	int GetMDayByYM(int year, int month);
public:
	int GetWeekByYMD(int year, int month, int day);
	void _ShowMenoloy(int year, int month);
public:
	CDataTime NextDataTime(int n);
public:

	CDataTime operator+(int day);

	CDataTime operator-(int day);
	CDataTime& operator++();//Ã÷Ìì
	CDataTime& operator--();
	
	

private:
	Data m_data;
	Time m_time;
};