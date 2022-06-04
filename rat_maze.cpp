// program to demonstrate the use of recursion and backtracking in maze problem
#include<iostream>
using namespace std;
//function to check either the x and y are inside the range or not
bool checkrange(int** arr,int x, int y, int n){
    if(x<n && y<n && arr[x][y] == 1){
        return true;
    }
    return false;
}
//main funciton
//x and y represents left and right
bool ratinMaze(int** arr, int x, int y,int n, int** solutionArr){

    if(x== n-1 && y == n-1 ){
        solutionArr[x][y] =1;
        return true;
    }
    if(checkrange(arr,x,y,n)){
        solutionArr[x][y] = 1;
        //recursion
        if(ratinMaze(arr,x+1,y,n,solutionArr)){
            return true;
        }
        if(ratinMaze(arr,x,y+1,n,solutionArr)){
            return true;
        }
        // backtracking
        solutionArr[x][y] = 0;
        return false;
    }
    return false;
}

 int main()
{
    int n;
    cout << "Enter the size of matrix (n*n) n: ";
    cin>>n;
    //dynamic array for the matrix
    int** arr = new int*[n];
    for(int i=0;i<n;i++){
        arr[i] = new int[i];
    }
    //scanning array from the user
    for(int i = 0;i<n;i++){
        for(int j=0 ;j<n;j++){
            cout << "arr["<<i<<"]["<<j<<"]:";
            cin>>arr[i][j];
        }
    }
    //defining solution array using dynamic array
    int** solutionArr = new int*[n];
    for(int i = 0;i<n;i++){
        solutionArr[i] = new int[n];
        for(int j=0 ;j<n;j++){
            solutionArr[i][j] = 0;
            //cin>>arr[i][j];
        }
    }

    //for displaying solution array
    if(ratinMaze(arr,0,0,n,solutionArr)){
        for(int i = 0;i<n;i++){
            for(int j=0 ;j<n;j++){
                cout<<solutionArr[i][j]<< " ";
            }
            cout << endl;
        }
    }
    return 0;
}
