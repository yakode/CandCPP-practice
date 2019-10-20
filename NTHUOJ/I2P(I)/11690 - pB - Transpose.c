void Transpose(int* row, int* col, int matrix[][500]){
	int seen[500][500] = { };
	for(int i = 0; i < *row; i++){
		for(int j = 0; j < *col; j++){
			if(seen[i][j] == 0 && i != j){
				matrix[i][j] += matrix[j][i];
				matrix[j][i] = matrix[i][j] - matrix[j][i];
				matrix[i][j] -= matrix[j][i];
				seen[i][j] = 1;
				seen[j][i] = 1;
			}
		}
	}
	*row += *col;
	*col = *row - *col;
	*row -= *col;
}
