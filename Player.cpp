//
// Created by User on 5/2/2022.
//

#include "Player.h"
#include "utilities.h"

Player::Player(const char *name, int hp , int force):
    m_name(name),
    m_level(1),
    m_coins(0){
    // validating hp and force inputs
    if (force>0) {
        this->m_force=force;
    }
    else {
        this->m_force=FORCE_DEFAULT;
    }
    if (hp<=0) {
        hp=HP_DEFAULT;
    }
    this->m_maxHP=hp;
    this->m_hp=hp;
}

void Player::printInfo(){
    printPlayerInfo(this->m_name,this->m_level, this->m_force, this->m_hp,  this->m_coins);
}
void Player::levelUp(){
    if (m_level<MAX_LVL) {
        this->m_level+=1;
    }
}
int Player::getLevel(){
    return this->m_level;
}
int Player::getAttackStrength(){
    return(this->m_level+this->m_force);
}
void Player::buff(int points){
    if (points<0) {
        points =0;
    }
   this->m_force += points;
}

void Player::heal(int points){
    if (points<0) {
        points =0;
    }
    if(this->m_hp + points >= this->m_maxHP) this->m_hp = this->m_maxHP;
    else this->m_hp += points;
}
void Player::damage(int points){
    if (points<0) {
        points =0;
    }
    if (this->m_hp - points <= 0) this->m_hp = 0;
    else this->m_hp -= points;
}
bool Player::isKnockedOut(){
    if(this->m_hp == 0) return true;
    return false;
}
void Player::addCoins(int amount){
    if (amount<0) {
        amount =0;
    }
    this->m_coins+=amount;
}
bool Player::pay(int amount){
    if (amount<0) {
        amount =0;
    }
    if (this->m_coins>=amount){
        this->m_coins-=amount;
        return true;
    } else{
        return false;
    }
}