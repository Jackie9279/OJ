
#include <iostream>

using namespace std;

class Monster;

class Ultraman {
protected:
    int ultraman_rank;
    int ultraman_exp, ultraman_hp, ultraman_damage, ultraman_money;
public:
    friend class Monster;

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

    void escape() {
        ultraman_money = 0;
        cout << "lose" << endl;
    }
    friend void attack() {}//奥特曼战斗
    friend void ultraman_attacked(Ultraman &p1, Monster &p2);//奥特曼受到攻击
    void restore() {//奥特曼加血
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

    friend void win(Ultraman &p1, Monster &p2);

    void upgrade() {
        if (ultraman_exp >= ultraman_rank * 10) {
            ultraman_exp = ultraman_exp - ultraman_rank * 10;
            ultraman_rank = ultraman_rank + 1;
            ultraman_hp = ultraman_rank * 10;
            ultraman_damage = ultraman_rank * 3;
        }
    }

    void display() {
        cout << "rank=" << ultraman_rank << " hp=" << ultraman_hp << " damage=" << ultraman_damage << " exp="
             << ultraman_exp << " money=" << ultraman_money << endl;
    }
};

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

    friend void monster_attacked(Ultraman &p1, Monster &p2);//怪兽受到攻击
    friend void fightback(Ultraman &p1, Monster &p2);//怪兽反击
    void display() {
        cout << "rank=" << monster_rank << " hp=" << monster_hp << " damage=" << monster_damage << " exp="
             << monster_exp << " money=" << monster_money << endl;
    }
};

void monster_attacked(Ultraman &p1, Monster &p2) {//怪兽受到攻击
    p2.monster_hp = p2.monster_hp - p1.getUltramanDamage();
}

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

void fightback(Ultraman &p1, Monster &p2) {

}


void ultraman_attacked(Ultraman &p1, Monster &p2) {//奥特曼受到攻击
    p1.ultraman_hp = p1.ultraman_hp - 0.5 * p2.getMonsterDamage();
}

void win(Ultraman &p1, Monster &p2) {
    p1.ultraman_money = p1.ultraman_money + p2.getMonsterMoney();
    p1.ultraman_exp = p1.ultraman_exp + p2.getMonsterExp();
    cout << "win" << endl;
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


int main() {
    int t, m, n;
    cin >> t;
    bool flag;
    while (t--) {
        flag = true;
        cin >> m >> n;
        Ultraman outman(m);//初始化奥特曼
        Monster monster(n);//初始化怪兽
        outman.display();
        monster.display();
        while (flag) {
            monster_attacked(outman, monster);
            if (monster.getMonsterHp() > 0) {
                ultraman_attacked(outman, monster);
                if (outman.getUltramanHp() > 10) {
                    if (outman.getUltramanHp() < outman.getUltramanRank() * 5 &&
                        outman.getUltramanHp() > 10) {
                        outman.restore();
                    }
                } else {
                    outman.escape();
                    outman.display();
                    flag = false;
                }
            } else if (monster.getMonsterHp() < 0) {
                win(outman, monster);
                outman.upgrade();
                outman.display();
                flag = false;
            }
        }
    }
    return 0;
}