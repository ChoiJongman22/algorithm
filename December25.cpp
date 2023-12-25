#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <unordered_map>
#include <queue>
#include <deque>
#define MAX 500002
using namespace std;

// 숫자카드2: 이분탐색으로 문제풀이
// int main(){
//     ios::sync_with_stdio(false);
// 	cin.tie(0);
//     cout.tie(0);
//     int n;
//     cin >> n;

//     int card[MAX] = {0,};
//     for (int i = 0; i < n; i++)
//     {
//         cin >> card[i];
//     }
//     sort(card, card + n);
//     int m;
//     cin >> m;
//     for (int i = 0; i < m; i++)
//     {
//         int temp;
//         cin >> temp;
//         cout << upper_bound(card, card + n, temp) - lower_bound(card, card + n, temp) << "\n";
//     }
//     return 0;
// }

// 숫자카드2: 해쉬 맵으로 문제풀이
int main(){
    unordered_map <int, int> m;
    int N,M,card;
    ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>N;
    for (int i=0;i<N;i++){
        cin>>card;
        m[card]++;
    }
    cin>>M;
    for(int i=0;i<M;i++){
        cin>>card;
        cout<<m[card]<<"\n";
    }
    return 0;
}

//해시맵
// int main() {
//     // std::unordered_map 생성 (키는 문자열, 값은 정수)
//     std::unordered_map<std::string, int> myMap;

//     // 값 삽입
//     myMap["apple"] = 5;
//     myMap["banana"] = 3;
//     myMap["orange"] = 7;

//     // 값 검색
//     std::cout << "Number of apples: " << myMap["apple"] << std::endl;

//     // 키의 존재 여부 확인
//     if (myMap.find("grape") != myMap.end()) {
//         std::cout << "Number of grapes: " << myMap["grape"] << std::endl;
//     } else {
//         std::cout << "Grape not found in the map." << std::endl;
//     }

//     return 0;
// }