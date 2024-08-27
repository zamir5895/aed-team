#include <iostream>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;

    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class List {
private:
    Node<T>* head;

public:
    List() : head(nullptr) {}

    T front() {
        return head->data;
    }

    T back() {
        Node<T>* temp;
        while(temp != nullptr) {
            temp = temp->next;
        }
        return temp->data;
    }

    void push_front(T val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = head;
        head = newNode;
    }
};

int main() {

    return 0;
}