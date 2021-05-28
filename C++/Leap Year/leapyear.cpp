/*
    
           /$$                                                                            
          | $$                                                                            
          | $$  /$$$$$$   /$$$$$$   /$$$$$$        /$$   /$$  /$$$$$$   /$$$$$$   /$$$$$$               __ ____    ___  ____ ______   ___ ___        ____  __ __       
          | $$ /$$__  $$ |____  $$ /$$__  $$      | $$  | $$ /$$__  $$ |____  $$ /$$__  $$             /  ]    \  /  _]/    |      | /  _]   \      |    \|  |  |
          | $$| $$$$$$$$  /$$$$$$$| $$  \ $$      | $$  | $$| $$$$$$$$  /$$$$$$$| $$  \__/            /  /|  D  )/  [_|  o  |      |/  [_|    \     |  o  )  |  |
          | $$| $$_____/ /$$__  $$| $$  | $$      | $$  | $$| $$_____/ /$$__  $$| $$                 /  / |    /|    _]     |_|  |_|    _]  D  |    |     |  ~  | 
          | $$|  $$$$$$$|  $$$$$$$| $$$$$$$/      |  $$$$$$$|  $$$$$$$|  $$$$$$$| $$                /   \_|    \|   [_|  _  | |  | |   [_|     |    |  O  |___, |
          |__/ \_______/ \_______/| $$____/        \____  $$ \_______/ \_______/|__/                \     |  .  \     |  |  | |  | |     |     |    |     |     |
                                  | $$             /$$  | $$                                         \____|__|\_|_____|__|__| |__| |_____|_____|    |_____|____/ 
                                  | $$            |  $$$$$$/                              
                                  |__/             \______/                                                        ___________________________________     
                                                                                                                   |      Joseph D + Gianna G        |
                                                                                                                   ```````````````````````````````````

                                   ___________________________              ______________________________________________________________ 
                                  /__________________________/|            /_____________________________________________________________/|
                                  |  ** Basic analysis: **  | |            |                ** Extended analysis: **                    | |
                                  | input - dates from file | |            |Take all of my previous labs and create function algorithm: | |
                                  | output - dates to file  | |            |                  sep each block of code                    | |
                                  |```````````````````````````/            |``````````````````````````````````````````````````````````````/
                                  \__________________________/             \_____________________________________________________________/
*/


#include<iostream>
#include <fstream>
#include <string>

using namespace std;

//function to check if 
//the year entered is 
//a leap year
bool isLeap(int year) {
     // divisible by 400
     if (year % 400 == 0) 
          return true;
     // divisible by 100
     if (year % 100 == 0) 
          return false;
     // divisible by 4
     if (year % 4 == 0)
          return true;
     return false;
}

//function to detemine days in month
int days_in_month(int month, int year)

{
     // if it's feburary or 
     // month 2, call isLeap
     if (month == 2)
     {
          if (isLeap(year)) {
               return 29;
          }
          else {
               return 28;
          }
     }
     else {
          // if not february
          // return day amount
          switch (month) 
          {
          case 1:
          case 3:
          case 5:
          case 7:
          case 8:
          case 10:
          case 12:
               return 31;
               break;
          case 4:
          case 6:
          case 9:
          case 11:
               return 30;
               break;
          }
     }
     return 0;
}
//function to determine days in the year
int days_in_year(int day, int month, int year) {
     int days = 0;
     // call days_in_month for each month 
     // of the year, and add to days
     for (int i = 1; i < month; i++) {
          days += days_in_month(i, year); 
     }
     days += day;
     return days;
}
//function to find day value
int day_value(int day, int month, int year) {
     int day_value = 0;
     // starting value -> 1900
     for (int i = 1900; i < year; i++) 
     {    // call isLeap, check
          if (isLeap(i) == true) 
          {
               day_value += 366;
          }
          else {
               day_value += 365;
          }
     }
     // calculate and return day_value
     day_value += days_in_year(day, month, year); 
     return day_value;
}
// function to find day of week
string day_of_week(int day, int month, int year) {

     // call day_value, and using modulo 7
     // find day of the week "value"
     int weekday = (int)day_value(day, month, year) % 7; 

     switch (weekday) {
     case 0:
          return "Sunday";
     case 1:
          return "Monday";
     case 2:
          return "Tuesday";
     case 3:
          return "Wednesday";
     case 4:
          return "Thursday";
     case 5:
          return "Friday";
     case 6:
          return "Saturday";
     default:
          break;
     }
     return "";
}

int main() {
     int day = 0, 
         month = 0, 
         year = 0;
     ifstream open;
     ofstream display;

     // read in txt file for data
     ifstream open("input.txt"); 
     // output data in txt file
     ofstream display("output.txt"); 
     while (open >> day >> month >> year) display << day_of_week(day, month, year) << " " << month << "/" << day << "/" << year <<
          " Has a day value of " << day_value(day, month, year) << "\n";
}
