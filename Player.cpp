//
// Created by User on 5/2/2022.
//

#include "Player.h"
#include "utilities.h"

Player::Player(const char *name, int hp , int force){
    this->m_name=name;
    if (force>0) {
        this->m_force=force;
    }
    else {
        this->m_force=5;
    }
    if (hp<=0) {
        hp=100;
    }
    this->m_level=1;
    this->m_maxHP=hp;
    this->m_hp=hp;
    this->m_coins=0;

}

void Player::printInfo(){
    printPlayerInfo(this->m_name,this->m_level, this->m_force, this->m_hp,  this->m_coins);
}
void Player::levelUp(){
    if (m_level<10) {
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