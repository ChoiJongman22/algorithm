//행렬 덧셈 공부하면서 이차원 배열 복습하기
#include <iostream>

using namespace std;

// int main(){
//     int n,m;
//     cin>>n>>m;
//     int** arr1 = new int* [n];//메모리 할당
//     int** arr2 = new int* [n];//메모리 할당
//     for (int i = 0; i < n; ++i)	{		
//         arr1[i] = new int[m];		
//         arr2[i] = new int[m];	
//     }
//     for(int i=0;i<n;++i){
//         for (int j=0;j<m;++j){
//             cin>>arr1[i][j];
//         }
//     }
//     for(int i=0;i<n;++i){
//         for (int j=0;j<m;++j){
//             cin>>arr2[i][j];
//         }
//     }
//     for(int i=0;i<n;++i){
//         for (int j=0;j<m;++j){
//             cout<<arr1[i][j]+arr2[i][j]<<' ';
//         }
//         cout<<'\n';
//     }
//     for(int i=0;i<n;i++){
//         delete[] arr1[i];//메모리 해제
//         delete[] arr2[i];//메모리 해제
//     }
//     delete[] arr1;
//     delete[] arr2;

// }

//색종이

int main(){
    bool paper[100][100]={0};//모두 0으로 초기화하기
    int sum=0;
    int n;
    cin>>n;
    

    while(n--){
        int x,y;
        cin>>x>>y;
        for (int i = y; i < y+10; i++){
            for(int j=x; j< x+10; j++){
                if(paper[i][j]) continue;
                paper[i][j]=1;
                sum++;
            }
        }
    }
    
    cout<<sum<<endl;
    return 0;


}