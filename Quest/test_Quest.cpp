#include<iostream>
#include<cassert>
#include<string>
#include"Quest.h"
using namespace std;

//This is probably all out of Date
void test_MainQuest() {
    MainQuest a;
    cout << "Title: " << a.get_title() << endl;
    cout << "Time: " << a.get_time() << endl;
    cout << endl;
    MainQuest b("Host BBQ", 4);
    cout << "Title: " << b.get_title() << endl;
    cout << "Time: " << b.get_time() << endl;
    cout << endl;
};

void test_BuildupQuest() {
    BuildupQuest a;
    cout << "Title: " << a.get_title() << endl;
    cout << "Time: " << a.get_time() << endl;
    cout << "Event Points: " << a.get_event_points() << endl;
    cout << endl;
    BuildupQuest b("Clean Grill", 2, 10);
    cout << "Title: " << b.get_title() << endl;
    cout << "Time: " << b.get_time() << endl;
    cout << "Event Points: " << b.get_event_points() << endl;
    cout << endl;
};

void test_SideQuest() {
    SideQuest a;
    cout << "Title: " << a.get_title() << endl;
    cout << "Time: " << a.get_time() << endl;
    cout << "Dad Points: " << a.get_dad_points() << endl;
    cout << endl;
    SideQuest b("Mow Lawn", 1, 10);
    cout << "Title: " << b.get_title() << endl;
    cout << "Time: " << b.get_time() << endl;
    cout << "Dad Points: " << b.get_dad_points() << endl;
    cout << endl;
};

void test_ShoppingQuest() {
    ShoppingQuest a;
    cout << "Title: " << a.get_title() << endl;
    cout << "Time: " << a.get_time() << endl;
    cout << "Multiplier: " << a.get_multiplier() << endl;
    cout << endl;
    ShoppingQuest b("Buy Lawnmower", 1, 5);
    cout << "Title: " << b.get_title() << endl;
    cout << "Time: " << b.get_time() << endl;
    cout << "Multiplier: " << b.get_multiplier() << endl;
    cout << endl;
};

int main() {
    test_MainQuest();
    test_BuildupQuest();
    test_SideQuest();
    test_ShoppingQuest();
}