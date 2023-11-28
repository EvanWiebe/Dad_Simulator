#include<string>
#include<fstream>
using namespace std;
#include"/usr/local/cs/cs251/react.h"
#include"State.h"

// 00 - LOGIN
void display_00(State &state) {
  int login_labels[6];
  login_labels[0] = state.offset2;

  string dad_sim = "Dad Simulator";
  string login = state.getLogin();
  string enter = "Enter";
  string email_adress = state.getDad().getEmail();
  string password = state.getDad().getPassword();

  _put_tilde_terminated_string(dad_sim, _global_mem + login_labels[0]);
  login_labels[1] = login_labels[0] + dad_sim.size() + 1;
  _put_tilde_terminated_string(login, _global_mem + login_labels[1]);
  login_labels[2] = login_labels[1] + login.size() + 1;
  _put_tilde_terminated_string(enter, _global_mem + login_labels[2]);
  _put_tilde_terminated_string(email_adress, _global_mem + state.mem_pos[18]);
  _put_tilde_terminated_string(password, _global_mem + state.mem_pos[19]);

  
  //Add YAML
  _add_yaml("yaml/login/base.yaml");
    _add_yaml("yaml/login/login.yaml", { {"dad_sim", login_labels[0]}, {"login", login_labels[1]},{"enter", login_labels[2]}, });
  
}

// 01 - REGISTER
void display_01(State &state) {
// NOT IMPLIMENTED  
}

// 10 - AESTHETIC SELECT
void display_10(State &state) {
// NOT IMPLIMENTED  
}

// 20 - ARCHETYPE SELECT
void display_20(State &state) {
// NOT IMPLIMENTED  
}

// 30 - TRANSITION
void display_30(State &state) {
// NOT IMPLIMENTED  
}

// 40 - DADBOARD
void display_40(State &state) {
// NOT IMPLIMENTED  
}

// 50 - CHECKLIST
void display_50(State &state) {
// NOT IMPLIMENTED  
}

// 60 - HOME DEFAULT
void display_60(State &state) {
  int side_quest_labels[4];
  string buildup_quest = state.getQuest()
    .getWeekQuests(state.getDad().getWeekNum())
    .getBuildupQuests(state.getDad().getCurrentBuildupQuest())
    .getTitle();
  _put_tilde_terminated_string(buildup_quest, _global_mem + state.offset2);
  side_quest_labels[0] = buildup_quest.size() + 1 + state.offset2;
  // Put Side/Shopping Quests into _global_mem
  for (int i = 0; i < 4; i++) {
    string side_quest = state.getQuest().getGridQuest(state.getQuestId(i)).getTitle();
    if (state.getQuestId(i) >= state.getQuest().getSideQuestBreak()) {
      int store_item = state.getQuest().getGridQuest(state.getQuestId(i)).getStoreItemId();
      if (state.getDad().getItemLevel(store_item) == 0) {
        side_quest = "Buy:\n" + side_quest;
      } else {
        side_quest = "Upgrade:\n" + side_quest;
      }
    }
    _put_tilde_terminated_string(side_quest, _global_mem + side_quest_labels[i]);
    if (i != 3) {
      side_quest_labels[i+1] = side_quest_labels[i] + side_quest.size() + 1;
    }
  }
  // Add YAML
  _add_yaml("yaml/home/top.yaml");
    _add_yaml("yaml/home/top_quest.yaml", { {"index", state.offset2} });
      for (int i = 0; i < 4; i++) {
        string button_id = "sidequest_" + to_string(i+1);
        string color;
        if (state.getQuestId(i) < state.getQuest().getSideQuestBreak()) {
          color = "lightblue";
        } else {
          color = "cornflowerblue";
        }
        _add_yaml("yaml/home/top_quest_item.yaml", { {"i", button_id}, { "index", side_quest_labels[i]}, {"color", color} });
      }
  _add_yaml("yaml/home/bottom.yaml", {
    {"checklist", "https://upload.wikimedia.org/wikipedia/commons/thumb/9/9d/Checklist_Noun_project_5166_yellow.svg/768px-Checklist_Noun_project_5166_yellow.svg.png?20150724212244"},
    {"dadboard", "https://clipart.world/wp-content/uploads/2020/12/Icon-Trophy-clipart-transparent.png"},
    {"profile", state.getDad().getPicture()},
  });
}

//61 - HOME W/CHECKLIST
void display_61(State &state) {
  int positions[7];
  positions[0] = state.offset2;
  
  string checklist_title = "Checklist";
  _put_tilde_terminated_string(checklist_title, _global_mem + positions[0]);
  positions[1] = positions[0] + checklist_title.size()+1;
  
  for (int i = 0; i < 6; i++) {
    string buildup_quest = state.getQuest().getWeekQuests(state.getDad().getWeekNum()).getBuildupQuests(i).getTitle();
    _put_tilde_terminated_string(buildup_quest, _global_mem+positions[i+1]);
    if (i != 5) {
      positions[i+2] = positions[i+1] + buildup_quest.size() + 1;
    }
  }
  //Add YAML
  _add_yaml("yaml/home/top.yaml");
    _add_yaml("yaml/home/top_checklist.yaml", { {"title", positions[0]} });
    //loop
    for (int i = 0; i < 6; i++) {
      string color;
      if (i < state.getDad().getCurrentBuildupQuest()) {
        color = "red";
      } else {
        color = "white";
      }
      _add_yaml("yaml/home/top_checklist_item.yaml", { {"checked", color}, {"quest", positions[i+1]} });
    }
  _add_yaml("yaml/home/bottom.yaml", {
    {"checklist", "https://www.driversupport.com/wp-content/uploads/2019/04/red-x-on-network-icon.png"},
    {"dadboard", "https://clipart.world/wp-content/uploads/2020/12/Icon-Trophy-clipart-transparent.png"},
    {"profile", state.getDad().getPicture()},
  });
}

//62 - HOME W/DADBOARD
void display_62(State &state) {
  int total_num = 47;
  int positions[total_num];
  int num = 0;
  int length = state.getNeighbors().num_neighbors;
  int dad_postion = 1;
  positions[num] = state.offset2;
  string dadboard = "DadBoard";
  int for_points = 1;
  bool dad;

  _put_tilde_terminated_string(dadboard, _global_mem + positions[num]);
  num++; // 1
  positions[num]= positions[num-1] + dadboard.length() + 1; // += 10;

  //for
  for (int j = 1; j < length; j++) {
    int points =  state.getNeighbors().getNeighbor(j).getTotalDadPoints();
    if (state.getDad().getTotalDadPoints() < points) {
      if (dad_postion !=10){
        dad_postion ++;
        dad = true;
        _put_int(j, _global_mem + positions[num], 2);
      }
    }
    if (state.getDad().getTotalDadPoints() > points){
      if (dad == true){
        _put_int(j+1, _global_mem + positions[num], 2);
        dad = false;
      }
      else{
        _put_int(j+1, _global_mem + positions[num], 2);
      }
    }
    num++; // 2
    positions[num]= positions[num-1] + 2;
    _put_tilde_terminated_string("~", _global_mem + positions[num]); //tilde postion 2 
    num++; // 3
    positions[num] =positions[num-1] + 1;
    string name = state.getNeighbors().getNeighbor(j).getName();
    _put_tilde_terminated_string(name, _global_mem +positions[num]); //name postion 3
    num++; // 4
    positions[num] =  positions[num-1] + name.size()+1;
    _put_int(points, _global_mem +positions[num], 7);
    num++; // 5
    positions[num] =  positions[num-1] + 7;
    _put_tilde_terminated_string("~", _global_mem + positions[num]); //tilde postion 5
    num++; //6
    positions[num] =  positions[num-1] + 1;
  }

  _put_int(dad_postion, _global_mem + positions[num], 2);
  num++; 
  positions[num]= positions[num-1] + 3;
  _put_tilde_terminated_string("~", _global_mem + positions[num]);

  //Add YAML
  _add_yaml("yaml/home/top.yaml");
    _add_yaml("yaml/home/top_dadboard.yaml", { {"dadboard", positions[0]} });
    int index = 1;
    //for loop 
    for (int k = 1; k < total_num-1;) {
      if (dad_postion == index){
      _add_yaml("yaml/home/top_dadboard_item.yaml", {
        {"place", positions[total_num-1]}, 
        {"name", state.mem_pos[1]},
        {"points", state.mem_pos[4]},
        }); 
        index +=1;
      }
      else{
      _add_yaml("yaml/home/top_dadboard_item.yaml", {
        {"place", positions[k]}, 
        {"name", positions[k+2]},
        {"points", positions[k+3]},
        });
        index +=1; 
      k += 5;
      }
    }

    _add_yaml("yaml/home/top_dadboard_user.yaml",{
        {"usrPlace", positions[total_num-1]}, 
        {"usrName", state.mem_pos[1]},
        {"usrPoints", state.mem_pos[4]},
      });
  
  _add_yaml("yaml/home/bottom.yaml", {
    {"checklist", "https://upload.wikimedia.org/wikipedia/commons/thumb/9/9d/Checklist_Noun_project_5166_yellow.svg/768px-Checklist_Noun_project_5166_yellow.svg.png?20150724212244"},
    {"dadboard", "https://www.driversupport.com/wp-content/uploads/2019/04/red-x-on-network-icon.png"},
    {"profile", state.getDad().getPicture()},
  });
}

//63 - HOME W/PROFILE
void display_63(State &state) {
  int item_positions[Store::num_items];
  //Add mem
  _put_tilde_terminated_string(state.getDad().getArchetype(), _global_mem + state.offset2); // limit archetype to 20 characters
  item_positions[0] = state.offset2 + 21;
  int pos = 0;
  for (int i = 0; i < Store::num_items; i++) {
    if (state.getDad().getItemLevel(i)) { /* zero returns false*/ 
      string item_string = state.getStore().items[i].getLevelName(state.getDad().getItemLevel(i));
      _put_tilde_terminated_string(item_string, _global_mem + item_positions[pos]);
      if (i != 9) {
        item_positions[pos+1] = item_positions[pos] + item_string.length() + 1;
      }
      pos++;
    }
  }
  //Add YAML
  _add_yaml("yaml/home/top.yaml");
    _add_yaml("yaml/home/top_profile.yaml", {
      {"dad_image", state.getDad().getPicture()},
      {"name", state.mem_pos[1]},
      {"archetype", state.offset2},
      {"dad_points", state.mem_pos[4]},
      {"week", state.mem_pos[6]}
    });
    int yaml_pos = 0;
    for (int i = 0; i < Store::num_items; i++) {
      if (state.getDad().getItemLevel(i)) {
        _add_yaml("yaml/home/top_profile_item.yaml", {
          {"item_image", state.getStore().items[i].getLevelImage(state.getDad().getItemLevel(i))},
          {"item_level", state.mem_pos[11]+(i*2)},
          {"item_name", item_positions[yaml_pos]}
        });
        yaml_pos++;
      }
    }
  _add_yaml("yaml/home/bottom.yaml", {
    {"checklist", "https://upload.wikimedia.org/wikipedia/commons/thumb/9/9d/Checklist_Noun_project_5166_yellow.svg/768px-Checklist_Noun_project_5166_yellow.svg.png?20150724212244"},
    {"dadboard", "https://clipart.world/wp-content/uploads/2020/12/Icon-Trophy-clipart-transparent.png"},
    {"profile", "https://www.driversupport.com/wp-content/uploads/2019/04/red-x-on-network-icon.png"}
  });
}

void display(State &state) {
  _put_int(state.getId(), _global_mem + state.mem_pos[0], 2);
  _put_tilde_terminated_string(state.getDad().getName(), _global_mem + state.mem_pos[1]);
  _put_int(state.getDad().getAestheticID(), _global_mem + state.mem_pos[2], 1);
  _put_int(state.getDad().getArchetypeID(), _global_mem + state.mem_pos[3], 1);
  _put_int(state.getDad().getTotalDadPoints(), _global_mem + state.mem_pos[4], 7);
  _put_float(state.getDad().getPassiveIncome(), _global_mem + state.mem_pos[5], 4);
  _put_int(state.getDad().getWeekNum(), _global_mem + state.mem_pos[6], 2);
  _put_int(state.getDad().getCurrentBuildupQuest(), _global_mem + state.mem_pos[7], 1);
  _put_int(state.getDad().getTimelineDay(), _global_mem + state.mem_pos[8], 1);
  _put_float(state.getDad().getTimelineHours(), _global_mem + state.mem_pos[9], 5);
  _put_int(state.getDad().getNumItems(), _global_mem + state.mem_pos[10], 2);
  for (int i = 0; i < Store::num_items; i++) {
    _put_int(state.getDad().getItemLevel(i), _global_mem + state.mem_pos[11] + 2*i, 1);
  }
  _put_int(state.getDad().getCurrentBuildupQuest(), _global_mem + state.mem_pos[12], 1);
  _put_int(state.getQuestId(0), _global_mem + state.mem_pos[13], 3);
  _put_int(state.getQuestId(1), _global_mem + state.mem_pos[14], 3); 
  _put_int(state.getQuestId(2), _global_mem + state.mem_pos[15], 3);
  _put_int(state.getQuestId(3), _global_mem + state.mem_pos[16], 3);
  
  _add_yaml("yaml/root.yaml");
  
  switch(state.getId()) {
    case 00: // DISPLAY LOGIN
      display_00(state);
      break;
    case 01: // DISPLAY LOGIN (REGISTER)
      display_01(state);
      break;
    case 10: // DISPLAY AESTHETIC SELECT
      display_10(state);
      break;
    case 20: // DISPLAY ARCHETYPE SELECT
      display_20(state);
      break;
    case 30: // DISPLAY TRANSITION
      display_30(state);
      break;
    case 40: // DISPLAY DADBOARD
      display_40(state);
      break;
    case 50: // DISPLAY CHECKLIST
      display_50(state);
      break;
    case 60: // DISPLAY HOME QUESTS
      display_60(state);
      break;
    case 61: // DISPLAY HOME CHECKLIST
      display_61(state);
      break;
    case 62: // DISPLAY HOME DADBOARD
      display_62(state);
      break;
    case 63: // DISPLAY HOME PROFILE
      display_63(state);
      break;
    default:
      cerr << "Couldn't display: Invalid page ID." << endl;
      break;
  }
}

int main() {
  _read_event_info_file("event_info"); //need event info

  if (! _just_starting()) {
    _read_global_mem_from_file("begin_mem");
  } else {
    _read_global_mem_from_file("blank_mem.txt");
  }

  State state;
  state.read_from(_global_mem);

  state.update();
  display(state);
  
  _write_global_mem_to_file("end_mem");
  _write_global_yaml_to_file("react.yaml");
  delete[] _global_mem;
}


// g++ -Wall display.cpp State.o update.o /usr/local/cs/cs251/react.o -lcurl
// ./a.out

// /usr/local/cs/cs251/frame.py
// /usr/local/cs/cs251/bridge.py

// http://anansi.stolaf.edu/sd/local/?TO=rns202-[MACHINE INT].cs.stolaf.edu:[PORT]
// http://anansi.stolaf.edu/sd/local/?TO=rns202-4.cs.stolaf.edu:25126 PETER
// http://anansi.stolaf.edu/sd/local/?TO=rns202-10.cs.stolaf.edu:25112  EVAN
