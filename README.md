# SnakeGame
 Your good ol-fashioned average snake game
Solution Sequence -Savva Bojko
STEP1: Create the grid 
-Matrix 9x9 – holds characters 
STEP2: initialize the grid
-in order to get an empty grid we need to initialize it – nested loops – set grid to empty
STEP3: Place our player (SNAKE)	
- the player needs to be centered on row 4 and column 4 – the snake has a body of 5 ( 5 characters ) – the snake will be aligned to a row or column as starting point-
STEP4: Place our apple
-Our apple cant be placed on the snakes coordinates – has to be randomly placed – will use a random generator to place apple(0-8) – will need while loop in order to assure that apples coordinates will not overlap the snakes coordinates. After placing apple position we want to print to the grid the “APPLE” symbol.
STEP5: Print grid to the console
STEP6: PLAY
-print to player that telling him to use the -A-W-S-D keys to move the snake – Will use enum to hold player direction- will need 4 if statements or a switch, depending on the input of the player , our snake will either move up, down, left, or right.
STEP7: Update body position
-we need to update the body position of the SNAKE every time it moves – reprint the grid according to the coordinates of the SNAKE and its body elements- the body parts follow the head
STEP8: Update the game
-I will need loops and if statements – if the player touches the body of the snake he loses – if the player exits the grid he loses – if the player eats the apple his body and score increment by 1- need to reprint the grid every time the player moves – need to respawn a new apple every time the SNAKE eats one –
STEP9: Keep playing
-while the score is under 5 we keep playing – updating the game – and print the grid- if the player loses – we print “GAMEOVER” – if player score is equal to 5 we print a congratulatory message

Implementation 
Will need enum called Direction
Will need struct called coordinates that holds  int rows and column
Will need const grid size which will be set to 9
Will need const Char SNAKE set to symbol ‘O’
Will need const Char APPLE set to symbol ‘X’
Will need const Char FREE set to symbol ‘ ’
Will need const Char SnakeBody set to symbol ‘o’
Will need a game grid of type char and a 9x9 – will be a mtrix
Create snake coordinates with type coordinates
Create apple coordinates with type coordinates
Create snake parts with type coordinates 
Create a Boolean called to check if player won, set it to false
Create a Boolean to check if player has lost, set it to false 
Create a variable of type int called int score 

void InitializeGrid()
1.	For each row
2.	For each column
3.	Set the row/column to empty space ‘ ‘
void PlaceSNAKE()- (head + body)
1.	Place snake at row 4 and column 4
2.	Set SNAKE symbol (head) to ‘O’
3.	For each snake Coordinate add 5 body parts / store them in a vector of “snake parts”
4.	Align snake parts to row and column of SNAKE head
5.	Set body parts to symbol ‘o’ 

void placeAPPLE()
1.	Create a variable(randomRow + randomColumn) for random generator function
2.	Create a Boolean “isSnake” set it to false
3.	Do at least once, assign the randomRow and randomColumn to GenerateRandomNumber, parameters 0 and 8.
4.	For all the snake parts, if the randomRow and randomColumn is equal to the coordinates of snakeParts row and column then set “isSnake” to true and break out the do-while loop
5.	Set appleCoordinates.row the randomRow and appleCoordinates.column to randomColumn
6.	Assign to grid the symbol for the apple coordinates 

void printGrid()
1.for each row 
2.for each column 
Print content for the row/column

void moveSnake(Direction direction)
1.If (direction == up)
		Decrement the current row
2.If (direction == Down)
		Increment the current row
3.If (direction == left)
		Decrement the current column
4.If (direction == right)
		Increment the current column
	void play()
1.	Aske the user to enter a character
2.	Read that character
3. If the character is equal to w or W
	MovePlayer (up)
4. If the character is equal to s or S
	MovePlayer (down)

5. If the character is equal to a or A
	MovePlayer (left)

6. If the character is equal to d or D
	MovePlayer (right)
		
		
void updateGame()
1.for all the snakeparts 
If the snake part coordinates equal to sake part coordinates then player has lost the game
2.if the snake coordinates column equal to grid size, then the game is over || if the row is equal to -1 then the game is over
3.if snakeCoordinates row and column equal to appleCoordinates row and column then player has found apple, if this happens place another apple , increment game score and add increment snakebody
void SnakeBody()
1.	Push back snake parts to snakeparts (copies the back and adds new part)
Void printGameOver()
1.	Print to console “GAME OVER”
Void GenerateRandomNumber(int min , int max)
1.	Generate random number from specific range (0-8)
2.	The function will be used when placing the apple coordinates 


int main()
1.	srand(time(NULL)); generate random seed based on time
	iniliazeGrid();
	placeSnake();
	placeApple();
	PrintGrid();

2.while the score of player is under 5
_- we want to keep playing 
  -Update the game
  -print the grid

If the player loses we want to print gameOverFucntion and break out of the loop
If the player score is 5 , we want to tell him that he has won the game !
	


 

