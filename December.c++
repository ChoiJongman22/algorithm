//행렬 덧셈 공부하면서 이차원 배열 복습하기
#include <iostream>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int** arr1 = new int* [n];//메모리 할당
    int** arr2 = new int* [n];//메모리 할당
    for (int i = 0; i < n; ++i)	{		
        arr1[i] = new int[m];		
        arr2[i] = new int[m];	
    }
    for(int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            cin>>arr1[i][j];
        }
    }
    for(int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            cin>>arr2[i][j];
        }
    }
    for(int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            cout<<arr1[i][j]+arr2[i][j]<<' ';
        }
        cout<<'\n';
    }
    for(int i=0;i<n;i++){
        delete[] arr1[i];//메모리 해제
        delete[] arr2[i];//메모리 해제
    }
    delete[] arr1;
    delete[] arr2;

}