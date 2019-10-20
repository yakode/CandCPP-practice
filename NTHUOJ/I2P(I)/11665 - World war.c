#include <stdio.h>
#include <string.h>

#define EAST 0
#define SOUTH 1
#define WEST 2
#define NORTH 3

/*
 *  3
 * 2 0
 *  1
 */

char map[100][100];
char actions[100]={};
int coin_amount = 0;
int cols, rows;
// tank's initial direction
char init_dir;
// tank's direction now
int dir_now;
// tank's center x and y
int center_x, center_y;

void decide_initial_direction()
{
    /// Decide tank's initial direction
    /// Using init_dir
    /// To determine dir_now
	if(init_dir == 'E')
		dir_now = 0;
	else if(init_dir == 'S')
		dir_now = 1;
	else if(init_dir == 'W')
		dir_now = 2;
	else if(init_dir == 'N')
		dir_now = 3;
}

void take_step(int step)
{
	int x, y;
    if (dir_now == NORTH){
        // Detect wall first
		x = center_x - (step + 1);
		y = center_y;
        if (center_x - ( step + 1 ) < 1 || map[center_x - ( step + 1 )][center_y] == '#' ){
			return;
        }
        // And then detect hill
		else if ( map[x][y - 1] == '^' || map[x][y] == '^' || map[x][y + 1] == '^') {
			return;
		}
        // If there is no obstacle, take a step
        else {
			center_x -= step;
			return;
        }
    }
    else if (dir_now == SOUTH){
		x = center_x + (step + 1);
	   	y = center_y;
        if (center_x + ( step + 1 ) > rows || map[center_x + ( step + 1 )][center_y] == '#' ){
			return;
        }
        else if ( map[x][y - 1] == '^' || map[x][y] == '^' || map[x][y + 1] == '^') {
			return;
		}
        else {
			center_x += step;
			return;
        }
    }
    else if (dir_now == EAST){
		x = center_x;
	   	y = center_y + (step + 1);
        if (center_y + ( step + 1 ) > cols || map[center_x][center_y + ( step + 1 )] == '#' ){
			return;
        }
        else if ( map[x - 1][y] == '^' || map[x][y] == '^' || map[x + 1][y] == '^') {
			return;
		}
        else {
			center_y += step;
			return;
        }
    }
    else if (dir_now == WEST){
		x = center_x;
		y = center_y - (step + 1);
        if (center_y - ( step + 1 ) < 1 || map[center_x][center_y - (step + 1)] == '#' ){
			return;
        }
        else if ( map[x - 1][y] == '^' || map[x][y] == '^' || map[x + 1][y] == '^') {
			return;
		}
        else {
			center_y -= step;
			return;
        }
    }
}

void pick_the_coins()
{
    int j, k;
    for (j = center_x - 1; j <= center_x + 1; j++){
        for (k = center_y - 1; k <= center_y + 1; k++){
            /// determine whether there are coins under the tank
			if(map[j][k] == '$'){
				coin_amount ++;
				map[j][k] = '.';
			}
        }
    }
}

void turn_right()
{
    /// Change direction depending on dir_now
	dir_now = ( dir_now + 1 ) % 4;	
}

 

void turn_left()
{
    /// Change direction depending on dir_now
	dir_now -= 1;
	if(dir_now < 0)
		dir_now += 4;
}

int main()
{
    int i, j, k;
    int actions_number;
    int component = 0;

    /// Raed problem's input
    scanf("%d %d %d %c", &rows, &cols, &actions_number, &init_dir);
    while (getchar() != '\n');
    for (i = 0; i < actions_number; i++){
        scanf("%c", &actions[i]);
    }

    /// Read map
    for (i = 1; i <= rows; i++){
        while (getchar() != '\n');
        for (j = 1; j <= cols; j++){
            scanf("%c", &map[i][j]);
            /// Find tank's center x and y
            if (((map[i][j]) == 'x') || ((map[i][j]) == 'o') || ((map[i][j]) == 'O')){
                component++;
                if (component == 5){
                    center_x = i;
                    center_y = j;
                }
            }
        }
    }

    decide_initial_direction();

    for (i = 0; i < actions_number; i++){
        if (actions[i] == 'F'){
			take_step(1);
            pick_the_coins();
        }

        else if ( actions[i] == 'J' ){

           /* TODO : Implement the instruction "J" here */
			take_step(2);
			pick_the_coins();
       }         
        else{
            if (actions[i] == 'R'){
                turn_right();
            }
            if (actions[i] == 'L'){
                turn_left();
            }
        }
    }

    printf("%d\n", coin_amount);

    return 0;
}
