#include"Date.h"
#define  _CRT_SECURE_NO_WARNINGS


int main()
{
	Date d;
	Date t(2019, 10, 27);
	d.GetCurDateTime();
	d.DateShow();
	t.DateShow();
	
	cout << "--------------------" << endl;
	int day = d - t;
	cout << day<<endl;

	Date dt = ++t;
	t.DateShow();
	dt.DateShow();
	cout << "-----------------------" << endl;

	Date dr = t++;
	t.DateShow();
	dr.DateShow();
	system("pause");
	return 0;
}