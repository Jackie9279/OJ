#include <iostream>
using namespace std;

template <class T>
class BoundArray {
    T *arr;
    int len;
public:
    BoundArray(int len) {
        this->len = len;
        arr = new T[len];
        for (int i = 0; i < len; i++) {
            cin >> arr[i];
        }
    }
    void sort() {
        for (int i = 0; i < len-1; i++) {
            for (int j = 0; j < len - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    T temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        for (int i = 0; i < len; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int search(T ele) {
        int index = -1;
        for (int i = 0; i < len; i++) {
            if (arr[i] == ele) {
                index = i;
                break;
            }
        }
        return index;
    }
    ~BoundArray() {
        if (arr != NULL) {
            delete[] arr;
            arr = NULL;
        }
    }
};

template<typename T>
void sortAndSearch(BoundArray<T> &ba) {
    T ele;
    ba.sort();
    cin >> ele;
    cout << ba.search(ele) << endl;
}

int main() {
    int t, len;
    char type;
    cin >> t;
    while (t--) {
        cin >> type >> len;
        switch (type) {
            case 'I': {
                BoundArray<int> ba(len);
                sortAndSearch(ba);
                break;
            }
            case 'D': {
                BoundArray<double> ba(len);
                sortAndSearch(ba);
                break;
            }
            case 'C': {
                BoundArray<char> ba(len);
                sortAndSearch(ba);
                break;
            }
        }
    }
    return 0;
}
