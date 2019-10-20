#include <stdio.h>

int main(){
	int card[5][5]; //bingo card
	int loc[25+1][20]; //position of nums
	int T, N;
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++){
			scanf("%d", &card[i][j]);
			loc[card[i][j]][0] = i;
			loc[card[i][j]][1] = j;
		}
	scanf("%d", &T);
	for(int t = 0; t < T; t++){
		printf("Case #%d: ", t+1);
		int bingo[2][5] = {};
		int xie[2] = {}; //xie xian de bu fen!
		int jud = 0; //have found target x
		int num;
		scanf("%d", &N);
		for(int i = 0; i < N; i++){
			scanf("%d", &num);
			if(jud == 0){
				bingo[0][loc[num][0]] ++;
				bingo[1][loc[num][1]] ++;
				if(loc[num][0] == loc[num][1]) xie[0] ++;
				if(loc[num][0] + loc[num][1] == 4) xie[1] ++;
				if(bingo[0][loc[num][0]] == 5 || bingo[1][loc[num][1]] == 5 || xie[0] == 5 || xie[1] == 5){
					printf("%d\n", i+1);
					jud = 1;
				}
			}
			
		}
		if(jud == 0) printf("Not yet \\(^o^)/\n");
	}
} 
