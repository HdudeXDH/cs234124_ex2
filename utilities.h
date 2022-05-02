//
// Created by Daniel_Meents on 12/04/2022.
//

#ifndef EX2_UTILITIES_H
#define EX2_UTILITIES_H




/*
 * Numeric stats of a card.
 */
struct CardStats{
    int force;  // The m_force of the monster
    int loot; // The profit you get when winning a battle or when getting a "Treasure" card
    int hpLossOnDefeat; // The amount of m_hp you lose when losing the battle

    int cost; // The cost of a "Buff/Heal" card
    int heal; // The amount of HP you get when buying a "HEAL" card
    int buff; // The amount of m_force you get when buying a "BUFF" card


    /*
     *C'tor of CardStats:
     *
     * @param m_force - The m_force of the card (monster).
     * @param hpLoss - HP loss when losing the battle.
     * @param cost - The cost of the card when is type is "Buff" or "Heal".
     * @param heal - The amount of HP is given when buying a "Heal" card.
     * @param buff - The amount of m_force is given when buying a "Buff" card.
     * @param loot - The profit from winning a battle or when getting a "Treasure" card.
     * @return
     *      New instance of CardStats.
    */
    explicit CardStats(int force = 0, int hpLoss = 0, int cost = 0, int heal = 0, int buff = 0, int loot = 0) {
        this->force = force;
        this->hpLossOnDefeat = hpLoss;
        this->cost = cost;
        this->heal = heal;
        this->buff = buff;
        this->loot = loot;
    }
};


/*
 * Prints info of a Battle card:
 *
 * @param card - Stats of the card.
 * @return
 *      void
 */
void printBattleCardInfo(const CardStats& card);


/*
 * Prints info of a Battle outcomes:
 *
 * @param win - Boolean.
 * @return
 *      void
 */
void printBattleResult(bool win);


/*
 * Prints info of a Buff card:
 *
 * @param win - Is the player won or lost the battle?
 * @return
 *      void
 */
void printBuffCardInfo(const CardStats& card);


/*
 * Prints info of a Heal card:
 *
 * @param card - Stats of the card.
 * @return
 *      void
 */
void printHealCardInfo(const CardStats& card);


/*
 * Prints info of a Treasure card:
 *
 * @param card - Stats of the card.
 * @return
 *      void
 */
void printTreasureCardInfo(const CardStats& card);


/*
 * Prints the details of the player:
 *
 * @param m_name - The m_name of the player.
 * @param m_level - The player's m_level.
 * @param m_force - The player's m_force.
 * @param m_hp - The player's HP points.
 * @param m_coins - The player's amount of m_coins.
 * @return
 *      void
 */
void printPlayerInfo(const char* name, int level, int force, int hp, int coins);



#endif //EX2_UTILITIES_H
