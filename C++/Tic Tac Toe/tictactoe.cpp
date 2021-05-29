#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

/*
  account info
               */
struct account {
     string name,
          password,
          email;
     int wins,
          losses,
          draws;
};

typedef vector <account> accountInfo;

char** board;       // create board

int BOARD_SIZE = 0, // array size
modifier = 0,       // modify board size
moveCount,          // increments number of spaces
userInput,          // user input
accountNum;         // stores num of accs 

bool win,
draw,
invalidMove,
player1,       // player
cpu;           // computer


// users for gameplay
account* player1User;
account* player2User;
account* activeUser;
account guest1;
account guest2;

// function prototypes
void newGame(bool com);
int checkNum(string prompt);
int cpuTurn();
void display();
void input();
void momSaidItsMyTurn();
void update();
bool winner();
bool other();
void end();

// user function prototypes
void readUsersFromFile(account&, fstream&);
void writeUsersToFile(account&, fstream&);
account* findUser(accountInfo&, string);
void display(const account&);