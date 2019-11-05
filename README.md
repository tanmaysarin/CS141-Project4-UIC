# CS141-Project4-UIC

Write an ASCII text version of the classic Palm game called Vexed.  There are ad-supported online versions (shown below), as well as Android and iOS versions, though they may be dated and buggy.

Vexed screen shot from https://www.mindgames.com/game/Vexed
In our solution commands will be entered from the Terminal and not done graphically.  This should look like the following, and is explained more fully below:

Welcome to Vexed!  
The objective is to place identical pieces next to each other, so that they vanish,   
clearing the board completely within the indicated number of moves. On each move      
enter the row, column, and direction (L or R) to move, in either upper or lower       
case. You may also enter 'x' to exit the program, or 'r' to reset the current level. 


    Board 0 par 4
      0 1 2 3 4 5 6 7 8 9  
    -----------------------
  A | . . . . . . . . . . | A
  B | . . . . . . . . . . | B
  C | . . . @ &     . . . | C
  D | . . . . .     . . . | D
  E | . . .         . . . | E
  F | . . . &     @ . . . | F
  G | . . . . & @ . . . . | G
  H | . . . . . . . . . . | H
    -----------------------
      0 1 2 3 4 5 6 7 8 9  
1. Your move: c4r

    Board 0 par 4
      0 1 2 3 4 5 6 7 8 9  
    -----------------------
  A | . . . . . . . . . . | A
  B | . . . . . . . . . . | B
  C | . . . @   &   . . . | C
  D | . . . . .     . . . | D
  E | . . .         . . . | E
  F | . . . &     @ . . . | F
  G | . . . . & @ . . . . | G
  H | . . . . . . . . . . | H
    -----------------------
      0 1 2 3 4 5 6 7 8 9  

    Board 0 par 4
      0 1 2 3 4 5 6 7 8 9  
    -----------------------
  A | . . . . . . . . . . | A
  B | . . . . . . . . . . | B
  C | . . . @       . . . | C
  D | . . . . . &   . . . | D
  E | . . .         . . . | E
  F | . . . &     @ . . . | F
  G | . . . . & @ . . . . | G
  H | . . . . . . . . . . | H
    -----------------------
      0 1 2 3 4 5 6 7 8 9  

    Board 0 par 4
      0 1 2 3 4 5 6 7 8 9  
    -----------------------
  A | . . . . . . . . . . | A
  B | . . . . . . . . . . | B
  C | . . . @       . . . | C
  D | . . . . .     . . . | D
  E | . . .     &   . . . | E
  F | . . . &     @ . . . | F
  G | . . . . & @ . . . . | G
  H | . . . . . . . . . . | H
    -----------------------
      0 1 2 3 4 5 6 7 8 9  

    Board 0 par 4
      0 1 2 3 4 5 6 7 8 9  
    -----------------------
  A | . . . . . . . . . . | A
  B | . . . . . . . . . . | B
  C | . . . @       . . . | C
  D | . . . . .     . . . | D
  E | . . .         . . . | E
  F | . . . &   & @ . . . | F
  G | . . . . & @ . . . . | G
  H | . . . . . . . . . . | H
    -----------------------
      0 1 2 3 4 5 6 7 8 9  
2. Your move: c3r

    Board 0 par 4
      0 1 2 3 4 5 6 7 8 9  
    -----------------------
  A | . . . . . . . . . . | A
  B | . . . . . . . . . . | B
  C | . . .   @     . . . | C
  D | . . . . .     . . . | D
  E | . . .         . . . | E
  F | . . . &   & @ . . . | F
  G | . . . . & @ . . . . | G
  H | . . . . . . . . . . | H
    -----------------------
      0 1 2 3 4 5 6 7 8 9  
3. Your move: c4r

    Board 0 par 4
      0 1 2 3 4 5 6 7 8 9  
    -----------------------
  A | . . . . . . . . . . | A
  B | . . . . . . . . . . | B
  C | . . .     @   . . . | C
  D | . . . . .     . . . | D
  E | . . .         . . . | E
  F | . . . &   & @ . . . | F
  G | . . . . & @ . . . . | G
  H | . . . . . . . . . . | H
    -----------------------
      0 1 2 3 4 5 6 7 8 9  

    Board 0 par 4
      0 1 2 3 4 5 6 7 8 9  
    -----------------------
  A | . . . . . . . . . . | A
  B | . . . . . . . . . . | B
  C | . . .         . . . | C
  D | . . . . . @   . . . | D
  E | . . .         . . . | E
  F | . . . &   & @ . . . | F
  G | . . . . & @ . . . . | G
  H | . . . . . . . . . . | H
    -----------------------
      0 1 2 3 4 5 6 7 8 9  

    Board 0 par 4
      0 1 2 3 4 5 6 7 8 9  
    -----------------------
  A | . . . . . . . . . . | A
  B | . . . . . . . . . . | B
  C | . . .         . . . | C
  D | . . . . .     . . . | D
  E | . . .     @   . . . | E
  F | . . . &   & @ . . . | F
  G | . . . . & @ . . . . | G
  H | . . . . . . . . . . | H
    -----------------------
      0 1 2 3 4 5 6 7 8 9  
4. Your move: f5l

    Board 0 par 4
      0 1 2 3 4 5 6 7 8 9  
    -----------------------
  A | . . . . . . . . . . | A
  B | . . . . . . . . . . | B
  C | . . .         . . . | C
  D | . . . . .     . . . | D
  E | . . .     @   . . . | E
  F | . . . & &   @ . . . | F
  G | . . . . & @ . . . . | G
  H | . . . . . . . . . . | H
    -----------------------
      0 1 2 3 4 5 6 7 8 9  

    Board 0 par 4
      0 1 2 3 4 5 6 7 8 9  
    -----------------------
  A | . . . . . . . . . . | A
  B | . . . . . . . . . . | B
  C | . . .         . . . | C
  D | . . . . .     . . . | D
  E | . . .         . . . | E
  F | . . . & & @ @ . . . | F
  G | . . . . & @ . . . . | G
  H | . . . . . . . . . . | H
    -----------------------
      0 1 2 3 4 5 6 7 8 9  

    Board 0 par 4
      0 1 2 3 4 5 6 7 8 9  
    -----------------------
  A | . . . . . . . . . . | A
  B | . . . . . . . . . . | B
  C | . . .         . . . | C
  D | . . . . .     . . . | D
  E | . . .         . . . | E
  F | . . .     @ @ . . . | F
  G | . . . .   @ . . . . | G
  H | . . . . . . . . . . | H
    -----------------------
      0 1 2 3 4 5 6 7 8 9  

    Board 0 par 4
      0 1 2 3 4 5 6 7 8 9  
    -----------------------
  A | . . . . . . . . . . | A
  B | . . . . . . . . . . | B
  C | . . .         . . . | C
  D | . . . . .     . . . | D
  E | . . .         . . . | E
  F | . . .         . . . | F
  G | . . . .     . . . . | G
  H | . . . . . . . . . . | H
    -----------------------
      0 1 2 3 4 5 6 7 8 9  

Congratulations!  On to the next level.
Score: 4

    Board 1 par 3
      0 1 2 3 4 5 6 7 8 9  
    -----------------------
  A | . . . . . . . . . . | A
  B | . . . . . . . . . . | B
  C | . . .     &     . . | C
  D | . . .     @     . . | D
  E | . . .   & +     . . | E
  F | . . .   @ %     . . | F
  G | . . . @ % +   + . . | G
  H | . . . . . . . . . . | H
    -----------------------
      0 1 2 3 4 5 6 7 8 9  
1. Your move: d5l

    Board 1 par 3
      0 1 2 3 4 5 6 7 8 9  
    -----------------------
  A | . . . . . . . . . . | A
  B | . . . . . . . . . . | B
  C | . . .     &     . . | C
  D | . . .   @       . . | D
  E | . . .   & +     . . | E
  F | . . .   @ %     . . | F
  G | . . . @ % +   + . . | G
  H | . . . . . . . . . . | H
    -----------------------
      0 1 2 3 4 5 6 7 8 9  

    Board 1 par 3
      0 1 2 3 4 5 6 7 8 9  
    -----------------------
  A | . . . . . . . . . . | A
  B | . . . . . . . . . . | B
  C | . . .           . . | C
  D | . . .   @ &     . . | D
  E | . . .   & +     . . | E
  F | . . .   @ %     . . | F
  G | . . . @ % +   + . . | G
  H | . . . . . . . . . . | H
    -----------------------
      0 1 2 3 4 5 6 7 8 9  
2. Your move: d4l

    Board 1 par 3
      0 1 2 3 4 5 6 7 8 9  
    -----------------------
  A | . . . . . . . . . . | A
  B | . . . . . . . . . . | B
  C | . . .           . . | C
  D | . . . @   &     . . | D
  E | . . .   & +     . . | E
  F | . . .   @ %     . . | F
  G | . . . @ % +   + . . | G
  H | . . . . . . . . . . | H
    -----------------------
      0 1 2 3 4 5 6 7 8 9  

    Board 1 par 3
      0 1 2 3 4 5 6 7 8 9  
    -----------------------
  A | . . . . . . . . . . | A
  B | . . . . . . . . . . | B
  C | . . .           . . | C
  D | . . .     &     . . | D
  E | . . . @ & +     . . | E
  F | . . .   @ %     . . | F
  G | . . . @ % +   + . . | G
  H | . . . . . . . . . . | H
    -----------------------
      0 1 2 3 4 5 6 7 8 9  

    Board 1 par 3
      0 1 2 3 4 5 6 7 8 9  
    -----------------------
  A | . . . . . . . . . . | A
  B | . . . . . . . . . . | B
  C | . . .           . . | C
  D | . . .     &     . . | D
  E | . . .   & +     . . | E
  F | . . . @ @ %     . . | F
  G | . . . @ % +   + . . | G
  H | . . . . . . . . . . | H
    -----------------------
      0 1 2 3 4 5 6 7 8 9  

    Board 1 par 3
      0 1 2 3 4 5 6 7 8 9  
    -----------------------
  A | . . . . . . . . . . | A
  B | . . . . . . . . . . | B
  C | . . .           . . | C
  D | . . .     &     . . | D
  E | . . .   & +     . . | E
  F | . . .     %     . . | F
  G | . . .   % +   + . . | G
  H | . . . . . . . . . . | H
    -----------------------
      0 1 2 3 4 5 6 7 8 9  

    Board 1 par 3
      0 1 2 3 4 5 6 7 8 9  
    -----------------------
  A | . . . . . . . . . . | A
  B | . . . . . . . . . . | B
  C | . . .           . . | C
  D | . . .     &     . . | D
  E | . . .     +     . . | E
  F | . . .   & %     . . | F
  G | . . .   % +   + . . | G
  H | . . . . . . . . . . | H
    -----------------------
      0 1 2 3 4 5 6 7 8 9  
3. Your move: e5r

    Board 1 par 3
      0 1 2 3 4 5 6 7 8 9  
    -----------------------
  A | . . . . . . . . . . | A
  B | . . . . . . . . . . | B
  C | . . .           . . | C
  D | . . .     &     . . | D
  E | . . .       +   . . | E
  F | . . .   & %     . . | F
  G | . . .   % +   + . . | G
  H | . . . . . . . . . . | H
    -----------------------
      0 1 2 3 4 5 6 7 8 9  

    Board 1 par 3
      0 1 2 3 4 5 6 7 8 9  
    -----------------------
  A | . . . . . . . . . . | A
  B | . . . . . . . . . . | B
  C | . . .           . . | C
  D | . . .     &     . . | D
  E | . . .           . . | E
  F | . . .   & % +   . . | F
  G | . . .   % +   + . . | G
  H | . . . . . . . . . . | H
    -----------------------
      0 1 2 3 4 5 6 7 8 9  

    Board 1 par 3
      0 1 2 3 4 5 6 7 8 9  
    -----------------------
  A | . . . . . . . . . . | A
  B | . . . . . . . . . . | B
  C | . . .           . . | C
  D | . . .     &     . . | D
  E | . . .           . . | E
  F | . . .   & %     . . | F
  G | . . .   % + + + . . | G
  H | . . . . . . . . . . | H
    -----------------------
      0 1 2 3 4 5 6 7 8 9  

    Board 1 par 3
      0 1 2 3 4 5 6 7 8 9  
    -----------------------
  A | . . . . . . . . . . | A
  B | . . . . . . . . . . | B
  C | . . .           . . | C
  D | . . .           . . | D
  E | . . .     &     . . | E
  F | . . .   & %     . . | F
  G | . . .   % + + + . . | G
  H | . . . . . . . . . . | H
    -----------------------
      0 1 2 3 4 5 6 7 8 9  

    Board 1 par 3
      0 1 2 3 4 5 6 7 8 9  
    -----------------------
  A | . . . . . . . . . . | A
  B | . . . . . . . . . . | B
  C | . . .           . . | C
  D | . . .           . . | D
  E | . . .     &     . . | E
  F | . . .   & %     . . | F
  G | . . .   %       . . | G
  H | . . . . . . . . . . | H
    -----------------------
      0 1 2 3 4 5 6 7 8 9  

    Board 1 par 3
      0 1 2 3 4 5 6 7 8 9  
    -----------------------
  A | . . . . . . . . . . | A
  B | . . . . . . . . . . | B
  C | . . .           . . | C
  D | . . .           . . | D
  E | . . .     &     . . | E
  F | . . .   &       . . | F
  G | . . .   % %     . . | G
  H | . . . . . . . . . . | H
    -----------------------
      0 1 2 3 4 5 6 7 8 9  

    Board 1 par 3
      0 1 2 3 4 5 6 7 8 9  
    -----------------------
  A | . . . . . . . . . . | A
  B | . . . . . . . . . . | B
  C | . . .           . . | C
  D | . . .           . . | D
  E | . . .           . . | E
  F | . . .   & &     . . | F
  G | . . .   % %     . . | G
  H | . . . . . . . . . . | H
    -----------------------
      0 1 2 3 4 5 6 7 8 9  

    Board 1 par 3
      0 1 2 3 4 5 6 7 8 9  
    -----------------------
  A | . . . . . . . . . . | A
  B | . . . . . . . . . . | B
  C | . . .           . . | C
  D | . . .           . . | D
  E | . . .           . . | E
  F | . . .           . . | F
  G | . . .   % %     . . | G
  H | . . . . . . . . . . | H
    -----------------------
      0 1 2 3 4 5 6 7 8 9  

    Board 1 par 3
      0 1 2 3 4 5 6 7 8 9  
    -----------------------
  A | . . . . . . . . . . | A
  B | . . . . . . . . . . | B
  C | . . .           . . | C
  D | . . .           . . | D
  E | . . .           . . | E
  F | . . .           . . | F
  G | . . .           . . | G
  H | . . . . . . . . . . | H
    -----------------------
      0 1 2 3 4 5 6 7 8 9  

Congratulations!  On to the next level.
Score: 7

    Board 2 par 14
      0 1 2 3 4 5 6 7 8 9  
    -----------------------
  A | . . . . . . . . . . | A
  B | . . . .     . . . . | B
  C | . . .         . . . | C
  D | . . ^   = #   ^ . . | D
  E | . . #   . .   = . . | E
  F | . . . #     = . . . | F
  G | . . . .     . . . . | G
  H | . . . . . . . . . . | H
    -----------------------
      0 1 2 3 4 5 6 7 8 9  
1. Your move: 