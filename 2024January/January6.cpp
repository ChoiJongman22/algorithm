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
#include <limits.h>

#define MAX 20001
using namespace std;
#define INF 987654321
// bool isSafe(int row, int col, vector<string> &board, int n) {
//     // 같은 열 검사
//     for (int i = 0; i < row; i++) {
//         if (board[i][col] == 'Q') {
//             return false;
//         }
//     }

//     // 왼쪽 대각선 검사
//     for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
//         if (board[i][j] == 'Q') {
//             return false;
//         }
//     }

//     // 오른쪽 대각선 검사
//     for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
//         if (board[i][j] == 'Q') {
//             return false;
//         }
//     }

//     return true;
// }

// void solveNQueen(int row, vector<string> &board, int n, vector<vector<string>> &result) {
//     if (row == n) {
//         result.push_back(board);
//         return;
//     }

//     for (int col = 0; col < n; col++) {
//         if (isSafe(row, col, board, n)) {
//             board[row][col] = 'Q';
//             solveNQueen(row + 1, board, n, result);
//             board[row][col] = '.'; // 백트래킹
//         }
//     }
// }

// vector<vector<string>> solveNQueens(int n) {
//     vector<vector<string>> result;
//     vector<string> board(n, string(n, '.'));
// 	//string(n, '.') 구문은 C++에서 std::string 클래스의 생성자로 사용되며, 특정 문자를 반복하여 문자열을 생성합니다. 구체적으로, string(n, '.')은 '.' 문자가 n 번 반복되는 문자열을 만듭니다.

//     solveNQueen(0, board, n, result);
//     return result;
// }

// int main() {
//     int n = 4;
//     vector<vector<string>> solutions = solveNQueens(n);

//     for (auto &solution : solutions) {
//         for (auto &row : solution) {
//             cout << row << endl;
//         }
//         cout << "-----------------" << endl;
//     }
//     return 0;
// }


//설탕 배달문제 백준

int dp[5001];//배열의 크기가 문제에서 요구한거보다 작다면 런타임 오류가 발생할 수 있다. (OutofBounds)
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin>>N;
    dp[3]=1;
    dp[5]=1;
    for(int i=6;i<=N;i++){
        if(dp[i-3]!=0){
            dp[i]=dp[i-3]+1;
        }
        if(dp[i-5]!=0){
            dp[i]=dp[i] ? min(dp[i],dp[i-5]+1):dp[i-5]+1;
        }
    }
    cout<<(dp[N] == 0 ? -1: dp[N])<<endl;
    return 0;
}