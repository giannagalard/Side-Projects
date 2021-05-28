
import random

input("Welcome to Rock, Paper, Scissors! Press Enter to start.")
print()
userScore = 0
compScore = 0

choices = ["rock", "paper", "scissors"]

while True:
  random_index = random.randint(0,2)
  compChoice = choices[random_index]

  userChoice = input("Rock, Paper, or Scissors? ").lower()
  while userChoice not in choices:
    userChoice = input("That is not a valid choice. Please try again: ").lower()
  
  print()
  print("Your choice:", userChoice)
  print("Computer's choice:", compChoice)
  print()

  if userChoice == 'rock':
    if compChoice == 'rock':
      print("It's a tie!")
    elif compChoice == 'scissors':
      print("You win!")
      userScore+=1
    elif compChoice == 'paper':
      print("You lose!")
      compScore+=1
  elif userChoice == 'paper':
    if compChoice == 'paper':
      print("It's a tie!")
    elif compChoice == 'rock':
      print("You win!")
      userScore+=1
    elif compChoice == 'scissors':
      print("You lose!")
      compScore+=1
  elif userChoice == 'scissors':
    if compChoice == 'scissors':
      print("It's a tie!")
    elif compChoice == 'paper':
      print("You win!")
      userScore+=1
    elif compChoice == 'rock':
      print("You lose!")
      compScore+=1

  print()
  print("You have "+str(userScore)+" win(s)")
  print("The computer has "+str(compScore)+" win(s)")
  print()

  repeat = input("Play again? (Y/N) ").lower()
  while repeat not in ['y', 'n']:
    repeat = input("That is not a valid choice. Please try again: ").lower()
  
  if repeat == 'n':
    break
  
  #divider
  print("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") 

