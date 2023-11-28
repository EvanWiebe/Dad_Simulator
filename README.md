# Dad Simulator Working Demo

## Team Members
Henry Geffert, Evan Wiebe, Peter Fortier

## Summary
**Dad SimulatorTM** is a point and click adventure game where you compete against other neighbors to be the best dad on the block. Completing random dad-related quests, collecting dad-related items, and working towards major end-of-week milestones like teaching your kid to drive boost your Dad Points on the Dadboard. At the end of the game, see how you matched up to other dads.

## Commands to Run
If you have access to the `Makefile`, all you need to get the game to compile is the `make` command. Otherwise, use the commands below:

> `g++ -Wall -c StoreItem/StoreItem.cpp -o StoreItem/StoreItem.o`
>
> `g++ -Wall -c Dad/Dad.cpp -o Dad/Dad.o`
>
> `g++ -Wall -c Quest/Quest.cpp -o Quest/Quest.o`
>
> `g++ -Wall -c State.cpp`
>
> `g++ -Wall -c update.cpp`
>
> `g++ -Wall display.cpp State.o update.o /usr/local/cs/cs251/react.o -lcurl`

Once you have the `a.out` file, execute it with
> `./a.out`

In another terminal working from the same `dad_sim` directory, use the command below to start the game running:
> `/usr/local/cs/cs251/bridge.py`

In a browser window, use the following web address with your actual running **machine integer** and **port**:
> `http://anansi.stolaf.edu/sd/local/?TO=rns202-[MACHINE INT].cs.stolaf.edu:[PORT]`

*HINT*: you can find your port after running `bridge.py` after the `stolaf.edu:` in an output like this:
> `Starting httpd at rns202-4.cs.stolaf.edu:25126`