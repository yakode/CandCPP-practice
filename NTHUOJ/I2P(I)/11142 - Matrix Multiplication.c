#include <stdio.h>
int matrix_a[1000][1000];
int matrix_b[1000][1000];
int matrix_c[1000][1000];

int main(){
	int n, m, p;
	while(scanf("%d%d%d", &n, &m, &p) != EOF){
		//scanf("%d%d", &m, &p);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				scanf("%d", &matrix_a[i][j]);
			}
		}
		for(int i = 0; i < m; i++){
			for(int j = 0; j < p; j++){
				scanf("%d", &matrix_b[i][j]);
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < p; j++){
				long long int ans = 0;
				for(int k = 0; k < m; k++){
					ans += matrix_a[i][k] * matrix_b[k][j];
				}
				if(j == p-1) printf("%lld",ans);
				else printf("%lld ",ans);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
