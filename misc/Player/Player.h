#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include <string>
using namespace std;
#include "~/dad_sim/Dad/Dad.h"


class Player {

private:
  string email;
  string password;
  Dad *dads;
public:
  // HELPER FUNCTIONS
  void initDads() {
    delete [] dads;
    dads = new Dad[6];
    for (int i = 0; i < 6; i++) {
      dads[i] = nullptr;
    }
  }
  // Default CONSTRUCTOR
  Player() {
    email = "";
    password = "";
    initDads();
  }
  // Standard CONSTRUCTOR
  Player(string em, string pass) {
    email = em;
    password = pass;
    initDads();
  }
  // DESTRUCTOR
  ~Player() {
    delete [] dads;
  }
  // SETTERS and GETTERS
  void setEmail(string em) { email = em; }
  string getEmail() { return email; }
  void setPassword(string pass) { password = pass; }
  string getPassword() { return password; }
  // METHODS list
  void loadDad(int i);
  void createDad();
  void deleteDad(int i);
};

#endif
