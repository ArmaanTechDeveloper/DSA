#include <iostream>

using namespace std;

int main(){
    // creation of 2d dynamic Array

    int row;
    int col;

    cout << "Enter row and column " << endl;
    cin >> row >> col;

    cout << "Enter the elements "<< endl;

    // creation
    int** arr = new int *[row];

    for(int i=0 ; i < row ; i++){
        arr[i] = new int[col];
    }

    // taking input 
    for(int i=0 ; i < row ; i++){
        for(int j=0 ; j < col ; j++){
            cin >> arr[i][j];
        }
    }
    cout << endl;

    // printing
    for(int i=0 ; i < row ; i++){
        for(int j=0 ; j < col ; j++){
            cout << arr[i][j] << " ";
        } cout << endl;
    }

    // releasing memory
    for(int i=0 ; i < row ; i++){
        delete [] arr[i];
    }
    delete [] arr;

    return 0;
}