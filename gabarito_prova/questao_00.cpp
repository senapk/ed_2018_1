#include <iostream>
#include <list>
using namespace std;

bool matar(list<int>& l){
    for(auto i = l.begin(); i != std::prev(l.end()); i++){
        for(auto j = std::next(i); j != l.end(); j++){
            if(*i == *j){
                l.push_back(2 * (*i));
                l.erase(i);
                l.erase(j);
                return true;
            }
        }
    }
    return false;
}

int main()
{
    list<i> l {2, 2, 4 , 3, 1, 4, 8};
    while(matar(l)){
        for(auto e : *l)
            cout << e << " ";
        cout << endl;
    }
    return 0;
}