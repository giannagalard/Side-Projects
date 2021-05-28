#basic python program (pokeshop)
print('-----------------------------------------')
print('> Welcome to the PokeStop Young Trainer! < ')
print('-----------------------------------------')

gengar = 0
togekiss = 0
clefairy= 0
ditto= 0
total=0

while(True):
  pokemon = int(input ('\nWhich Pokemon would you like to "collect"? \n\n 1. gengar \n 2. togekiss \n 3. clefairy \n 4. ditto \n 5. Exit\n\n')) 

  if (pokemon == 1):
    n = int(input ("\nHow many Gengar's would you like?\n\n"))
    gengar +=n

  elif (pokemon == 2):
    n = int(input ("\nHow many Togekiss's would you like?\n\n"))
    togekiss += n

  elif (pokemon == 3):
    n = int(input ("\nHow many Clefairy's would you like?\n\n"))
    clefairy += n

  elif (pokemon == 4):
    n = int(input ("\nHow many Ditto's would you like?\n\n"))
    ditto += n
    print(ditto)

  elif (pokemon == 5):
    print('Total: ' + str(gengar) + " gengar's " + str(togekiss) + " togekiss's " + str(clefairy) + " clefairy's " +  str(ditto) + " ditto's " )
    break

  else:
    print('\nInvalid Choice.')
