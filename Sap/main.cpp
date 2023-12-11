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
    // std::locale::global(std::locale("ru_RU.UTF-8"));  // Uncomment if needed

    Sap game;
    game.run();

    return 0;
}
