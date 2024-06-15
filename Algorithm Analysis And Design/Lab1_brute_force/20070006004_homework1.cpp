#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 8
#define COLUMN 8
#define MONSTER_REWARD 5
#define EMPTY_SYMBOL ' '
#define HERO_SYMBOL 'H'
#define MONSTER_SYMBOL 'M'
#define NUMBER_OF_MONSTERS 5

typedef struct Coordinate{
    int row;
    int column;
} 
Coordinate;
const int STAMINA = 10;
Coordinate heroPosition;
Coordinate monsterPositions[5];
char gameArea[ROW][COLUMN];

void fillGameArea(){
    for(int row = 0 ; row < ROW ; row++){
        for(int col = 0 ; col < COLUMN ; col++){
            gameArea[row][col] = EMPTY_SYMBOL;
        }
    }
}

void printGameArea(){
    for(int row = 0 ; row < ROW ; row++){
        for(int col = 0 ; col < COLUMN ; col++){
            printf("%c ",gameArea[row][col]);
        }
        printf("\n");
    }
}

bool isValidCoordinate(int row, int col){
    return (row >= 0 && row < ROW && col >= 0 && col < COLUMN);
}

bool validMonsterPosition(int row, int col){
    if(!isValidCoordinate(row,col)){
        return false;
    }
    if(gameArea[row][col] != EMPTY_SYMBOL){
        return false;
    }
    for(int i = row-2 ; i <= row+2 ; i++){
        for (int j = col-2 ; j <= col+2 ; j++){
            if(isValidCoordinate(i,j) && gameArea[i][j] == MONSTER_SYMBOL){
                return false;
            }
        }
    }
    return true;
}

void assignMonsters(){
    srand(time(NULL));
    int monstersAssigned = 0;
    while(monstersAssigned < NUMBER_OF_MONSTERS){
        int row = rand() % ROW;
        int col = rand() % COLUMN;
        if(validMonsterPosition(row,col)){
            gameArea[row][col] = MONSTER_SYMBOL;
            monstersAssigned++;
        }
    }
}

Coordinate* assignHero() {
    int row, column;
    do {
        row = rand() % ROW;
        column = rand() % COLUMN;
    } while (!validMonsterPosition(row, column));

    gameArea[row][column] = HERO_SYMBOL;
    heroPosition.row = row;
    heroPosition.column = column;
    return &heroPosition;
}

int main(){
	fillGameArea();
	printGameArea();
	assignMonsters();
	printGameArea();
}
