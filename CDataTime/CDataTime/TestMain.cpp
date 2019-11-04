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
		cout << "--- [1]显示当前日期        [0]退出      ---" << endl;
		cout << "--- [2]动态显示            [3]显示月历  ---" << endl;
		cout << "--- [4]昨天                [5]明天      ---" << endl;
		cout << "--- [6]N天前               [7]N天后     ---" << endl;
		cout << "-------------------------------------------" << endl;
		cout << "请选择->";
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
			printf("请输入数字：");
			scanf("%d", &day);
			dt - day;
			dt.CDataTimeshow();
			break;
		case 7:
			printf("请输入数字：");
			scanf("%d", &day);
			dt + day;
			dt.CDataTimeshow();
			break;
		}
	}
	system("pause");
	return 0;
}