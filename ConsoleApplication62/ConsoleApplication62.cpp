// ConsoleApplication62.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <clocale>
#include <ctime>
#include <deque>
#include <queue>
#include <string>
#include <stdio.h>
using namespace std;
/*
Задание 2: Используя стандартную реализацию. #include <queue>	// Стандартная реализация очереди из stl
Разработать приложение, имитирующее очередь печати принтера. Должны быть клиенты,
посылающие запросы на принтер, у каждого из которых есть свой приоритет. Каждый
новый клиент попадает в очередь в зависимости от своего приоритета. Необходимо
сохранять статистику печати (пользователь, время) в отдельной очереди. Предусмотреть
вывод статистики на экран.
*/
int main()
{
	setlocale(LC_ALL, "rus");
 int millisec = 0;

 printf("Дата и время распечатки:");
 struct tm newtime;
 char am_pm[] = "AM";
 __time64_t long_time;
 char time_buffer[26];
 errno_t err;

 
 _time64(&long_time);

 
 err = _localtime64_s(&newtime, &long_time);

 if (err)
 {
	 printf("Invalid argument to _localtime64_s.\n");
	 exit(1);
 }

 printf(" %d/%d/%d\n", newtime.tm_mday, newtime.tm_mon + 1, 1900 + newtime.tm_year);


 if (err)
 {
	 printf("Invalid argument to _localtime64_s.\n");
	 exit(1);
 }

 //Вечернее время
 if (newtime.tm_hour > 12)
 {
	 strcpy_s(am_pm, sizeof(am_pm), "PM");
	 printf("%d:%d %s\n", newtime.tm_hour, newtime.tm_min, am_pm);
	 
 }
 //Буднее время
 else
 {
	 strcpy_s(am_pm, sizeof(am_pm), "AM");
	 printf("%d:%d %s\n", newtime.tm_hour, newtime.tm_min, am_pm);
	
 }
#pragma region queue
	priority_queue<string>name;

	
	name.push("Oldrich");
	name.push("Leubouf");
	name.push("Trey"); 
	name.push("Kate"); 

				
	while (!name.empty())
	{
		if (name.top() == "Trey") {
			cout << "First in queue - " << name.top() << endl;
			name.pop();
		}
		else if (name.top() == "Oldrich" || name.top() == "Leubouf") {
			cout << "Next in queue - " << name.top() << endl;
			name.pop();
		}
		else {
			cout << "Last in queue - " << name.top() << endl;
			name.pop();
		}
	};
#pragma endregion
	cin.get();
	return 0;
}
