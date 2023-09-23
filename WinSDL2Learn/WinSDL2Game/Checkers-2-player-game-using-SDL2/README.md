# Checkers-2-player-game-using-SDL2
A 2 player game of Checkers/Draughts made in C++ using SDL2
![ScreenshotOfProgram](assets/Checkers-Game-Screenshot.png?raw=true)

## Compile and run using Microsft Visual Studio (MVS)
- Clone the repository
- Open the solution file
- Compile and run in x86 mode in either Debug or Release
- If you want to run from the executable file located in the generated "bin" folder then do the following:
  - copy assets folder into the same folder as the executable.
  - copy the "SDL2.dll" file into the same folder as the executable.

## What is Checkers/Draughts?
https://en.wikipedia.org/wiki/Draughts

## SDL2
This project uses SDL2 as a dependency which requires a dll file called "SDL2.dll". This is therefore required in the main directory to run from MVS. It is also required in the executable directories for the executable to run.

## Source files
All the .cpp and .h files can be found in the src folder.

## Code structure
### OOP
Each square on the board is treated as an object. The main attributes for each square are:
  - checker:
    - no checker
    - red checker
    - black checker
    - king red checker
    - king black checker
  - highlight:
    - clickable (only the current players' checkers are clickable)
    - possible square to move to (including jumps over opponent's checkers) 
    - colour 
    - dimensions and position (using SDL_Rect data structure)
  - background colour (to form the checkered pattern of the board)
  - flag checker for possible removal (when checker is about to be jumped and only remove if the player choses to jump it)
  - previous square (keep track which square caused the flagged)

### Textures
The textures were made in Microsoft paint. They are loaded into a texture cache variable which stores pointers with "SDL_Texture*" type so that they can be reused by any square. This is done by simply pointing to the desired texture in the texture cache variable.
    
### Game loop
The main game loop is split into different game states:
  - outline current player state
  - selecting state
  - selected state
  - moving state
This allows the code to have a more flexiable structure so that only certain parts of the game loop are called if that is the current state.

### Rendering
Each square, checker, and highlight has a render method that is called in the game loop only when something has changed. This is to avoid re-rendering of objects that have not changed when going from different game states.

## Learning outcomes
  - how to detect mouse events in a specific area of the rendering context
  - game loops
  - recursion (when checking for multiple possible checker jumps)
  - better understanding of the SDL2 framework

## Possible future improvements
  - instead of displaying the winner/draw message in the console. Display it with text on the rendering context
  - create a reset button
  - add a timer
  - add animations
