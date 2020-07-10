#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Ultraman;

class Angle;

class Monster {
protected:
    int monster_rank;
    int monster_exp, monster_hp, monster_damage, monster_money;
    string type;
    bool isdead;
public:
    Monster() {}

    Monster(int initial_rank) {
        monster_rank = initial_rank;//初始化怪兽等级
        monster_exp = initial_rank * 10;//初始化怪兽经验值
        monster_hp = initial_rank * 20;//初始化怪兽生命值
        monster_damage = initial_rank * 2;//初始化怪兽战斗力
        monster_money = initial_rank * 10;//初始化怪兽的小钱
        isdead = false;
    }


    bool isIsdead() const;

    void setIsdead(bool isdead);

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

    const string &getType() const;

    void setType(const string &type);

    virtual void display();

    virtual void lose();

    virtual void fightback(Ultraman &outman);

};

class NMonster : public Monster {
public:
    NMonster(int initialRank) : Monster(initialRank) {
        monster_damage = 2 * initialRank;
        monster_hp = 10 * initialRank;
        monster_money = 10 * initialRank;
        monster_exp = 10 * initialRank;
        type = "N";
    }

};

class AMonster : public Monster {
public:
    AMonster(int initialRank) : Monster(initialRank) {
        monster_damage = 4 * initialRank;
        monster_hp = 5 * initialRank;
        monster_money = 10 * initialRank;
        monster_exp = 10 * initialRank;
        type = "A";
    }
};

class DMonster : public Monster {
public:
    DMonster(int initialRank) : Monster(initialRank) {
        monster_hp = 20 * initialRank;
        monster_money = 10 * initialRank;
        monster_exp = 10 * initialRank;
        monster_damage = initialRank * 1;
        type = "D";
    }
};

class SMonster : public Monster {
public:
    SMonster(int initialRank) : Monster(initialRank) {
        monster_hp = 10 * initialRank;
        monster_money = 20 * initialRank;
        monster_exp = 20 * initialRank;
        monster_damage = initialRank;
        type = "S";

    }
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

    void win(Monster &monster, int angle_money, int angle_exp);

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
    cout << "rank=" << monster_rank << " hp=" << monster_hp << " damage=" << monster_damage
         << " exp="
         << monster_exp << " money=" << monster_money << endl;
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
    if (type == "A") {
        outman.setUltramanHp(outman.getUltramanHp() - (monster_damage + monster_rank / 2) / 2);
    } else {
        outman.setUltramanHp(outman.getUltramanHp() - monster_damage / 2);
    }
}

const string &Monster::getType() const {
    return type;
}

void Monster::setType(const string &type) {
    Monster::type = type;
}

bool Monster::isIsdead() const {
    return isdead;
}

void Monster::setIsdead(bool isdead) {
    Monster::isdead = isdead;
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
    if (monster.getType() == "D") {
        monster.setMonsterHp(monster.getMonsterHp() - (ultraman_damage + 2) / 2);
    } else if (monster.getType() == "A") {
        monster.setMonsterHp(monster.getMonsterHp() - (ultraman_damage + 1));
    } else {
        monster.setMonsterHp(monster.getMonsterHp() - ultraman_damage);
    }

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

void Ultraman::win(Monster &monster, int angle_money, int angle_exp) {
    if (monster.getType() == "S") {
        ultraman_money = ultraman_money + monster.getMonsterMoney() * 2;
        ultraman_exp = ultraman_exp + monster.getMonsterExp() * 2;
    } else if (monster.getType() == "D" || monster.getType() == "A") {
        ultraman_money = ultraman_money + monster.getMonsterMoney() + angle_money;
        ultraman_exp = ultraman_exp + monster.getMonsterExp() + angle_exp;
    } else {
        ultraman_money = ultraman_money + monster.getMonsterMoney();
        ultraman_exp = ultraman_exp + monster.getMonsterExp();
    }


}

void Ultraman::win(Boss &boss) {
    ultraman_money = ultraman_money + boss.getMonsterMoney();
    ultraman_exp = ultraman_exp + boss.getMonsterExp();
}

void Ultraman::display() {
    cout << "rank=" << ultraman_rank << " hp=" << ultraman_hp << " damage=" << ultraman_damage
         << " exp="
         << ultraman_exp << " money=" << ultraman_money << endl;
}

Ultraman &Ultraman::operator++() {
    ultraman_rank *= 2;
    ultraman_hp = ultraman_rank * 10;
    ultraman_damage = ultraman_rank * 3;
    ultraman_exp *= 2;
    ultraman_money *= 2;
}

ostream &operator<<(ostream &os, const Ultraman &ultraman) {
    os << "rank=" << ultraman.ultraman_rank << " hp=" << ultraman.ultraman_hp << " damage="
       << ultraman.ultraman_damage
       << " exp="
       << ultraman.ultraman_exp << " money=" << ultraman.ultraman_money << endl;
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


class Angle : public Monster, public Ultraman {
private:
    string angle_type;
    int angle_rank;
    int angle_damage;
    int angle_hp;
    int angle_exp;
    int angle_money;
public:
    Angle(Monster &monster);

    Angle(Ultraman &outman);

    const string &getAngleType() const;

    void setAngleType(const string &angleType);

    int getAngleRank() const;

    void setAngleRank(int angleRank);

    int getAngleDamage() const;

    void setAngleDamage(int angleDamage);

    int getAngleHp() const;

    void setAngleHp(int angleHp);

    int getAngleExp() const;

    void setAngleExp(int angleExp);

    int getAngleMoney() const;

    void setAngleMoney(int angleMoney);

};

Angle::Angle(Monster &monster) {
    angle_type = monster.getType();
    angle_rank = monster.getMonsterRank();
    angle_exp = monster.getMonsterRank() * 5;
    angle_damage = monster.getMonsterRank() / 2;
    if (angle_type == "N") {
        angle_money = monster.getMonsterRank() * 5 + monster.getMonsterMoney();
    } else {
        angle_money = monster.getMonsterRank() * 5;
    }
    angle_hp = 0;
}

Angle::Angle(Ultraman &outman) {
    angle_type = "outman";
    angle_rank = outman.getUltramanRank();
    angle_damage = outman.getUltramanRank() / 2;
    angle_hp = 0;
    angle_exp = 0;
    angle_money = 0;

}

const string &Angle::getAngleType() const {
    return angle_type;
}

void Angle::setAngleType(const string &angleType) {
    angle_type = angleType;
}

int Angle::getAngleRank() const {
    return angle_rank;
}

void Angle::setAngleRank(int angleRank) {
    angle_rank = angleRank;
}

int Angle::getAngleDamage() const {
    return angle_damage;
}

void Angle::setAngleDamage(int angleDamage) {
    angle_damage = angleDamage;
}

int Angle::getAngleHp() const {
    return angle_hp;
}

void Angle::setAngleHp(int angleHp) {
    angle_hp = angleHp;
}

int Angle::getAngleExp() const {
    return angle_exp;
}

void Angle::setAngleExp(int angleExp) {
    angle_exp = angleExp;
}

int Angle::getAngleMoney() const {
    return angle_money;
}

void Angle::setAngleMoney(int angleMoney) {
    angle_money = angleMoney;
}


int main() {
    int t;
    cin >> t; // Enter the number of tests
    while (t--) {
        int ograd;
        cin >> ograd; // Enter the level value of Outman, and use the level value to declare an Ultraman object.
        Ultraman uobj(ograd);
        cout << uobj; // Display the initial state of the Outman object
        vector<Monster> monsterlist;
        int nrank, arank, drank, srank;
        cin >> nrank >> srank >> drank >> arank;
        NMonster N(nrank);
        AMonster A(arank);
        DMonster D(drank);
        SMonster S(srank);
        monsterlist.push_back(N);
        monsterlist.push_back(S);
        monsterlist.push_back(D);
        monsterlist.push_back(A);
        for (auto it:monsterlist) {
            it.display();
        }

        bool flag = true;
        while (flag) {
            for (auto &it:monsterlist) {
                uobj.attack(it);
            }

            for (auto &it:monsterlist) {
                if (!it.isIsdead()) {
                    if (it.getMonsterHp() > 0) {
                        it.fightback(uobj);
                        if (uobj.getUltramanHp() > 10) {
                            uobj.restore();
                        } else {
                            uobj.escape();
                            cout << "lose" << endl;
                            uobj.display();
                            return 0;
                        }
                    } else if (it.getMonsterHp() <= 0) {
                        Angle angle(it);
                        uobj.win(it, angle.getAngleMoney(), angle.getAngleExp());
                        cout << "win" << endl;
                        uobj.upgrade();
                        uobj.display();
                        it.setIsdead(true);
                    }
                }
                if (monsterlist[0].isIsdead() && monsterlist[1].isIsdead() && monsterlist[2].isIsdead() &&
                    monsterlist[3].isIsdead()) {
                    flag = false;
                    cout << "win all" << endl;
                    break;
                }
            }
        }
    }
    return 0;
}