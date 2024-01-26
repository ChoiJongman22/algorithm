#include <iostream>

#include <vector>

#include <string>

#include <algorithm>

#include <cstring>

using namespace std;

const int INF = 987654321;

const int MAX = 200 + 20;

int cache[MAX][MAX][2];

vector<int> numbers;

vector<string> ops;

void init(vector<string> arr)

{

    for (int i = 0; i < arr.size(); i++)

    {

        if (i % 2 == 0)

        {

            numbers.push_back(stoi(arr[i]));
        }

        else

        {

            ops.push_back(arr[i]);
        }
    }
}

int func(int start, int end, bool isMax)

{
    cout<<"START :"<<start<< "END: "<<end<<endl;
    int &result = cache[start][end][isMax];
    cout<<"isMax: "<<isMax<<endl;
    if (result != -1)
    {
        cout<<"RESULT: "<<result<<endl;
        return result;
    }

    if (start == end)

    {
        result = numbers[start]; //같으면 자기 자신을 저장해주고
        cout<<"RESULT: "<<result<<endl;
        return result;
    }

    result = isMax ? -INF : INF;

    for (int i = start; i < end; i++)

    {
        if (ops[i] == "-")
        {
            cout<<"ops : "<<ops[i]<<endl;
            result = isMax ?
                           max(result, func(start, i, true) - func(i + 1, end, false))//최대는 최대에서 최소를 뺴기
                           :
                           min(result, func(start, i, false) - func(i + 1, end, true));//최소는 최소에서 최대를 뺴기
        }

        else

        {
            cout<<"ops : "<<ops[i]<<endl;
            result = isMax ?

                           max(result, func(start, i, true) + func(i + 1, end, true))
                           :
                           min(result, func(start, i, false) + func(i + 1, end, false));
        }
    }
    cout << "start: " << start << ", end: " << end << ", isMax: " << isMax << ", result: " << result << endl; // 추가된 출력문
    return result;
}

int solution(vector<string> arr)

{
    init(arr);
    cout<<numbers.size()<<" "<<ops.size()<<endl;
    memset(cache, -1, sizeof(cache));//-1로 초기화함.
    return func(0, arr.size() / 2, true);
}

int main(void)

{

    vector<string> arr = {"1", "-", "3", "+", "5", "-", "8"};

    cout << solution(arr) << "\n";
    return 0;
}
