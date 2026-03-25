#include <iostream>
#include <string>
#include <climits>

#include <Windows.h>

#include "counter.h"

namespace my_namespace {
	Counter::Counter() : numCounter(1) {}
	Counter::Counter(int initial) : numCounter(initial) {}
	void Counter::run() {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        std::string answer;
        int initValue = 0;
        Counter counter;

        std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
        while (true) {
            std::cin >> answer;
            if (answer == "да" || answer == "нет") {
                break;
            }
            std::cout << "Пожалуйста, введите 'да' или 'нет': ";
        }

        if (answer == "да") {
            std::cout << "Введите начальное значение счётчика: ";
            while (true) {
                std::cin >> initValue;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(INT_MAX, '\n');
                    std::cout << "Ошибка ввода. Пожалуйста, введите целое число: ";
                }
                else {
                    std::cin.ignore(INT_MAX, '\n');
                    break;
                }
            }
            counter = Counter(initValue);
        }

        char command;
        bool exitRequested = false;
        do {
            std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
            std::cin >> command;

            if (command == '=') {
                std::cout << counter.getValue() << "\n";
            }
            else {
                exitRequested = counter.processCommand(command);
            }
        } while (!exitRequested);

        std::cout << "До свидания!\n";
    }
    Counter::~Counter() {}
    int Counter::getValue() const { return numCounter; }
    void Counter::increment() { ++numCounter; }
    void Counter::decrement() { --numCounter; }
    bool Counter::processCommand(char cmd) {
        switch (cmd) {
        case '+':
            increment();
            return false;
        case '-':
            decrement();
            return false;
        case 'x':           // английская раскладка
            return true;
        case '\xF5':        // русская х в этой кодировке
            return true;
        default:
            std::cout << "Unknown operation.\n";
            return false;
        }
    }
}