// NON CONTINOUS STRING SEARCH

/*
find if string s = "haacdkerrranuk" contains 
the string "hackerrank" in a non contiguos fashion
print YES if it does
*/


#include <iostream>
#include <string>
using namespace std;


void stringSearch(string txt){
    
    string pat ="hackerrank";
    int currentIndex = 0;    

    for(int i = 0; i < txt.size(); i++){
        if(txt[i] == pat[currentIndex]){
            currentIndex++;
            if(currentIndex == pat.size()) return "YES";
        }
    }
    return "NO";
}

int main(){
    stringSearch("crackerhackerknar","hackerrank");
    //stringSearch("aloubefecihihd","abcd");
}


/*
HA a C d KERAN u K
equal comparisons = 10 (cuz of double A)

HACKERRANK, m = 10
*/












// void stringSearch(string txt, string pat){
//     cout << endl;
    
//     int n = txt.length();
//     int m = pat.length();
//     int i,j,start;
//     int cnt=0;
//     int num = -250;
//     int flag = 0;

//     for (i=0; i<n; i++){
//         cout<<"i = "<<i<<endl;
//         if(flag == 1)
//             start = i+1;
//         else
//             start = i;
//         cout<<"start = "<<start<<endl;
//         if(start>=num){
//             for(j=start; j<n; j++){
//                 if(cnt == m){
//                     break;
//                 } else if(pat[i] == txt[j] ){
//                     cnt++;
//                     cout << txt[j]<<i<<","<<j<<endl;
//                     break;
//                 }
//             }
//         }
//         num = j;
//         cout <<"num = " <<num<<endl;
//         if(j==i+1)
//             flag = 1;
//         else
//             flag = 0;
            
//     }
//     if(cnt==m)
//         cout << "YES" <<"\n";
//     else
//         cout << "NO" << "\n";

//     cout << endl;
// }




//"abDEcLMdEE"
// "abcd"