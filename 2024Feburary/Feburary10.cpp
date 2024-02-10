

//수 이어쓰기
// #include <iostream>
// #include <string>
// using namespace std;

// int main(){
//     string str;
//     cin>>str;

//     int ptr=0, num=0;
//     while(num++<3000){
//         string numstr=to_string(num);
//         for(int i=0;i<numstr.size();i++){
//             if(str[ptr]==numstr[i]){//숫자 내에 현재 위치의 숫자가 있는지를 하나씩 계속 비교합니다.
//                 ptr+=1;//위치를 하나씩 옮겨가며
//             }
//             if(ptr==str.length()){//그리고 숫자의 위치가 결국 더 나가갈 곳이 없다면
//                 cout<<num<<"\n";//그떄의 숫자는 무조건 답이 됩니다.
//                 return 0;
//             }
//         }
//     }
//     return 0;

// }


//햄버거 분배
#include <iostream>
#include <string>
using namespace std;
int main(){
    int N,K;
    string loca;
    cin>>N>>K;
    cin>>loca;
    int cnt=0;
    for(int i=0;i<N;i++){
        if(loca[i]!='P'){
            continue;
        }
        for(int j=i-K;j<=i+K;j++){//범위를 설정해서 탐색하기, 앞에서 먹는 것 부터가 제일 유리함. 
            if(0<=j && j<N && loca[j]=='H'){
                loca[j]='-';//먹었다고 표시하기
                cnt+=1;
                break;
            }
        }
    }
    cout<<cnt;
}




//진우의 달 여행