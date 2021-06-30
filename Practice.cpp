#include <iostream>
#include <locale>
using namespace std;

void search(const int* array, int index, const int num, int& count, int step = 0)
{
	if (index < 0)
	{
		cout << "  Вызовов рекурсии: " << step << endl;
		return;
	}
	if (array[index] == num) count++;
	
	return search(array, index - 1, num, count, step + 1);

}

void checking(int num)
{
	if (num < 1)
	{
		throw invalid_argument(" В массиве не может быть отрицательное или нулевое число элементов");
	}

}

int inputLength()
{
	int input;
	bool incorrect_length;
	do {
		cout << " Введите длину массива :  ";
		cin >> input;
		try
		{
			checking(input);
			incorrect_length = false;
		}
		catch (invalid_argument & ex)
		{
			cerr << "\t" << ex.what() << endl;
			incorrect_length = true;
		}
	} while (incorrect_length);

	return input;

}

int * getResult(const int *arr, const int l, int &newlen)
{
	int* result = new int[newlen];
	for (int i = 0; i < l; i++)
	{
		if (arr[i] < 0 && arr[i] % 2 == 0)
		{
			result [newlen] = arr[i];
			newlen++;
		}
	}
	return result;
	delete[] result;
	
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	int number, count = 0, res_len = 0;
	int length = inputLength();
	int *array = new int[length];

	// for (int i = 0; i < length; i++)
	// {
	//	cout << "Введите " << i + 1 << "-й элемент массива: ";
	//	cin >> array[i];
	// }

	cout << " Введите число, наличие которого необходимо проверить в массиве: ";
	cin >> number ;

	cout << " Элементы массива: " << endl;
	for (int i = 0; i < length; i++)
	{
		array[i] = -100 + rand() % 100;
		cout << array[i] << ", ";
	}

	cout << endl;
	int* res = getResult(array, length, res_len);

	cout << " Четные отрицательные элементы массива: ";
	for (int i = 0; i < res_len; i++) cout << " " << *(res + i);
		
	cout << "\n Длина нового массива: " << res_len;
	
	search(array, length - 1, number, count);
	cout << " Колличество элементов, равных  " << number << ": " << count;
		
	delete[] array;
	return 0;

}
