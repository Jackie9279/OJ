#include <bits/stdc++.h>

using namespace std;

class Television {
private:
    int volume, mode, channelnumber{}, num{};
    static int TVnums;
    static int DVDnums;
public:
    void print() {
        if (mode == 1)
            cout << "TV No." << num << "-TV mode-Channel" << " " << channelnumber << "-Volume" << " " << volume << endl;
        if (mode == 2)
            cout << "TV No." << num << "-DVD mode-Channel" << " " << channelnumber << "-Volume" << " " << volume
                 << endl;
    }

    Television();

    void setnum(int n);

    void setmode(int n);

    static int getelevisionVnums();

    static int getDvDnums();

    static void DVDtoTV();

    static void TVtoDVD();

    friend Television controler(Television &television, int mode, int change, int channelnumber);

    static int getTVnums();

};

int Television::DVDnums = 0;
int Television::TVnums = 0;

Television::Television() {
    volume = 50;
    mode = 1;
    TVnums++;
}

int Television::getelevisionVnums() {
    return TVnums;
}

int Television::getDvDnums() {
    return DVDnums;
}

void Television::setnum(int n) {
    num = n;
    channelnumber = n;
}

void Television::setmode(int n) {
    mode = n;
}

void Television::DVDtoTV() {
    DVDnums--;
    TVnums++;
}

void Television::TVtoDVD() {
    TVnums--;
    DVDnums++;
}

Television controler(Television &television, int mode, int change, int channelnumber) {
    int k = television.mode;
    if (mode == 1) {
        television.channelnumber = channelnumber;
        television.setmode(mode);
    }
    if (mode == 2) {
        television.channelnumber = 99;
        television.setmode(mode);
    }

    television.volume += change;
    television.volume = (television.volume > 100) ? 100 : television.volume;
    television.volume = (television.volume < 0) ? 0 : television.volume;

    if (k == 1 && mode == 2) {
        television.TVtoDVD();
    }
    if (k == 2 && mode == 1) {
        television.DVDtoTV();
    }

    television.print();
}

int Television::getTVnums() {
    return TVnums;
}

int main() {
    int t;
    cin >> t;
    Television *television = new Television[t];
    for (int i = 0; i < t; ++i) {
        television[i].setnum(i);
    }
    int n;
    cin >> n;
    for (int j = 0; j < n; ++j) {
        int tele, mode, change, channelnumber;
        cin >> tele >> mode >> channelnumber >> change;
        controler(television[tele], mode, change, channelnumber);
    }

    cout << "Number of TVs playing TV is" << " " << Television::getTVnums() << endl;
    cout << "Number of TVs playing DVD is" << " " << Television::getDvDnums() << endl;

}







