#include <bits/stdc++.h>

using namespace std;

class CFraction {
private:
public:
    int fz, fm;

    CFraction();

    CFraction(int fz_val, int fm_val);

    CFraction add(const CFraction &r);

    CFraction sub(const CFraction &r);

    CFraction mul(const CFraction &r);

    CFraction div(const CFraction &r);

    CFraction huajian(CFraction &r);

    int getGCD(const CFraction &r); //Find the greatest common divisor of the numerator and denominator of the object

    void print();
};

CFraction::CFraction(int fz_val, int fm_val) {
    fz = fz_val;
    fm = fm_val;
}

CFraction::CFraction() {
    fz = 0;
    fm = 0;
}

int CFraction::getGCD(const CFraction &p) {
    int fzz;
    int fmm;
    fzz = abs(p.fz);
    fmm = abs(p.fm);
    if (fzz < fmm) {
        swap(fzz, fmm);
    }
    int r = fzz % fmm;
    while (r != 0) {
        fzz = fmm;
        fmm = r;
        r = fzz % fmm;
    }
    return fmm;
}

CFraction CFraction::huajian(CFraction &r) {
    if (r.fm < 0) {
        r.fz = -r.fz;
        r.fm = -r.fm;
    }
    if (r.fz == 0) {
        r.fm = 1;
    } else {
        int num = getGCD(r);
        r.fz /= num;
        r.fm /= num;
    }
    return r;
}

void CFraction::print() {
    cout << fz << "/" << fm << endl;
}

CFraction CFraction::add(const CFraction &r) {
    CFraction a;
    a.fz = fz * r.fm + fm * r.fz;
    a.fm = fm * r.fm;
    return huajian(a);
}


CFraction CFraction::mul(const CFraction &r) {
    CFraction a;
    a.fz = fz * r.fz;
    a.fm = fm * r.fm;
    return huajian(a);
}

CFraction CFraction::div(const CFraction &r) {
    CFraction a;
    a.fz = fz * r.fm;
    a.fm = fm * r.fz;
    return huajian(a);
}

CFraction CFraction::sub(const CFraction &r) {
    CFraction a;
    a.fz = fz * r.fm - fm * r.fz;
    a.fm = fm * r.fm;
    return huajian(a);
}

int main() {
    int t;
    cin >> t;
    for (size_t i = 0; i < 2 * t; i = i + 2) {
        CFraction a(0, 0);
        CFraction b(0, 0);

        scanf("%d/%d", &a.fz, &a.fm);
        scanf("%d/%d", &b.fz, &b.fm);

        a.add(b).print();
        a.sub(b).print();
        a.mul(b).print();
        a.div(b).print();
        if (i != 2 * t - 2) {
            cout << endl;
        }
    }
    return 0;
}