/**
 * @file main.cpp
 * @brief �������� ���� ��������� ��� ���� "�����".
 * @details �������� ������� main, ����������� ����.
 */

#include "Sap.h"

 /**
  * @brief �������� ������� ���������.
  * @details ������� ������ ���� Sap, �������������� ��������� ��������� �����,
  * ������������� ������ ��� ������ �� ������� ����� (����������������� ��� �������������),
  * � ��������� ���� ������� ������ run().
  * @return ���������� 0 ��� �������� ���������� ���������.
  */
int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::locale::global(std::locale("ru_RU.UTF-8"));  

    Sap game;
    game.run();

    return 0;
}
