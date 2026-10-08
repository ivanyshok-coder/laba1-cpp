#include "Task3.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

// Задача 2. Числа наоборот
std::string reverseListNums(int x) {
    std::string result = "";
    for (int i = x; i >= 0; i--) {
        result += std::to_string(i);
        if (i > 0) {
            result += " ";
        }
    }
    return result;
}

void task2ReverseListNums() {
    int x;
    std::cout << "Введите число X: ";
    std::cin >> x;
    if (std::cin.fail() || x < 0) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Ошибка: введено некорректное число\n";
        return;
    }
    std::cout << reverseListNums(x) << "\n";
}

// Задача 4. Степень числа
int pow(int x, int y) {
    int result = 1;
    for (int i = 0; i < y; i++) {
        result *= x;
    }
    return result;
}

void task4Pow() {
    int x, y;
    std::cout << "Введите основание X: ";
    std::cin >> x;
    std::cout << "Введите степень Y: ";
    std::cin >> y;
    if (std::cin.fail() || y < 0) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Ошибка: введено некорректное число\n";
        return;
    }
    std::cout << "Результат: " << pow(x, y) << "\n";
}

// Задача 6. Одинаковость
bool equalNum(int x) {
    int abs_x = std::abs(x);
    int first = abs_x % 10;
    abs_x /= 10;
    while (abs_x > 0) {
        if (abs_x % 10 != first) {
            return false;
        }
        abs_x /= 10;
    }
    return true;
}

void task6EqualNum() {
    int x;
    std::cout << "Введите число X: ";
    std::cin >> x;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Ошибка: введено не число\n";
        return;
    }
    if (equalNum(x)) {
        std::cout << "true\n";
    } else {
        std::cout << "false\n";
    }
}

// Задача 8. Левый треугольник
void leftTriangle(int x) {
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < i; j++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}

void task8LeftTriangle() {
    int x;
    std::cout << "Введите высоту треугольника X: ";
    std::cin >> x;
    if (std::cin.fail() || x <= 0) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Ошибка: введено некорректное число\n";
        return;
    }
    leftTriangle(x);
}

// Задача 10. Угадайка
void guessGame() {
    std::srand(std::time(0));
    int secret = std::rand() % 10;
    int attempts = 0;
    int guess;

    do {
        std::cout << "Введите число от 0 до 9: ";
        std::cin >> guess;
        attempts++;

        if (std::cin.fail() || guess < 0 || guess > 9) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ошибка: нужно ввести число от 0 до 9\n";
            attempts--;
            continue;
        }

        if (guess == secret) {
            std::cout << "Вы угадали!\n";
        } else {
            std::cout << "Вы не угадали\n";
        }
    } while (guess != secret);

    std::cout << "Вы отгадали число за " << attempts << " попытки\n";
}

void task10GuessGame() {
    guessGame();
}
