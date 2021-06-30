#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <thread>
#include <chrono>
#pragma comment(linker, "/STACK:2500000")
using namespace std;
using namespace chrono;

// Использование функций из предыдущего задания
void filling(int array[], int len);
void merge_sort(int* a, int start, int end);

void comboSort(int array[], int length)
{
    int step = length;
    float k = 0.8;
    bool swapped = true;

    while (step != 1 || swapped == true)
    {
        step *= k;
        swapped = false;
        if (step < 1)
        {
            step = 1;
            break;
        }
        for (int i = 0; i < length - step; i++)
        {
            if (array[i] < array[i + step])
            {
                swap(array[i], array[i + step]);
                swapped = true;
            }
        }
    }
}

void bubbleSort(int array[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (array[j] < array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Вычисление среднего времени
void average_time(long array[], float &average, long &min, long &max)
{
    float sum = 0;
    min = LONG_MAX;
    max = 0;

    for (int i = 3; i < 13; i++)
    {
        sum += array[i];
        if (array[i] < min)
        {
            min = array[i];
        }
        else
            if (array[i] >  max)
            {
               max = array[i];
            }
    }
    average = sum / 10;
}

// Вывод результатов времени на консоль
void results_time_cout(long merge[], long bubble[], long combo[], int len) {
    float average;
    long max, min;
    cout << "\n\n Сортировка " << len << " элементов методом слияния: ";
    for (int i = 3; i < 13; i++) {
        cout << "\n \t Измерение " << i-3  << ":\t " << merge[i];
    }
    average_time(merge, average, min, max);
    cout << endl << setw(70) << setfill('-');
    cout << "\n Cреднее время: \t" << average << " мкс";
    cout << "\n Максимальное время: \t" << max << " мкс";
    cout << "\n Минимальное время: \t" << min << " мкс";

    
    cout << "\n\n Сортировка " << len << " элементов методом пузырька: ";
    for (int i = 3; i < 13; i++) {
        cout << "\n\t Измерение " << i - 3 << ": \t" << bubble[i];
    }
    average_time(bubble,average, min, max);
    cout << endl <<setw(70) << setfill('-');
    cout << "\n Cреднее время: \t" << average << " мкс";
    cout << "\n Максимальное время: \t" << max << " мкс";
    cout << "\n Минимальное время: \t" << min << " мкс";
    
    cout << "\n\n Сортировка " << len << " элементов методом расчески: ";
    for (int i = 3; i < 13; i++) {
        cout << "\n\t Измерение " << i - 3 << ": \t" << combo[i];
    }
    average_time(combo, average, min, max);
    cout << endl << setw(70) << setfill('-');
    cout << "\n Cреднее время: \t" << average << " мкс";
    cout << "\n Максимальное время: \t" << max << " мкс";
    cout << "\n Минимальное время: \t" << min << " мкс";
}


// Создание копий массивов
void making_copies(int array[], int new_array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        new_array[i] = array[i];
    }
}

// Последовательная сортировка массивов и запись 
// измерений в массивы времени

void arrays_sorting(int merge[], int bubble[], int comb[], int length, long time_merge[], long time_bubble[], long time_combo[], int i) {

    auto begin = high_resolution_clock::now();    
    merge_sort(merge, 0, length);
    auto end = high_resolution_clock::now();    
    duration <double, micro> time = end - begin;
    time_merge[i] = (long)time.count(); 
   
    begin = high_resolution_clock::now();
    bubbleSort(bubble, length);
    end = high_resolution_clock::now();
    time = end - begin;
    time_bubble[i] = (long)time.count();

    begin = high_resolution_clock::now();
    comboSort(comb, length);
    end = high_resolution_clock::now();
    time = end - begin;
    time_combo[i] = (long)time.count();
  
}


int main() {

    // Установка языка и форматированного вывода
    cout.setf(ios::fixed);  
    cout.precision(1);
	setlocale(LC_ALL, "Russian");
	srand(time(0));

    // (метод для замера общего времени программы)
    auto begin = steady_clock::now();
    
    // Начало второй части задания
    // 0.1) Инициализация переменных, отвечающих за 
    // длины массивов и  колличество измерений 
    const int len_100 = 100;
    const int len_1k = 1000;
    const int len_5k = 5000;
    const int len_10k = 10000;
    const int len_50k = 50000;
    const int len_100k = 100000;

    const int measures = 10 + 3;

    // 0.2) Инициализация Основных массивов
    int array_100[len_100];
    int array_1k[len_1k];
    int array_5k[len_5k];
    int array_10k[len_10k];
    int array_50k[len_50k];
    int array_100k[len_100k];

    // 0.3) Инициализация будущих копий массивов
    int merge_100[len_100], bubble_100[len_100], combo_100[len_100];
    int merge_1k[len_1k], bubble_1k[len_1k], combo_1k[len_1k];
    int merge_5k[len_5k], bubble_5k[len_5k], combo_5k[len_5k];
    int merge_10k[len_10k], bubble_10k[len_10k], combo_10k[len_10k];
    int merge_50k[len_50k], bubble_50k[len_50k], combo_50k[len_50k];
    int merge_100k[len_100k], bubble_100k[len_100k], combo_100k[len_100k];
    
    long time_merge_100[measures];
    long time_bubble_100[measures];
    long time_combo_100[measures];
    
    long time_merge_1k[measures];
    long time_bubble_1k[measures];
    long time_combo_1k[measures];
    
    long time_merge_5k[measures];
    long time_bubble_5k[measures];
    long time_combo_5k[measures];

    long time_merge_10k[measures];
    long time_bubble_10k[measures];
    long time_combo_10k[measures];

    long time_merge_50k[measures];
    long time_bubble_50k[measures];
    long time_combo_50k[measures];

    long time_merge_100k[measures];
    long time_bubble_100k[measures];
    long time_combo_100k[measures];
    
    cout << "\t LOG: Массивы инициализированы ";

    // 1) Генерирование случайных массивов
    filling(array_100, len_100);
    filling(array_1k, len_1k);
    filling(array_5k, len_5k);
    filling(array_10k, len_10k);
    filling(array_50k, len_50k);
    filling(array_100k, len_100k);

    

    // 2) Создание копий массивов
    making_copies(array_100, merge_100, len_100);
    making_copies(array_100, bubble_100, len_100);
    making_copies(array_100, combo_100, len_100);

    making_copies(array_1k, merge_1k, len_1k);
    making_copies(array_1k, bubble_1k, len_1k);
    making_copies(array_1k, combo_1k, len_1k);

    making_copies(array_5k, merge_5k, len_5k);
    making_copies(array_5k, bubble_5k, len_5k);
    making_copies(array_5k, combo_5k, len_5k);

    making_copies(array_10k, merge_10k, len_10k);
    making_copies(array_10k, bubble_10k, len_10k);
    making_copies(array_10k, combo_10k, len_10k);

    making_copies(array_50k, merge_50k, len_50k);
    making_copies(array_50k, bubble_50k, len_50k);
    making_copies(array_50k, combo_50k, len_50k);

    making_copies(array_100k, merge_100k, len_100k);
    making_copies(array_100k, bubble_100k, len_100k);
    making_copies(array_100k, combo_100k, len_100k);
    
    auto end = steady_clock::now();
    auto time = duration_cast<microseconds>(end - begin);
    cout << "\n\t LOG: Массивы заполнены и скопированы, прошло времени (микросекунд): " << time.count();

    

    for (int j = 0; j < measures; j++)
    {
        // 3) Сортировка массивов и замеры времени 
        arrays_sorting(merge_100, bubble_100, combo_100, len_100, time_merge_100, time_bubble_100, time_combo_100, j);
        arrays_sorting(merge_1k, bubble_1k, combo_1k, len_1k, time_merge_1k, time_bubble_1k, time_combo_1k, j);  
        arrays_sorting(merge_5k, bubble_5k, combo_5k, len_5k, time_merge_5k, time_bubble_5k, time_combo_5k, j); 
        arrays_sorting(merge_10k, bubble_10k, combo_10k, len_10k, time_merge_10k, time_bubble_10k, time_combo_10k, j);   
        arrays_sorting(merge_50k, bubble_50k, combo_50k, len_50k, time_merge_50k, time_bubble_50k, time_combo_50k, j);  
        arrays_sorting(merge_100k, bubble_100k, combo_100k, len_100k, time_merge_100k, time_bubble_100k, time_combo_100k, j);

    }

    // 4) Вывод результатов замеров времени на экран
    cout << "\n\t LOG: Массивы Отсортированы. Результаты: ";
    results_time_cout(time_merge_100, time_bubble_100, time_combo_100, len_100);
    results_time_cout(time_merge_1k, time_bubble_1k, time_combo_1k, len_1k);
    results_time_cout(time_merge_5k, time_bubble_5k, time_combo_5k, len_5k);
    results_time_cout(time_merge_10k, time_bubble_10k, time_combo_10k, len_10k);
    results_time_cout(time_merge_50k, time_bubble_50k, time_combo_50k, len_50k);
    results_time_cout(time_merge_100k, time_bubble_100k, time_combo_100k, len_100k);
    auto end_all = steady_clock::now();
    auto timer_all = duration_cast<seconds>(end_all - begin);
    cout << " \n\t LOG: Общее время работы программы: " << timer_all.count() << " секунд \n";
    return 0;
}

