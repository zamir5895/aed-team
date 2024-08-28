#include <iostream>
#include "Forward_list.h"

using namespace std;

int main() {
    Forward_list<int> myList;

    // Test de push_front y front
    myList.push_front(10);
    myList.push_front(20);
    myList.push_front(30);
    cout << myList.front() << endl; // 30

    // Test de push_back y back
    myList.push_back(40);
    myList.push_back(50);
    cout << myList.back() << endl; // 50

    // Test de pop_front
    cout << myList.pop_front() << endl; // 30
    cout << myList.front() << endl; // 20

    // Test de pop_back
    cout << myList.pop_back() << endl; // 50
    cout << myList.back() << endl; // 40

    // Test de insert en la posición 1
    myList.insert(25, 1);
    myList.pop_front(); // Saltar el primer elemento
    cout << myList.front() << endl; // 25

    // Test de inserción al final
    myList.insert(55, 2);
    cout << myList.back() << endl; // 55

    // Test de inserción en la cabeza
    myList.insert(100, 0);
    cout << myList.front() << endl; // 100

    return 0;
}