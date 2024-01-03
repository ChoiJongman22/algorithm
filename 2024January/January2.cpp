#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <unordered_map>
#include <queue>
#include <deque>
#include <cmath> //pow함수 선언
#define MAX 500002
using namespace std;

// int arr[129][129];
// int blue=0;
// int white=0;
// void paper(int x, int y, int n){
//     bool cut=false;
//     int first_cr=arr[x][y];
//     for(int i=x;i<x+n;i++){
//         for(int j=y;j<y+n;j++){
//             if(arr[i][j]!=first_cr){
//                 cut=true;
//                 break;
//             }
//         }
//     }
//     if(cut==true){
//         paper(x,y,n/2);
//         paper(x,y+n/2,n/2);
//         paper(x+n/2,y,n/2);
//         paper(x+n/2,y+n/2,n/2);
//     }else{
//         if(first_cr==1){
//             blue++;
//         }else{
//             white++;
//         }
//     }
// }

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int testcase;
//     cin>> testcase;
//     for(int i=0;i<testcase;i++){
//         for(int j=0;j<testcase;j++){
//             int temp;
//             cin>>temp;
//             arr[i][j]=temp;
//         }
//     }
//     paper(0,0,testcase);
//     cout<<white<<"\n";
//     cout<<blue<<"\n";
//     return 0;
// }

void hanoi(int n, int from, int by, int to)
{
    if (n == 1)
    {
        cout << from << " " << to << "\n";
    }else{
        hanoi(n - 1, from, to, by);
        cout << from << " " << to << "\n";
        hanoi(n - 1, by, from, to);
    }
}

//하노이의 탑
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    int testcase;
    cin >> testcase;
    int ans=0;
    ans=pow(2,testcase)-1;
    cout<<ans<<"\n";
    hanoi(testcase,1,2,3);
}