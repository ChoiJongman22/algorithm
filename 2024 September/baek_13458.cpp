// 시험 감독
#include <iostream>
using namespace std;
#include <vector>

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    int B, C;
    vector<int> testClass(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> testClass[i];
    }
    cin >> B >> C;
    long long supervisor = 0;  // long long으로 선언해 큰 수를 처리할 수 있게 합니다.
    for (int i = 0; i < N; i++)
    {
        supervisor += 1;
        if (testClass[i] - B > 0)
        {
            int tmp = testClass[i] - B;
            supervisor += (tmp + C - 1) / C;  // 나머지가 있을 경우 부감독관이 한 명 더 필요

        }
    }
    cout << supervisor;
    return 0;
}