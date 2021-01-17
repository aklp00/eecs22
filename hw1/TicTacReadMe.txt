Akhil Pappu 
Professor QV Dang 
EECS 22

This program runs a Tic Tac Toe game while also implementing user customizability using character arrays and strings. Some 
features include being able to change the icon of the players (from the default X or O), changing the icon of the color using 
ANSI escape codes, and being able to play against either another human player or an AI. Should they opt to play against an AI, 
they are able to have the option of being the first or second place. The way I implemented the program was by using functions.
To print the board, I had two functions: one to initialize empty spaces in the array and the other function to actually print
out the board. Next, I had individual functions to get the player move and also to get the AI move. Finally, I had two functions,
one for human vs human and another for human vs computer. I made many functions to increase modularity of my code, but to also 
make it easier for me to debug within each function should I encounter an error. 
