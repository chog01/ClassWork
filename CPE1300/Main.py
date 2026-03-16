# Writen by Noah Marchman for CPE1300 on 11/29/2022

import time
from pimoroni import Button
from picographics import PicoGraphics, DISPLAY_PICO_DISPLAY, PEN_RGB332

display = PicoGraphics(DISPLAY_PICO_DISPLAY)

WIDTH, HEIGHT = display.get_bounds()

Game_Over = False

#Color Definitions
Maze_color = display.create_pen(0,0,0)
Wall_color = display.create_pen(255,255,255)
Player_color = display.create_pen(0,255,0)
Bomb_color = display.create_pen(255,0,0)
End_color = display.create_pen(15,176,0)


#maze array creation
Maze = [[1,3,0,0,0,0,0,0,0,0,0,0,2,1,1,0,0,0,0,0,0,1,1,1],
        [1,0,0,1,1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,1,1],
        [1,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,1,1,1],
        [1,1,1,1,1,1,1,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1],
        [1,1,0,0,0,0,0,1,0,1,0,1,0,1,1,1,1,1,0,1,2,1,1,1],
        [1,1,0,1,1,1,0,0,0,1,0,1,0,1,1,1,1,1,0,1,1,1,1,1],
        [1,1,0,1,1,1,1,1,1,2,0,1,0,0,0,1,1,1,0,1,1,1,1,1],
        [1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1],
        [1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,1,1,1],
        [1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1],
        [1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1],
        [1,0,0,1,1,2,0,1,1,1,1,1,0,0,0,0,1,1,1,1,0,1,1,1],
        [1,1,1,1,1,1,1,1,1,1,1,1,4,1,2,1,1,1,1,1,2,1,1,1]]

#to get size of array
row = len(Maze)
col = len(Maze[0])

#to draw the maze each block is 10x10 pixels 
def DrawMaze(maze):
    for x in range(row):
        for y in range(col):
            if maze[x][y] == 1:
                display.set_pen(Wall_color)
                display.rectangle(x * 10,y * 10,10,10)
                display.update()
            elif maze[x][y] == 0 or 4 or 2:
                display.set_pen(Maze_color)
                display.rectangle(x * 10,y * 10,10,10)
                display.update()
            elif maze[x][y] == 3:
                display.set_pen(Player_color)
                display.rectangle(x * 10,y * 10,10,10)
                display.update()

DrawMaze(Maze)
  # Used to move the player            
def MoveUp(Maze):
    #checks where player is
    for x in range(row):
        for y in range(col):
            if maze[x][y] == 3:
                x = Px
                y = Py
    if Maze[Px][Py-1] == 1:
        return
    elif Maze[Px][Py-1] == 2:
        gameover = True
        display.set_pen(Bomb_color)
        display.rectangle(Px,Py,10,10)
        time.sleep(50)
        display.clear()
        display.text("Game Over", 100, 50, 500, 25, 0, 3)
        display.update()
        return gameover
    elif Maze[Px][Py-1] == 4:
        display.clear()
        display.text("Winner", 100, 50, 500, 25, 0, 3)
        display.update()
        
    elif Maze[Px][Py-1] == 0:
        Maze[Px][Py-1] = 3
        Maze[Px][Py] = 0
        return Maze
    else:
        display.clear()
        display.text("Error", 100, 50, 500, 25, 0, 3)
        display.update()
        

def MoveDown(Maze):
    #checks where player is
    for x in range(row):
        for y in range(col):
            if maze[x][y] == 3:
                x = Px
                y = Py
    if Maze[Px][Py+1] == 1:
        return
    elif Maze[Px][Py+1] == 2:
        gameover = True
        display.set_pen(Bomb_color)
        display.rectangle(Px,Py,10,10)
        time.sleep(50)
        display.clear()
        display.text("Game Over", 100, 50, 500, 25, 0, 3)
        display.update()
        return gameover
    elif Maze[Px][Py+1] == 4:
        display.clear()
        display.text("Winner", 100, 50, 500, 25, 0, 3)
        display.update()
        
    elif Maze[Px][Py+1] == 0:
        Maze[Px][Py+1] = 3
        Maze[Px][Py] = 0
        return Maze
    else:
        display.clear()
        display.text("Error", 100, 50, 500, 25, 0, 3)
        display.update()
        
    
def MoveLeft(Maze):
    #checks where player is
    for x in range(row):
        for y in range(col):
            if maze[x][y] == 3:
                x = Px
                y = Py
    if Maze[Px-1][Py] == 1:
        return
    elif Maze[Px-1][Py] == 2:
        gameover = True
        display.set_pen(Bomb_color)
        display.rectangle(Px,Py,10,10)
        time.sleep(50)
        display.clear()
        display.text("Game Over", 100, 50, 500, 25, 0, 3)
        display.update()
        return gameover
    elif Maze[Px-1][Py] == 4:
        display.clear()
        display.text("Winner", 100, 50, 500, 25, 0, 3)
        display.update()
        
    elif Maze[Px-1][Py] == 0:
        Maze[Px-1][Py] = 3
        Maze[Px][Py] = 0
        return Maze
    else:
        display.clear()
        display.text("Error", 100, 50, 500, 25, 0, 3)
        display.update()
        

def MoveRight(Maze):
    #checks where player is
    for x in range(row):
        for y in range(col):
            if maze[x][y] == 3:
                x = Px
                y = Py
    if Maze[Px+1][Py] == 1:
        return
    elif Maze[Px+1][Py] == 2:
        gameover = True
        display.set_pen(Bomb_color)
        display.rectangle(Px,Py,10,10)
        time.sleep(50)
        display.clear()
        display.text("Game Over", 100, 50, 500, 25, 0, 3)
        display.update()
        return gameover
    elif Maze[Px+1][Py] == 4:
        display.clear()
        display.text("Winner", 100, 50, 500, 25, 0, 3)
        display.update()
        
    elif Maze[Px+1][Py] == 0:
        Maze[Px+1][Py] = 3
        Maze[Px][Py] = 0
        return Maze
    else:
        display.clear()
        display.text("Error", 100, 50, 500, 25, 0, 3)
        displat.update()
        
#while loop for running the game
    while(Game_Over == False):
        DrawMaze(Maze)
        display.update()
        # Will read buttons pressed and move accordingly
        if button_a.read():
            MoveRight(Maze)
            if MoveRight(Maze) == True:
                Game_Over == True
            else:
                DrawMaze(Maze)
                display.update()
            
        elif button_b.read():
            MoveLeft(Maze)
            if MoveLeft(Maze) == True:
                Game_Over == True
            else:
                DrawMaze(Maze)
                display.update()
            
        elif button_x.read():
            MoveDown(Maze)
            if MoveDown(Maze) == True:
                Game_Over == True
            else:
                DrawMaze(Maze)
                display.update()
                
        elif button_y.read():
            MoveUp(Maze)
            if MoveUp(Maze) == True:
                Game_Over == True
            else:
                DrawMaze(Maze)
                display.update()
                
    
  # Used to move the player            
def MoveUp(Maze):
    #checks where player is
    for x in range(row):
        for y in range(col):
            if maze[x][y] == 3:
                x = Px
                y = Py
    if Maze[Px][Py-1] == 1:
        return
    elif Maze[Px][Py-1] == 2:
        gameover = True
        display.set_pen(Bomb_color)
        display.rectangle(Px,Py,10,10)
        time.sleep(50)
        display.clear()
        display.text("Game Over", 100, 50, 500, 25, 0, 3)
        display.update()
        return gameover
    elif Maze[Px][Py-1] == 4:
        display.clear()
        display.text("Winner", 100, 50, 500, 25, 0, 3)
        display.update()
        
    elif Maze[Px][Py-1] == 0:
        Maze[Px][Py-1] = 3
        Maze[Px][Py] = 0
        return Maze
    else:
        display.clear()
        display.text("Error", 100, 50, 500, 25, 0, 3)
        display.update()
        

def MoveDown(Maze):
    #checks where player is
    for x in range(row):
        for y in range(col):
            if maze[x][y] == 3:
                x = Px
                y = Py
    if Maze[Px][Py+1] == 1:
        return
    elif Maze[Px][Py+1] == 2:
        gameover = True
        display.set_pen(Bomb_color)
        display.rectangle(Px,Py,10,10)
        time.sleep(50)
        display.clear()
        display.text("Game Over", 100, 50, 500, 25, 0, 3)
        display.update()
        return gameover
    elif Maze[Px][Py+1] == 4:
        display.clear()
        display.text("Winner", 100, 50, 500, 25, 0, 3)
        display.update()
        
    elif Maze[Px][Py+1] == 0:
        Maze[Px][Py+1] = 3
        Maze[Px][Py] = 0
        return Maze
    else:
        display.clear()
        display.text("Error", 100, 50, 500, 25, 0, 3)
        display.update()
        
    
def MoveLeft(Maze):
    #checks where player is
    for x in range(row):
        for y in range(col):
            if maze[x][y] == 3:
                x = Px
                y = Py
    if Maze[Px-1][Py] == 1:
        return
    elif Maze[Px-1][Py] == 2:
        gameover = True
        display.set_pen(Bomb_color)
        display.rectangle(Px,Py,10,10)
        time.sleep(50)
        display.clear()
        display.text("Game Over", 100, 50, 500, 25, 0, 3)
        display.update()
        return gameover
    elif Maze[Px-1][Py] == 4:
        display.clear()
        display.text("Winner", 100, 50, 500, 25, 0, 3)
        display.update()
        
    elif Maze[Px-1][Py] == 0:
        Maze[Px-1][Py] = 3
        Maze[Px][Py] = 0
        return Maze
    else:
        display.clear()
        display.text("Error", 100, 50, 500, 25, 0, 3)
        display.update()
        

def MoveRight(Maze):
    #checks where player is
    for x in range(row):
        for y in range(col):
            if maze[x][y] == 3:
                x = Px
                y = Py
    if Maze[Px+1][Py] == 1:
        return
    elif Maze[Px+1][Py] == 2:
        gameover = True
        display.set_pen(Bomb_color)
        display.rectangle(Px,Py,10,10)
        time.sleep(50)
        display.clear()
        display.text("Game Over", 100, 50, 500, 25, 0, 3)
        display.update()
        return gameover
    elif Maze[Px+1][Py] == 4:
        display.clear()
        display.text("Winner", 100, 50, 500, 25, 0, 3)
        display.update()
        
    elif Maze[Px+1][Py] == 0:
        Maze[Px+1][Py] = 3
        Maze[Px][Py] = 0
        return Maze
    else:
        display.clear()
        display.text("Error", 100, 50, 500, 25, 0, 3)
        displat.update()
        
#while loop for running the game
    while(Game_Over == False):
        DrawMaze(Maze)
        display.update()
        # Will read buttons pressed and move accordingly
        if button_a.read():
            MoveRight(Maze)
            if MoveRight(Maze) == True:
                Game_Over == True
            else:
                DrawMaze(Maze)
                display.update()
            
        elif button_b.read():
            MoveLeft(Maze)
            if MoveLeft(Maze) == True:
                Game_Over == True
            else:
                DrawMaze(Maze)
                display.update()
            
        elif button_x.read():
            MoveDown(Maze)
            if MoveDown(Maze) == True:
                Game_Over == True
            else:
                DrawMaze(Maze)
                display.update()
                
        elif button_y.read():
            MoveUp(Maze)
            if MoveUp(Maze) == True:
                Game_Over == True
            else:
                DrawMaze(Maze)
                display.update()
                
    


            
            


