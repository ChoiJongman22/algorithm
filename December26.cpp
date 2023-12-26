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

// int main()
// {
//     int N;
//     cin >> N;
//     //vector<int> answer = {0,1,2};
//     vector<long long> answer;
//     for (int i = 0; i < 3; i++)
//     {
//         answer.push_back(i);
//     }
//     for (int i = 3; i <= N; i++)
//     {
//         int tmp;
//         tmp = answer[i - 1] + answer[i - 2];
//         answer.push_back(tmp % 15746);
//     }
//     cout << answer[N] << "\n";
// }

// int main() {
//     int N;
//     cin >> N;

//     vector<long long> answer(3, 0);
//     answer[1]=1;
//     answer[2]=2;

//     for (int i = 3; i <= N; i++) {
//         long long tmp = (answer[i-1] + answer[i-2]) % 15746;
//         answer.push_back(tmp);
//     }

//     cout << answer[N] << "\n";

//     return 0;
// }



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, end, begin;
    vector<pair<int, int> > schedule;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> begin >> end;
        schedule.push_back(make_pair(end, begin));
    }
    sort(schedule.begin(), schedule.end());//스케쥴 정렬
    int time = schedule[0].first;
    int count =1;
    for(int i=1;i<N;i++){
        if(time<=schedule[i].second){//시작점과 끝점
            count++;
            time=schedule[i].first;
        }
    }
    cout<<count<<"\n";
}