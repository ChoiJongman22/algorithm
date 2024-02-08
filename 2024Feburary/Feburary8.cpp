#include <iostream>
#include <vector>
using namespace std;


//스위치 켜고 끄기

int main(){
    int T;
    cin>>T;
    vector<int> swc(T,0);
    for(int i=0;i<T;i++){
        cin>>swc[i];
    }
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int gender, num;
        cin>>gender>>num;
        if(gender==1){
            for(int j=num-1;j<T;j+=num){
                swc[j]=1-swc[j];
            }
        }else{
            num--;
            swc[num]=1-swc[num];
            int left=num-1,right=num+1;
            while(left>=0 &&right<T &&swc[left]==swc[right]){
                swc[left]=1-swc[left];
                swc[right]=1-swc[right];
                left--;
                right++;

            }
        }
    }
    for(int i=0;i<T;i++){
        cout<<swc[i]<<" ";
        if((i+1)%20==0){
            cout<<"\n";
        }
    }
    return 0;

    


}


//주유소



//타노스


