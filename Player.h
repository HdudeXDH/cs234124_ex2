//
// Created by User on 5/2/2022.
//

#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H




class Player {
    const char *m_name;
    int m_level;
    int m_force;
    int m_hp;
    int m_coins;
    int m_maxHP;
public:
    Player(const char *name, int hp=100, int force=5);
    Player(const Player &)=default; //TODO: validate, else see tirgul 6 page 12
    ~Player() = default;
    Player & operator=(const Player &)=default;
    /*
     *
     */
    void printInfo();
    /*
     *
     */
    void levelUp();
    /*
     *
     */
    int getLevel();
    /*
     *
     */
    int getAttackStrength();
    /*
     *
     */
    void buff(int points);
    /*
     *
     */
    void heal(int points);
    /*
     *
     */
    void damage(int points);
    /*
     *
     */
    bool isKnockedOut();
    /*
     *
     */
    void addCoins(int amount);
    /*
     *
     */
    bool pay(int amount);
};


#endif //EX2_PLAYER_H
