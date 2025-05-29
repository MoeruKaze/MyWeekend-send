#include <iostream>
#include "RedBlackTree.h"
#include "locale.h"
int main() {
    setlocale(LC_ALL, "RU");
    RedBlackTree<int> tree;

    // Добавляем элементы в дерево
    tree.add(10);
    tree.add(5);
    tree.add(15);
    tree.add(3);
    tree.add(7);
    tree.add(12);
    tree.add(20);

    // Выводим структуру дерева
    std::cout << "Красно-черное дерево (int):\n";
    std::cout << tree << std::endl;

    // Проверяем наличие элементов
    std::cout << "Содержит 7: " << (tree.find(7) ? "Да" : "Нет") << std::endl;
    std::cout << "Содержит 8: " << (tree.find(8) ? "Да" : "Нет") << std::endl;

    return 0;
}