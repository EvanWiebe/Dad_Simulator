#include <iostream>
#include <string>
#include"/usr/local/cs/cs251/react.h"
using namespace std;
#include "State.h"

//NEW READ
void State::read_from(char *mem){
  setId(_get_int(mem + State::mem_pos[0],2));
  getDad().setName(_get_tilde_terminated_string(_global_mem+ State::mem_pos[1]));
  getDad().setAestheticID(_get_int(mem + State::mem_pos[2], 1));
  getDad().setArchetypeID(_get_int(mem + State::mem_pos[3], 1));
  getDad().setTotalDadPoints(_get_int(mem + State::mem_pos[4], 7));
  getDad().setPassiveIncome(_get_float(mem + State::mem_pos[5], 4));
  getDad().setWeekNum(_get_int(mem + State::mem_pos[6], 2));
  getDad().setCurrentBuildupQuest(_get_int(mem + State::mem_pos[7], 1));
  getDad().setTimelineDay(_get_int(mem + State::mem_pos[8], 1));
  getDad().setTimelineHours(_get_float(mem + State::mem_pos[9], 5));
  getDad().setNumItems(_get_int(mem + State::mem_pos[10], 2));
  for(int i= 0; i< 8; i++){
    getDad().setItemLevel(i,_get_int(mem + State::mem_pos[11] + (2*i), 1));
  }
  getDad().setCurrentBuildupQuest(_get_int(mem + State::mem_pos[12], 1));
  for (int i = 0; i < 4; i++) {
    setQuestId(i, _get_int(mem + State::mem_pos[13+i], 3));
  }
}
