#include "functions.h"
#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <fstream>
#include <chrono>
using namespace std;
using namespace chrono;

int main() {
	setlocale(LC_ALL, "");
	srand(time(NULL));
	cout << "Лабораторная работа №10 ИКБО-13-21 Черномуров С.А. Вариант 23" << endl << endl;
	cout << "Выберите номер задания:\n1) Дан пакет из n документов. Каждый документ - \nэто текст протокола собрания коллектива.В протоколе\nесть фраза : Слушали сообщение : после которой через\nпробел следует фамилия и инициалы\n(записаны поформату : Иванов И.И.) выступившего.Сформировать\nмассив данных по выступившим для каждого\nпротокола.Линейный поиск\n\n2) Определить, является ли строка номером \nтелефона в формате + 7 - 000 - 000 - 00 - 00\n\n0) Закончить программу\n\n";

	int choice1;
	
	do {
		cin >> choice1;

		if (choice1 != 1 && choice1 != 2  && choice1 != 0) cout << "Введено неверное значение, попробуйте снова.\n";
	} while (choice1 != 1 && choice1 != 2 && choice1 != 0);

	system("cls");
	switch (choice1) {
	case 1: {
		cout << "Введите количество документов: ";
		int n;
		cin >> n;
		vector <string> people;
		int k = 0;
		int a=0;
		for (int i = 0; i < n; i++) {

			ifstream file("C:/Users/KLINY-ПК/Desktop/.data/Учёба/2 семестр/Структуры и алгоритмы обработки данных/Zadanie10/Zadanie10/files/Protokol"+to_string(i+1)+".txt");
			if (file.is_open()) {
				string line;
				string s = "aaabaaa";
				while (getline(file, line)) {
					string copy = line;
					const char* line1 = line.c_str();
					const char* s1 = s.c_str();
					auto begin = steady_clock::now();
					
					int start_pos = BMSearch(line1,s1);
					auto end = steady_clock::now();
					auto time = duration_cast<nanoseconds>(end - begin);
					k += time.count();
					copy.erase(0, start_pos);
					int end_pos = search(copy, ".") + 2+start_pos;// line.find(".", start_pos) + 2;
					if (start_pos!=-1 && end_pos!=-1 && end_pos>start_pos) people.push_back(line.substr(start_pos, end_pos - start_pos+1));
				}
			}
			file.close();
		}
		cout << k << " nanosecs";
		cout << "\nЛюди, чьи сообщения были прослушаны:\n";
		for (int i = 0; i < people.size(); i++)
			cout << i + 1 << ") " << people[i].erase(0, 22) << endl;

		cout << "\n\n";
		break;
	}
	case 2:
	{
		cout << "Введите строку, которую нужно проверить: ";
		string s;
		cin >> s;
		if (IsValidPhone(s)) cout << "\nСтрока является номером телефона\n\n";
		else cout << "\nСтрока не является номером телефона\n\n";
		break;
	}

	case 0:
		return 0;
	}

	main();
}