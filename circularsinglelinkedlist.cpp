#include <iostream>
template<typename T = int> 
struct Nodo{
    T dato;
    Nodo<T>* siguiente;
};
template<typename T = int>
class ListaEnlazadaCircular{
private:
    Nodo<T>* head;
public:
    ListaEnlazadaCircular(){
        head = nullptr;
    }

    T front(){
        if(isEmpty()){
            throw std::runtime_error("Lista vacia");
        }
        return head->dato;
    }
    T back(){
        if(isEmpty()){
            throw std::runtime_error("Lista vacia");
        }
        Nodo<T>* aux = head;
        while(aux->siguiente != head){
            aux = aux->siguiente;
        }
        return aux->dato;
    }

    T get_any(int pos){
        if(isEmpty()){
            throw std::runtime_error("Lista vacia");
        }
        Nodo<T>* aux = head;
        for(int i = 0; i < pos; i++){
            aux = aux->siguiente;
            if(aux == head){
                throw std::runtime_error("Posicion no valida");
            }
        }
        return aux->dato;
    }

    bool isEmpty() const{
        return head == nullptr;
    }

    void push_front(T valor){
        if(isEmpty()){
            head = new Nodo<T>{valor, nullptr};
            head->siguiente = head;
        }else{
            Nodo<T>* nuevo = new Nodo<T>{valor, nullptr};
            Nodo<T>* aux = head;
            while(aux->siguiente != head){
                aux = aux->siguiente;
            }
            aux->siguiente = nuevo;
            nuevo->siguiente = head;
            head = nuevo;
        }
    }
    void push_back(T valor){
        if(isEmpty()){
            head = new Nodo<T>{valor, nullptr};
            head->siguiente = head; 
        }else{
            Nodo<T>* nuevo = new Nodo<T>{valor, nullptr};
            Nodo<T>* aux = head;
            while (aux->siguiente != head){
                aux = aux->siguiente;
            }
            aux->siguiente = nuevo;
            nuevo->siguiente = head;
        }
    }
    void push_any(T valor, int pos){
        if(isEmpty()){
            throw std::runtime_error("Lista vacia");
        }
        Nodo<T>* nuevo = new Nodo<T>{valor, nullptr};
        Nodo<T>* aux = head;
        for(int i = 0; i < pos - 1; i++){
            aux = aux->siguiente;
            if(aux == head){
                throw std::runtime_error("Posicion no valida");
            }
        }
        nuevo->siguiente = aux->siguiente;
        aux->siguiente = nuevo;
    }

    void pop_front(){
        if(isEmpty()){
            std::runtime_error("Lista vacia");
        }
        Nodo<T>* aux = head;
        while(aux->siguiente != head){
            aux = aux->siguiente;
        }
        if(aux == head){
            delete head;
            head = nullptr;
            return;
        }
        Nodo<T>* temp = head;
        head = head->siguiente;
        aux->siguiente = head;
        delete temp;
    }
    void pop_back(){
        if(isEmpty()){
            std::runtime_error("Lista vacia");
        }
        Nodo<T>* aux = head;
        while(aux->siguiente->siguiente != head){
            aux = aux->siguiente;
        }
        Nodo<T>* temp = aux->siguiente;
        aux->siguiente = head;
        delete temp;
    }
    void pop_any(int pos){
        if(isEmpty()){
            std::runtime_error("Lista vacia");
        }
        Nodo<T>* aux = head;
        for(int i = 0; i < pos - 1 && aux->siguiente != head; i++){
            aux = aux->siguiente;
        }
        if(aux->siguiente == head){
            std::runtime_error("Posicion no valida");
        }
        Nodo<T>* temp = aux->siguiente;
        aux->siguiente = aux->siguiente->siguiente;
        delete temp;
    }
    void clear(){
        if(isEmpty()){
            return;
        }
        Nodo<T>* aux = head;
        while(aux->siguiente != head){
            Nodo<T>* temp = aux;
            aux = aux->siguiente;
            delete temp;
        }
        delete aux;
        head = nullptr;
    }
    int size(){
        if(isEmpty()){
            return 0;
        }
        Nodo<T>* aux = head;
        int contador = 0;
        do{
            contador++;
            aux = aux->siguiente;
        }while(aux != head);
        return contador;
    }
    void reverse(){
        if(isEmpty()){
            return;
        }
        Nodo<T>* aux = head;
        Nodo<T>* prev = nullptr;
        Nodo<T>* next = nullptr;
        do{
            next = aux->siguiente;
            aux->siguiente = prev;
            prev = aux;
            aux = next;
        }while(aux != head);
        head->siguiente = prev;
        head = prev;
    }
    void print(){
        if(isEmpty()){
            std::cout << "Lista vacia" << std::endl;
            return;
        }
        Nodo<T>* aux = head;
        do{
            std::cout << aux->dato << ' ';
            aux = aux->siguiente;
        }while(aux != head);
        /*
        solo con  while
        Nodo<T>* aux = head;
        std::cout << aux->dato << ' ';
        aux = aux->siguiente;
        while(aux != head){
            std::cout << aux->dato << ' ';
            aux = aux->siguiente;
        }
        */
        std::cout << '\n';
    }

};


int main(){
    ListaEnlazadaCircular<int> lista;
    if(lista.isEmpty()){
        std::cout << "Lista vacia" << std::endl;
    }
    lista.push_front(1);
    lista.push_front(2);
    lista.push_front(3);
    lista.push_front(4);
    lista.push_back(5);
    lista.push_back(6);
    lista.push_any(7, 3);
    lista.print();
    std::cout << "Tamaño: " << lista.size() << '\n';
    std::cout << "Frente: " << lista.front() << '\n';
    std::cout << "Final: " << lista.back() << '\n';
    std::cout << "Posicion 3: " << lista.get_any(3) << '\n';
    lista.pop_front();
    lista.print();
    lista.pop_back();
    lista.print();
    lista.pop_any(2);
    lista.print();
    lista.reverse();
    lista.print();
    return 0;
}