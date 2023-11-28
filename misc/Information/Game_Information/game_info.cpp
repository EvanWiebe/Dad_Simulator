#include<iostream>
using namespace std;
#include"/usr/local/cs/cs251/show_mem.h"
#include"game_info.h"

#include <fstream> 
 
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