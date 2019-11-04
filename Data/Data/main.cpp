#include"Date.h"
#define  _CRT_SECURE_NO_WARNINGS


int main()
{
	Date d;
	Date t(2019, 10, 27);
	d.GetCurDateTime();
	d.DateShow();
	t.DateShow();
	
	cout << "-----------" << endl;
	int day = d - t;
	cout << day<<endl;


	system("pause");
	return 0;
}