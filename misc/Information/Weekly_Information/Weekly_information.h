#ifndef __WEEK_H__
#define __WEEK_H__

#include<iostream>
#include<string>
#include"Quest.h"

class Week {
private:
  string season;
  string age_group;
  MainQuest *main_quest = nullptr;
  BuildupQuest *buildup_quests = nullptr; // array[6], made once
  SideQuest *side_quests = nullptr; // array[var length], remade on random quest updates
  ShoppingQuest *shopping_quests = nullptr; // array[var length], remade on random quest updates

  // PRIVATE METHODS
  void newBuildupQuests(BuildupQuest *b) {
    delete [] buildup_quests;
    buildup_quests = new BuildupQuest[6];
    for (int i = 0; i < 6; i++) {
      buildup_quests[i] = b[i];
    }
  }

  void randomize_side_quests();
  void trigger_main_event();


public:
  // default CONSTRUCTOR
  Week() {
    week_num = 0;
    season = "";
    age_group = "";
    timeline_hours = 0.;
    timeline_day = 0;
  }
  // simple CONSTRUCTOR
  Week(int w, string s, string a) {
    week_num = w;
    season = s;
    age_group = a;
    timeline_hours = 0.;
    timeline_day = 0;
  }
  // single-items CONSTRUCTOR
  Week(int w, string s, string a, MainQuest m) {
    week_num = w;
    season = s;
    age_group = a;
    delete main_quest;
    main_quest = new MainQuest(m.getTitle(), ); // ISSUE
    timeline_hours = 0.;
    timeline_day = 0;
  }
  // no-changes CONSTRUCTOR
  Week(int w, string s, string a, MainQuest m, BuildupQuest *b) {
    week_num = w;
    season = s;
    age_group = a;
    delete main_quest;
    main_quest = new MainQuest(m...; // ISSUE
    newBuildupQuests(b);
    timeline_hours = 0.;
    timeline_day = 0;
  }
  // GETTERS
  int getWeekNum() { return week_num; }
  string getSeason() { return season; }
  string getAgeGroup() { return age; }
  MainQuest *getMainQuest() { return main_quest; }
  BuildupQuest *getBuildupQuest() { return buildup_quests; }
  SideQuest *getSideQuests() { return side_quests; }
  ShoppingQuest *getShoppingQuests() { return shopping_quests; }
  float getTimelineHours() { return timeline_hours; }
  int getTimelineDay() { return timeline_day; }
  // SETTERS definitions
  void setBuildupQuests(BuildupQuest *b) { newBuildupQuests(b); }
  void setTimelineHours(float h) { timeline_hours = h; }
  void setTimelineDay(int d) { timeline_day = d; }
  // SETTERS declarations
  void setSideQuests()... /////////////////////////////////////
  // DESTRUCTOR
  ~Week() {
    delete main_quest;
    delete [] buildup_quests;
    delete [] side_quests;
    delete [] shopping_quests;
  }
};


#endif