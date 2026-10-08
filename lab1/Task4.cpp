#include "Task4.h"

#include <iostream>

// Глобальные переменные для передачи размеров массивов.
// Сигнатуры функций заданы без размеров, поэтому используем глобальные.
int g_size = 0;         // размер основного массива
int g_size2 = 0;        // размер второго массива (для concat)
int g_result_size = 0;  // размер массива-результата

// Вспомогательная функция вывода массива
void printArray(int arr[], int size) {
    std::cout << "[";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i];
        if (i < size - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}

// Вспомогательная функция ввода массива
bool readArray(int arr[], int* size) {
    std::cout << "Введите размер массива: ";
    std::cin >> *size;
    if (std::cin.fail() || *size <= 0 || *size > 100) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Ошибка: размер должен быть от 1 до 100\n";
        return false;
    }
    std::cout << "Введите " << *size << " элементов массива:\n";
    for (int i = 0; i < *size; i++) {
        std::cin >> arr[i];
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ошибка: введено не число\n";
            return false;
        }
    }
    return true;
}

// Задача 2. Поиск последнего значения
int findLast(int arr[], int x) {
    int last_index = -1;
    for (int i = 0; i < g_size; i++) {
        if (arr[i] == x) {
            last_index = i;
        }
    }
    return last_index;
}

void task2FindLast() {
    int arr[100];
    if (!readArray(arr, &g_size)) {
        return;
    }
    int x;
    std::cout << "Введите число X для поиска: ";
    std::cin >> x;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Ошибка: введено не число\n";
        return;
    }
    int result = findLast(arr, x);
    std::cout << "Индекс последнего вхождения: " << result << "\n";
}

// Задача 4. Добавление в массив
int* add(int arr[], int x, int pos) {
    g_result_size = g_size + 1;
    int* result = new int[g_result_size];
    for (int i = 0; i < pos; i++) {
        result[i] = arr[i];
    }
    result[pos] = x;
    for (int i = pos; i < g_size; i++) {
        result[i + 1] = arr[i];
    }
    return result;
}

void task4Add() {
    int arr[100];
    if (!readArray(arr, &g_size)) {
        return;
    }
    int x, pos;
    std::cout << "Введите значение X: ";
    std::cin >> x;
    std::cout << "Введите позицию pos (от 0 до " << g_size << "): ";
    std::cin >> pos;
    if (std::cin.fail() || pos < 0 || pos > g_size) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Ошибка: некорректные данные\n";
        return;
    }
    int* result = add(arr, x, pos);
    std::cout << "Результат: ";
    printArray(result, g_result_size);
    delete[] result;
}

// Задача 6. Реверс
void reverse(int arr[]) {
    for (int i = 0; i < g_size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[g_size - 1 - i];
        arr[g_size - 1 - i] = temp;
    }
}

void task6Reverse() {
    int arr[100];
    if (!readArray(arr, &g_size)) {
        return;
    }
    reverse(arr);
    std::cout << "Результат: ";
    printArray(arr, g_size);
}

// Задача 8. Объединение
int* concat(int arr1[], int arr2[]) {
    g_result_size = g_size + g_size2;
    int* result = new int[g_result_size];
    for (int i = 0; i < g_size; i++) {
        result[i] = arr1[i];
    }
    for (int i = 0; i < g_size2; i++) {
        result[g_size + i] = arr2[i];
    }
    return result;
}

void task8Concat() {
    int arr1[100];
    int arr2[100];
    std::cout << "--- Первый массив ---\n";
    if (!readArray(arr1, &g_size)) {
        return;
    }
    std::cout << "--- Второй массив ---\n";
    if (!readArray(arr2, &g_size2)) {
        return;
    }
    int* result = concat(arr1, arr2);
    std::cout << "Результат: ";
    printArray(result, g_result_size);
    delete[] result;
}

// Задача 10. Удалить негатив
int* deleteNegative(int arr[]) {
    int* result = new int[g_size];
    int count = 0;
    for (int i = 0; i < g_size; i++) {
        if (arr[i] >= 0) {
            result[count] = arr[i];
            count++;
        }
    }
    g_result_size = count;
    return result;
}

void task10DeleteNegative() {
    int arr[100];
    if (!readArray(arr, &g_size)) {
        return;
    }
    int* result = deleteNegative(arr);
    std::cout << "Результат: ";
    printArray(result, g_result_size);
    delete[] result;
}