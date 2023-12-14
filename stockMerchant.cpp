// int sockMerchant(int n, vector<int> ar) {

//     int pair = 0;
//     int size = ar.size();
//     sort(ar.begin(),ar.end());

//     for(int i=0; i<size; i++){
                
//         while(ar[i] == ar[i+1] && i < n-1){
//             i++; //counter
//         }
//         cout << i << "\n";   
        
//         // FINDS NUMBER OF PAIRS 
//         if(cnt % 2 != 0){
//             int n = cnt - (cnt%2); // (finding closest num div by 2)
//             pair += n/2;
//         }else{
//             pair += cnt/2;
//         }    
//     }
//     return pair;
// }

int sockMerchant(int n, vector<int> ar) {
    
    sort(ar.begin(), ar.end());
    int i = 0,pair = 0;
    char flag = 'n';
    
    while(i<ar.size())
    {
        for(int j=i; j < ar.size(); j++){
            if(ar[j] == ar[j+1]){
                pair++;
                i = j+2;
                break;
            }
            if(j >= n-1 ){
                flag = 'y';
            }
        }
        if(flag == 'y'){
            break;
        }
    }    
    return pair;
}