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

int main() {
     // naming players
     guest1.name = "Player 1"; 
     guest2.name = "Player 2";

     accountInfo list;
     
     // create txt file that holds 
     // users, then extract the number
     // of accounts in file starting at
     // the first line and using it to
     // detect the end of file
     fstream file("users.txt" ios::in);
     file >> accountNum;
     file.ignore();

     // read the number stored in accountNum and read
     // all the user names of current account
     for (int count = 0; count < accountNum; count++) {
          accountInfo user;
          readUsersFromFile(user, file);
          list.push_back(user); // stores user in list
     }

     file.close(); // close file

     // menu options
     int userChoice = 0,
          userChoiceSize;
     string username,
            password;

     // title 
     string title[3] = { "::::::::::: ::::::::::: ::::::::       ::::::::::: :::      ::::::::       ::::::::::: ::::::::  :::::::::: \n"
                         "    :+:         :+:    :+:    :+:          :+:   :+: :+:   :+:    :+:          :+:    :+:    :+: :+:        \n"
                         "    +:+         +:+    +:+                 +:+  +:+   +:+  +:+                 +:+    +:+    +:+ +:+        \n"
                         "    +#+         +#+    +#+                 +#+ +#++:++#++: +#+                 +#+    +#+    +:+ +#++:++#   \n"
                         "    +#+         +#+    +#+                 +#+ +#+     +#+ +#+                 +#+    +#+    +#+ +#+        \n"
                         "    #+#         #+#    #+#    #+#          #+# #+#     #+# #+#    #+#          #+#    #+#    #+# #+#        \n"
                         "    ###     ########### ########           ### ###     ###  ########           ###     ########  ########## \n" 
                       };


     while (userChoice != 4) {
          // display title
          for (int i = 0; i < 3; i++)
               cout << title[i];
     
          cout << endl;

          cout << "Welcome, choose an option to continue !\n"
                  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                  "1. Login\n"
                  "2. Sign up\n"
                  "3. Play as a guest\n"
                  "4. QUIT\n\n";
          cin >> userChoice;
     }
}