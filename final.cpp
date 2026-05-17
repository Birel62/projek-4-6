#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class Player {
public:
    string clas;

    int hp, maxHp;
    int mana, maxMana;
    int attack;

    int gold;
    int exp;
    int level;

    Player() {
        gold = 0;
        exp = 0;
        level = 1;
    }

    void stats() {
        cout << "\n===== HRAC =====\n";
        cout << "Class: " << clas << endl;
        cout << "HP: " << hp << "/" << maxHp << endl;
        cout << "Mana: " << mana << "/" << maxMana << endl;
        cout << "Attack: " << attack << endl;
        cout << "Gold: " << gold << endl;
        cout << "Level: " << level << endl;
    }

    void levelUp() {
        if (exp >= level * 10) {
            exp = 0;
            level++;

            maxHp += 2;
            hp = maxHp;

            maxMana += 1;
            mana = maxMana;

            attack++;

            cout << "\nLEVEL UP!\n";
            cout << "HP +2\n";
            cout << "Mana +1\n";
            cout << "Attack +1\n";
        }
    }
};

class Enemy {
public:
    string name;
    int hp;
    int attack;
    int gold;
    int exp;
};

void chooseClass(Player &p) {

    int c;
    bool ok = false;

    while (!ok) {

        cout << "\n===== CLASSY =====\n";
        cout << "1. Femboy\n";
        cout << "2. Wizard\n";
        cout << "3. Rytir\n";
        cout << "4. Farmar\n";

        cin >> c;

        if (c == 1) {
            p.clas = "Femboy";
            p.maxHp = 6;
            p.hp = 6;
            p.maxMana = 5;
            p.mana = 5;
            p.attack = 2;
        }

        else if (c == 2) {
            p.clas = "Wizard";
            p.maxHp = 4;
            p.hp = 4;
            p.maxMana = 8;
            p.mana = 8;
            p.attack = 1;
        }

        else if (c == 3) {
            p.clas = "Rytir";
            p.maxHp = 8;
            p.hp = 8;
            p.maxMana = 3;
            p.mana = 3;
            p.attack = 3;
        }

        else if (c == 4) {
            p.clas = "Farmar";
            p.maxHp = 7;
            p.hp = 7;
            p.maxMana = 4;
            p.mana = 4;
            p.attack = 2;
            p.gold = 5;
        }

        p.stats();

        cout << "\nPotvrdit?\n1. Ano\n2. Ne\n";
        cin >> c;

        if (c == 1)
            ok = true;
    }
}

void village(Player &p) {

    int c;

    while (true) {

        cout << "\n===== VESNICE =====\n";
        cout << "1. Heal HP (5 gold)\n";
        cout << "2. Zvysit HP (10 gold)\n";
        cout << "3. Zvysit manu (10 gold)\n";
        cout << "4. Zvysit attack (15 gold)\n";
        cout << "5. Odejit\n";

        cin >> c;

        if (c == 1) {

            if (p.gold >= 5) {
                p.gold -= 5;
                p.hp = p.maxHp;
                cout << "HP doplneno.\n";
            }

            else
                cout << "Malo gold.\n";
        }

        else if (c == 2) {

            if (p.gold >= 10) {
                p.gold -= 10;
                p.maxHp += 2;
                p.hp = p.maxHp;
                cout << "HP zvyseno.\n";
            }

            else
                cout << "Malo gold.\n";
        }

        else if (c == 3) {

            if (p.gold >= 10) {
                p.gold -= 10;
                p.maxMana += 2;
                p.mana = p.maxMana;
                cout << "Mana zvysena.\n";
            }

            else
                cout << "Malo gold.\n";
        }

        else if (c == 4) {

            if (p.gold >= 15) {
                p.gold -= 15;
                p.attack++;
                cout << "Attack zvysen.\n";
            }

            else
                cout << "Malo gold.\n";
        }

        else if (c == 5)
            break;
    }
}

void playerAttack(Player &p, Enemy &e) {

    int c;

    cout << "\n1. Basic attack\n";
    cout << "2. Ability\n";

    cin >> c;

    if (c == 1) {

        e.hp -= p.attack;

        cout << "Udelil jsi " << p.attack << " damage.\n";
    }

    else {

        if (p.clas == "Wizard") {

            cout << "1. Fireball (2 mana)\n";
            cin >> c;

            if (c == 1 && p.mana >= 2) {
                p.mana -= 2;
                e.hp -= 5;
                cout << "Fireball za 5 damage.\n";
            }
        }

        else if (p.clas == "Rytir") {

            cout << "1. Furious Slash (2 mana)\n";
            cin >> c;

            if (c == 1 && p.mana >= 2) {
                p.mana -= 2;
                e.hp -= 6;
                cout << "Silny utok za 6 damage.\n";
            }
        }

        else if (p.clas == "Farmar") {

            cout << "1. Slepice (2 mana)\n";
            cin >> c;

            if (c == 1 && p.mana >= 2) {

                int dmg = rand() % 5 + 1;

                p.mana -= 2;
                e.hp -= dmg;

                cout << "Slepice dala " << dmg << " damage.\n";
            }
        }

        else if (p.clas == "Femboy") {

            cout << "1. UwU Heal (2 mana)\n";
            cin >> c;

            if (c == 1 && p.mana >= 2) {

                p.mana -= 2;
                p.hp += 3;

                if (p.hp > p.maxHp)
                    p.hp = p.maxHp;

                cout << "Heal +3 HP.\n";
            }
        }
    }

    if (e.hp < 0)
        e.hp = 0;
}

