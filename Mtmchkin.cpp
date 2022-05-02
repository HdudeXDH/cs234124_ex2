//
// Created by User on 5/2/2022.
//

#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards):
    m_player(playerName),
    m_game_status(GameStatus::MidGame),
    m_cards(cardsArray),
    m_cards_count(numOfCards),
    m_cards_index(0) {
}
//todo add constrctors


//// copy constructor
//Mtmchkin::Mtmchkin(const Mtmchkin& m) = default;
////    :m_player(new Player) ,
////    m_game_status(m.m_game_status),
////    m_cards(m.m_cards),
////    m_cards_count(m.m_cards_count),
////    m_cards_index(m.m_cards_index) {
////{
//
//
////}
////
//Mtmchkin& Mtmchkin::operator=(const Mtmchkin& game) = default;

GameStatus Mtmchkin::getGameStatus() const {
    return this->m_game_status;
}

bool Mtmchkin::isOver() {
    if (this->m_player.isKnockedOut()) {
        this->m_game_status=GameStatus::Loss;
        return true;
    }
    if (this->m_player.getLevel()==10){
        this->m_game_status=GameStatus::Win;
        return true;
    }
    return false;
}

void Mtmchkin::playNextCard() {
     Card currentCard = this->m_cards[this->m_cards_index];
     currentCard.printInfo();
     currentCard.applyEncounter(m_player);
     this->m_player.printInfo();
     //proceed to next card, reset if gets to m_cards_count.
     this->m_cards_index= (this->m_cards_index+1)%this->m_cards_count;
}