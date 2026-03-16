#writen by Noah Marchman
#9-29-2022

import random
gameOver = False

while gameOver == False:
    print("Welcome to my guessing game!\nToday you will be guessing my age on a scale from 1 - 75.\nYou will have 15 tries!")
    age = random.randint(1, 75)
    numberOfGuesses = 0
    while numberOfGuesses < 15:
        print("Guess " + str(numberOfGuesses+1) + ":")
        guess = (int(input()))
        numberOfGuesses += 1
        if age > guess:
            print("Thank you I was I was that young again Try Again!")
        elif age < guess:
            print("You really thing im that old Try again!")
        elif age == guess:
            print("Congrats you got my age in only " + str(numberOfGuesses) + " guesses!")
            break
    if age == guess:
        playAgain = input('Do you wanna play again?\nYes or No')
        if playAgain.lower() == 'no'.lower():
            gameOver = True
            break           
    elif age != guess and numberOfGuesses > 14:
        print("You Failed to guess my age in 15 guesses. What a shame:(")
        print("Do you wanna play again?\nYes or No")
        playAgain = input()
        if playAgain.lower() == 'no'.lower():
            gameOver = True
            break

            
    


        
