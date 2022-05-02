//
// Created by User on 5/2/2022.
//

#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H




class Player {
    const char *name;
    int level;
    int force;
    int hp;
    int coins;
    int maxHP;
public:
    Player(const char *name, int force=5, int hp = 100);
    ~Player();
    void printInfo();
    void levelUp();
    int getLevel();
    int getAttackStrength();
    void buff(int points);
    void heal(int points);
    void damage(int points);
    bool isKnockedOut();
    void addCoins(int amount);
    bool pay(int amount);
};


#endif //EX2_PLAYER_H
