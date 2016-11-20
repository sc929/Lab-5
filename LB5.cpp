#include "stdafx.h"
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

unsigned  Evklid(int a, int b)
{
	// Находим НОК для а и b
	int a1, b1;
	if (a>b)
	{
		a1 = a; b1 = b;
	}
	else
	{
		a1 = b; b1 = a;
	}
	int o;
	do
	{
		o = a1 % b1;
		if (o == 0) return (a* b) / b1;
		a1 = b1;
		b1 = o;
	} while (1);
}

int main(int argc, char *argv[])
{
	int a, b, // Исходные числа
		NOK;
	setlocale(LC_ALL, "rus"); // Возможность вывода русских символов в кодировке  
							  //    Windows-1251 на консоль
	if (argc < 3) // Ошибка
	{
		printf_s("Ошибка, параметров в командной строке не хватает для задания исходных данных. Для завершения нажмите любую клавишу\n");
		system("pause");
		return 1;
	}
	// Читаем значения из командной строки
	if (sscanf_s(argv[1], "%d", &a) < 1) // Читаем a
	{
		printf_s("Ошибка, неверный формат первого входного параметра. Для завершения нажмите любую клавишу\n");
		system("pause");
		return 1;
	}
	if (sscanf_s(argv[2], "%d", &b) < 1) // Читаем a
	{
		printf_s("Ошибка, неверный формат первого входного параметра. Для завершения нажмите любую клавишу\n");
		system("pause");
		return 1;
	}
	NOK = Evklid(a, b); // Получаем наибольшее общее кратное 

	printf("a=%d, b=%d, Наибольшее общее кратное=%d.\n", a, b, NOK);
	system("pause"); // Остановка программы до нажатия любой клавиши
	return 0;
}
