#include <iostream>
#include "Forward_list.h"

using namespace std;

int main() {
    Forward_list<int> myList;

    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    myList.push_back(4);

    myList.print();

    cout << myList.size();

    return 0;
}