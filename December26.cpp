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

int main() {
    int N;
    cin >> N;

    vector<long long> answer(3, 0);
    answer[1]=1;
    answer[2]=2;

    for (int i = 3; i <= N; i++) {
        long long tmp = (answer[i-1] + answer[i-2]) % 15746;
        answer.push_back(tmp);
    }

    cout << answer[N] << "\n";

    return 0;
}
