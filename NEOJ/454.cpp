#include <iostream>

int main(){
	int M, N;
	int A[12][12], B[12][12], C[12][12];
	std::cin >> N >> M;
	std::cin >> M >> N;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			std::cin >> A[i][j];
	for(int i = 0; i < M; i++)
		for(int j = 0; j < N; j++)
			std::cin >> B[i][j];
	int sum;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			sum = 0;	
			for(int k = 0; k < M; k++)	
				sum += A[i][k] * B[k][j];
			C[i][j] = sum;
		}
	}

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(j != N-1)
				std::cout << C[i][j] << " ";
			else
				std::cout << C[i][j] << std::endl;
		}
	}
	return 0;
}
