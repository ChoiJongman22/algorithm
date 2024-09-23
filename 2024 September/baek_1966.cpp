//프린터큐
#include <iostream>
using namespace std;
#include <vector>
#include <queue>
int T;
int M, N;



int main()
{
    cin>> T;
    while(T--){
        cin>>N>>M;
        queue<pair<int,int>> q; //pair를 사용함으로써 map을 대체할 수 있다.
        priority_queue<int> pq; //우선순위큐(최대힙)

        for(int i=0;i<N;i++){
            int priority;
            cin>>priority;
            q.push({priority,i}); //pair를 통해 map의 형태로 중요도와 문서 인덱스를 추가
            pq.push(priority);

        }
        int printOrder = 0; //프린트 순서

        while (!q.empty()){
            int curPriority = q.front().first;
            int curIndex = q.front().second;
            q.pop(); //q에서 제거를 해줘야함. 왜냐면 끝나지 않는 경우에는 다시 뒤로 집어넣어줘야함. 

            if(curPriority == pq.top()){
                printOrder++;
                pq.pop();

                if(curIndex == M){
                    cout << printOrder <<endl;
                    break;
                }
            }else{
                q.push({curPriority,curIndex});//다시 넣는 이유는 내가 원하는 문서인데 중요도에 맞지 않으면 다시 뒤로 넣어서 언제 출력되는지를 확인해야하기 때문이다. 
            }
        }
    }
    return 0;
}
