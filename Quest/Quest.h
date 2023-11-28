#ifndef __C_H__
#define __C_H__
#include<string>
#include"../StoreItem/StoreItem.h"
using namespace std;

//Classes for types of quests
//Superclass
class SuperQuest {
protected:
	string title;
	int time;
public:
	SuperQuest() : title("untitled"), time(0) {}
	SuperQuest(string titl, int tim) : title(titl), time(tim) {}
	
	int getTime() { return time; }
	void setTime(int t) { time = t; }
	string getTitle() { return title; }
	void setTitle(string t) { title = t; }

	// Virtual functions
	virtual int getDadPoints() {}
	virtual void setDadPoints(int dp) {}
	// virtual float getMultiplier() {}
	// virtual void setMultiplier(float m) {}
	virtual int getStoreItemId() {}
	virtual void setStoreItemId(int sti) {}
};

//Subclasses
class BuildupQuest : public SuperQuest {
private:
  int event_points;
public:
  BuildupQuest() : SuperQuest(), event_points(0) {}
  BuildupQuest(string titl, int tim, int mp) : SuperQuest(titl, tim), event_points(mp) {}

  int getEventPoints() {return event_points;};
	void setEventPoints(int p) { event_points = p; }
};

class MainQuest : public SuperQuest {
public:
	static const int buildup_quest_num = 6;
	BuildupQuest buildupquests[MainQuest::buildup_quest_num];
	
	MainQuest() : SuperQuest() {}
	MainQuest(string titl, int tim) : SuperQuest(titl, tim) {}

	BuildupQuest &getBuildupQuests(int i){ 
		return buildupquests[i];
	}
};

class SideQuest : public SuperQuest {
private:
  int dad_points;
public:
  SideQuest() : SuperQuest(), dad_points(0) {}
  SideQuest(string titl, int tim, int dp) : SuperQuest(titl, tim), dad_points(dp) {}

  virtual int getDadPoints() override { return dad_points; }
	virtual void setDadPoints(int dp) override { dad_points = dp; }
};

class ShoppingQuest : public SuperQuest {
private:
  // float multiplier;
	int store_item_id;
public:
  ShoppingQuest() : SuperQuest() /*, multiplier(0.0)*/ {}
  ShoppingQuest(string titl, int tim, float mul) : SuperQuest(titl, tim) /*, multiplier(mul)*/ {}

  // virtual float getMultiplier() override { return multiplier; }
	// virtual void setMultiplier(float m) override { multiplier = m; }
	virtual int getStoreItemId() override { return store_item_id; }
	virtual void setStoreItemId(int sti) override { store_item_id = sti; }
};

//Class for arrays of yearly and weekly quests
class Quest{
private:
  static const int main_quest_num = 18;
  static const int side_quest_num = 8;
	static const int shopping_quest_num = 8;
  MainQuest week_quests[Quest::main_quest_num];
  // SuperQuest grid_quests[Quest::side_quest_num];
  SuperQuest **grid_quests;
	Store store;

public:
  Quest() {
		grid_quests = new SuperQuest*[Quest::side_quest_num + Quest::shopping_quest_num];
		for (int i = 0; i < Quest::side_quest_num; i++) {
			grid_quests[i] = new SideQuest;
		}
		for (int i = Quest::side_quest_num; i < Quest::side_quest_num + Quest::shopping_quest_num; i++) {
			grid_quests[i] = new ShoppingQuest;
		}

		//Buildup quest initialization
		week_quests[0].buildupquests[0].setTitle("Build a crib");
		week_quests[0].buildupquests[0].setTime(4);
		week_quests[0].buildupquests[1].setTitle("Baby-proof house");
		week_quests[0].buildupquests[1].setTime(4);
		week_quests[0].buildupquests[2].setTitle("Hold spouse's belly");
		week_quests[0].buildupquests[2].setTime(4);
		week_quests[0].buildupquests[3].setTitle("Read books on parenting");
		week_quests[0].buildupquests[3].setTime(4);
		week_quests[0].buildupquests[4].setTitle("Take a deep breath");
		week_quests[0].buildupquests[4].setTime(4);
		week_quests[0].buildupquests[5].setTitle("Fall asleep in delivery room");
		week_quests[0].buildupquests[5].setTime(4);
		week_quests[0].setTitle("Your child is born");
		week_quests[0].setTime(12.00);

		//Side Quest Initialization
		grid_quests[0]->setTitle("Sit on porch");
		grid_quests[0]->setTime(4);
		grid_quests[0]->setDadPoints(2000);
		grid_quests[1]->setTitle("Feed the dog");
		grid_quests[1]->setTime(4);
		grid_quests[1]->setDadPoints(2500);
		grid_quests[2]->setTitle("Weedwack");
		grid_quests[2]->setTime(4);
		grid_quests[2]->setDadPoints(2000);
		grid_quests[3]->setTitle("Clear driveway");
		grid_quests[3]->setTime(4);
		grid_quests[3]->setDadPoints(3000);
		grid_quests[4]->setTitle("Walk the dog");
		grid_quests[4]->setTime(4);
		grid_quests[4]->setDadPoints(2500);
		grid_quests[5]->setTitle("Comment on lawns");
		grid_quests[5]->setTime(4);
		grid_quests[5]->setDadPoints(2000);
		grid_quests[6]->setTitle("Sneeze loudly");
		grid_quests[6]->setTime(4);
		grid_quests[6]->setDadPoints(3000);
		grid_quests[7]->setTitle("Mow the lawn");
		grid_quests[7]->setTime(4);
		grid_quests[7]->setDadPoints(3000);

		//Shopping quest items
		for (int i = 0; i < Store::num_items; i++) {
			grid_quests[Quest::side_quest_num + i]->setTitle(store.items[i].getType());
			grid_quests[Quest::side_quest_num + i]->setStoreItemId(i);
			grid_quests[Quest::side_quest_num + i]->setTime(4);
		}
  }

	//GETTERS and SETTERS
	int getMainQuestNum() const { return Quest::main_quest_num; }
	int getGridQuestNum() const { return Quest::side_quest_num + Quest::shopping_quest_num; }
	int getSideQuestBreak() const { return Quest::side_quest_num; }
	
	SuperQuest &getGridQuest(int i) { return *(grid_quests[i]); }
	MainQuest &getWeekQuests(int i){ return week_quests[i]; }

	~Quest() {
		for (int i = 0; i < Quest::side_quest_num + Quest::shopping_quest_num; i++) {
			delete grid_quests[i];
		}
		delete [] grid_quests;
	}
};

#endif
