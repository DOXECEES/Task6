#include <iostream>
#include <windows.h>


int main()
{
	srand(time(0));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RU");

	int arrayLength;


	std::cout << "Введите длину массива" << std::endl;
	std::cin >> arrayLength;
	

	int* array = new int[arrayLength];
	std::cout << "Созданый массив" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;

	for (int i = 0; i < arrayLength; i++)
	{
		array[i] = 0 + rand() % 9; // Случайные числа от 0 до 9
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::endl;


	std::cout << "Массив после удаления из его нолей" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;

	int zeroCounter = 0;
	int howMuchZeroSkipped = 0;

	for (int i = 0; i < arrayLength; i++)//Считаем количество нолей в массиве
	{
		if (array[i] == 0)
		{
			zeroCounter++;
		}
	}

	int* arrayWithoutZeros = new int[arrayLength - zeroCounter];//Создаем новый массив размером на zeroCounter меньше

	for (int i = 0; i < arrayLength; i++)
	{

		if (array[i] == 0)// Скипаем элементы с нолями и считаем сколько нолей скипнули
		{
			
			howMuchZeroSkipped++;
			continue;
		}
		arrayWithoutZeros[i - howMuchZeroSkipped] = array[i]; 
	}
	delete[] array;
	
	for (int i = 0; i < (arrayLength - zeroCounter); i++)
	{
		std::cout << arrayWithoutZeros[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	
	delete[] arrayWithoutZeros;
}
