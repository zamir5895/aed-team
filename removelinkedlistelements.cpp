
 
 #include <iostream>
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* nodo1 = head;
        ListNode* anterior = nodo1;
        ListNode* actual = head;
        //Verificamos si es vacio
        if(actual == nullptr){
            return nullptr;
        }
        //Recorremos toda la lista
        while(actual != nullptr){
            //Si el valor es diferente al que queremos eliminar
            if(actual->val != val){
                //Solo cambiamos y avanzamos al siguiente
                //El nodo anterior apunta al actual
                anterior->next = actual;
                //El nodo anterior se convierte en el actual
                anterior = actual;
            }else{
                //Si el valor es igual al que queremos eliminar
                //es decir el actual nodo, lo eliminamos
                anterior->next = actual->next;
                delete actual;
            }
            //AVanzamos al siguiente nodo
            actual = actual->next;
        }
        //Creamos un nodo temporal para eliminar el nodo1
        //ELiminamos el nodo1 siguiente porque es un nodo auxiliar
        return nodo1->next;
    }
};