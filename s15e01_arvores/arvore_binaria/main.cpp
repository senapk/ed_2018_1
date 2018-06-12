#include <iostream>

using namespace std;

struct Node {
    int value;
    Node * left;
    Node * right;
    Node(){
    }
    Node(int value, Node * left, Node * right):
        value(value), left(left), right(right){
    }
};

struct Tree {
    Node * root;
    Lista(){
        root = nullptr;
    }

    Tree(Tree other){
        root = clone(other.root)
    }

    Node * clone(Node * node){
        if(node == nullptr)
            return nullptr;
        return new Node(node->value, clone(node->left),
                                     clone(node->right));
    }

    bool equals(Lista other){
        return equals(this->head, other.head);
    }

    bool equals(Node * node, Node * other){
        if((node == nullptr) && (other == nullptr))
            return true;
        if((node == nullptr) || (other == nullptr))
            return false;
        if(node->value != other->value)
            return false;
        return equals(node->left, other->left) &&
               equals(node->right,other->right);
    }


    ~Tree(){
        Node * node = head;
        while(node != nullptr){
            auto aux = node->left;
            auto aux = node->r;
            delete node;
            node = aux;
        }
    }

    void erase(Node * node){
        if(node == nullptr)
            return;
        erase(node->right);
        erase(node->left);
        delete node;
    }

    Node * find(Node * node, int key){
        if(node == nullptr)
            return nullptr;
        if(node->key == key)
            return node;
        auto resp = find(node->left, key);
        if(resp != nullptr)
            return resp;
        return find(node->right, key);
    }



};


int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
