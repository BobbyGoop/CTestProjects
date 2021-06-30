#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#pragma comment(linker, "/STACK:2500000")
using namespace std;


//Заполнение массива случайными элементами 
void filling(int array[], int len)
{
    for (int i = 0; i < len; i++)
    {
        array[i] = i;
        i++;
    }
}


// Вывод массива на консоль
void out_console(int array[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << ' ' << array[i];
    }
}

//Заполнение массива нулями 
void fill_zeros(int array[], int len)
{
    for (int i = 0; i < len; i++)
    {
        array[i] = 0;
    }
}

// Запись массива в файл
void write_in_file(ofstream& out, int array[], int len)
{
    for (int i = 0; i < len; i++)
    {
        if (i % 50 == 0) out << endl;
        out << array[i] << " ";
    }
    out << endl;
}

//Вывод массива из файла 
void read_from_file(ifstream& out, int array[], int len)
{
   for (int i = 0; i < len; i++) {
        
        out >> array[i];
    }
}

// Сортировка слиянием
void merge_sort(int* a, int start , int end)
{
    if (end - start < 2) return;
    int mid = (end - start) / 2;
    merge_sort(a, start, start + mid);
    merge_sort (a, start + mid, end);
   
    int* tmp = new int[end - start];
    int bg_first = start;
    int end_first = start + mid;
    int bg_scnd = end_first;
    for (int step = 0; step < end - start; step++) 
    {
        if ((bg_scnd >= end) || ((bg_first < end_first) && (a[bg_first] > a[bg_scnd])))
        {
            tmp[step] = a[bg_first];
            bg_first++;
        }
        else
        {
            tmp[step] = a[bg_scnd];
            bg_scnd++;
        }
    }
    for (int i = start; i < end; i++) {
        a[i] = tmp[i-start];
    }
    delete[] tmp;
}

////Сортировка пузырьком 
//void bubbleSort(int array[], int length)
//{
//    for (int i = 0; i < length - 1; i++)
//    {
//        for (int j = 0; j < length - i - 1; j++)
//        {
//            if (array[j] < array[j + 1])
//            {
//                int temp = array[j];
//                array[j] = array[j + 1];
//                array[j + 1] = temp;
//            }
//        }
//    }
//}
//
////Сортировка расчёской 
//void comboSort(int array[], int length)
//{
//    int step = length;
//    float k = 0.8;
//    bool swapped = true;
//    
//    while (step != 1 || swapped == true)
//    {
//        step *= k;
//        swapped = false;
//        if (step < 1)
//        {
//            step = 1;
//            break;
//        }
//        for (int i = 0; i < length - step; i++)
//        {
//            if (array[i] < array[i + step])
//            {
//                swap(array[i], array[i + step]);
//                swapped = true;
//            }
//        }
//    }
//}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    // 0) Инициализация массивов
    const int length = 500;
    int array_merge[length];
    int array_bubble[length];
    int array_combo[length];

    // 1) Генерация массивов
    filling(array_merge, length);
    filling(array_bubble, length);
    filling(array_combo, length);
    
    // 2) Заполнение файла и вывод
    ofstream file_wr;
    file_wr.open("Arrays.txt");
    if (file_wr.is_open()) cout << "\t Файл успешно открыт ";
    
    write_in_file(file_wr, array_merge, length);
    write_in_file(file_wr, array_bubble, length);
    write_in_file(file_wr, array_combo, length);
    file_wr.close();

    cout << "\n\n\t ИСХОДНЫЕ МАССИВЫ" << endl;
    cout << "\t Первый массив: ";
    out_console(array_merge, length);
    cout << "\n\n\t Второй массив: ";
    out_console(array_bubble, length);
    cout << "\n\n\t Третий массив: ";
    out_console(array_combo, length);

    // 3) Обнуление файлов и вывод
    fill_zeros(array_merge, length);
    fill_zeros(array_bubble, length);
    fill_zeros(array_combo, length);
    
    cout << "\n\n\t ОБНУЛЕННЫЕ МАССИВЫ" << endl;
    cout << "\t Первый массив: ";
    out_console(array_merge, length);
    cout << "\n\n\t Второй массив: ";
    out_console(array_bubble, length);
    cout << "\n\n\t Третий массив: ";
    out_console(array_combo, length);
   
    // 4) Чтение массивов из файла
    ifstream file_out;
    file_out.open("Arrays.txt");
    read_from_file(file_out, array_merge, length);
    read_from_file(file_out, array_bubble, length);
    read_from_file(file_out, array_combo, length);
    file_out.close();

    // 5) СОРТИРОВКА МАССИВОВ
    merge_sort(array_merge, 0, length);
    /*comboSort(array_combo, length);
    bubbleSort(array_bubble, length);*/

    // 6) Вывод в консоль
    cout << "\n\n\t ОТСОРТИРОВАННЫЕ МАССИВЫ" << endl;
    cout << "\t Первый массив: ";
    out_console(array_merge, length);
    cout << "\n\n\t Второй массив: ";
    out_console(array_bubble, length);
    cout << "\n\n\t Третий массив: ";
    out_console(array_combo, length);

    // 7) Запись в файл (дозапись)
    ofstream file_sort;
    file_sort.open("Arrays.txt", ios::app);
    write_in_file(file_sort, array_merge, length);
    write_in_file(file_sort, array_bubble, length);
    write_in_file(file_sort, array_combo, length);
    file_sort.close();
    return 0;
}

