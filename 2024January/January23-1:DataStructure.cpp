#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <queue>
#include <deque>
#include <cmath> //pow함수 선언
#include <limits.h>
#include <map>
#include <utility> // std::pair 헤더
using namespace std;
//Stack
int main() {
    stack<int> s;
    s.push(1); // 원소 1 삽입
    s.push(2); // 원소 2 삽입
    s.push(3); // 원소 3 삽입

    cout << "Top element: " << s.top() << endl; // 최상위 원소 출력 (3)
    s.pop(); // 최상위 원소 제거
    cout << "Top element after pop: " << s.top() << endl; // 최상위 원소 출력 (2)

    return 0;
}
//큐
int main() {
    queue<int> q;
    q.push(1); // 원소 1 삽입
    q.push(2); // 원소 2 삽입
    q.push(3); // 원소 3 삽입

    cout << "Front element: " << q.front() << endl; // 맨 앞 원소 출력 (1)
    q.pop(); // 맨 앞 원소 제거
    cout << "Front element after pop: " << q.front() << endl; // 맨 앞 원소 출력 (2)

    return 0;
}

//이진 탐색 트리
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int val) {
    if (!root) {
        return new Node(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }

    return root;
}

bool search(Node* root, int val) {
    if (!root) {
        return false;
    }

    if (val == root->data) {
        return true;
    } else if (val < root->data) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    if (search(root, 40)) {
        cout << "Found 40 in the tree." << endl;
    } else {
        cout << "40 not found in the tree." << endl;
    }

    return 0;
}

//Heap

int main() {
    vector<int> heap;

    // 원소 추가
    heap.push_back(3);
    heap.push_back(2);
    heap.push_back(5);
    heap.push_back(1);
    heap.push_back(6);

    // 최소 힙 구성
    make_heap(heap.begin(), heap.end(), greater<int>());

    cout << "Min element: " << heap.front() << endl; // 최소 원소 출력 (1)

    // 원소 제거
    pop_heap(heap.begin(), heap.end(), greater<int>());
    heap.pop_back();

    cout << "Min element after pop: " << heap.front() << endl; // 최소 원소 출력 (2)

    return 0;
}
//해시 테이블
int main() {
    unordered_map<string, int> hashTable;
    
    // 키-값 쌍 추가
    hashTable["apple"] = 5;
    hashTable["banana"] = 3;
    hashTable["cherry"] = 8;

    // 값 조회
    cout << "Number of apples: " << hashTable["apple"] << endl;
    
    // 존재 여부 확인
    if (hashTable.find("banana") != hashTable.end()) {
        cout << "Banana exists." << endl;
    } else {
        cout << "Banana does not exist." << endl;
    }

    return 0;
}
//그래프

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int V = 5; // 정점 개수
    vector<vector<int>> graph(V); // 인접 리스트

    // 간선 추가
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(3);
    graph[3].push_back(4);

    // 간선 출력
    for (int i = 0; i < V; i++) {
        cout << "Adjacent vertices of " << i << ": ";
        for (int j : graph[i]) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
