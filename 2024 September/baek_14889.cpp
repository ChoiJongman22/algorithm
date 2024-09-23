#include <iostream>
using namespace std;
#include <vector>

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> S(N, vector<int>(N, 0));
    vector<pair<int,int>> P;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> S[j][i];
            if(i!=j){
            P.push_back(make_pair(j, i));  // pair로 저장

            }
        }
    }
    int min = S[P[0].first][P[0].second] + S[P[0].second][P[0].first];
    vector<int> answer;
    for(int i =1;i<P.size();i++){
        int a = S[P[i].first][P[i].second] + S[P[i].second][P[i].first];

    }
    cout << min ;
}