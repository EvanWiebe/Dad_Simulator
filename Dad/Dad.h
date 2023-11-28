#ifndef __DAD_H__
#define __DAD_H__

#include <iostream>
#include <string>
using namespace std;

//Character class
class Dad {
private:
  //User
  string email;
  string password;
  //Main info
  string name;
  string picture;
  int aesthetic_ID;
  int archetype_ID;
  //Scoring factors
  int total_dad_points;
  int event_points;
  float passive_income;
  //Time info
  int week_num;
  int current_buildup_quest;
  int timeline_day; // 1,2,3,4,5,6,or 7
  float timeline_hours; // 0-8
  //Store info
  int num_store_items;
  int store_item_levels[10] {0};

public:
  //Constant references
  string archetypes[4] {"Grillmaster", "Coach", "Handyman", "Outdoorsman"};
  string aesthetics[4] {"Cargo", "Camo", "Boating", "Sports"};

  Dad() {
    name = "Charlie";
    picture = "https://media.newyorker.com/photos/61ae95d1c5995b40b8cb84e3/1:1/w_1707,h_1708,c_limit/Shouts-Dunigan-Questions-Texted-Dad.jpg";
    aesthetic_ID = 0;
    archetype_ID = 0;
    total_dad_points = 0;
    passive_income = 1.0;
    week_num = 0;
    current_buildup_quest = 1;
    timeline_day = 2;
    timeline_hours = 0;
    num_store_items = 0;
    // Note: store_item_levels automatically initialized at zeros.
  }

  // SETTERS and GETTERS
  void setName(string n) { name = n; }
  string getName() { return name; }
  void setPicture(string pic) { picture = pic; }
  string getPicture() { return picture; }
  void setTotalDadPoints(int pts) { total_dad_points = pts; }
  int getTotalDadPoints() { return total_dad_points; }
  void setEventPoints(int ep) { event_points = ep; }
  int getEventPoints() { return event_points; }
  void setPassiveIncome(float pi) { passive_income = pi; }
  float getPassiveIncome() { return passive_income; }
  int getAestheticID() { return aesthetic_ID; }
  void setAestheticID(int i) { aesthetic_ID = i; }
  int getArchetypeID() { return archetype_ID; } 
  void setArchetypeID(int j) { archetype_ID = j;}
  float getTimelineHours() { return timeline_hours; }
  void setTimelineHours(float l) { timeline_hours = l; }
  int getTimelineDay() { return timeline_day; }
  void setTimelineDay(int l) { timeline_day = l; }
  int getCurrentBuildupQuest() { return current_buildup_quest; }
  void setCurrentBuildupQuest(int c) { current_buildup_quest = c; }
  int getWeekNum() { return week_num; }
  void setWeekNum(int w) { week_num = w; }
  int getNumItems() { return num_store_items; }
  void setNumItems(int n) { num_store_items = n; }
  string getEmail() { return email; }
  void setEmail(string em) { email = em; }
  string getPassword() { return password; }
  void setPassword(string pass) { password = pass; }

  //Methods listed
  void updateDadPoints() { total_dad_points *= passive_income; }
  void addPassiveIncome(float pi) { passive_income += pi; }
  void setItemLevel(int i, int j) { store_item_levels[i] = j; }
  int getItemLevel(int i) { return store_item_levels[i]; }
  void updateWeek() { week_num++; }
  void updateBuildup() { current_buildup_quest++; }
  string getAesthetic() { return aesthetics[aesthetic_ID]; }
  string getArchetype() { return archetypes[archetype_ID]; }
};

//Class for opponent players
class Neighbors {
private:
  Dad *neighbors = nullptr;

public:
  static const int num_neighbors = 10;

  Neighbors() {
    neighbors = new Dad[Neighbors::num_neighbors];
    
    neighbors[0].setName("Papa John");
    // neighbors[0].setPicture("???");
    neighbors[0].setAestheticID(0);
    neighbors[0].setArchetypeID(0);
    neighbors[0].setTotalDadPoints(234300);

    neighbors[1].setName("Big Jo");
    // neighbors[1].setPicture("???");
    neighbors[1].setAestheticID(1);
    neighbors[1].setArchetypeID(3);
    neighbors[1].setTotalDadPoints(178650);

    neighbors[2].setName("Jo");
    // neighbors[2].setPicture("???");
    neighbors[2].setAestheticID(3);
    neighbors[2].setArchetypeID(2);
    neighbors[2].setTotalDadPoints(118700);

    neighbors[3].setName("Stan");
    // neighbors[3].setPicture("???");
    neighbors[3].setAestheticID(1);
    neighbors[3].setArchetypeID(0);
    neighbors[3].setTotalDadPoints(83150);

    neighbors[4].setName("Mark");
    // neighbors[4].setPicture("???");
    neighbors[4].setAestheticID(1);
    neighbors[4].setArchetypeID(1);
    neighbors[4].setTotalDadPoints(80950);

    neighbors[5].setName("Billiam");
    // neighbors[5].setPicture("???");
    neighbors[5].setAestheticID(3);
    neighbors[5].setArchetypeID(0);
    neighbors[5].setTotalDadPoints(74560);

    neighbors[6].setName("Jim");
    // neighbors[6].setPicture("???");
    neighbors[6].setAestheticID(2);
    neighbors[6].setArchetypeID(2);
    neighbors[6].setTotalDadPoints(66345);

    neighbors[7].setName("Mr. Brown");
    // neighbors[7].setPicture("???");
    neighbors[7].setAestheticID(0);
    neighbors[7].setArchetypeID(1);
    neighbors[7].setTotalDadPoints(61300);

    neighbors[8].setName("Bob");
    // neighbors[8].setPicture("???");
    neighbors[8].setAestheticID(2);
    neighbors[8].setArchetypeID(3);
    neighbors[8].setTotalDadPoints(60490);

    neighbors[9].setName("Frank");
    // neighbors[9].setPicture("???");
    neighbors[9].setAestheticID(2);
    neighbors[9].setArchetypeID(1);
    neighbors[9].setTotalDadPoints(52440);
  }
  ~Neighbors() {
    delete [] neighbors;
  }
  // GETTERS and SETTERS
  Dad &getNeighbor(int i) { return neighbors[i]; }
};

#endif
