#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h> 
#include <string> // for string class
using namespace std;
//#include "Weekly_information.h"
#include <map>
//template<typename Map>


#include <fstream> 
#include<iostream>
#include<fstream>
using namespace std;
#include"/usr/local/cs/cs251/show_mem.h"


class Game_info{
private: 
    //Weekly_information *all_weeks;
    string *dad_aesthetic_options;
    string  *dad_archetype_options;
    //string ***sidequests;

   
    int Perma_SQ = 0;
    int Seasonal_SQ = 1;
    int Age_related_SQ = 2;
    int Store = 3;
    int Fall = 0;
    int Winter = 1;
    int Spring = 2;
    int Summer = 3;
    int age_0_3 = 0;
    int age_4_8 = 1;
    int age_9_12 = 2;
    int age_13_18 = 2;

public:
    string ***sidequests;
    /*map<int, string> map1_of_things = {{0, "Perma_SQ",}, 
                                {1, "Seasonal_SQ",},
                                {2, "Age_related_SQ",},
                                {3, "Store",},
                                {4, "Fall",},
                                {5, "Winter",},
                                {6, "Spring",},
                                {7, "Summer",},
                                {8, "age_0_3",},
                                {9, "age_4_8",},
                                {10, "age_9_12",},
                                {11, "age_13_18",}};
    */
    Game_info(){
        _read_global_mem_from_file("info.txt");
        //cerr << "_global_mem contains " << _global_mem << endl;

        //Weekly_information *all_weeks innitalize;
        dad_archetype_options = new string[9];
        dad_archetype_options = new string[10];
        sidequests = new string**[4];
        for(int i = 0; i<5; i++) {

            sidequests[i] = new string*[4];
            for (int j = 0; j<5; j++){
                sidequests[i][j] = new string[5];  
            } 
        }
        //sidequests[1][1][1] = "hello";
        //cout << sidequests[1][1][1] << endl;



    }
    void randomize_side_quest_square_types();
    char get_weekly_info( int info);
    void read_from(const char *mem, string***sidequestss);

};

void Game_info::read_from(const char *mem, string***sidequestss) {
    int j=0;
    for(int i= 0; i <4; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 5; k++){
                sidequests[i][j][k] = string(_get_tilde_terminated_string(mem));
                mem += sidequests[i][j][k].size() +1;
                j += sidequests[i][j][k].size() +1;
                cout<< "mem is "  << j << endl;
                cout << string(sidequests[i][j][k]) << endl;
            }
        }
    }
    cout << sidequests[1][1][1] << endl;
    cout << sidequests[1][1][2] << endl;
    cout << sidequests[1][1][3] << endl;

}



void Game_info::randomize_side_quest_square_types(){
    
    //int j = template::map1_of_things[rand1];
    for (int i = 0; i < 4; i++){
        int rand1 = rand() % 3 + 0;
        if (rand1 == 0){
            cout << "Perma SQ" << endl;
            string **SD_QTST = sidequests[0];

            //send data to somewhere but I don't know where 
        }
        else{
            if  (rand1 == 1){
                cout << "Seasonal_SQ" << endl;
                string **SD_QTST = sidequests[1];
                //send data to somewhere but I don't know where 
            }
            else{
                if (rand1 == 0){
                    cout << "Age_related_SQ" << endl;
                    string **SD_QTST = sidequests[2];
                    //send data to somewhere but I don't know where 
                }
                else
                {
                    cout << "Store" << endl;
                    string **SD_QTST = sidequests[3];
                    //send data to somewhere but I don't know where s
                }
            }
        }
    }
    

    //stores quest and randomizes the quests that are displayed by the randomize quest buttion.

}
char Game_info::get_weekly_info(int info){
   // return 

    //gets the weekly info from a file 
    

}

int main(){
    Game_info f;
    f.read_from(_global_mem, f.sidequests);
    //f.randomize_side_quest_square_types();
    

}
    

