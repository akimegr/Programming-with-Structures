#include <iostream>
#include<stdio.h>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

const int m = 30, arr_progress = 5, all_student = 5;
struct Student
{
	//string name;
	char name[m];
	int number_group;
	int progress[arr_progress];
};
Student all_progress[all_student]; 

void printFile(string name) {
	ofstream myFile;
	myFile.open(name + ".txt");
	if (!myFile.is_open()) 
		cout << "Файл не может быть открыт!\n"; 
	else
	{
		for (int i = 0; i < all_student; i++) {
			myFile << all_progress[i].name << " ";
			myFile << all_progress[i].number_group << " ";
			for (int z = 0; z < 5; z++) {
				myFile << all_progress[i].progress[z] << " ";
			}
			myFile << endl;
		}
	}
	myFile.close();
};

int main()
{
	setlocale(LC_ALL, "RUS");

	for (int i = 0; i < all_student; i++)  
	{
		cout << "Enter name : ";

		cin.getline(all_progress[i].name, m);

		//getline(cin, all_progress[i].name);
		cout << "Enter group : ";
		cin >> all_progress[i].number_group;

		for (int z = 0; z < arr_progress; z++) 
		{
			cout << "Enter grade " << z + 1 << " : ";
			cin >> all_progress[i].progress[z];

		}
		cin.ignore(); 
		cout << endl << endl;
	}

	printFile("student");

	for (int k = 0; k <= all_student; k++) 
	{
		for (int i = 0; i < (all_student - 1); i++) 
		{
			int max, min;
			if (sizeof(all_progress[i].name) > sizeof(all_progress[i + 1].name)) {
				max = sizeof(all_progress[i].name);
				min = sizeof(all_progress[i + 1].name);
			}
			else {
				min = sizeof(all_progress[i].name);
				max = sizeof(all_progress[i + 1].name);
			}
			for (int f = 0; f < max; f++) {
				if (all_progress[i].name[f] > all_progress[i + 1].name[f])
				{
					swap(all_progress[i], all_progress[i + 1]);
					break;
				}
				else if (all_progress[i].name[f] == all_progress[i + 1].name[f]) {
					;
				}
				else
					break;
			}




		}
	}
	cout << " Сортировка алфваиту " << endl;
	for (int i = 0; i < all_student; i++)
	{
		cout << " Ф.И.О. : " << all_progress[i].name << endl;
		cout << "Номер группы : " << all_progress[i].number_group << endl;
		cout << "Успеваемость : ( ";
		for (int z = 0; z < arr_progress; z++)
		{
			cout << all_progress[i].progress[z] << "  ";
		}
		cout << ")" << endl << endl << endl;
	}
	printFile("student1");

	cout << "Студенты имеющие 4 или 5: " << endl; 
	bool check_all = true; 
	for (int i = 0; i < all_student; i++)
	{
		bool check = false; 
		for (int z = 0; z < arr_progress; z++)
		{
			if (all_progress[i].progress[z] == 4 or all_progress[i].progress[z] == 5)
			{
				check = true;
			}

		}
		if (check)
		{
			cout << "ФИО : " << all_progress[i].name << endl;
			cout << "Группа : " << all_progress[i].number_group << endl << endl;
			check_all = false;
		}

	}
	if (check_all)
		cout << "У всех учеников оценки меньше 4" << endl;
	cout << endl << endl;
	return 0;

}
