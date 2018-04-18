#include <iostream>

using namespace std;

struct  Node{
    int value;
    Node* next;

    Node(int value = 0, Node * next = nullptr){
        this->value = value;
        this->next = next;
    }
};

struct SList{

    Node* head;

    SList(){
        this->head = nullptr;
    }

    void push_front(int value){
        //this->head = new Node(value, this->head);
        Node * node = new Node(value);
        node->next = head;
        this->head = node;
    }

    void pop_front(){
        if(head == nullptr)
            return;
        Node * aux = head;
        head = head->next;
        delete aux;
    }

    void push_back(int value){ //todo
        if(head == nullptr){
            head = new Node(value);
            return;
        }
        auto node = new Node();
        while(node->next != nullptr)
            node = node->next;
        node->next = new Node(value);
    }

    Node * _push_back(Node * node, int value){
        //todo
    }

    void pop_back(){
        if(head == nullptr)
            return;
        if(head->next == nullptr){
            delete head;
            head = nullptr;
            return;
        }
        auto node = head;
        while(node->next->next != nullptr)
            node = node->next;
        delete node->next;
        node->next = nullptr;
    }

    Node * _rpop_back(Node * node){
        if(node->next == nullptr){
            delete node;
            return nullptr;
        }
        node->next = _rpop_back(node->next);
    }

    void rpop_back(){
        this->head = _rpop_back(head);
    }

    void ishow(){
        auto node = head;
        while(node != nullptr){
            cout << node->value << " ";
            node = node->next;
        }
        cout << endl;
    }
private:
    void _rshow(Node * node){
        if(node == nullptr)
            return;
        _rshow(node->next);
        cout << node->value << " ";
    }
public:
    void rshow(){
        _rshow(head);
        cout << endl;
    }

    Node * _remove(Node * node, int value){
        if(node == nullptr)
            return nullptr;
        if(node->value == value){
            auto aux = node->next;
            delete node;
            return aux;
        }
        node->next = _remove(node->next, value);
    }

    void rremove(int value){
        head = _remove(head, value);
    }

    void iremove(int value){
        //todo
    }

    /*
    head = 900;
    900:{1 500};
    500:{2 700};
node700:{4 250};
    300:{6 0};
    250:{5 300};
    */

    //5
    //2 >4 X 6
    void inserir_ordenado(int value){
        auto node = head;
        if(head == nullptr || head->value > value){
            this->head = new Node(value, head);
            return;
        }
        while(node->next != nullptr && node->next->value < value){
            node = node->next;
        }
        node->next = new Node(value, node->next);
    }

    Node * _rinserir_ordenado(Node * node, int value){
        //todo
    }

    void rinserir_ordenado(int value){
        //todo
    }

    int rsomar(Node * node){
        //todo
    }

    int rmin(Node * node){
        if(node->next == nullptr)
            return node->value;
        return std::min(node->value, rmin(node->next));
    }

};


int main()
{
    SList lista;
    lista._rshow(lista.head);
    return 0;
}
