﻿/**
 * @file Sap.cpp
 * @brief Имплементация класса Sap.
 */

#include "Sap.h"
#include <algorithm>
#include <iterator>

 /**
  * @brief Конструктор по умолчанию.
  */
Sap::Sap()
{
}

/**
 * @brief Деструктор.
 */
Sap::~Sap()
{
}

/**
 * @brief Конструктор с параметрами.
 * @param field Игровое поле.
 * @param opened Массив открытых клеток.
 */
Sap::Sap(const std::vector<std::vector<int>>& field, const std::vector<std::vector<bool>>& opened)
    : Playing_field(field), open(opened) {}

/**
 * @brief Конструктор копирования.
 * @param other Другой объект класса Sap.
 */
Sap::Sap(const Sap& other)
    : Playing_field(other.Playing_field), open(other.open) {}

/**
 * @brief Оператор копирования.
 * @param other Другой объект класса Sap.
 * @return Возвращает ссылку на текущий объект Sap.
 */
Sap& Sap::operator=(const Sap& other)
{
    if (this != &other)
    {
        Playing_field = other.Playing_field;
        open = other.open;
    }
    return *this;
}

/**
 * @brief Оператор сравнения.
 * @param other Другой объект класса Sap.
 * @return Возвращает true, если объекты равны, и false в противном случае.
 */
bool Sap::operator==(const Sap& other) const
{
    return (Playing_field == other.Playing_field) && (open == other.open);
}

/**
 * @brief Оператор ввода.
 * @param is Входной поток.
 * @param game Объект Sap.
 * @return Возвращает ссылку на входной поток.
 */
std::istream& operator>>(std::istream& is, Sap& game)
{
    // Ваша реализация ввода с использованием std::vector и алгоритмов STL
    for (int i = 0; i < Sap::N; ++i)
    {
        for (int j = 0; j < Sap::N; ++j)
        {
            is >> game.Playing_field[i][j];
        }
    }

    for (int i = 0; i < Sap::N; ++i)
    {
        for (int j = 0; j < Sap::N; ++j)
        {
            int value;
            is >> value;
            game.open[i][j] = static_cast<bool>(value);
        }
    }

    return is;
}

/**
 * @brief Оператор вывода.
 * @param os Выходной поток.
 * @param game Объект Sap.
 * @return Возвращает ссылку на выходной поток.
 */
std::ostream& operator<<(std::ostream& os, const Sap& game)
{
    // Ваша реализация вывода с использованием std::vector и алгоритмов STL
    for (int i = 0; i < Sap::N; ++i)
    {
        std::copy(game.Playing_field[i].begin(), game.Playing_field[i].end(), std::ostream_iterator<int>(os, " "));
        os << '\n';
    }

    for (int i = 0; i < Sap::N; ++i)
    {
        std::copy(game.open[i].begin(), game.open[i].end(), std::ostream_iterator<bool>(os, " "));
        os << '\n';
    }

    return os;
}

/**
 * @brief Создает двумерный массив для игрового поля.
 */
void Sap::createIntArr()
{
    Playing_field.resize(N, std::vector<int>(N, 0));
}

/**
 * @brief Создает двумерный массив для массива открытых клеток.
 */
void Sap::createBoolArr()
{
    open.resize(N, std::vector<bool>(N, false));
}

/**
 * @brief Очищает двумерный массив для игрового поля.
 */
void Sap::deleteIntArr()
{
    Playing_field.clear();
}

/**
 * @brief Очищает двумерный массив для массива открытых клеток.
 */
void Sap::deleteBoolArr()
{
    open.clear();
}




/**
 * @brief Запускает игру.
 */
void Sap::run()
{
    //std::srand(static_cast<unsigned int>(std::time(nullptr)));
    //std::locale::global(std::locale("ru_RU.UTF-8"));  

    Sap game;

    char choice{};
    while (true)
    {
        std::system("cls");
        std::wcout << L"SAPPER " << std::endl << std::endl << std::endl;

        std::wcout << L"1 - Play " << std::endl;
        std::wcout << L"2 - THE RULES OF THE GAME << SAPPER >> " << std::endl;
        std::wcout << L"0 - Exit" << std::endl << std::endl << std::endl;
        std::wcout << L"MAKE YOUR CHOICE:" << std::endl << std::endl;
        std::cin >> choice;
        std::wcout << std::endl;
        std::cin.ignore(100, '\n');

        if (choice == '0')
            break;

        switch (choice)
        {
        case '1':
        {
            game.createIntArr();
            game.createBoolArr();
            int i{};
            int j{};
            for (i = 0; i < Sap::N; i++) // заполнение 0-ми
            {
                for (j = 0; j < Sap::N; j++) // заполнение 0-ми
                {
                    game.Playing_field[i][j] = 0;
                    game.open[i][j] = false;
                }
            }
            for (int c = 0; c < Sap::BOOM; c++) // заполнение минами
            {
                do
                {
                    i = std::rand() % Sap::N;
                    j = std::rand() % Sap::N;
                } while (game.Playing_field[i][j] != 0);
                game.Playing_field[i][j] = -1;
            }
            for (i = 0; i < Sap::N; i++) // заполнение подсказками
            {
                for (j = 0; j < Sap::N; j++)
                {
                    if (game.Playing_field[i][j] != -1)
                    {
                        int quantity{};
                        if (game.mine(i - 1, j - 1)) quantity++;
                        if (game.mine(i - 1, j)) quantity++;
                        if (game.mine(i - 1, j + 1)) quantity++;
                        if (game.mine(i, j - 1)) quantity++;
                        if (game.mine(i, j + 1)) quantity++;
                        if (game.mine(i + 1, j - 1)) quantity++;
                        if (game.mine(i + 1, j)) quantity++;
                        if (game.mine(i + 1, j + 1)) quantity++;
                        game.Playing_field[i][j] = quantity;
                    }
                }
            }
            while (true)
            {
                std::system("cls");
                std::wcout << L"************************************************" << std::endl << std::endl;
                std::wcout << L"* I made a mistake once and you made a mistake *" << std::endl << std::endl;
                std::wcout << L"************************************************" << std::endl;
                std::wcout << std::endl << std::endl;
                game.print_array_2D();
                std::wcout << std::endl;

                // запрашиваем координаты удара
                char input_coordinate[3]{ '\0' };
                std::wcout << L"Enter the coordinates of the impact (Example: D3): ";
                std::cin >> input_coordinate;
                // переводим координаты в цифровой вид
                if ((input_coordinate[0] >= 'A') && (input_coordinate[0] <= 'J'))
                {
                    j = input_coordinate[0] - 'A';        // буква в промежутке от A до J
                }
                else if ((input_coordinate[0] >= 'a') && (input_coordinate[0] <= 'j'))
                {
                    j = input_coordinate[0] - 'a';  // буква в промежутке от a до j
                }
                else continue;                              // если введены неверные значения, возврат в начало цикла
                if ((input_coordinate[1] >= '0') && (input_coordinate[1] <= '9'))
                {
                    i = input_coordinate[1] - '0';
                }
                else continue;

                // далее проверяем все восемь окрестных полей на пустые клетки показываем некий кусок поля               
                game.clean(i, j);
                if (game.mine(i, j))
                {
                    game.openmines();
                    game.final(true);
                    break;
                }
                if (game.win_or_lose())
                {
                    game.final(false);
                    break;
                }
            }
            game.deleteBoolArr();
            game.deleteIntArr();
        }
        break;

        case '2':
        {
            game.rules();
            std::system("pause");
        }
        break;

        default:
        {
            std::wcout << L"Error, try again, press the <Enter> button to try again" << std::endl;
            break;
        }
        }
        std::cin.get();
    }
}


/**
 * @brief Выводит правила игры на экран.
 */
void Sap::rules()
{
    std::wcout << L"\tMINESWEEPER: RULES AND GENERAL INFORMATION" << std::endl << std::endl << std::endl << std::endl;
    std::wcout << L"\tStart by opening one cell." << std::endl;
    std::wcout << L"\tThe number in the cell shows how many mines are hidden around this cell. This number will help you understand where the safe cells are and where the bombs are." << std::endl;
    std::wcout << L"\tIf there is an empty cell next to an open cell, it will open automatically." << std::endl;
    std::wcout << L"\tif you open a cell with a mine, the game is lost." << std::endl;
    std::wcout << L"\tIf a number is specified in a cell, it shows how many mines are hidden in the eight cells around the given one. This number helps you understand where the safe cells are." << std::endl;
    std::wcout << L"\tThe game continues until you open all the unlined cells." << std::endl << std::endl << std::endl;
    std::wcout << L"\tHave a good game!)" << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
}

/**
 * @brief Выводит символ мины.
 */
void Sap::show_of_mines()
{
    std::wcout << L"* ";
}

/**
 * @brief Открывает все мины на игровом поле.
 */
void Sap::openmines()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (Playing_field[i][j] == -1) open[i][j] = true;
        }
    }
}

/**
 * @brief Проверяет, является ли клетка пустой.
 * @param i Координата i.
 * @param j Координата j.
 * @return Возвращает true, если клетка пуста, и false в противном случае.
 */
bool Sap::empty(int i, int j)
{
    if ((i >= 0) && (i < N))
    {
        if ((j >= 0) && (j < N))
        {
            if (Playing_field[i][j] == 0) return true;
        }
    }
    return false;
}

/**
 * @brief Проверяет, содержит ли клетка мину.
 * @param i Координата i.
 * @param j Координата j.
 * @return Возвращает true, если клетка содержит мину, и false в противном случае.
 */
bool Sap::mine(int i, int j)
{
    if ((i >= 0) && (i < N))
    {
        if ((j >= 0) && (j < N))
        {
            if (Playing_field[i][j] == -1) return true;
        }
    }
    return false;
}

/**
 * @brief Выводит игровое поле на экран.
 */
void Sap::print_array_2D()
{
    const std::string strLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::wcout << L"  ";
    for (int i = 0; i < N; i++)
    {
        std::wcout << L" " << strLetters[i];
    }
    std::wcout << std::endl;

    for (int x = 0; x < N; x++)
    {
        std::wcout << x << L"|";

        for (int y = 0; y < N; y++)
        {
            if (open[x][y])
            {
                if (Playing_field[x][y] == -1)
                {
                    show_of_mines();
                }
                else if (Playing_field[x][y] == 0)
                {
                    std::wcout << L"  ";
                }
                else
                {
                    std::wcout << Playing_field[x][y] << L" ";
                }
            }
            else
            {
                std::wcout << L"& ";
            }
        }
        std::wcout << L"\n";
    }
}

/**
 * @brief Очищает соседние пустые клетки, начиная с указанной клетки.
 * @param i Координата i.
 * @param j Координата j.
 */
void Sap::clean(int i, int j)
{
    if ((i >= 0) && (i < N) && (j >= 0) && (j < N) && !open[i][j])
    {
        open[i][j] = true;
        if (Playing_field[i][j] == 0)
        {
            clean(i - 1, j - 1);
            clean(i - 1, j);
            clean(i - 1, j + 1);
            clean(i, j - 1);
            clean(i, j + 1);
            clean(i + 1, j - 1);
            clean(i + 1, j);
            clean(i + 1, j + 1);
        }
    }
}

/**
 * @brief Проверяет, выиграна ли игра или проиграна.
 * @return Возвращает true, если игра выиграна или проиграна, и false в противном случае.
 */
bool Sap::win_or_lose()
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            if ((Playing_field[x][y] == -1 && open[x][y]) || (Playing_field[x][y] >= 0 && !open[x][y]))
                return false; // Игра не завершена
        }
    }
    return true; // Игра завершена
}

/**
 * @brief Выводит результат игры на экран (победа или поражение).
 * @param loser Параметр, указывающий, проиграна игра или нет.
 */
void Sap::final(bool loser)
{
    std::system("cls");
    print_array_2D();
    if (loser)
    {
        std::wcout << L"\a" << std::endl;
        std::wcout << L"YOU'VE LOST!(" << std::endl << std::endl;
    }
    else
    {
        std::wcout << L"\a" << std::endl;
        std::wcout << L"YOU'VE LOST!)" << std::endl << std::endl;
    }
    std::cin.get();
    std::wcout << std::endl << std::endl;
}
