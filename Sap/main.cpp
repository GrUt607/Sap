/**
 * @file main.cpp
 * @brief Основной файл программы для игры "Сапер".
 * @details Содержит функцию main, запускающую игру.
 */

#include "Sap.h"

 /**
  * @brief Основная функция программы.
  * @details Создает объект игры Sap, инициализирует генератор случайных чисел,
  * устанавливает локаль для вывода на русском языке (раскомментировать при необходимости),
  * и запускает игру вызовом метода run().
  * @return Возвращает 0 при успешном завершении программы.
  */
int main()
{
    //std::srand(static_cast<unsigned int>(std::time(nullptr)));
    //std::wcout.imbue(std::locale("ru_RU.UTF-8"));


    Sap game;
    game.run();

    return 0;
}
