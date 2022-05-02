//
// Created by User on 5/2/2022.
//

#include "Player.h"
#include "utilities.h"

Player::Player(const char *name, int force, int hp){
    this->name=name;
    this->force=force;
    this->level=1;
    this->hp=hp;
    this->coins=0;
};
Player::~Player(){
};//TODO: check what is the standard?!?

void Player::printInfo(){
    printPlayerInfo(this->name,this->level, this->force, this->hp,  this->coins);
};
void Player::levelUp(){

};
int Player::getLevel(){

};
int Player::getAttackStrength(){

};
void Player::buff(int points){

};
void Player::heal(int points){

};
void Player::damage(int points){

};
bool Player::isKnockedOut(){

};
void Player::addCoins(int amount){

};
bool Player::pay(int amount){

};