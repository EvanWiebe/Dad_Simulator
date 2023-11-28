#ifndef __GRID_H__
#define __GRID_H__

#include <iostream>
#include <string> // for string class
using namespace std;


class End_of_Game{
private: 
    char *Ending_options;
    char *Credits;

public:
    void set_ending(int dad_points, int number_of_needed_points);
    void play_credits(int number);


};
    

#endif