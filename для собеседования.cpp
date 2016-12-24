#include <iostream>
#include <conio.h>
#include <cstdio>

class geometri
{
private:
	int volume; // �����
	int height; // ������
	int number_gran; // ���-�� ������
	int size_side; // ����� ������
	int footprint; // ������� ���������
public:
	void setgeometri(int *i)
	{
		std::cout << "������� ����� " << *i + 1 << " ������: ";
		std::cin >> volume;
		std::cout << "������� ������ " << *i + 1 << " ������: ";
		std::cin >> height;
		std::cout << "������� ���-�� ������ " << *i + 1 << " ������: ";
		std::cin >> number_gran;
		std::cout << "������� ����� ������ " << *i + 1 << " ������: ";
		std::cin >> size_side;
		std::cout << "������� ������� ��������� " << *i + 1 << " ������: ";
		std::cin >> footprint;
		std::cout << std::endl;
	}
	void show(int *i)
	{
		std::cout << *i + 1 << ") �����: " << volume << "  ������: " << height << "  ���-�� ������: " << number_gran << "  ����� ������: " << size_side << "  ������� ���������: " << footprint << std::endl;
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
	std::cout << "������� ���-�� �����:";
	int number;
	std::cin >> number;
	geometri *prism = new geometri[number]; // �.�. ��������� ������������ ������ � �� ������ �� ������ �� ����� 
	bool *flag = new bool[number];			// ����������� ���� ��� ����� ��� �� ������
	std::cout << "����������:\n";
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
			std::cout << "������� ����� ������ ������� ������ �������: ";
			int number;
			std::cin >> number;
			flag[number - 1] = false;
			break;
			}
		case 4:
			{
			std::cout << "������� ����� ������:";
			int number, parametr, znachenie;
			std::cin >> number;
			std::cout << "������� ����� ��������� ������� ������ �������:";
			std::cin >> parametr;
			std::cout << "������� ����� ��������:";
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
	std::cout << "1) ������ �����\n";
	std::cout << "2) ���������� ������\n";
	std::cout << "3) �������� ������\n";
	std::cout << "4) ��������� ��������� ������\n";
	std::cout << "0) �����\n";
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
				std::cout << "EROR, ��� ����� ������, ������� ������� ����� ������";
				_getch();
				break;
			}
	}
}
