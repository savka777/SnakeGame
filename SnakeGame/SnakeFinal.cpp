#include <iostream>							// SAVVA BOJKO// SAVVA BOJKO// SAVVA BOJKO
#include <cstdlib>						// SAVVA BOJKO// SAVVA BOJKO// SAVVA BOJKO						
#include <time.h>					// SAVVA BOJKO// SAVVA BOJKO// SAVVA BOJKO
#include <vector>					// SAVVA BOJKO
									// SAVVA BOJKO 
using namespace std;					// SAVVA BOJKO
											// SAVVA BOJKO
struct Coordinate								// SAVVA BOJKO
{													// SAVVA BOJKO
	int row = -1;										// SAVVA BOJKO
	int column = -1;										// SAVVA BOJKO
};																// SAVVA BOJKO
																// SAVVA BOJKO				
enum Direction												// SAVVA BOJKO
{														// SAVVA BOJKO
	LEFT = 0,											// SAVVA BOJKO
	RIGHT,							// SAVVA BOJKO// SAVVA BOJKO
	DOWN,						// SAVVA BOJKO// SAVVA BOJKO
	UP						// SAVVA BOJKO// SAVVA BOJKO
};

void PrintGrid();
void PrintGameOver();
int GenerateRandomNumber(int, int);

const int GRID_SIZE = 9;
const char SNAKE = 'O';
const char APPLE = 'X';
const char FREE = ' ';
const char snakeBodySymbol = 'o';		

char gameGrid[GRID_SIZE][GRID_SIZE];

Coordinate snakeCoordinates;
Coordinate appleCoordinates;
vector<Coordinate> snakeParts;

void iniliazeGrid();
void placeSnake();
void placeApple();
void moveSnake(Direction direction);
void updateBodyPosition();
void play();
void updateGame();
void snakeBody();

bool didWin = false;
bool didPlayerLose = false;


int gameScore;

int main()
{
	cout << "WELCOME TO THE SNAKE GAME " << endl;
	srand(time(NULL));
	iniliazeGrid();
	placeSnake();
	placeApple();
	PrintGrid();
	
	gameScore = 0;

	while (gameScore < 5)
	{
		play();
		updateGame();
		PrintGrid();
		if (didPlayerLose)
		{
			PrintGameOver();
			break;
		}
	}

	if (gameScore == 5)
	{
		cout << "YOU HAVE WON THE GAME !" << endl;
	}
}

void iniliazeGrid() //The game must be played on a 9 x 9 grid
{
	for (int i= 0; i < GRID_SIZE; i++)
	{
		for (int j = 0; j < GRID_SIZE; j++)
		{
			gameGrid[i][j] = ' ';
		}
	}
}
void placeSnake()
{
	//The snake has a starting size of 5.

	snakeCoordinates.row = 4;
	snakeCoordinates.column = 4;
	gameGrid[snakeCoordinates.row][snakeCoordinates.column] = SNAKE;

	for (int i = snakeCoordinates.row-1; i >= 0; i--)
	{ // added body parts // placed them on all the rows// started at players head row -1
		Coordinate snakePart;
		snakePart.row = i;
		snakePart.column = snakeCoordinates.column;
		snakeParts.push_back(snakePart);
		gameGrid[snakePart.row][snakePart.column] = snakeBodySymbol;
		
	}

	
}

void placeApple()
{ //An apple is spawned at a random location on the grid (but not on the snake)

	int randomRow = 0;
	int randomColumn = 0;
	bool isSnake = false;

	do
	{
		randomRow = GenerateRandomNumber(0,8);
		randomColumn = GenerateRandomNumber(0, 8);
		
		for (int i = 0; i < snakeParts.size(); i++)
		{ // if 
			if (randomRow == snakeParts[i].row && randomColumn == snakeParts[i].column)
			{
				isSnake = true;
				break;
			}
			
		}

	} while (randomRow==snakeCoordinates.row && randomColumn==snakeCoordinates.column||isSnake);

	appleCoordinates.row = randomRow;
	appleCoordinates.column = randomColumn;

	gameGrid[appleCoordinates.row][appleCoordinates.column] = APPLE;
}


void PrintGrid()
{
	system("CLS");
	cout << '\t' << '\t' << " --------------------" << endl;

	for (int i = 0; i < GRID_SIZE; i++)
	{
		cout << '\t' << '\t' << " |";
		for (int j = 0; j < GRID_SIZE; j++)
		{
			cout << " " << gameGrid[i][j];
		}
		
		cout << "|" << endl;

		if (i == GRID_SIZE - 1)
		{
			cout << '\t' << '\t' << " --------------------" << endl;
		}
	}

	cout << endl << endl << '\t' << '\t' << '\t' << "SCORE: " << gameScore << endl << endl << endl;
}

void moveSnake(Direction direction)
{
	gameGrid[snakeCoordinates.row][snakeCoordinates.column] = ' ';
	updateBodyPosition(); // 

	if (direction == UP)
	{
		snakeCoordinates.row--;
	}

	if (direction == DOWN)
	{
		snakeCoordinates.row++;
	}

	if (direction == LEFT)
	{
		snakeCoordinates.column--;
	}

	if (direction == RIGHT)
	{
		snakeCoordinates.column++;
	}

	gameGrid[snakeCoordinates.row][snakeCoordinates.column] = SNAKE;
	
}

void updateBodyPosition() 
{ 
	// clear grid of existing body part positions 
	for (int i = 0; i < snakeParts.size(); ++i)
	{ 
		gameGrid[snakeParts[i].row][snakeParts[i].column] = FREE;
	} 
	// loop through the snake parts from back to front // excluding the front of the body
	for (int i = snakeParts.size() - 1; i >= 1; --i)
	{
		//each part follows the position of the part in front of it 
		snakeParts[i] = snakeParts[i - 1];
		gameGrid[snakeParts[i].row][snakeParts[i].column] = snakeBodySymbol; // assign the symbol

	} 
	//front of the body follows the head of the snake 
	snakeParts[0] = snakeCoordinates;	
	gameGrid[snakeParts[0].row][snakeParts[0].column] = snakeBodySymbol; // assign the symbol
}

void play()
{
	char input;
	cout << "USE THE -A-W-S-D- KEYS TO MOVE THE SNAKE !" << endl;
	cin >> input;

	if (input == 'w' || input == 'W')
	{
		moveSnake(UP);
	}

	if (input == 's' || input == 'S')
	{
		moveSnake(DOWN);
	}

	if (input == 'a' || input == 'A')
	{
		moveSnake(LEFT);
	}

	if (input == 'd' || input == 'D')
	{
		moveSnake(RIGHT);
	}
}

void snakeBody()
{ 
	// adding new body part // copy of the part of the back and add a new entry to the list of snake parts 
	Coordinate endOfsnake = snakeParts[snakeParts.size() - 1];
	snakeParts.push_back(endOfsnake);
}

void updateGame()
{
	// If the head of the snake touches the body, the game is over
	for (int i = 0; i < snakeParts.size(); ++i)
	{
		if (snakeCoordinates.row == snakeParts[i].row && snakeCoordinates.column == snakeParts[i].column)
		{
			didPlayerLose = true;
		}
	}
		// If the head of the snake exits the grid, the game is over
	if (snakeCoordinates.row == GRID_SIZE || snakeCoordinates.column == GRID_SIZE || snakeCoordinates.row == -1 || snakeCoordinates.column == -1)
	{
		didPlayerLose = true;
	}
	// if the player finds an apple, we need to increment the score and spawn new apple // increment the size of snakes body
	if (snakeCoordinates.row == appleCoordinates.row && snakeCoordinates.column == appleCoordinates.column)
	{
		placeApple();
		gameScore++;
		snakeBody();
	}

}



void PrintGameOver()
{
	cout << "   _____          __  __ ______    ______      ________ _____  " << endl;
	cout << "  / ____|   /\\   |  \\/  |  ____|  / __ \\ \\    / /  ____|  __ \\ " << endl;;
	cout << " | |  __   /  \\  | \\  / | |__    | |  | \\ \\  / /| |__  | |__) |" << endl;;
	cout << " | | |_ | / /\\ \\ | |\\/| |  __|   | |  | |\\ \\/ / |  __| |  _  / " << endl;;
	cout << " | |__| |/ ____ \\| |  | | |____  | |__| | \\  /  | |____| | \\ \\ " << endl;;
	cout << "  \\_____/_/    \\_\\_|  |_|______|  \\____/   \\/   |______|_|  \\_\\ " << endl;;
}

//This function generates a random number in a specific range
int GenerateRandomNumber(int min, int max)
{
	int range = max - min + 1;
	return rand() % range + min;
}