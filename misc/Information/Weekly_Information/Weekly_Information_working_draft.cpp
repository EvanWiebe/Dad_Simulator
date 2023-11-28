#include <iostream>
#include <string> // for string class
using namespace std;


class Weekly_information{
private: 
    //Main_Event *Main_events
    char *main_event_derivative_quests;
    Checklist_item *Checklist;
    char *Season;

public:
    void Randomize_side_quests();
    void Update_checklist();
    void Trigger_the_main_event();
    void randomize_side_quest_types_helper(string *seasons);
    void intialize_main();
    void Update_checklist(Checklist_item item, int location);


};


class Checklist_item{
private: 
    bool complete;
    string checklist;

};

void Weekly_information::Update_checklist(Checklist_item item, int location){
    item[location].complete = true;
    
}


 

void Weekly_information::caller(int hpt){
    //if()
}

void Weekly_information::randomize_side_quest_types_helper( string *seasons){
    
    /*//int j = template::map1_of_things[rand1];
    for (int i = 0; i < 4; i++){
        int rand1 = rand() % 3 + 0;
        if (rand1 == 0){
            cout << seasons[1]<< endl;
            string **SD_QTST = sidequests[0];

            //send data to somewhere but I don't know where 
        }
        else{
            if  (rand1 == 1){
                cout << seasons[2] << endl;
                string **SD_QTST = sidequests[1];
                //send data to somewhere but I don't know where 
            }
            else{
                if (rand1 == 0){
                    cout << seasons[3] << endl;
                    string **SD_QTST = sidequests[2];
                    //send data to somewhere but I don't know where 
                }
                else
                {
                    cout << seasons[4] << endl;
                    string **SD_QTST = sidequests[3];
                    //send data to somewhere but I don't know where s
                }
            }
        }
    }
}
*/

void Weekly_information:: intialize_main(){
        //calls main

}
    


    

