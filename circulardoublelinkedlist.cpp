#include <iostream>
template <typename T = int>
struct Nodo{
    T dato;
    Nodo<T> *siguiente;
    Nodo<T> *anterior;
    Nodo(T dato): dato(dato), siguiente(nullptr), anterior(nullptr){}
};
template <typename T = int>
class ListaCircularDoble{
private:
    Nodo<T>* cabeza;
    Nodo<T>* cola;
public:
    ListaCircularDoble(): cabeza(nullptr), cola(nullptr){};

    bool isEmpty(){
        return cabeza == nullptr;
    }    
    T front(){
        if(isEmpty()){
            throw std::runtime_error("Lista vacia");
        }   
        return cabeza->dato;
    }
    T back(){
        if(isEmpty()){
            throw std::runtime_error("Lista vacia");
        }   
        return cola->dato;
    }
    T operator[](int pos){
        if(isEmpty()){
            throw std::runtime_error("Lista vacia");
        }   
        Nodo<T> *aux = cabeza;
        for(int i = 0; i < pos; i++){
            aux = aux->siguiente;
            if(aux == cabeza){
                throw std::runtime_error("Posicion no valida");
            }
        }
        return aux->dato;
    }
    void push_front(T valor){
        if(isEmpty()){
            cabeza = new Nodo<T>(valor);
            cabeza->siguiente = cabeza;
            cabeza->anterior = cabeza;
            cola = cabeza;
        }else{
            Nodo<T> *nuevo = new Nodo<T>(valor);
            nuevo->siguiente = cabeza;
            nuevo->anterior = cola;
            cabeza->anterior = nuevo;
            cola->siguiente = nuevo;
            cabeza = nuevo;
        }
    }
    void push_back(T valor){
        if(isEmpty()){
            cabeza = new Nodo<T>(valor);
            cabeza->siguiente = cabeza;
            cabeza->anterior = cabeza;
            cola = cabeza;
        }else{
            Nodo<T> *nuevo = new Nodo<T>(valor);
            nuevo->siguiente = cabeza;
            nuevo->anterior = cola;
            cabeza->anterior = nuevo;
            cola->siguiente = nuevo;
            cola = nuevo;
        }
    }
    void push_any(T valor, int pos){
        if(isEmpty()){
            cabeza = new Nodo<T>(valor);
            cabeza->siguiente = cabeza;
            cabeza->anterior = cabeza;
            cola = cabeza;
        }else{
            Nodo<T> *nuevo = new Nodo<T>(valor);
            Nodo<T> *aux = cabeza;
            for(int i = 0; i < pos; i++){
                aux = aux->siguiente;
                if(aux == cabeza){
                    throw std::runtime_error("Posicion no valida");
                }
            }
            nuevo->siguiente = aux;
            nuevo->anterior = aux->anterior;
            aux->anterior->siguiente = nuevo;
            aux->anterior = nuevo;
        }
    }
    void pop_front(){
        if(isEmpty()){
            throw std::runtime_error("Lista vacia");
        }
        if(cabeza == cola){
            delete cabeza;
            cabeza = nullptr;
            cola = nullptr;
        }else{
            Nodo<T> *aux = cabeza;
            cabeza = cabeza->siguiente;
            cabeza->anterior = cola;
            cola->siguiente = cabeza;
            delete aux;
        }
    }
    void pop_back(){
        if(isEmpty()){
            throw std::runtime_error("Lista vacia");
        }
        if(cabeza == cola){
            delete cabeza;
            cabeza = nullptr;
            cola = nullptr;
        }else{
            Nodo<T> *aux = cola;
            cola = cola->anterior;
            cola->siguiente = cabeza;
            cabeza->anterior = cola;
            delete aux;
        }
    }
    void pop_any(int pos){
        if (isEmpty()){
            throw std::runtime_error("Lista vacia");
        }else{
            Nodo<T> *aux = cabeza;
            for(int i = 0; i < pos; i++){
                aux = aux->siguiente;
                if(aux == cabeza){
                    throw std::runtime_error("Posicion no valida");
                }
            }
            aux->anterior->siguiente = aux->siguiente;
            aux->siguiente->anterior = aux->anterior;
            delete aux;
        }
    }
    int size(){
        if(isEmpty()){
            return 0;
        }
        Nodo<T> *aux = cabeza;
        int cont = 0;
        do{
            cont++;
            aux = aux->siguiente;
        }while(aux != cabeza);
        return cont;
    }
    void reverse(){
        if(isEmpty){
            throw std::runtime_error("Lista vacia");    
        }
        Nodo<T> *aux = cabeza;
        do{
            Nodo<T> *temp = aux->siguiente;
            aux->siguiente = aux->anterior;
            aux->anterior = temp;
            aux = aux->anterior;
        }while(aux != cabeza);
        Nodo<T> *temp = cabeza;
        cabeza = cola;
        cola = temp;
    }
    void print(){
        if(isEmpty()){
            return;
        }
        Nodo<T> *aux = cabeza;
        do{
            std::cout << aux->dato << " ";
            aux = aux->siguiente;
        }while(aux != cabeza);
        std::cout << '\n';
    }
};


int main(){
    ListaCircularDoble<int> lista;
    lista.push_back(1);
    lista.push_back(2);
    lista.push_front(0);
    lista.push_any(3, 3);
    lista.push_any(4, 4);
    lista.push_any(5, 5);
    lista.push_any(2, 6);
    lista.print();
    lista.pop_any(6);
    lista.print();
    lista.pop_front();
    lista.print();
    lista.pop_back();
    std::cout << lista.size() << '\n';
    lista.print();
    lista.reverse();
    lista.print();
    return 0;
}