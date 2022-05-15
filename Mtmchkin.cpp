#include "Mtmchkin.h"
#include "Card.h"

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards):
    m_player(playerName),
    m_game_status(GameStatus::MidGame),
    m_cards(new Card[numOfCards]),
    m_cards_count(numOfCards),
    m_cards_index(0) {
    for (int i = 0; i<numOfCards;i++){
        m_cards[i] = cardsArray[i];
    }
}


// copy constructor
Mtmchkin::Mtmchkin(const Mtmchkin& m) :
    m_player(Player(m.m_player)) ,
    m_game_status(m.m_game_status),
    m_cards(new Card[m.m_cards_count]),
    m_cards_count(m.m_cards_count),
    m_cards_index(m.m_cards_count) {
    for (int i = 0; i < m.m_cards_count; i++) {
        m_cards[i] = m.m_cards[i];
    }
}

Mtmchkin & Mtmchkin::operator=(const Mtmchkin & m) {
    if (this == &m){
        return *this;
    }
    delete[] m_cards;
    m_cards = new Card[m.m_cards_count];
    for (int i = 0; i<m.m_cards_count;i++){
        m_cards[i] = m.m_cards[i];
    }
    this->m_player = Player(m.m_player);
    return *this;
}


Mtmchkin::~Mtmchkin(){
    delete[] m_cards;
}

GameStatus Mtmchkin::getGameStatus() const {
    return this->m_game_status;
}

bool Mtmchkin::isOver() {
    if (this->m_player.isKnockedOut()) {
        this->m_game_status=GameStatus::Loss;
        return true;
    }
    if (this->m_player.getLevel()>=10){
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