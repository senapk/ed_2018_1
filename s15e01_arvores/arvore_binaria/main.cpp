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
        root = clone(other.root);
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

    //ligatures
    int _min(Node * node){
        if((node->left == nullptr) && (node->right == nullptr))
            return node->value;
        int menor;
        if(node->left != nullptr)
            menor = std::min(node->value, _min(node->left));
        if(node->right != nullptr)
            menor = std::min(menor, _min(node->right));
        return menor;
    }

    int _min(Node * node){
        if(node == nullptr)
            return 2147483647;
        return std::min(std::min(node->value, _min(node->left)),
                                 _min(node->right));
    }

    int min(){
        return _min(head);
    }

    int _soma(Node * node){
        if(node == nullptr)
            return 0;
        return node->value + _soma(node->left) + _soma(node->right);
    }

    int soma(){
        return _soma(root);
    }

    void _show(Node * node){
        if(node == nullptr)
            return;
        _show(node->left);
        _show(node->right);
        cout << node->value << " ";
    }

    void show(){
        _show(root);
    }


};


int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
