//Reto 3 - Pila basada en lista
//Por Rubén Mogica Garrido y Arturo Cortés Sánchez

#include <list>
#include <iostream>
using namespace std;
template <class T>
class pila{
    private:
        list<T> p;
    public:
        bool empty(){
            return p.empty();
        }
        int size(){
            return p.size();
        }
        T top(){
            return p.front();
        }
        void push(T a){
            p.push_front(a);
        }
        void emplace(T a){
            p.emplace_front(a);
        }
        void pop(){
            p.pop_front();
        }
        void swap(pila a){
            p.swap(a.p);
        }
        void swap(pila a, pila b){
            a.p.swap(b.p);
        }
        bool operator==(const pila & pi){
            return p==pi.p;     
        }
        bool operator!=(const pila & pi){
            return p!=pi.p;     
        }
        bool operator<=(const pila & pi){
            return p<=pi.p;     
        }
        bool operator>=(const pila & pi){
            return p>=pi.p;     
        }        
        bool operator<(const pila & pi){
            return p<pi.p;     
        }    
        bool operator>(const pila & pi){
            return p>pi.p;     
        }
        friend ostream& operator<< (ostream & os, const pila & pi){
            os << '[';
            for(auto i: pi.p){
                os << i;
                i != pi.p.back() ? os << ", " :  os << ']';
            }
            if (pi.p.empty()) os << ']';
            return os;
        }
};

int main(){
    pila<int> pila1, pila2;
    pila<char> pila_char;
    cout << "pila1.empty() "<< pila1.empty() << endl;
    cout << "pila2.empty() "<< pila2.empty() << endl;
    cout << "pila_char.empty() "<< pila_char.empty() << endl;
    cout << "pila1.size() "<< pila1.size() << ", pila1: " << pila1 << endl;
    cout << "pila2.size() "<< pila2.size() << ", pila2: " << pila2 << endl;
    cout << "pila_char.size() "<< pila_char.size() << ", pila_char: " << pila_char << endl;

    cout <<endl << "llenando pilas"<< endl << endl ;
    
    for (auto i : "abcdef"){
        if(i!='\0') pila_char.push(i);
    }
    for(int i=0; i< 10;i+=2){
        pila1.push(i);
    }
    for (int i=0; i< 10;i++){
        pila2.push(i);
    }
    cout << "pila1.empty() "<< pila1.empty() << endl;
    cout << "pila2.empty() "<< pila2.empty() << endl;
    cout << "pila_char.empty() "<< pila_char.empty() << endl;
    cout << "pila1.size() "<< pila1.size() << ", pila1: " << pila1 << endl;
    cout << "pila2.size() "<< pila2.size() << ", pila2: " << pila2 << endl;
    cout << "pila_char.size() "<< pila_char.size() << ", pila_char: " << pila_char << endl;    
    pila1.pop();
    pila2.pop();
    pila_char.pop();
    cout << "pila1.pop()"  << ", pila1: " << pila1 << endl;
    cout << "pila2.pop()"  << ", pila2: " << pila2 << endl;
    cout << "pila_char.pop()"  << ", pila_char: " << pila_char << endl;
    pila1.swap(pila2);
    cout << "pila1.swap(pila2) "  << ", pila1: " << pila1 << endl;
    cout << "pila1 == pila2 " << bool(pila1==pila2) << endl;
    cout << "pila1 != pila2 " << bool(pila1!=pila2) << endl;
    cout << "pila1 <= pila2 " << bool(pila1<=pila2) << endl;
    cout << "pila1 >= pila2 " << bool(pila1>=pila2) << endl;
    cout << "pila1 < pila2 " << bool(pila1<pila2) << endl;
    cout << "pila1 > pila2 " << bool(pila1>pila2) << endl;
}