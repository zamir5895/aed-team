#include <iostream>


template<typename T>
struct Nodo{
    T datos;
    Nodo<T> *siguiente;
};

template<typename T>
class LIstaENlazada{
    private:
    Nodo<T>* nodo;
};


int main(){

}