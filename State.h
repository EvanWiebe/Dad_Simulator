#ifndef __STATE_H__
#define __STATE_H__

#include <iostream>
#include <string>
using namespace std;
#include "Dad/Dad.h"
#include "StoreItem/StoreItem.h"
#include "Quest/Quest.h"

class State {
private:
  int id;
  Dad dad;
  Store store;
  Quest quest;
  string login = "login";
  Neighbors neighbors; 
  int quest_ids[4];

public:
  static const int offset = 10;
  const int offset2 = 200;
  const int offset3 = 350;
  const int mem_pos[19] {
    State::offset, // page id [0]
    State::offset + 3, // dad name [1]
    State::offset + 24, // aes [2]
    State::offset + 26, // arch [3]
    State::offset + 28, // dad points [4]
    State::offset + 36, // passive income bonus [5]
    State::offset + 41, // current week [6]
    State::offset + 44, // current buidup quest [7]
    State::offset + 46, // timeline day [8]
    State::offset + 48, // timeline hours [9]
    State::offset + 54, // number of store items [10]
    State::offset + 57, // store item levels [11]
    State::offset + 77, // buildup quest id [12]
    State::offset + 79, // quest id 1 [13]
    State::offset + 83, // quest id 2 [14]
    State::offset + 87, // quest id 3 [15]
    State::offset + 91, // quest id 4 [16]
    State::offset + 95, // email
    State::offset + 115, // password
  };

  State() {}

  State(int i) {
    id = i;
  }

  // GETTERS and SETTERS
  void setId(int i) { id = i; }
  int getId() { return id; }
  Dad &getDad() { return dad; }
  Store &getStore() { return store; }
  Quest &getQuest() { return quest; }
  Neighbors &getNeighbors() { return neighbors;}
  void setQuestId(int idx, int i) { quest_ids[idx] = i; }
  int getQuestId(int idx) { return quest_ids[idx]; }
  string getLogin(){return login;}
  void setLogin(string e){login = e;}
  //Methods
  void read_from(char *c);
  void randomize_quests();
  void update();
  void handle_button_event(int i);
  void handle_buildupquest_event();
  void handle_gridquest_event(int i);
};

#endif
