//
// Created by User on 5/2/2022.
//

#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H


static const int HP_DEFAULT = 100;
static const int FORCE_DEFAULT = 5;
static const int MAX_LVL = 10;

class Player {
    const char *m_name;
    int m_level;
    int m_force;
    int m_hp;
    int m_coins;
    int m_maxHP;
public:
    Player(const char *name, int hp=HP_DEFAULT, int force=FORCE_DEFAULT);
    Player(const Player &)=default;
    ~Player() = default;
    Player & operator=(const Player &)=default;

    /*
     * printing player info
     */
    void printInfo();

    /*
     * level up the player
     */
    void levelUp();

    /*
     * return current level player
     */
    int getLevel();

    /*
     * return current player strength (force + level)
     */
    int getAttackStrength();

    /*
     * adding points to the player's force
     */
    void buff(int points);

    /*
     * healing points to the player, if surpasses the maxhp will stay on maxhp
     */
    void heal(int points);

    /*
     * Damage the player
     */
    void damage(int points);

    /*
     * check whether the player is knocked out (true/false)
     */
    bool isKnockedOut();

    /*
     * Add coins to player
     */
    void addCoins(int amount);

    /*
     * Pay the amount, if successful returns true
     */
    bool pay(int amount);
};


#endif //EX2_PLAYER_H
