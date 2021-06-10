import pyautogui  # pip3 install -r requirements.txt
import time  

#NOTE : THIS WILL GO ON FOREVER UNTIL YOU STOP IT
# TO STOP IT, TAB BACK INTO CMD AND CTRL Z

script = 'spam spam spam insert whichever phrase u want here ... i like using the bee movie script'

input('PRESS ENTER TO UNLEASH HELL')
print('3!')
time.sleep(1)
print('2!')
time.sleep(1)
print('1!')
time.sleep(1)

while True:
    for word in script.split():  # splits so only 1 word is entered at a time
        pyautogui.write(word)
        pyautogui.press('enter')