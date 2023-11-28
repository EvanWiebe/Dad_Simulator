
#include <iostream>
#include <string> // for string class
using namespace std;
//#include "Weekly_information.h"
#include"/usr/local/cs/cs251/show_mem.h"
//#include"End_of_Game.h"

#include <fstream> 

void read();
    string line;
    fstream myfile; 
    myfile.open("example.txt", ios::in); 
    if (myfile.is_open())
    {
    while ( getline (myfile,line) )
    {
        cout << line << '\n';
    }
    myfile.close();
    }

    else cout << "Unable to open file"; 

    return 0;



class End_of_Game{
private: 
    string **Ending_options;
    string *Credits;
    int dad_points;
    int number_of_needed_points = 20;

public:
    End_of_Game(int dadpoints{
        dad_points = dadpoints;
        Ending_options = {{"maaad", "baaad"}, {"sad", "depressed"},{"mad"},{"bad"}};
        Credits = read();
    }
    void set_ending(int dad_p, int number_of_needed_p);
    string* play_credits();


};

    
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
}

int main(){
    End_of_Game r;
}
    

