// test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <locale>
using namespace std;

void search(const int* array, int index, const int num,  int &count, int step = 0)
{
    if (array[index] == num)
        count++;
    if (index < 0) {
        cout << "  Вызовов рекурсии: " << step << endl;
        return;
    }
    return search(array, index - 1, num, count, step + 1);
  
}

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    int length, number, count = 0;
    //cout << " Введите длину массива: ";
    //cin >> length;
    length = 1 + rand()%200;
    int* array = new int[length];  
    cout << " Введите число: ";
    cin >> number;
    cout << " Длина массива: " << length << endl ;
    //cout << " Введите элементы массива: " << endl;
    cout << " Элементы массива: " << endl;
    for (int i = 0; i < length; i++) {
        array[i] = 25 + rand()%100;
        cout << array[i] << ", ";
    }
    search(array, length - 1, number, count);
    cout << " Колличество элементов, равных  "
        << number << ": " << count;
}


