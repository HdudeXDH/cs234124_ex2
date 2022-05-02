#include "Card.h"
#include "utilities.h"


Card::Card(CardType type, const CardStats& stats){
    this->m_effect=type;
    this->m_stats=stats;
};

void Card::applyEncounter(Player& player) const{
    switch (this->m_effect) {
        case (CardType::Battle): {
            if (player.getAttackStrength()>this->m_stats.force){
                player.levelUp();
                player.addCoins(this->m_stats.loot);
            } else {
                player.damage(this->m_stats.hpLossOnDefeat);
            }
        }
        case (CardType::Buff): {
            if(player.pay(this->m_stats.cost)) {
                player.buff(this->m_stats.buff);}
        };
        case (CardType::Heal): {
            if(player.pay(this->m_stats.cost)) {
                player.heal(this->m_stats.heal);}
        };
        case (CardType::Treasure): {
            player.addCoins((this->m_stats.loot));
        };
    }
};

void Card::printInfo() const{
    switch (this->m_effect) {
        case (CardType::Battle): printBattleCardInfo(this->m_stats);
        case (CardType::Buff): printBuffCardInfo(this->m_stats);
        case (CardType::Heal): printHealCardInfo(this->m_stats);
        case (CardType::Treasure): printTreasureCardInfo(this->m_stats);
    }
};
