#ifndef __GAME_INFO__H__
#define __GAME_INFO__H__

#include <iostream>
#include <string> // for string class
using namespace std;
//#include "Weekly_information.h"

#include <fstream> 


class Game_info{
private: 
    //Weekly_information *all_weeks;
    string *dad_aesthetic_options;
    string  *dad_archetype_options;
    string ***sidequests;

    void setDadAesthetique() {
        dad_aesthetic_options = new string[3];
        dad_aesthetic_options[0] = "Flannel",
        dad_aesthetic_options[1] = "Cargo shorts",
        dad_aesthetic_options[2] = "Newbalance"
    }
    void setDadArchetype() {
        dad_archetype_options = new string[3];
        dad_archetype_options[0] = "Golpher",
        dad_archetype_options[1] = "Chef",
        dad_archetype_options[2] = "Remodeler"
    }
public:
    Game_info(){
        // dad_archetype_options = new string[9];
        // dad_archetype_options = new string[10];
        setDadAesthetique();
        setDadArchetype();
        sidequests = new string**[4];
        for(int i = 0; i<5; i++) {
            sidequests[i] = new string*[4];
            for (int j = 0; j<5; j++){
                sidequests[i][j] = new string[5];  
            } 
        }
        sidequests[1][1][1] = "hello";
        cout << sidequests[1][1][1] << endl;

    }
    void randomize_side_quest_square_types();
    char get_weekly_info();

};
    

#endif