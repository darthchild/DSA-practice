/*

You are given an m x n integer grid accounts where accounts[i][j] is the amount 
of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. Return the wealth that the richest customer has.

A customer's wealth is the amount of money they have in all their bank accounts. 
The richest customer is the customer that has the maximum wealth.

 

Example 1:

Input: accounts = [[1,2,3],[3,2,1]]
Output: 6
Explanation:
1st customer has wealth = 1 + 2 + 3 = 6
2nd customer has wealth = 3 + 2 + 1 = 6
Both customers are considered the richest with a wealth of 6 each, so return 6.

*/



int max(int arr[], int length) {            
    
    int max = arr[0];         
    for (int i = 0; i < length; i++) {      
       if(arr[i] > max)    
           max = arr[i];    
    }  
    return max;  
}

int maximumWealth(int** accounts, int accountsSize, int* accountsColSize){

    int cust = accountsSize;
    int bank = *accountsColSize;
    int wealth[cust];
    int sum;

    for(int i=0; i<cust; i++){
        sum = 0;
        for(int j=0; j<bank; j++){
            sum += accounts[i][j];
        }
        wealth[i] = sum;
    }
    
    return max(wealth,cust);
}


// BETTER MORE CONCISE SOLUTION 

int maximumWealth(int** accounts, int accountsSize, int* accountsColSize){
        int res = 0;
        for(int i =0;i<accountsSize;i++){
            int temp = 0;
            for(int j = 0;j<*accountsColSize;j++){
                temp+=accounts[i][j];
            }
            if(temp > res) res = temp;
        }
        return res;
}