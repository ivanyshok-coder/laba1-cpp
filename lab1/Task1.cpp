#include "Task1.h"

#include <iostream>
#include <cstdlib>

// Задача 2. Сумма знаков
int sumLastNums(int x) {
    int abs_x = std::abs(x);
    if (abs_x < 10) {
        std::cout << "Ошибка: число должно содержать не менее двух цифр\n";
        return -1;
    }
    int last_two = abs_x % 100;
    return last_two / 10 + last_two % 10;
}

void task2SumLastNums() {
    int x;
    std::cout << "Введите число X (не менее двух цифр): ";
    std::cin >> x;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Ошибка: введено не число\n";
        return;
    }
    int result = sumLastNums(x);
    if (result != -1) {
        std::cout << "Сумма последних двух цифр: " << result << "\n";
    }
}

// Задача 4. Есть ли позитив
bool isPositive(int x) {
    return x > 0;
}

void task4IsPositive() {
    int x;
    std::cout << "Введите число X: ";
    std::cin >> x;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Ошибка: введено не число\n";
        return;
    }
    if (isPositive(x)) {
        std::cout << "true\n";
    } else {
        std::cout << "false\n";
    }
}

// Задача 6. Большая буква
bool isUpperCase(char x) {
    return x >= 'A' && x <= 'Z';
}

void task6IsUpperCase() {
    char x;
    std::cout << "Введите символ X: ";
    std::cin >> x;
    if (isUpperCase(x)) {
        std::cout << "true\n";
    } else {
        std::cout << "false\n";
    }
}

// Задача 8. Делитель
bool isDivisor(int a, int b) {
    if (a == 0 || b == 0) {
        return false;
    }
    return (b % a == 0) || (a % b == 0);
}

void task8IsDivisor() {
    int a, b;
    std::cout << "Введите число A: ";
    std::cin >> a;
    std::cout << "Введите число B: ";
    std::cin >> b;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Ошибка: введено не число\n";
        return;
    }
    if (isDivisor(a, b)) {
        std::cout << "true\n";
    } else {
        std::cout << "false\n";
    }
}

// Задача 10. Многократный вызов
int lastNumSum(int a, int b) {
    return std::abs(a) % 10 + std::abs(b) % 10;
}

void task10LastNumSum() {
    int nums[5];
    std::cout << "Введите 5 чисел:\n";
    for (int i = 0; i < 5; i++) {
        std::cout << "Число " << i + 1 << ": ";
        std::cin >> nums[i];
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ошибка: введено не число\n";
            return;
        }
    }

    int result = nums[0];
    for (int i = 1; i < 5; i++) {
        int next = lastNumSum(result, nums[i]);
        std::cout << result << "+" << nums[i] << " = " << next << "\n";
        result = next;
    }
    std::cout << "Итого: " << result << "\n";
}

