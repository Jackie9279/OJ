#include <iostream>

using namespace std;

class Ultraman;

class Monster {
protected:
    int monster_rank;
    int monster_exp, monster_hp, monster_damage, monster_money;
public:
    Monster() {}

    Monster(int initial_rank) {
        monster_rank = initial_rank;//初始化怪兽等级
        monster_exp = initial_rank * 10;//初始化怪兽经验值
        monster_hp = initial_rank * 20;//初始化怪兽生命值
        monster_damage = initial_rank * 2;//初始化怪兽战斗力
        monster_money = initial_rank * 10;//初始化怪兽的小钱
    }

    int getMonsterRank() const;

    int getMonsterExp() const;

    int getMonsterHp() const;

    int getMonsterDamage() const;

    int getMonsterMoney() const;

    void setMonsterRank(int monsterRank);

    void setMonsterExp(int monsterExp);

    void setMonsterHp(int monsterHp);

    void setMonsterDamage(int monsterDamage);

    void setMonsterMoney(int monsterMoney);

    virtual void display();

    virtual void lose();

    virtual void fightback(Ultraman &outman);

};

class Boss : public Monster {
private:
    int attackedcount;
public:
    Boss() {
        monster_rank = 10;
        monster_hp = 300;
        monster_exp = 1000;
        monster_damage = 50;
        monster_money = 1001;
        attackedcount = 0;
    }

    void lose() override;

    void fightback(Ultraman &outman) override;

    void display() override;
};

class Ultraman {
protected:
    int ultraman_rank;
    int ultraman_hp;
    int ultraman_damage;
    int ultraman_money;
    int ultraman_exp;
public:
    Ultraman() {}

    Ultraman(int initial_rank) {
        ultraman_rank = initial_rank;//初始化奥特曼等级
        ultraman_exp = 0;//初始化奥特曼经验值
        ultraman_hp = ultraman_rank * 10;//初始化奥特曼生命值
        ultraman_damage = ultraman_rank * 3;//初始化奥特曼攻击能力
        ultraman_money = ultraman_rank * 10;//初始化奥特曼的小钱
    }

    int getUltramanRank() const;

    int getUltramanExp() const;

    int getUltramanHp() const;

    int getUltramanDamage() const;

    int getUltramanMoney() const;

    void setUltramanRank(int ultramanRank);

    void setUltramanHp(int ultramanHp);

    void setUltramanDamage(int ultramanDamage);

    void setUltramanMoney(int ultramanMoney);

    void setUltramanExp(int ultramanExp);

    void escape();

    void attack(Monster &monster);//奥特曼战斗
    void restore();

    void win(Monster &monster);

    void win(Boss &boss);

    void upgrade();

    void display();

    friend ostream &operator<<(ostream &os, const Ultraman &ultraman);

    Ultraman &operator++();

    Ultraman &operator--();

    bool operator<(Monster monster);

    bool operator==(Monster monster);


};


int Monster::getMonsterRank() const {
    return monster_rank;
}

int Monster::getMonsterExp() const {
    return monster_exp;
}

int Monster::getMonsterHp() const {
    return monster_hp;
}

int Monster::getMonsterDamage() const {
    return monster_damage;
}

int Monster::getMonsterMoney() const {
    return monster_money;
}


void Monster::display() {
    cout << "Monster status (" << "rank=" << monster_rank << " hp=" << monster_hp << " damage=" << monster_damage
         << " exp="
         << monster_exp << " money=" << monster_money << ")" << endl;
}

void Monster::lose() {
    cout << "Boss!Help!" << endl;
}

void Monster::setMonsterRank(int monsterRank) {
    monster_rank = monsterRank;
}

void Monster::setMonsterExp(int monsterExp) {
    monster_exp = monsterExp;
}

void Monster::setMonsterHp(int monsterHp) {
    monster_hp = monsterHp;
}

void Monster::setMonsterDamage(int monsterDamage) {
    monster_damage = monsterDamage;
}

void Monster::setMonsterMoney(int monsterMoney) {
    monster_money = monsterMoney;
}

void Monster::fightback(Ultraman &outman) {
    outman.setUltramanHp(outman.getUltramanHp() - 0.5 * monster_damage);
}


void ultraman_attacked(Ultraman &p1, Monster &p2) {//奥特曼受到攻击
}


int Ultraman::getUltramanRank() const {
    return ultraman_rank;
}

int Ultraman::getUltramanExp() const {
    return ultraman_exp;
}

int Ultraman::getUltramanHp() const {
    return ultraman_hp;
}

int Ultraman::getUltramanDamage() const {
    return ultraman_damage;
}

int Ultraman::getUltramanMoney() const {
    return ultraman_money;
}

void Ultraman::attack(Monster &monster) {
    monster.setMonsterHp(monster.getMonsterHp() - ultraman_damage);

}

void Ultraman::setUltramanRank(int ultramanRank) {
    ultraman_rank = ultramanRank;
}

void Ultraman::setUltramanHp(int ultramanHp) {
    ultraman_hp = ultramanHp;
}

void Ultraman::setUltramanDamage(int ultramanDamage) {
    ultraman_damage = ultramanDamage;
}

void Ultraman::setUltramanMoney(int ultramanMoney) {
    ultraman_money = ultramanMoney;
}

void Ultraman::setUltramanExp(int ultramanExp) {
    ultraman_exp = ultramanExp;
}

void Ultraman::restore() {
    if (ultraman_hp < ultraman_rank * 5 && ultraman_hp > 10) {
        int m = ultraman_money / 10;
        int n = m;
        if (m == 0) {
            return;
        }
        for (int i = 0; i < m; i++) {
            if (ultraman_hp == ultraman_rank * 10)
                break;
            ultraman_hp++;
            n--;
        }
        ultraman_money = ultraman_money - (m - n) * 10;
    }
}

void Ultraman::escape() {
    ultraman_money = 0;
}

void Ultraman::upgrade() {
    while (ultraman_exp >= ultraman_rank * 10) {
        ultraman_exp = ultraman_exp - ultraman_rank * 10;
        ultraman_rank = ultraman_rank + 1;
        ultraman_hp = ultraman_rank * 10;
        ultraman_damage = ultraman_rank * 3;
    }
}

void Ultraman::win(Monster &monster) {
    ultraman_money = ultraman_money + monster.getMonsterMoney();
    ultraman_exp = ultraman_exp + monster.getMonsterExp();
}

void Ultraman::win(Boss &boss) {
    ultraman_money = ultraman_money + boss.getMonsterMoney();
    ultraman_exp = ultraman_exp + boss.getMonsterExp();
}

void Ultraman::display() {
    cout << "Outman status (" << "rank=" << ultraman_rank << " hp=" << ultraman_hp << " damage=" << ultraman_damage
         << " exp="
         << ultraman_exp << " money=" << ultraman_money << ")" << endl;
}

Ultraman &Ultraman::operator++() {
    ultraman_rank *= 2;
    ultraman_hp = ultraman_rank * 10;
    ultraman_damage = ultraman_rank * 3;
    ultraman_exp *= 2;
    ultraman_money *= 2;
}

ostream &operator<<(ostream &os, const Ultraman &ultraman) {
    os << "Outman status (" << "rank=" << ultraman.ultraman_rank << " hp=" << ultraman.ultraman_hp << " damage="
       << ultraman.ultraman_damage
       << " exp="
       << ultraman.ultraman_exp << " money=" << ultraman.ultraman_money << ")" << endl;
    return os;
}

Ultraman &Ultraman::operator--() {
    ultraman_hp /= 2;
    ultraman_exp /= 2;
    ultraman_damage /= 2;
    ultraman_money /= 2;
}

bool Ultraman::operator<(Monster monster) {
    if (monster.getMonsterRank() < ultraman_rank) {
        ultraman_hp += monster.getMonsterHp() / 2;
        ultraman_damage += monster.getMonsterDamage() / 2;
        ultraman_exp += monster.getMonsterExp() / 2;
        ultraman_money += monster.getMonsterMoney() / 2;
    }
    return true;
}

bool Ultraman::operator==(Monster monster) {
    if (ultraman_rank == monster.getMonsterRank()) {
        ultraman_hp += monster.getMonsterHp();
        ultraman_damage += monster.getMonsterDamage();
        ultraman_exp += monster.getMonsterExp();
        ultraman_money += monster.getMonsterMoney();
    }
    return true;
}


void Boss::lose() {
    cout << "I'll be back!" << endl;
}

void Boss::fightback(Ultraman &outman) {
    if (attackedcount % 5 == 0) {
        Monster::fightback(outman);
        Monster::fightback(outman);
        Monster::fightback(outman);
    } else {
        Monster::fightback(outman);
    }
}

void Boss::display() {
    cout << "Boss status (" << "rank=" << monster_rank << " hp=" << monster_hp << " damage=" << monster_damage
         << " exp="
         << monster_exp << " money=" << monster_money << ")" << endl;
}

int main() {
    int ograd;
    cin >> ograd; // Enter the level value of Outman, and use the level value to declare an Ultraman object.
    Ultraman uobj(ograd);
    cout << uobj; // Display the initial state of the Outman object

    int t;
    cin >> t; // Enter the number of tests
    while (t--) {
        char c = 0;
        while (1) {
            cin
                    >> c; // Enter the magic bag to be used, G stands for good deeds, B stands for misfortune, X stands for star attraction, Y stands for chance
            if (c == 'G') {
                cout << "**** Good things double ****" << endl;
                ++uobj;
                cout << "**** Successfully doubled ****" << endl;
                break;
            } else if (c == 'B') {
                cout << "**** Worse is not a single line ****" << endl;
                --uobj;
                cout << "**** Unfortunately halved ****" << endl;
                break;
            } else if (c == 'X') {
                int r;
                cin
                        >> r; // Enter the level value of the monster. Use the level value to declare a monster object and display the initial state of the object.
                Monster mobj(r);
                mobj.display();
                cout << "**** Star Suck Dafa ****" << endl;
                if (uobj < mobj) cout << "**** You're done ****" << endl;
                else cout << "**** has not succeeded ****" << endl;
                break;
            } else if (c == 'Y') {
                int r;
                cin
                        >> r; // Enter the level value of the monster. Use the level value to declare a monster object and display the initial state of the object.
                Monster mobj(r);
                mobj.display();
                cout << "**** Fate to meet ****" << endl;
                if (uobj == mobj) cout << "**** destined fate ****" << endl;
                else cout << "**** No fate ****" << endl;
                break;
            } else cout << "Please re-enter the magic bag type" << endl;
        }
        cout << uobj;
    }
    return 0;
}