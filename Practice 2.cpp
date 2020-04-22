#include <iostream>
#include <locale>
using namespace std;

int checking_ex(int sw) {
	int number;
	cin >> number;
	switch (sw) {
		case 1: {
			if (cin.fail() || number < 1) {
				cin.clear();
				cin.ignore(32767, '\n');
				throw invalid_argument(" Введите целое неотрицательное число больше 0 ");
				break;
			}
			else return number;
		}
		case 2: {
			if (!cin) {
				while (cin.get() != '\n') cin.clear();
				throw invalid_argument(" Элемент массива должен быть целым числом");
				break;
			}
			else return number;
		}
	}	
}

int input_data(int sw, int count = 1) {
	int input;
	bool incorrect_length; 
	do {
		switch (sw) {
		case 1: { cout << " Введите длину исходного массива: ";
			break;
		}
		case 2: {
			cout << " Введите " << count  << "-й элемент массива: ";
			break;
		}
		}
		try {
			input = checking_ex(sw);
			incorrect_length = false;
		}
		catch (invalid_argument & ex) {
			cerr << "\t" << ex.what() << endl;
			incorrect_length = true;
		}
	} while (incorrect_length);

	return input;

}

int * getResult(const int *arr, const int l, int &newlen) {
	int* result = new int[newlen];
	for (int i = 0; i < l; i++) {
		if (arr[i] < 0 && arr[i] % 2 == 0) {
			result [newlen] = arr[i];
			newlen++;
		}
	}
	return result;
	delete[] result;
	
}

int main() {
	setlocale(LC_ALL, "rus");
	int res_len = 0, action;
	int length = input_data(action = 1);
	int *array = new int[length];
	for (int i = 0; i < length; i++) {
		array[i] = input_data(action = 2, i + 1);
	}
	int* res = getResult(array, length, res_len);
	if (res_len != 0) {
		cout << " Четные отрицательные элементы массива: ";
		for (int i = 0; i < res_len; i++)
			cout << *(res + i) << ", "  ;
		cout << "\n Длина нового массива: " << res_len;
	}
	else cout << " Среди введенных чисел нет четных отрицательных ";
	delete[] array;
	return 0;

}
