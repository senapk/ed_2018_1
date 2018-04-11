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

    void push_back(int value){
        if(head == nullptr){
            head = new Node(value);
            return;
        }
        auto node = new Node();
        while(node->next != nullptr)
            node = node->next;
        node->next = new Node(value);
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

    void show(){
        auto node = head;
        while(node != nullptr){
            cout << node->value << " ";
            node = node->next;
        }
        cout << endl;
    }

    void _rshow(Node * node){
        if(node == nullptr)
            return;
        _rshow(node->next);
        cout << node->value << " ";
    }

    void rshow(){
        _rshow(head);
        cout << endl;
    }

    Node * _rpop_back(Node * node){
        if(node->next == nullptr){
            delete node;
            return nullptr;
        }
        node->next = _rpop_back(node->next);
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

    void remove(int value){
        head = _remove(head, value);
    }
};


int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
