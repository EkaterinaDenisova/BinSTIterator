// BSTIterator.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "TreeNode.h"
#include "BinSTree.h"

int main()
{
    setlocale(LC_ALL, "rus");

    cout << "Класс бинарного дерева поиска";

    //     8
    //    / \
    //   3   10
    //  / \
    // 1   6
    //    /
    //   4


    // создание дерева
    BinSTree<int> tr;
    // вставка
    tr.Insert(8);
    tr.Insert(3);
    tr.Insert(1);
    tr.Insert(10);
    tr.Insert(6);
    tr.Insert(4);

    cout << "\nБинарное дерево поиска: ";
    inorderPrint(tr.GetRoot(), &printNode);

    //cout << "\nКол-во узлов в дереве: " << tr.ListSize();

    cout << "\nИтератор:\n";

    // цикл с использованием итераторов
    for (BinSTree<int>::BinSTreeIterator<int> it1 = tr.begin(); it1 != tr.end(); ++it1) {
        cout << *it1 << " ";
    }

    std::cout << "\n";

    // Автоматически создаётся 2 итератора на начало и конец
    // совпадает с циклом выше, но реализация короче
    for (auto it2 : tr) {
        cout << it2 << " ";
    }

    std::cout << "\n";
    //inorderPrint(tr.GetRoot(), &printNode);

    tr.ClearList();
}


