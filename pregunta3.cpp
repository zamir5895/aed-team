
//Zamir LIzardo
//Mateo Ramirez
//JOel Miguel

struct Nodo{
    int val;
    Nodo *next;
    Nodo() : val(0), next(nullptr) {};
    Nodo(int x) : val(x), next(nullptr) {};
    Nodo(int x, Nodo *siguiente) : val(x), next(siguiente) {};

};
Nodo* solucion3(Nodo* head) {
        Nodo* aux = head;
        Nodo* prev = nullptr;
        while(aux != nullptr && aux->next != nullptr){
            Nodo* temp = aux->next;
            if(prev == nullptr){
                head = temp;
            }else{
                prev->next = temp;
            }
            aux->next = temp->next;
            temp->next = aux;
            prev = aux;
            aux = aux->next;
        }
        return head;
}
int main(){
    return 0;

}