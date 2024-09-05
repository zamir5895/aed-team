
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
int gcd (int a, int b ){
    if(b>a){
        return gcd(b,a);
    }
    if(a*b==0){
        return 0;
    }
    return a%b==0?b:gcd(b,a%b);
}

Nodo* solucion2(Nodo* head) {
        Nodo* aux = head;
        while(aux != nullptr && aux->next != nullptr){
            Nodo* temp = aux->next;
            int valor = gcd(aux->val, temp->val);
            Nodo* nuevo = new Nodo(valor);
            nuevo->next = temp;
            aux->next = nuevo;
            aux = temp;     
        }
    return head;
}
int main(){
    return 0;

}