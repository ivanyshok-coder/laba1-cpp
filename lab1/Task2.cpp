#include "Task2.h"

#include <iostream>
#include <string>

// Задача 2. Безопасное деление
double safeDiv(int x, int y) {
    if (y == 0) {
        return 0;
    }
    return static_cast<double>(x) / y;
}

void task2SafeDiv() {
    int x, y;
    std::cout << "Введите число X: ";
    std::cin >> x;
    std::cout << "Введите число Y: ";
    std::cin >> y;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Ошибка: введено не число\n";
        return;
    }
    std::cout << "Результат: " << safeDiv(x, y) << "\n";
}

// Задача 4. Строка сравнения
std::string makeDecision(int x, int y) {
    if (x > y) {
        return std::to_string(x) + " > " + std::to_string(y);
    }
    if (x < y) {
        return std::to_string(x) + " < " + std::to_string(y);
    }
    return std::to_string(x) + " == " + std::to_string(y);
}

void task4MakeDecision() {
    int x, y;
    std::cout << "Введите число X: ";
    std::cin >> x;
    std::cout << "Введите число Y: ";
    std::cin >> y;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Ошибка: введено не число\n";
        return;
    }
    std::cout << makeDecision(x, y) << "\n";
}

// Задача 6. Тройная сумма
bool sum3(int x, int y, int z) {
    return (x + y == z) || (x + z == y) || (y + z == x);
}

void task6Sum3() {
    int x, y, z;
    std::cout << "Введите число X: ";
    std::cin >> x;
    std::cout << "Введите число Y: ";
    std::cin >> y;
    std::cout << "Введите число Z: ";
    std::cin >> z;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Ошибка: введено не число\n";
        return;
    }
    if (sum3(x, y, z)) {
        std::cout << "true\n";
    } else {
        std::cout << "false\n";
    }
}

// Задача 8. Возраст
std::string age(int x) {
    int last_two = x % 100;
    int last_one = x % 10;

    if (last_two >= 11 && last_two <= 14) {
        return std::to_string(x) + " лет";
    }
    if (last_one == 1) {
        return std::to_string(x) + " год";
    }
    if (last_one >= 2 && last_one <= 4) {
        return std::to_string(x) + " года";
    }
    return std::to_string(x) + " лет";
}

void task8Age() {
    int x;
    std::cout << "Введите возраст X: ";
    std::cin >> x;
    if (std::cin.fail() || x < 0) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Ошибка: введено некорректное число\n";
        return;
    }
    std::cout << age(x) << "\n";
}

// Задача 10. Вывод дней недели
void printDays(int x) {
    switch (x) {
        case 1:
            std::cout << "понедельник\n";
        case 2:
            std::cout << "вторник\n";
        case 3:
            std::cout << "среда\n";
        case 4:
            std::cout << "четверг\n";
        case 5:
            std::cout << "пятница\n";
        case 6:
            std::cout << "суббота\n";
        case 7:
            std::cout << "воскресенье\n";
            break;
        default:
            std::cout << "это не день недели\n";
    }
}

void task10PrintDays() {
    int x;
    std::cout << "Введите номер дня недели (1-7): ";
    std::cin >> x;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Ошибка: введено не число\n";
        return;
    }
    printDays(x);
}

