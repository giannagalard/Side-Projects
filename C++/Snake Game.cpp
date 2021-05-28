#include <iostream>                                       
#include <cstdlib>                                        
#include <ctime>                                          
#include <conio.h>                                        
#include <windows.h>                                      

using namespace std; 

// end game
bool gameOver;       

// size of playing board
const int boardWidth = 30,                                
          boardLength = 15,
fieldArea = boardWidth * boardLength;

// snake head, fruit, and score counter
int headX, headY, fruitX, fruitY, score; 

// stops current direction
enum eDirection { STOP, LEFT, RIGHT, UP, DOWN } direction;

// stores tail 
int tailX[fieldArea], tailY[fieldArea];

// # of tail segments
int tailLength = 0;    

// snake movement
int speed = 50;                                        


/*
*** Start in middle of field ***
*** Random fruit position ***
*/
void newLevel()
{
     gameOver = false;
     direction = STOP;
     headX = boardWidth / 2;        
     headY = boardLength / 2;
     srand(time(NULL));                                   
     fruitX = 1 + rand() % boardWidth;
     fruitY = 1 + rand() % boardLength;
     score = 0; 
}

/*
*** Outputs to Console ***
*/
void generate()                                                             
{
     system("cls"); // clear 
     cout << " ::::::::  ::::    :::     :::     :::    ::: ::::::::::       ::::::::      :::     ::::    ::::  :::::::::: \n"
          << ":+:    :+: :+:+:   :+:   :+: :+:   :+:   :+:  :+:             :+:    :+:   :+: :+:   +:+:+: :+:+:+ :+:        \n"
          << "+:+        :+:+:+  +:+  +:+   +:+  +:+  +:+   +:+             +:+         +:+   +:+  +:+ +:+:+ +:+ +:+        \n"
          << "+#++:++#++ +#+ +:+ +#+ +#++:++#++: +#++:++    +#++:++#        :#:        +#++:++#++: +#+  +:+  +#+ +#++:++#   \n"
          << "       +#+ +#+  +#+#+# +#+     +#+ +#+  +#+   +#+             +#+   +#+# +#+     +#+ +#+       +#+ +#+        \n"
          << "#+#    #+# #+#   #+#+# #+#     #+# #+#   #+#  #+#             #+#    #+# #+#     #+# #+#       #+# #+#        \n"
          << " ########  ###    #### ###     ### ###    ### ##########       ########  ###     ### ###       ### ########## \n\n";
     cout << "Use WASD to move !, to exit click x ..." << endl << endl;
     
     /*
     *** Iterates through rows + columns of console ***
         *** generates board, snake body, and fruit ***
     */
     for (int i = 0; i < boardLength + 2; i++)
     {
          for (int j = 0; j < boardWidth + 2; j++)
          {
               if (i == 0 || i == boardLength + 1 || j == 0 || j == boardWidth + 1) 
                    cout << '±';
               else if (j == headX && i == headY)
                    cout << '*';
               else if (j == fruitX && i == fruitY) 
                    cout << "+";
               else
               {
                    bool tailPrint = false;
                    for (int k = 1; k <= tailLength; k++)  
                    {
                         if (j == tailX[k] && i == tailY[k])  
                         {
                              cout << ":";
                              tailPrint = true;
                         }
                    }
                    if (!tailPrint)   
                         cout << ' ';
               }
          }
          cout << endl;
     }
     cout << "\nSCORE:  " << score << endl;
}

/*
         *** if key is pressed,
         move in that direction ***
 */
void key() 
{
     if (_kbhit())   
     {
          switch (_getch())   
          {
          case 'a':
               direction = LEFT;
               break;
          case 's':
               direction = DOWN;
               break;
          case 'w':
               direction = UP;
               break;
          case 'd':
               direction = RIGHT;
               break;
          case 'x':
               gameOver = true;
               break;
          }
     }
}

/*
     *** CONTROLS MOVEMENT ***
*/
void movement() 
{
     tailX[0] = headX;
     tailY[0] = headY;

     // move each segment to tail
     for (int i = tailLength; i > 0; i--)
     {
          tailX[i] = tailX[i - 1];
          tailY[i] = tailY[i - 1];
     }

     // move snake head
     // based on key
     switch (direction)     
     {
     case LEFT:
          headX--;
          break;
     case RIGHT:
          headX++;
          break;
     case UP:
          headY--;
          break;
     case DOWN:
          headY++;
          break;
     }

     // move through walls 
     if (headX <= 0)        
          headX = boardWidth;
     else if (headX >= boardWidth + 1)
          headX = 1;
     else if (headY <= 0)
          headY = boardLength;
     else if (headY >= boardLength + 1)
          headY = 1;

     // if the fruit has been eaten
     if (headX == fruitX && headY == fruitY) 
     {
          score++;
          // new fruit position
          srand(time(NULL));    
          fruitX = 1 + rand() % boardWidth;
          fruitY = 1 + rand() % boardLength;
          // add segment
          tailLength++; 
          // snake speed zOOM
          if (speed > 0)  
               speed--;
     }

     // if you collide with tail, game over
     for (int j = 1; j <= tailLength; j++)
     {
          if (headX == tailX[j] && headY == tailY[j])
               gameOver = true;
     }
}

int main()
{
     newLevel();  
     while (!gameOver)
     {
          generate(); 
          key();
          movement();
          Sleep(speed); 
     }
          
     return 0; 
          
}
