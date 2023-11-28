#include"/usr/local/cs/cs251/react.h"
#include"State.h"
#include<ctime>
using namespace std;

void State::randomize_quests() {
  srand(time(NULL));
  int first = rand() % getQuest().getGridQuestNum();
  int choices[4] = {first, first, first, first};
  while(choices[1] == choices[0]) {
    choices[1] = rand() % getQuest().getGridQuestNum();
  }
  while(choices[2] == choices[0] || choices[2] == choices[1]) {
   choices[2] = rand() % getQuest().getGridQuestNum();
  }
  while(choices[3] == choices[0] || choices[3] == choices[1] || choices[3] == choices[2]) {
    choices[3] = rand() % getQuest().getGridQuestNum();
  }
  setQuestId(0, choices[0]);
  setQuestId(1, choices[1]);
  setQuestId(2, choices[2]);
  setQuestId(3, choices[3]);
}

void State::handle_button_event(int i)  {
  if (i == 3) {
    if (id != 63) {
      id = 63;
    } else {
      id = 60;
    }
  }

  if (i == 1) {
    if (id != 61) {
      id = 61;
    } else {
      id = 60;
    }
  }

  if (i == 2) {
    if (id != 62) {
      id = 62;
    } else {
      id = 60;
    }
  } 
}

void State::handle_buildupquest_event() {
  
  int additional = getQuest()
    .getWeekQuests(getDad().getWeekNum())
    .getBuildupQuests(getDad().getCurrentBuildupQuest())
    .getEventPoints();
  
  getDad().setEventPoints(getDad().getEventPoints() + additional);
  
  if (getDad().getCurrentBuildupQuest() < 5) {
    getDad().updateBuildup();
  } else {
    getDad().setCurrentBuildupQuest(0);
  }

  randomize_quests();
}

void State::handle_gridquest_event(int i) {

  if (getQuestId(i) < getQuest().getSideQuestBreak()) {
    int additional = getQuest()
      .getGridQuest(getQuestId(i))
      .getDadPoints();
    getDad().setTotalDadPoints(getDad().getTotalDadPoints() + additional);
  } else {
    int store_item = getQuest().getGridQuest(getQuestId(i)).getStoreItemId();
    if (getDad().getItemLevel(store_item) < 5) {
      getDad().setItemLevel(store_item, getDad().getItemLevel(store_item) + 1);
    } else {
      getDad().setTotalDadPoints(getDad().getTotalDadPoints() + 100);
    }
  }
  
  randomize_quests();
}

void State::update() {
  if (_just_starting()) {
    // RESET STATE FOR NEW GAME
  } else {
    if (_received_event()) {
      // UPDATE STATE FOR EVENT
      // state member variables changed ?????
      // something updates _global_mem ????????
      for (int i = 1; i < 4; ++i) { // FIRING FOR EVERY BUTTON
        if (_event_id_is("button_", i)) {
          handle_button_event(i);
        } 
      }
      if (_event_id_is("buildupquest_", 1)) {
        handle_buildupquest_event();
      }
      for (int i = 1; i < 5; i++) {
        if (_event_id_is("sidequest_", i)) {
          handle_gridquest_event(i-1);
        }
      }
    }
  }
}