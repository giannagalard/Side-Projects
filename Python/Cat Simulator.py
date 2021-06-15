print('''
         *                  *
             __                *
          ,db'    *     *
         ,d8/       *        *    *
         888
         `db\       *     *
           `o`_                    **
      *               *   *    _      *
            *                 / )
         *    (\__/) *       ( (  *
       ,-.,-.,)    (.,-.,-.,-.) ).,-.,-.
      | @|  ={      }= | @|  / / | @|o |
     _j__j__j_)     `-------/ /__j__j__j_
     ________(               /___________
      |  | @| \              || o|O | @|
      |o |  |,'\       ,   ,'"|  |  |  |  hjw
     vV\|/vV|`-'\  ,---\   | \Vv\hjwVv\//v
                _) )    `. \ /
               (__/       ) )
                         (_/
''')

print("Welcome to Cat Simulator!")
print("Your main objective is to find your way home.")

choice1 = input('You\'re at a dead end... Where do you want to go? Type "turn around" or "over fence"\n').lower()
if choice1 == "turn around":
    choice2 = input('As you turn around, you come across a lonely raccoon. Type "befriend" to introduce yourself to him or type "ignore" to sneak past them.\n').lower()
    if choice2 =="befriend":
        choice3 = input('You approach the raccoon and tell them you\'re lost. You tell them which area you live in and they say they know how to get there! Typer "follow" to let them show you the way or type "stranger danger" to run away\n').lower()
        if choice3 == "follow":
            print ("Congratulations! You made it home and made a new friend along the way :)")
if choice1 == "over fence":
    choice2 = input('You gracefully hop over the fence and see another group of cats playing. Type "join" to join them.\n')
    if choice2 == "join":
        print("yeah youre never making it home. Game Over")
        