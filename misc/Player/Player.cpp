#include<iostream>
using namespace std;
// #include"/usr/local/cs/cs251/show_mem.h"
#include "Player.h"
// g++ -Wall -c Player.cpp
// g++ -Wall -c test_Player.cpp
// g++ -Wall Player.o test_Player.o
// ./a.out


// Player methods defined

void Player::getDad(int i) {
  return dads[i];
}
void createDad();
void deleteDad(int i);