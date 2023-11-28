#include<iostream>
using namespace std;
#include"/usr/local/cs/cs251/show_mem.h"
//#include"game_info.h"

#include <fstream> 
 
void End_of_Game::set_ending( int dad_p, int number_of_needed_p){
    if (number_of_needed_p <= (dad_p * 0.75)){
        cerr << Ending_options[1] << endl;
    }
    else{
        if (number_of_needed_p <= (dad_p * 0.5)){
            cerr << Ending_options[2] << endl;
        }
        else{
            if (number_of_needed_p <= (dad_p * 0.25)){
                cerr << Ending_options[3] << endl;
            }
            else{
                cerr << Ending_options[4] << endl;
            }  
        }    
    }

    //Sets ending based on Dad points
}
string* End_of_Game::play_credits(){
    return Credits;