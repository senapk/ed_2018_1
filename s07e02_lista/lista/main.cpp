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

    ~SList(){
        deletarTudo(head);
    }

    void deletarTudo(Node * node){

    }

    5 4 7 8 9 3 1
    cortarRabo(8)
    5 4 7
    //procura o valor, remove desse no em diante
    Node * cortarRabo(Node * node, int value){

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
        auto node = head;
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
        cout << node->value << " ";
        _rshow(node->next);
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
        return nullptr;
        //todo
    }

    void rinserir_ordenado(int value){
        //todo
    }

    //todo
    int size(){
        return 0;
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

int main(){
    SList lista;
    lista.push_back(5);
    lista.push_back(6);
    lista.push_back(7);
    lista.push_back(10);
    return 0;
}


//int main()
//{
//    SList lista;
//    lista._rshow(lista.head);
//    return 0;
//}

////int mainc(){
////    char produto[] = "nescau 200 ml 10.00 5 laticineos";
////    char str[50];
////    float valor = 4.50;
////    int qtd = 10;
////    char setor[] = "hortifruti";
////    sprintf(str, "uva %f %d %s", valor, qtd, setor);
////    char nome[50];
////    sscanf(produto, "%s %f %d %s", nome, &valor, &qtd, setor);
////    return 0;
////}

////#include <fstream>

////int maincpp(){
////    int x;
////    ofstream asaida("../lista/saida.txt");
////    ifstream ainput("../lista/entrada.txt");
////    string linha;
////    getline(ainput, linha, ';');
////    asaida << "digite um inteiro" << endl;
////    ainput >> x;
////    asaida << "digite um nome bonito" << endl;
////    string s;
////    ainput >> s;
////    asaida << "x = " << x << ", s = " << s << endl;

////    return 0;
////}

////#include <sstream>
////int main(){
////    stringstream ss;
////    ss << "hoje " << 24 << "abril de 2014, temp=" << 27.73 << endl;
////    cout << ss.str();

////    string str("44 38");
////    stringstream ss2(str);
////    int lixo;
////    int i;
////    ss2 >> lixo >> i;
////    return 0;
////}



