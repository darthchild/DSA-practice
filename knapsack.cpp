#include <bits/stdc++.h>
using namespace std;

int main(){
    int p[7] = {10,5,15,7,6,18,3};
    int w[7] = {2,3,5,7,1,4,1};
    int pw[7];
    int cnt = 0;
    int tot = 0;  //total profit

    int size = sizeof(p)/sizeof(p[0]);
    int m = 15;

    for(int i=0; i<=size; i++){
        pw[i] = p[i]/w[i];
    }

    sort(pw,pw+size);
    sort(w,w+size);
    sort(p,p+size);

    for(int i=1; i<=size; i++){   
        if(m>0 && w[i]<=m){
            m -= w[i];
            tot += p[i];
            cnt++;
        }else{
            break;
        }

        //fractional case
        if(m>0){
            tot += (m/w[cnt] * p[cnt])
        }
    }
}