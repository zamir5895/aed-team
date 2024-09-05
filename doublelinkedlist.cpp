#include <iostream>
template<typename T = int>
struct Nodo{
    T dato;
    Nodo<T>* siguiente;
    Nodo<T>* anterior;
};
    
template<typename T = int>
class ListaEnlazada{
private:
    Nodo<T>* head;
    Nodo<T>* cola;
public:
    ListaEnlazada(){
        head = nullptr;
        cola = nullptr;
    }
    bool empty(){
        return head == nullptr;
    }
    T front(){
        if(head == nullptr){
            throw std::runtime_error("Lista vacia");
        }
        return head->dato;
    }
    T back(){
        if(head == nullptr){
            throw std::runtime_error("Lista vacia");
        }
        return cola->dato;
    }

    void push_back(T valor){
        Nodo<T>* nuevonodo = new Nodo<T>{valor, nullptr, nullptr};
        if(head == nullptr){
            head = nuevonodo;
            cola = nuevonodo;
            return;
        }
        cola->siguiente = nuevonodo;
        nuevonodo->anterior = cola;
        cola = nuevonodo;
    }
    void push_front(T valor){
        Nodo<T>* nuevonodo = new Nodo<T>{valor, nullptr, nullptr};
        if(head == nullptr){
            head = nuevonodo;
            cola = nuevonodo;
            return;
        }
        head->anterior = nuevonodo;
        nuevonodo->siguiente = head;
        head = nuevonodo;
    }
    void push_any(T valor, int pos){
        Nodo<T>* nuevonodo = new Nodo<T>{valor, nullptr, nullptr};
        if(head == nullptr || head->siguiente == nullptr){
            return push_front(valor);
        }
        Nodo<T>* aux = head;
        if(pos == 0){
            return push_front(valor);
        }
        for(int i = 0; i < pos; i++){
            aux = aux->siguiente;
        }
        if(aux == nullptr){
            delete nuevonodo;
            throw std::runtime_error("Posicion no valida");
        }
        
        aux->anterior->siguiente = nuevonodo;
        nuevonodo->anterior = aux->anterior;
        aux->anterior = nuevonodo;
        nuevonodo->siguiente = aux;
    }
    T pop_front(){
        if(head == nullptr){
            throw std::runtime_error("Lista vacia");
        }
        Nodo<T>* aux = head;
        T valor = aux->dato;
        head = head->siguiente;
        delete head->anterior;

        if(head != nullptr){
            head->anterior = nullptr;
        }else{
            cola = nullptr;
        }
        delete aux;
        return valor;
    }
    T pop_back(){
        if(head == nullptr){
            throw std::runtime_error("Lista vacia");
        }
        if(head->siguiente == nullptr){
            T valor = head->dato;
            delete head;
            head = nullptr;
            return valor;
        }
        Nodo<T>* aux = cola;
        T valor = aux->dato;
        cola = cola->anterior;
        delete cola->siguiente;
        cola->siguiente = nullptr;
        delete aux;
        return valor;
    }
    T pop_any(int pos){
        if(head == nullptr){
            throw std::runtime_error("Lista vacia");
        }
        if(pos == 0){
            return pop_front();
        }
        Nodo<T>* aux = head;
        for(int i = 0; i < pos && aux!= nullptr; ++i){
            aux = aux->siguiente;
        }
        if(aux == nullptr){
            throw std::runtime_error("Posicion no valida");
        }
        T valor = aux->dato;
        aux->anterior->siguiente = aux->siguiente;
        aux->siguiente->anterior = aux->anterior;

        delete aux;
        return valor;
    }
    bool isEmpty(){
        return head == nullptr;
    }
    int size(){
        Nodo<T>* aux = head;
        int cont = 0;
        while(aux != nullptr){
            aux = aux->siguiente;
            cont++;
        }
        //for(Nodo<T>* aux = head; aux != nullptr; aux = aux->siguiente;cont++;)
        return cont;
    }
    T operator[](int pos){
        if(head == nullptr){
            throw std::runtime_error("Lista vacia");
        }
        Nodo<T>* aux = head;
        for(int i = 0; i < pos && aux != nullptr; ++i){
            aux = aux->siguiente;
        }
        if(aux == nullptr){
            throw std::runtime_error("Posicion no valida");
        }
        return aux->dato;
    }
    void imprimiradelante(){
        Nodo<T>* aux = head;
        while(aux != nullptr){
            std::cout << aux->dato << " ";
            aux = aux->siguiente;
        }
        std::cout << '\n';
    }
    void imprimiratras(){
        Nodo<T>* aux = cola;
        while(aux != nullptr){
            std::cout << aux->dato << " ";
            aux = aux->anterior;
        }
        std::cout << '\n';
    }
    void clear(){
        while(!isEmpty()){
            pop_front();
        }
    }
    void pop_value(T valor){
        Nodo<T>* aux = head;
        while(aux != nullptr){
            if(aux->dato == valor){
                if(aux->anterior != nullptr){
                    aux->anterior->siguiente = aux->siguiente;
                }else{
                    head = aux->siguiente;
                }
                if(aux->siguiente != nullptr){
                    aux->siguiente->anterior = aux->anterior;
                }else{
                    cola = aux->anterior;
                }
                delete aux;
                return;
            }
            aux = aux->siguiente;
        }
    }
    void reverse(){
        Nodo<T>* aux = head;
        Nodo<T>* temp = aux->siguiente;
        aux->siguiente = nullptr;
        aux->anterior = temp;
        while(temp != nullptr){
            temp->anterior = temp->siguiente;
            temp->siguiente = aux;
            aux = temp;
            temp = temp->anterior;
        }
        head = aux;
    }
};



int main(){
    ListaEnlazada<int> lista;
    lista.push_back(1);
    lista.push_back(2);
    lista.push_back(3);
    lista.push_back(4);
    lista.push_front(0);
    lista.push_any(5, 2);
    lista.imprimiradelante();
    lista.imprimiratras();
    lista.pop_any(2);
    lista.imprimiradelante();
    lista.imprimiratras();
    lista.pop_value(3);
    lista.imprimiradelante();
    lista.imprimiratras();
    std::cout << lista[2] << '\n';
    std::cout << lista.size() << '\n';
    std::cout << "reverse" << '\n';
    lista.reverse();
    lista.imprimiradelante();
    lista.clear();

    return 0;
}