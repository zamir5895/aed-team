#include <iostream>
#include <cstddef>

template<typename T>
struct Nodo {
    T dato;
    Nodo<T>* siguiente;
};

template<typename T>
class ListaEnlazada {
private:
    Nodo<T>* head;
public:
    ListaEnlazada() {
        head = nullptr;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    T front() {
        if (isEmpty()) {
            throw std::runtime_error("Lista vacia");
        }
        return head->dato;
    }

    T back() {
        if (isEmpty()) {
            throw std::runtime_error("Lista vacia");
        }
        Nodo<T>* aux = head;
        while (aux->siguiente != nullptr) {
            aux = aux->siguiente;
        }
        return aux->dato;
    }
    void push_front(T dato) {
        if(isEmpty()) {
            head = new Nodo<T>{dato, nullptr};
            return;
        }
        Nodo<T>* nuevo = new Nodo<T>();
        nuevo->dato = dato;
        nuevo->siguiente = head;
        head = nuevo;
    }
    void push_back(T dato){
        if(isEmpty()) {
            head = new Nodo<T>{dato, nullptr};
            return;
        }//Creamoas el nuevo nodo aqui
        Nodo<T>* nodonuevo = new Nodo<T>{dato, nullptr};
        //Creamos un nodo temporal para recorrer la lista
        Nodo<T>* aux = head;
        while(aux->siguiente != nullptr) { //Recorremos la lista hasta llegar al ultimo nodo
            aux = aux->siguiente;
        }
        aux->siguiente = nodonuevo;
    }
    void push_any(T valor, int posicion){
        if(posicion<1){
            throw std::runtime_error("Posicion no valida, debe de ser mayor a 1");
        }
        if (posicion == 1){
            push_front(valor);
            return;
        }
        Nodo<T>* nodonuevo = new Nodo<T>();
        nodonuevo->dato = valor;
        Nodo<T>* aux = head;
        for(int i = 1; i < posicion -1 &&aux != nullptr;++i){
            aux = aux->siguiente;
        }
        if(aux == nullptr){
            delete nodonuevo;
            throw std::runtime_error("Posicion no valida");
        }
        nodonuevo->siguiente = aux->siguiente;
        aux->siguiente = nodonuevo;
    }
    T pop_front(){
        if(isEmpty()){
            throw std::runtime_error("Lista vacia");
        }
        Nodo<T>* aux = head;
        T valor = aux->dato;
        head = head->siguiente; 
        delete aux;
        return valor;
    }
    T pop_back(){
        if(isEmpty()){
            throw std::runtime_error("Lista vacia");
        }
        if(head->siguiente == nullptr){
            T valor = head->dato;
            delete head;
            head = nullptr;
            return valor;
        }
        Nodo<T>* aux = head;
        while(aux->siguiente->siguiente != nullptr){
            aux = aux->siguiente;
        }
        T valor = aux->siguiente->dato;
        delete aux->siguiente;
        aux->siguiente = nullptr;

    }
    T pop_any(int posicion){
        if(posicion < 1){
            throw std::runtime_error("Posicion no valida, debe ser mayor a 1");
        }
        if(posicion ==1){
            return pop_front();
        }
        Nodo<T>* aux = head;
        for(int i = 1; i <posicion-1 && aux != nullptr; ++i){
            aux = aux->siguiente;
        }
        if(aux == nullptr || aux->siguiente == nullptr){
            throw std::runtime_error("Posicion no valida");
            
        }
        Nodo<T>* nodoaeliminar = aux->siguiente;
        T valor = nodoaeliminar->dato;
        aux->siguiente = aux->siguiente->siguiente;
        delete nodoaeliminar;
        return valor;
    }

    T operator[](int posicion){
        if(posicion < 1){
            throw std::runtime_error("Posicion no valida, debe ser mayor a 1");
        }
        Nodo<T>* aux = head;
        for(int i = 1; i < posicion && aux != nullptr; ++i){
            aux = aux->siguiente;
        }
        if(aux == nullptr){
            throw std::runtime_error("Posicion no valida");
            
        }
        return aux->dato;
    }
    int size(){
        Nodo<T>* aux = head;
        int contador = 0; 
        while(aux != nullptr){
            aux = aux->siguiente;
            contador++;
        }
        return contador;
    }
    void clear(){
        while(!isEmpty()){
            pop_front();
        }
    }
    void reverse(){
        Nodo<T>* actual = head;
        Nodo<T>* anterior = nullptr;
        Nodo<T>* siguiente;
        while(actual != nullptr){
            siguiente = actual->siguiente;
            actual->siguiente = anterior;
            anterior = actual;
            actual = siguiente;
        }
        head = anterior;
    }
    void printlista(){
        if(isEmpty()){
            std::cout<<"LIsta vacia"<<'\n';
            return;
        }
        Nodo<T>* aux = head;
        while(aux != nullptr){
            std::cout<<aux->dato<<" ";
            aux = aux->siguiente;
        }
        std::cout<<'\n';
    }

};

int main() {
    ListaEnlazada<int> lista;
    if(lista.isEmpty()){
        std::cout<<"lista vacia"<<'\n';
    }
    lista.push_front(3);
    lista.push_back(4);
    lista.push_back(6);
    lista.push_back(7);
    lista.push_any(8,3);
    lista.printlista();
    lista.reverse();
    lista.printlista();
}