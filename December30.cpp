#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <unordered_map>
#include <queue>
#include <deque>
#include <cmath>//pow함수 선언
#define MAX 500002
using namespace std;

struct cmp{
    bool operator()(int a, int b){
        return a > b; // 부호 주의 swap이기 때문
    } 
};

int main(){
    int testcase;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>testcase;
    priority_queue<int,vector<int>,cmp> heap;
    for(int i=0;i<testcase;i++){
        int tmp;
        cin>>tmp;
        if(tmp==0){
            if(heap.empty()){
                cout<<0<<"\n";
            }else{
                cout<<heap.top()<<"\n";
                heap.pop();
            }
        }else{
            heap.push(tmp);
        }
    }
    return 0;
}


//queue에 struct를 사용해서 연산자를 사용할 수 있음.
#include <iostream>
#include <queue>

// 사용자 정의 구조체
// struct Person {
//     std::string name;
//     int age;

//     // 비교 연산자 정의
//     bool operator<(const Person& other) const {
//         return age < other.age; // 나이를 기준으로 우선순위 결정
//     }
// };

// int main() {
//     // Person을 저장하는 priority_queue
//     std::priority_queue<Person> pq;

//     // 구조체를 생성하여 priority_queue에 추가
//     pq.push({"Alice", 30});
//     pq.push({"Bob", 25});
//     pq.push({"Charlie", 35});

//     // 우선순위에 따라 출력
//     while (!pq.empty()) {
//         Person person = pq.top();
//         std::cout << "Name: " << person.name << ", Age: " << person.age << std::endl;
//         pq.pop();
//     }

//     return 0;
// }
