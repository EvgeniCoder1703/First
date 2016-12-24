#include <iostream>
#include <conio.h>
#include <cstdio>

class geometri
{
private:
	int volume; // обьем
	int height; // высота
	int number_gran; // кол-во граней
	int size_side; // длина сторон
	int footprint; // площадь основания
public:
	void setgeometri(int *i)
	{
		std::cout << "Введите обьем " << *i + 1 << " призмы: ";
		std::cin >> volume;
		std::cout << "Введите высоту " << *i + 1 << " призмы: ";
		std::cin >> height;
		std::cout << "Введите кол-во граней " << *i + 1 << " призмы: ";
		std::cin >> number_gran;
		std::cout << "Введите длину сторон " << *i + 1 << " призмы: ";
		std::cin >> size_side;
		std::cout << "Введите площадь основания " << *i + 1 << " призмы: ";
		std::cin >> footprint;
		std::cout << std::endl;
	}
	void show(int *i)
	{
		std::cout << *i + 1 << ") Обьем: " << volume << "  высота: " << height << "  кол-во граней: " << number_gran << "  длины сторон: " << size_side << "  площадь основания: " << footprint << std::endl;
	}
	void change(int *parametr, int *znachenie)
	{
		switch (*parametr)
		{
		case 1: volume = *znachenie; break;
		case 2: height = *znachenie; break;
		case 3: number_gran = *znachenie; break;
		case 4: size_side = *znachenie; break;
		case 5: footprint = *znachenie; break;
		}
	}
};

void menu();
void add(bool *flag,int *number, geometri prism[]);

int main()
{
	setlocale(LC_ALL, "rus");
	std::cout << "Введите кол-во призм:";
	int number;
	std::cin >> number;
	geometri *prism = new geometri[number]; // т.к. использую динамический массив а не вектор то призмы не будут 
	bool *flag = new bool[number];			// добавляться если все слоты под их забиты
	std::cout << "Заполнение:\n";
	for (int i = 0; i < number; i++)
	{
		prism[i].setgeometri(&i);
		flag[i] = true;
	}
	int choice;
	do
	{
		menu();
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			{
			system("cls");
			for (int i = 0; i < number; i++)
				if (flag[i] == true)
					prism[i].show(&i);
			_getch();
			break;
			}
		case 2: add(flag,&number,prism); break;
		case 3: 
			{
			std::cout << "Введите номер призмы которую хотите удалить: ";
			int number;
			std::cin >> number;
			flag[number - 1] = false;
			break;
			}
		case 4:
			{
			std::cout << "Введите номер призмы:";
			int number, parametr, znachenie;
			std::cin >> number;
			std::cout << "Введите номер параметра который хотите сменить:";
			std::cin >> parametr;
			std::cout << "Введите новое значение:";
			std::cin >> znachenie;
			prism[number - 1].change(&parametr,&znachenie);
			}
		}
	}while (choice != 0);
	delete[] prism;
	delete[] flag;
}

void menu()
{
	system("cls");
	std::cout << "1) Список призм\n";
	std::cout << "2) Добавление призмы\n";
	std::cout << "3) Удаление призмы\n";
	std::cout << "4) Изменение параметра призмы\n";
	std::cout << "0) Выход\n";
}
void add(bool *flag, int *number, geometri prism[])
{
	system("cls");
	for (int i = 0; i < *number; i++)
	{
		if (flag[i] == false)
		{
			prism[i].setgeometri(&i);
			flag[i] = true;
			break;
		}
		else
			if (i == *number - 1)
			{
				std::cout << "EROR, все слоты забиты, сначала удалите любую призму";
				_getch();
				break;
			}
	}
}
