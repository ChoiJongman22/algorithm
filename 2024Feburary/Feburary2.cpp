

// 백준 리모컨 문제
//  #include <iostream>
//  #include <vector>
//  #include <cmath>
//  using namespace std;

// vector<bool> remote(10);//리모컨 고장난지 여부 확인할거야

// //숫자로만 갈 수 있는 지 확인하기
// int check(int n){
//     if(n==0){
//         if(remote[0]){
//             return 0;
//         }else{
//             return 1;
//         }
//         //0번을 누르려고할떄는
//     }
//     int len=0;
//     while(n>0){
//         if(remote[n%10]){
//             return 0;
//         }
//         n=n/10;
//         len+=1;
//     }
//     return len;

// }
// int main(){
//     int N, broke;
//     cin>>N>>broke;

//     for(int i=0;i<broke;i++){
//         int x;
//         cin>> x;
//         remote[x]=true;//고장남
//     }
//     int count=abs(N-100);
//     for(int i=0;i<=1000000;i++){
//         int c=i;
//         int len=check(c);
//         if(len>0){
//             int press=abs(c-N);
//             if(count>press+len){
//                 count=press+len;
//             }
//         }
//     }
//     cout<<count;
//     return 0;
// }

// 백준 스택
// #include <stack>
// #include <iostream>
// using namespace std;

// int main(){
//     stack<int> s;
//     int T;
//     cin>>T;
//     for(int i=0;i<T;i++){
//         int tmp;
//         cin>>tmp;
//         if(tmp==0 && !s.empty()){
//             s.pop();
//         }
//         else{
//             s.push(tmp);
//         }
//     }
//     int answer=0;

//     //이렇게 하면 스택의 요소가 자꾸 비기 때문에 사이즈가 변한다 절대로 이렇게 하지말자.
//     // for(int i=0;i<s.size();i++){
//     //     cout<<s.top()<<"\n";
//     //     answer+=s.top();
//     //     s.pop();
//     // }
//     while(!s.empty()){
//         answer+=s.top();
//         s.pop();
//     }

//     cout<<answer<<"\n";
// }

// 기본에 충실하자 Queue
// 백준 카드2
//  #include <iostream>
//  #include <queue>
//  using namespace std;

// int main()
// {
//     int T;
//     cin >> T;
//     queue<int> q;
//     for (int i = 0; i < T; i++)
//     {
//         q.push(i+1);
//     }
//     while (q.size()>1)
//     {
//         q.pop();
//         q.push(q.front());
//         q.pop();
//     }
//     cout<<q.front()<<'\n';
// }
// #include <iostream>
// #include <map>
// #include <vector>
// using namespace std;

// vector<int> checks(21, 0);
// int check(int i)
// {
//     if (checks[i] == 1)
//     {
//         return 1;
//     }
//     return 0;
// }
// int main()
// {
//     int T;
//     cin >> T;
//     int var;
//     vector<int> S;
//     S.resize(21);
//     map<string, int> ops;
//     ops["add"] = 1;
//     ops["remove"] = 2;
//     ops["check"] = 3;
//     ops["toggle"] = 4;
//     ops["all"] = 5;
//     ops["empty"] = 6;
//     string op;
//     for (int i = 0; i < T; i++)
//     {
//         cin >> op;
//         switch (ops[op])
//         {
//         case 1:
//         {
//             cin >> var;
//             if (check(var) == 0)
//             {
//                 S.push_back(var);
//                 checks[var] = 1;
//             }
//         }
//         break;

//         case 3:
//         {
//             cin >> var;
//             cout << check(var) << "\n";
//         }
//         break;

//         case 2:
//         {
//             cin >> var;
//             if (check(var) == 1)
//             {
//                 S.erase(S.begin() + var);
//                 checks[var] = 0;
//             }
//         }
//         break;

//         case 4:
//         {
//             cin >> var;
//             if (check(var) == 1)
//             {
//                 S.erase(S.begin() + var);
//                 checks[var] = 0;
//             }
//             else
//             {
//                 S.push_back(var);
//                 checks[var] = 1;
//             }
//         }
//         break;

//         case 5:
//         {
//             S.clear();
//             for (int i = 0; i < 20; i++)
//             {
//                 S.push_back(i + 1);
//             }
//         }
//         break;

//         case 6:
//         {
//             S.clear();
//         }
//         break;

//         default:
//             break;
//         }
//     }
// }
