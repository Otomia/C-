#include"CDataTime.h"
#define _CRT_SECURE_NO_WARNINGS
/*
void main()
{
	CDataTime dt;
	dt.GetCurCDataTime();
	dt.CDataTimeshow();
	CDataTime tmp = dt.NextDataTime(10);
	tmp.CDataTimeshow();
	
	//dt._ShowMenoloy(2012, 2);
	//cout << dt.GetWeekByYMD(2012, 2, 29) << endl;



	system("pause");
}*/

int main()
{
	CDataTime dt;
	int select = 1;
	int day = 0;
	while (select)
	{
		cout << "--------------------------------------------" << endl;
		cout << "--- [1]��ʾ��ǰ����        [0]�˳�      ---" << endl;
		cout << "--- [2]��̬��ʾ            [3]��ʾ����  ---" << endl;
		cout << "--- [4]����                [5]����      ---" << endl;
		cout << "--- [6]N��ǰ               [7]N���     ---" << endl;
		cout << "-------------------------------------------" << endl;
		cout << "��ѡ��->";
		cin >> select;
		switch (select)
		{
		case 1:
			dt.GetCurCDataTime();
			dt.CDataTimeshow();
			break;
		case 2:
			dt.DataTimeDShow();
			break;
		case 3:
			dt.ShowMenology();
			break;
		case 4:
			--dt;
			dt.CDataTimeshow();
			break;
		case 5:
			++dt;
			dt.CDataTimeshow();
		case 6:
			printf("���������֣�");
			scanf("%d", &day);
			dt - day;
			dt.CDataTimeshow();
			break;
		case 7:
			printf("���������֣�");
			scanf("%d", &day);
			dt + day;
			dt.CDataTimeshow();
			break;
		}
	}
	system("pause");
	return 0;
}