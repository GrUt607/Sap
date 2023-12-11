/**
 * @file Sap.h
 * @brief ������������ ���� ��� ���� "�����".
 * @details �������� �������� ������ Sap � ��� �������.
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
  * @brief ������������ ���� ��� ���� "�����".
  */
class Sap {
public:
    /**
     * @brief ����������� �� ���������.
     */
    Sap();

    /**
     * @brief ����������.
     */
    ~Sap();

    /**
     * @brief ����������� � �����������.
     * @param field ������� ����.
     * @param opened ������ �������� ������.
     */
    Sap(const std::vector<std::vector<int>>& field, const std::vector<std::vector<bool>>& opened);

    /**
     * @brief ����������� �����������.
     * @param other ������ ������ ������ Sap.
     */
    Sap(const Sap& other);

    /**
     * @brief �������� �����������.
     * @param other ������ ������ ������ Sap.
     * @return ���������� ������ �� ������� ������ Sap.
     */
    Sap& operator=(const Sap& other);

    /**
     * @brief �������� ���������.
     * @param other ������ ������ ������ Sap.
     * @return ���������� true, ���� ������� �����, � false � ��������� ������.
     */
    bool operator==(const Sap& other) const;

    /**
     * @brief �������� �����.
     * @param is ������� �����.
     * @param game ������ Sap.
     * @return ���������� ������ �� ������� �����.
     */
    friend std::istream& operator>>(std::istream& is, Sap& game);

    /**
     * @brief �������� ������.
     * @param os �������� �����.
     * @param game ������ Sap.
     * @return ���������� ������ �� �������� �����.
     */
    friend std::ostream& operator<<(std::ostream& os, const Sap& game);

    /**
     * @brief ������� ��������� ������ ��� �������� ����.
     */
    void createIntArr();

    /**
     * @brief ������� ��������� ������ ��� ������� �������� ������.
     */
    void createBoolArr();

    /**
     * @brief ������� ��������� ������ ��� �������� ����.
     */
    void deleteIntArr();

    /**
     * @brief ������� ��������� ������ ��� ������� �������� ������.
     */
    void deleteBoolArr();

    /**
     * @brief ������� ������� ���� �� �����.
     */
    void rules();

    /**
     * @brief ������� ������ ����.
     */
    void show_of_mines();

    /**
     * @brief ��������� ��� ���� �� ������� ����.
     */
    void openmines();

    /**
     * @brief ���������, �������� �� ������ ������.
     * @param i ���������� i.
     * @param j ���������� j.
     * @return ���������� true, ���� ������ �����, � false � ��������� ������.
     */
    bool empty(int i, int j);

    /**
     * @brief ���������, �������� �� ������ ����.
     * @param i ���������� i.
     * @param j ���������� j.
     * @return ���������� true, ���� ������ �������� ����, � false � ��������� ������.
     */
    bool mine(int i, int j);

    /**
     * @brief ������� ������� ���� �� �����.
     */
    void print_array_2D();

    /**
     * @brief ������� �������� ������ ������, ������� � ��������� ������.
     * @param i ���������� i.
     * @param j ���������� j.
     */
    void clean(int i, int j);

    /**
     * @brief ���������, �������� �� ���� ��� ���������.
     * @return ���������� true, ���� ���� �������� ��� ���������, � false � ��������� ������.
     */
    bool win_or_lose();

    /**
     * @brief ������� ��������� ���� �� ����� (������ ��� ���������).
     * @param loser ��������, �����������, ��������� ���� ��� ���.
     */
    void final(bool loser);

    /**
     * @brief ��������� ����.
     */
    void run();

    /**
     * @brief ������ ����.
     */
    static const int N = 10;

    /**
     * @brief ���������� ��� �� ����.
     */
    static const int BOOM = 10;

    /**
     * @brief ������� ����.
     */
    std::vector<std::vector<int>> Playing_field;

    /**
     * @brief ������ �������� ������.
     */
    std::vector<std::vector<bool>> open;
};

#endif // SAP_H
