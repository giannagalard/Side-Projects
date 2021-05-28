/*
This program allows the user to buy coffee in any size and in any number of cups, shows
the total number of cups of each size sold, shows the total amount of coffee sold, and
shows the total money made.
*/
#include <iostream>
#include <iomanip>
 
using namespace std;
// named constants
const double smallCost = 2.75;
const int smallSize = 9;
const double mediumCost = 2.90;
const int mediumSize = 12;
const double largeCost = 3.00;
const int largeSize = 15;
// declaring functions
void menu();
void business(int & smallSold, int & mediumSold, int & largeSold, int & coffee, double & profit); // & for ref
void cupsSold(int small, int medium, int large);
void ozSold(int totalCoffee);
void revenue(double profit);
 
int main()
{
 int order;
 int coffee = 0;
 int smallSold = 0, mediumSold = 0, largeSold = 0;
 bool quit = false;
 double profit = 0;
// opening output statement  // greeting
cout << "                      Hello, Welcome to Mochi's Cafe °˖✧◝(⁰▿⁰)◜✧˖°ﾟ" << endl;
while(!quit)
 {
   // displaying menu
   menu();
   cout << " "<< endl;
   cout << "                      |Please Select an Option: ";
   cin >> order;
   {
     switch(order)
     {
       case 1: // selling
         business(smallSold, mediumSold, largeSold, coffee, profit);
         break;
       case 2: // sold stats
         cupsSold(smallSold, mediumSold, largeSold);
         break;
       case 3: // sold stats
         ozSold(coffee);
         break;
       case 4: // money stats
         revenue(profit);
         break;
       case 5: // set boolean to true for quit
         quit = true;
         break;
       default: cout << "                      ERROR / (⁎˃ᆺ˂)＼ PLEASE TRY AGAIN ✧˖°:" << endl;
     }
   }
}}
// function that outputs menu options
void menu()
{
 cout << " "<< endl;
 cout << "                                    ︵‿︵‿୨♡୧‿︵‿︵"<< endl;
 cout << "                                        M E N U" << endl;
 cout << "                       ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"<< endl;
 cout << "                      |  1.     ♡ B U Y  A  C O F F E E ♡          |" << endl;
 cout << "                      |  2.   ♡  T O T A L  C U P S  S O L D ♡     |" << endl;
 cout << "                      |  3. ♡ T O T A L  C O F F E E  S O L D ♡    |" << endl;
 cout << "                      |  4.          ♡ R E V E N U E ♡             |" << endl;
 cout << "                      |  5.            ♡ E X I T ♡                 |" << endl;
 cout << "                       ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
}
// function that sells coffee
void business(int & smallSold, int & mediumSold, int & largeSold, int & totalSold, double & revenue)
{
 int size;
 bool uwu = true;
 while(uwu)
 {
   cout << " " << endl;
   cout << "                                   ꘎♡━━━━━━━━━━━━━━♡꘎" << endl;
   cout << "                                  PLEASE SELECT A SIZE " << endl;
   cout << "                                  ⭒☆━━━━━━━━━━━━━━━━☆⭒" << endl;
   cout << "                      | 1. S M A L L ( 9oz )" << endl;
   cout << "                      | 2. M E D I U M ( 12oz )" << endl;
   cout << "                      | 3. L A R G E ( 15oz )" << endl;
   cout << "                      | 4. E X I T" << endl;
   cout << "                      | ";
   cin >> size;
  
   if(size == 4)
   {
     uwu = false;
   }
   else if(size == 1)
   {
     smallSold += 1;
     totalSold += 9;
     revenue += 2.75;
   }
   else if(size == 2)
   {
     mediumSold += 1;
     totalSold += 12;
     revenue += 2.90;
   }
   else if(size == 3)
   {
     largeSold += 1;
     totalSold += 15;
     revenue += 3.00;
   }
   else
     cout << "ERROR / (⁎˃ᆺ˂)＼ PLEASE TRY AGAIN ✧˖°:" << endl;
 }
}
// function that outputs cups sold
void cupsSold(int small, int medium, int large)
{
 cout << " " << endl;
 cout << "                      ━━━━━━━━━━━━━━━━━━━━" << endl;
 cout << setprecision(0) << fixed << "                      |Small Cups Sold: " << small << endl;
 cout << setprecision(0) << fixed << "                      |Medium Cups Sold: " << medium << endl;
 cout << setprecision(0) << fixed << "                      |Large Cups Sold: " << large << endl;
 cout << "                      ━━━━━━━━━━━━━━━━━━━━" << endl;
}
// function that prints total oz of coffee sold
void ozSold(int totalCoffee)
{
 cout << " " << endl;
 cout << "                       ━━━━━━━━━━━━━━━━━━━━━━━" << endl;
 cout << setprecision(0) << fixed << "                      | Total Coffee Sold: " << totalCoffee << "oz" << endl;
 cout << "                       ━━━━━━━━━━━━━━━━━━━━━━━" << endl;
 }
// function that prints revenue
void revenue(double profit)
{
 cout << " " << endl;
 cout << "                       ━━━━━━━━━━━━━━━━━━━━━" << endl;
  cout << setprecision(2) << fixed << "                      |Total Revenue: $" << profit << endl;
 cout << "                       ━━━━━━━━━━━━━━━━━━━━━" << endl;
}
