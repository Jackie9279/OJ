#include <iostream>
#include <cstring>
 
using namespace std;
 
 
template<class T>
class list {
private:
    T val[100];
    int len;
public:
    list(T val[], int len) {
        list::len = len;
        for (int i = 0; i < len; ++i) {
            list::val[i] = val[i];
        }
    }
 
    list() {}
 
    void insert(int pos, T ival);
 
    void del(int pos);
 
    void print();
};
 
template<class T>
void list<T>::print() {
    for (int i = 0; i < len; ++i) {
        cout << val[i] << " ";
    }
    cout << endl;
}
 
template<class T>
void list<T>::insert(int pos, T ival) {
    for (int i = len; i > pos; --i) {
        val[i ] = val[i -1];
    }
    val[pos] = ival;
    len++;
}
 
template<class T>
void list<T>::del(int pos) {
    for (int i = pos; i < len; ++i) {
        val[i] = val[i + 1];
    }
    len--;
}
 
 
int main() {
    int t;
    int insertnum;
    int insertpos;
    int delpos;
    float insertnum2;
    cin >> t;
    int a[t];
    for (int i = 0; i < t; ++i) {
        cin >> a[i];
    }
 
    list<int> l(a, (sizeof(a) / sizeof(int)));
    cin >> insertpos >> insertnum;
    cin >> delpos;
    l.insert(insertpos, insertnum);
    l.del(delpos);
    l.print();
 
    cin >> t;
    float aa[t];
    for (int i = 0; i < t; ++i) {
        cin >> aa[i];
    }
    list<float> ll(aa, (sizeof(a) / sizeof(float)));
    cin >> insertpos >> insertnum2;
    cin >> delpos;
    ll.insert(insertpos, insertnum2);
    ll.del(delpos);
    ll.print();
 
}