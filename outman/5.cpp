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

    void display() override ;
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

    void display() {
        cout << "Outman status (" << "rank=" << ultraman_rank << " hp=" << ultraman_hp << " damage=" << ultraman_damage
             << " exp="
             << ultraman_exp << " money=" << ultraman_money << ")" << endl;
    }

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
    // Enter the level value of Outman, use the level value, declare an Outman object and display the initial state of the Outman object.
    int ograd;
    cin >> ograd;
    Ultraman uobj(ograd);
    int t;
    cin >> t; // Enter the number of monsters to play
    while (t-- && uobj.getUltramanHp() >
                  10) {// As long as Ultraman is not dead and does not escape, continue to fight with the monster
        uobj.display();
        Monster *p;
        char c = 0;
        while (true) {
            cin >> c;
            if (c == 'B') {
                p = new Boss();
                break;
            } else if (c == 'M') {
                int r;
                cin >> r;
                p = new Monster(r);
                break;
            } else cout << "Please re-enter the monster type" << endl;
        }
        p->display();
        // Set the battle flag flag to true to start the battle loop, as follows:
        int flag = 1;
        while (flag) // Continue when the battle is not over
        {
            uobj.attack(*p); // Outman attack 1 time
            if (p->getMonsterHp() > 0) // The monster is not dead
            {
                p->fightback(uobj); // Monster fights back 1 time
                if (uobj.getUltramanHp() > 10) // Outman health is greater than the point, do not escape
                    uobj.restore(); // Outman returns blood, in the method to determine whether it is necessary to add blood
                else {// Outman escapes, and outputs "lose" and returns
                    uobj.escape();
                    cout << "lose" << endl;
                    uobj.display(); // Outman state output
                    flag = 0; // Stop fighting
                }
            } else // the monster is dead
            {
                uobj.win(*p); // Outman wins, and outputs "win" and returns
                cout << "win" << endl;
                uobj.upgrade(); // Outman upgrade
                p->lose(); // Output monster defeat information
                flag = 0; // Stop fighting
            }
        }
    }
    return 0;
}