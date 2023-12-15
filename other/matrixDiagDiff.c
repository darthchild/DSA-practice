int diagonalDifference(int arr_rows, int arr_columns, int** arr) {
    
    // order of matrix
    int n = arr_rows;
      
    // left diagonal 
    int lsum = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j){
                lsum += arr[i][j];
            }
        }
    }
    
    // right diagonal
    int rsum = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i+j == n+1){
                rsum += arr[i][j];
            }
        }
    }
    int diff = abs(lsum - rsum);
    return 
}
