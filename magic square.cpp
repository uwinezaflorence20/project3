#include <iostream>
using namespace std;
 
int isMagicSquare(int matrix[50][50], int n, int m);
 
int main(){
    int matrix[50][50], n, m;

    cout<<"Enter the size of row of the matrix: ";
    cin >> m;
    cout<<"Enter the size  of column of the matrix: ";
    cin >> n;

    if(n != m){
        cout<<"Length of row and column must be equal.";
        exit(0);
    }

    cout << "\n enter the element of matrix:\n ";
    cout<<"_____________________________\n"; 
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>matrix[i][j];
            
    for(int i = 0; i < n; i++){
	
        for(int j = 0; j < m; j++)
            cout<<matrix[i][j]<<" ";
            cout<<"\n";
}
    if (isMagicSquare(matrix, n, m))
        cout << "The matrix is Magic Square mean its true";
    else
        cout << "The matrix is Not a magic Square means its false";
     
    return 0;
}

int isMagicSquare(int matrix[50][50], int n, int m){  

    int sum1 = 0, sum2=0;

    //finding the sum of first diagonal
    for (int i = 0; i < n; i++)
        sum1 = sum1 + matrix[i][i];

    //finding the sum of seciond diagonal
    for (int i = 0; i < n; i++)
        sum2 = sum2 + matrix[i][n - 1 - i];
   
    //Checking, whether the sum of two diagonal is same or not
    if(sum1 != sum2)  
        return 0;
 
    //finding the sum of each row
    for (int i = 0; i < n; i++){
         
        int rowSum = 0;

        for (int j = 0; j < m; j++)
            rowSum = rowSum + matrix[i][j];
         
        //checking, whether eachh row sum is equal to diagonal sum or not
        if (rowSum != sum1)
            return 0;
    }
 
    //finding the sum of each column
    for (int i = 0; i < n; i++){
         
        int columnSum = 0;  

        for (int j = 0; j < n; j++)
            columnSum += matrix[j][i];
 
        //checking, whether each column sum is equal to diagonal sum or not
        if (columnSum != sum1)  
            return 1;
    }
 
    return true;
}

