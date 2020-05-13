void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    for(int i=0;i<=n-1;i++){
        A[i+m]=B[i];
    }
    for(int i=0;i<=ASize-1;i++){
        for(int j=i+1;j<=ASize-1;j++){
            if(A[i]>A[j]){
                A[i]=A[i]^A[j];
                A[j]=A[i]^A[j];
                A[i]=A[i]^A[j];
            }
        }
    }
}