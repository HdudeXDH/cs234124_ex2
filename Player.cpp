//
// Created by User on 5/2/2022.
//

#include "Player.h"
#include "utilities.h"

Player::Player(const char *name, int force, int hp){
    this->name=name;
    this->force=force;
    this->level=1;
    this->maxHP=hp;
    this->hp=hp;
    this->coins=0;

};
Player::~Player(){
};//TODO: check what is the standard?!?

void Player::printInfo(){
    printPlayerInfo(this->name,this->level, this->force, this->hp,  this->coins);
};
void Player::levelUp(){
    if (level<10) {
        this->level+=1;
    };
};
int Player::getLevel(){
    return this->level;
};
int Player::getAttackStrength(){

};
void Player::buff(int points){
   this->force += points;
};

void Player::heal(int points){
    if(this->hp + points >= this->maxHP) this->hp = this->maxHP;
    else this->hp += points;
};
void Player::damage(int points){
    if (this->hp - points <= 0) this->hp = 0;
    else this->hp -= points;
}
bool Player::isKnockedOut(){
    if(this->hp == 0) return true;
    return false;
};
void Player::addCoins(int amount){
    this->coins+=amount;
};
bool Player::pay(int amount){
    if (this->coins>=amount){
        this->coins-=amount;
        return true;
    } else{
        return false;
    }
};