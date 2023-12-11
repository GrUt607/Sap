/**
 * @file Sap.h
 * @brief Заголовочный файл для игры "Сапер".
 * @details Содержит описание класса Sap и его методов.
 */

#ifndef SAP_H
#define SAP_H

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <string>

 /**
  * @brief Пространство имен для игры "Сапер".
  */
class Sap {
public:
    /**
     * @brief Конструктор по умолчанию.
     */
    Sap();

    /**
     * @brief Деструктор.
     */
    ~Sap();

    /**
     * @brief Конструктор с параметрами.
     * @param field Игровое поле.
     * @param opened Массив открытых клеток.
     */
    Sap(const std::vector<std::vector<int>>& field, const std::vector<std::vector<bool>>& opened);

    /**
     * @brief Конструктор копирования.
     * @param other Другой объект класса Sap.
     */
    Sap(const Sap& other);

    /**
     * @brief Оператор копирования.
     * @param other Другой объект класса Sap.
     * @return Возвращает ссылку на текущий объект Sap.
     */
    Sap& operator=(const Sap& other);

    /**
     * @brief Оператор сравнения.
     * @param other Другой объект класса Sap.
     * @return Возвращает true, если объекты равны, и false в противном случае.
     */
    bool operator==(const Sap& other) const;

    /**
     * @brief Оператор ввода.
     * @param is Входной поток.
     * @param game Объект Sap.
     * @return Возвращает ссылку на входной поток.
     */
    friend std::istream& operator>>(std::istream& is, Sap& game);

    /**
     * @brief Оператор вывода.
     * @param os Выходной поток.
     * @param game Объект Sap.
     * @return Возвращает ссылку на выходной поток.
     */
    friend std::ostream& operator<<(std::ostream& os, const Sap& game);

    /**
     * @brief Создает двумерный массив для игрового поля.
     */
    void createIntArr();

    /**
     * @brief Создает двумерный массив для массива открытых клеток.
     */
    void createBoolArr();

    /**
     * @brief Очищает двумерный массив для игрового поля.
     */
    void deleteIntArr();

    /**
     * @brief Очищает двумерный массив для массива открытых клеток.
     */
    void deleteBoolArr();

    /**
     * @brief Выводит правила игры на экран.
     */
    void rules();

    /**
     * @brief Выводит символ мины.
     */
    void show_of_mines();

    /**
     * @brief Открывает все мины на игровом поле.
     */
    void openmines();

    /**
     * @brief Проверяет, является ли клетка пустой.
     * @param i Координата i.
     * @param j Координата j.
     * @return Возвращает true, если клетка пуста, и false в противном случае.
     */
    bool empty(int i, int j);

    /**
     * @brief Проверяет, содержит ли клетка мину.
     * @param i Координата i.
     * @param j Координата j.
     * @return Возвращает true, если клетка содержит мину, и false в противном случае.
     */
    bool mine(int i, int j);

    /**
     * @brief Выводит игровое поле на экран.
     */
    void print_array_2D();

    /**
     * @brief Очищает соседние пустые клетки, начиная с указанной клетки.
     * @param i Координата i.
     * @param j Координата j.
     */
    void clean(int i, int j);

    /**
     * @brief Проверяет, выиграна ли игра или проиграна.
     * @return Возвращает true, если игра выиграна или проиграна, и false в противном случае.
     */
    bool win_or_lose();

    /**
     * @brief Выводит результат игры на экран (победа или поражение).
     * @param loser Параметр, указывающий, проиграна игра или нет.
     */
    void final(bool loser);

    /**
     * @brief Запускает игру.
     */
    void run();

    /**
     * @brief Размер поля.
     */
    static const int N = 10;

    /**
     * @brief Количество мин на поле.
     */
    static const int BOOM = 10;

    /**
     * @brief Игровое поле.
     */
    std::vector<std::vector<int>> Playing_field;

    /**
     * @brief Массив открытых клеток.
     */
    std::vector<std::vector<bool>> open;
};

#endif // SAP_H
