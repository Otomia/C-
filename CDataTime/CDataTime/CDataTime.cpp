#include"CDataTime.h"

#define _CRT_SECURE_NO_WARNINGS

#define ESC 0x1B




void HideCursor()
{
	HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };
	SetConsoleCursorInfo(hd, &cursor_info);
}

void ShowCursor()
{
	HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursor_info = { 1,1 };
	SetConsoleCursorInfo(hd, &cursor_info);
}
CDataTime::CDataTime()
{
	m_data.year   = 1;
	m_data.month  = 1;
	m_data.day    = 1;
	m_time.hour   = 0;
	m_time.minute = 0;
	m_time.second = 0;
}

CDataTime::CDataTime(int year, int month, int day,int hour, int minute, int second)
{
	m_data.year = year;
	m_data.month = month;
	m_data.day = day;
	m_time.hour = hour;
	m_time.minute = minute;
	m_time.second = second;
}

CDataTime::~CDataTime()
{}

void CDataTime::GetCurCDataTime()
{
	time_t te;
	time(&te);

	struct tm *ptm = localtime(&te);
	m_data.year   = ptm->tm_year + 1900;
	m_data.month  = ptm->tm_mon  + 1;
	m_data.day    = ptm->tm_mday;
	m_time.hour   = ptm->tm_hour;
	m_time.minute = ptm->tm_min;
	m_time.second = ptm->tm_sec;
}
void CDataTime::CDataTimeshow()
{
	//GetCurCDataTime();
	cout << m_data.year << "年" << m_data.month << "月" << m_data.day << "日"<<\
		m_time.hour << "时" << m_time.minute << "分" << m_time.second << "秒" << endl;
}

void CDataTime::DataTimeDShow()
{
	HideCursor();
	while (1)
	{
		if (_kbhit())
		{
			int val = _getch();
			if (val == ESC)
				break;
		}
		GetCurCDataTime();
		CDataTimeshow();
		Sleep(1000);
		system("cls");
	}
	ShowCursor();
}

void CDataTime::ShowMenology()
{
	GetCurCDataTime();
	_ShowMenoloy(m_data.year, m_data.month);
}

void CDataTime::_ShowMenoloy(int year, int month)
{

	const char *title[] = { "一","二","三","四","五","六","日" };
	
	for (int i = 0; i < 7; ++i)
		printf("%-6s", title[i]);
	printf("\n");

	int mdays = GetMDayByYM(year, month);
	int week = GetWeekByYMD(year, month, 1);

	if (week == 0)
		week = 7;
	for (int i = 0; i < week - 1; ++i)
		printf("%-6c", ' ');

	for (int i = 1; i <= mdays; ++i)
	{
		printf("%-6d", i);
		int w = GetWeekByYMD(year, month, i);
		if (w == 0)
		{
			printf("\n");
			printf("\n");
		}
	}
	printf("\n");

}

bool CDataTime::IsLeap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	return false;
}

int CDataTime::GetMDayByYM(int year, int month)
{
	int days[] = { 29,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2)
	{
		if (IsLeap(year))
			return days[0];
	}
	return days[month];
}

int CDataTime::GetWeekByYMD(int year, int month, int day)
{
	int count = 0;
	for (int i = 1; i < month; ++i)
	{
		count += GetMDayByYM(year, i);
	}
	count += day;

	//蔡勒公式
	int x = (year - 1) + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400 + count ;
	return x % 7;
}


CDataTime CDataTime::NextDataTime(int n)
{
	
	int y = m_data.year;
	int m = m_data.month;
	int d = m_data.day;
	
	int mday = GetMDayByYM(y, m);
	while (d + n > mday)
	{
		m++;
		if (m > 12)
		{
			m = 1;
			y++;
		}
		n -= mday;
		mday = GetMDayByYM(y, m);
	}
	d += n;
	return CDataTime(y, m, d,m_time.hour,m_time.minute,m_time.second);
}

CDataTime CDataTime::operator+(int days)
{
	m_data.day += days;
	int mday = GetMDayByYM(m_data.year, m_data.month);
	while (m_data.day > mday)
	{
		m_data.day -= mday;
		if (m_data.month == 12)
		{
			++m_data.year;
			m_data.month = 1;
		}
		else
		{
			++m_data.month;
		}
	}
	return *this;
}

CDataTime CDataTime::operator-(int days)
{
	int mday = GetMDayByYM(m_data.year, m_data.month);
	m_data.day -= days;
	while (m_data.day < 1)
	{
		if (m_data.month == 1)
		{
			--m_data.year;
			m_data.month = 12;
		}
		else
		{
			--m_data.month;
			m_data.day += mday;
		}
	}
	return *this;
}

CDataTime& CDataTime::operator++()
{
	*this = *this + 1;
	return *this;
}

CDataTime& CDataTime::operator--()
{
	*this = *this - 1;
	return *this;
}