VPATH = StoreItem:Dad:Quest


a.out: display.cpp State.o update.o Quest.o StoreItem.o Dad.o
	g++ -Wall -g display.cpp State.o update.o /usr/local/cs/cs251/react.o -lcurl

State.o: State.cpp State.h Quest.o StoreItem.o Dad.o
	g++ -Wall -g -c State.cpp

update.o: State.o update.cpp
	g++ -Wall -g -c update.cpp


StoreItem.o: StoreItem.h StoreItem.cpp
	g++ -Wall -g -c StoreItem/StoreItem.cpp -o StoreItem/StoreItem.o

Dad.o: Dad.cpp Dad.h
	g++ -Wall -g -c Dad/Dad.cpp -o Dad/Dad.o

Quest.o: Quest.cpp Quest.h
	g++ -Wall -g -c Quest/Quest.cpp -o Quest/Quest.o




























