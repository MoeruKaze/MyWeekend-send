#include "RedBlackTree.h"
#include "MyDateTime.h"
#include <locale.h>



int main() {
    setlocale(LC_ALL, "RU");

    RedBlackTree<int> treeint;
    int a = 10;
    int a1 = 5;
    int a2 = 15;
    int a3 = 7;
    int a4 = 13;
    treeint.add(a1);
    treeint.add(a2);
    treeint.add(a3);
    treeint.add(a4);

    RedBlackTree<MyDateTime> tree;
    MyDateTime date1 = MyDateTime(19, 12, 2006, 04, 13, 23);
    MyDateTime date2 = MyDateTime(31, 24, 2006, 15, 44, 23);
    MyDateTime date3 = MyDateTime(19, 12, 1984, 15, 44, 23);
    MyDateTime date4 = MyDateTime(10, 10, 1000, 10, 10, 10);
    MyDateTime date5 = MyDateTime(01, 53, 5000, 10, 10, 10);
    MyDateTime date6 = MyDateTime(10, 10, 2000, 10, 10, 10);

    tree.add(date1);
    tree.add(date2);
    tree.add(date3);
    tree.add(date4);
    tree.add(date5);

    std::cout << tree << std::endl;

    std::cout << "Содержит date6: " << (tree.find(date6) ? "Да" : "Нет") << std::endl;
    std::cout << "Содержит date1: " << (tree.find(date1) ? "Да" : "Нет") << std::endl;

    std::cout << treeint << std::endl;
    std::cout << "Содержит date6: " << (treeint.find(7) ? "Да" : "Нет") << std::endl;
    std::cout << "Содержит date1: " << (treeint.find(8) ? "Да" : "Нет") << std::endl;



    return 0;
}