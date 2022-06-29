#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int min(int a, int b){
    return (a>b)? b: a;
}

int MatrixChainMultiplication(int *dimen, int num){

    int matrix[num][num];

    for (int i=0; i<num; i++){
        matrix[i][i] = 0;
    }

    for (int l=2; l<num; l++){
        for (int i=0; i<num-l+1; i++){

            int j = i+l-1;
            matrix[i][j] = INT_MAX;

            for (int k=i; k<=j-1; k++){
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k + 1][j] + dimen[i - 1] * dimen[k] * dimen[j]);
            }
        }
    }

    return matrix[1][num - 1];
}

int main(){
    int num, dimen1, dimen2;

    cout<<"Enter number of matrices: ";
    cin>>num;

    int *dimen = new int[num];
    int j = 0;

    cout<<endl;
    for(int i=0; i<num; i++){
        cout<<"Enter dimensions of matrix "<<i+1<<": ";
        cin>>dimen1>>dimen2;

        if(i == 0){
            dimen[j++] = dimen1;
            dimen[j++] = dimen2;
        }else{
            if(dimen[j-1] == dimen1){
                dimen[j++] = dimen2;
            }else{
                cout<<"\nMatrix multiplication not possible";
            }
        }
    }

    cout<<"\nArray of unique dimensions taken are: ";
    for(int i=0; i<=num; i++){
        cout<<dimen[i]<<" ";
    }

    cout<<"\nMinimum number of multiplications required is: "<<MatrixChainMultiplication(dimen, j);

    return 0;
}
