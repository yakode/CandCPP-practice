#include <cstdio>
#include <cstdlib>

int target_number;
int less_counter = 0;
int less(int guess_num){
    less_counter++;
    if (less_counter > 15){
        printf("You guess too many times ...\n");
    }
    if (target_number < guess_num){
        return 1;
    } else {
        return 0;
    }
}
void guess(int guess_num){
    if (guess_num == target_number){
        printf("Correct!\n");
    } else {
        printf("Not correct! Q__Q\n");
    }
}

int main()
{
    while (scanf("%d", &target_number) != EOF){ /* input a number between [1,101)*/
        less_counter = 0;
        
        /*
            請在此寫你的程式碼
        */
		int L = 1, R = 101, mid;
		while(L+1 != R){
			mid = (L+R) /2;
			if(less(mid))
				R = mid;
			else
				L = mid;
		}
		guess(L);
    }

    return 0;
}
