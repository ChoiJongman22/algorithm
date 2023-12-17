//행렬 덧셈 공부하면서 이차원 배열 복습하기
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include<stack>

using namespace std;

// int main(){
//     int n,m;
//     cin>>n>>m;
//     int** arr1 = new int* [n];//메모리 할당
//     int** arr2 = new int* [n];//메모리 할당
//     for (int i = 0; i < n; ++i)	{		
//         arr1[i] = new int[m];		
//         arr2[i] = new int[m];	
//     }
//     for(int i=0;i<n;++i){
//         for (int j=0;j<m;++j){
//             cin>>arr1[i][j];
//         }
//     }
//     for(int i=0;i<n;++i){
//         for (int j=0;j<m;++j){
//             cin>>arr2[i][j];
//         }
//     }
//     for(int i=0;i<n;++i){
//         for (int j=0;j<m;++j){
//             cout<<arr1[i][j]+arr2[i][j]<<' ';
//         }
//         cout<<'\n';
//     }
//     for(int i=0;i<n;i++){
//         delete[] arr1[i];//메모리 해제
//         delete[] arr2[i];//메모리 해제
//     }
//     delete[] arr1;
//     delete[] arr2;

// }

//색종이

// int main(){
//     bool paper[100][100]={0};//모두 0으로 초기화하기
//     int sum=0;
//     int n;
//     cin>>n;
    

//     while(n--){
//         int x,y;
//         cin>>x>>y;
//         for (int i = y; i < y+10; i++){
//             for(int j=x; j< x+10; j++){
//                 if(paper[i][j]) continue;
//                 paper[i][j]=1;
//                 sum++;
//             }
//         }
//     }
    
//     cout<<sum<<endl;
//     return 0;


// }

//브루트포스

// int main(){
//     int n,m;
//     cin>>n>>m;
//     int goal;
//     int min=99999;
//     int* arr1=new int[n];
//     int a=0;
//     for (int i = 0;i<n;i++){
//         cin>>a;
//         arr1[i]=a;

//     }
//     int sum=0;
//     for(int i=0; i<n-2 ;i++){
//         for(int j=i+1; j<n-1 ;j++){
//             for(int k=j+1; k<n ;k++){
//                 sum=arr1[i]+arr1[j]+arr1[k];
//                 if (m-sum<min && m-sum>=0){
//                     min=m-sum;
//                     goal=sum;
//                 }
//             }
//         }        
//     }
//     cout<<goal<<endl;
//     delete[] arr1;

//     return 0;
// }


// int main(){
//     int n;
//     cin>>n;
//     int x,y;
//     x=n/5;
//     while (1){
//         if (x<0){
//             cout<<"-1";
//             return 0;
//         }
        
//         if((n-(5*x))%3==0){
//             y=(n-(5*x))/3;
//             break;
//         }
//         x--;
//     }
//     cout<<x+y<<endl;
//     return 0;
// }


//문자열 공부

// int main(){
//     string s="Test";
//     cout<<s[0];

//     int a=2;
//     string b;
//     b=to_string(a);
//     cout<<b<<endl;

//     string str_a ="7";
//     string str_b ="7.02";
//     string str_c ="3.14";
//     string str_d = "2300000000";

//     int after_a = stoi(str_a); // "7"을 int형 7로 바꿔줌
//     double after_b = stod(str_b); // "7.02"를 double형 7.02로 바꿔줌
//     float after_c = stof(str_c); // "3.14"를 float형 3.14로 바꿔줌
//     long int after_d = stof(str_d); // "2300000000"을 long int형으로 바꿔줌
//     cout<<b.capacity()<<endl;
//     string c;
//     cout<<c.capacity()<<endl;
//     c.reserve(100);
//     cout<<c.capacity()<<endl;
//     cout<<c.empty()<<endl;
//     c="Almighty";
//     c.append("f");
//     cout<<c<<endl;

//     string str1 = "TEST";
//     string str2 = "ST";

//     cout<<str1.find(str2)<<endl; // 2 반환 (TEST에서 ST의 S는 2번째 인덱스므로)


//     // string str1 = "TEST";
//     // string str2 = "your";
//     // str1.replace(1, 2, str2); // str1의 1번째 인덱스인 E부터 2개의 길이만큼의 문자열이 str2로 변경
//     // string str1 = "TEST";
//     // str1.replace(str1.begin()+1, str1.begin()+4, "aa");
//     // // EST를 aa로 변경하여, TaaT 가 반환됨


//     string str3 = "aaad";
//     string str4 = "aaaf";

//     cout << (str3 < str4)<<endl; // 1(참)이 반환됩니다.
//     // 즉, str1과 str2 중 사전 순으로 str1이 더 앞선 글자므로, str2보다 작습니다.

//     string str5 = "10";
//     string str6 = "6";

//     cout << (str5 < str6); // 1이 반환됩니다.
//     // 즉, 사전순으로는 10이 6보다 앞서 있기 때문입니다.

//     string str7 = str5 + str6; // "106"
//     string str8 = str6 + str5; // "610"

//     cout << (str7 < str8); // "610"이 사전 순서상 더 뒤이므로 크고, 1이 반환됩니다.
//     // 이를 응용하면, 같은 자릿수로 받아진 정수 형태(ex: "1234")의 문자열 비교는
//     // 단순히 int형끼리 비교하는 것과 같습니다.    
//     return 0;
// }


//문자열 다루기 1
// int main(){
//     string a;
//     int b;
//     cin>>a;
//     cin>>b;
//     for (int i=0;i<a.length();i++){
//         if(i==b-1){
//             cout<<a[i]<<endl;
//         }
//     }
//     return 0;

// }

//문자열 다루기 2
// int main(){
//     int testcase;
//     int r1;
//     string s1;
//     string s2="";
//     vector<string> strArray; 
//     cin>>testcase;
//     while(testcase--){
//         cin>>r1>>s1;
//         for (int i=0;i<s1.length();i++){
//             for(int j=0;j<r1;j++){
//                 s2+=s1[i];
//             }      
//         }
//         strArray.push_back(s2);
//         s2="";
//     }
//     for (int i=0;i<strArray.size();i++){
//         cout<< strArray[i]<<endl;
//     }
//     return 0;
// }

// 그대로 출력하기
// int main(){
//     string s1;

//     while(true){
//         getline(cin,s1);
//         if (s1==""){
//             break;
//         }
//         cout<<s1<<endl;
//     }
//     return 0;

// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     int testcase;
//     cin>>testcase;
//     int idx;
//     int Array[10001]={};
//     for (int i=0;i<testcase;i++){
//         cin>>idx;
//         Array[idx]+=1;
//     }

//     for (int i=1;i<=10000;i++){
//         for(int j=1; j<=Array[i];j++){
//             cout << i << "\n";
//         }
//     }
// }

//포켓몬 문제 풀이
// int main(){
//     map<string, int> pokemon;
//     vector<string> name;
//     int n,m;
//     string a;
//     cin>>n>>m;
//     vector<string> result;

//     for(int i=1;i<=n;i++){
//         cin>>a;
//         name.push_back(a);
//         pokemon.insert(make_pair(a,i));
//     } 
//     for(int i=0;i<m;i++){
//         cin>>a;
//         if(a[0]>=65 && a[0]<=90){
//             result.push_back(to_string(pokemon[a]));
//         }
//         else{
//             result.push_back(name[stoi(a)-1]);
//         }
        
//     }
//     for(int i=0;i<result.size();i++){
//         cout<<result[i]<<"\n";
//     }

// }

int main(){
    stack<char> pr;
    int testcase;
    cin>>testcase;
    cin.ignore();

    for(int i=0;i<testcase;i++){
        int cnt=0;
        string a;
        getline(cin, a);
        for(int j=0;j<a.length();j++){
            if (a[j]=='('){
                pr.push(a[j]);
            }
            else if(a[j]==')'){
                if(!pr.empty()){
                    pr.pop();
                }
                else{
                    cnt++;
                }
            }
        }
        if(!pr.empty()){
            cout<<"NO"<<'\n';
        }
        else if(cnt!=0){
            cout<<"NO"<<'\n';
        }
        else{
            cout<<"YES"<<'\n';
        }
        while(!pr.empty()){
            pr.pop();
        }
    }
    return 0;
}
