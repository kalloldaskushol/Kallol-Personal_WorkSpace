/*
3. Write a code to implement both the 0/1 knapsack and the coin change problem. Both should be in separate functions. If I press '0' , it will call the zeroone function and calculate the maximum profit and the selected objects. If I press 'C', it will call the coinchange function and determine the minimum number of coins as well as the selected coin's types.
*/ 
#include<bits/stdc++.h>
using namespace std;

void ZeroOne_Knapsack(){
    int n, m;
    cin >> n >> m;
    int profit[n];
    int weight[n];

    for(int i = 0; i<n; i++){
        cin >> profit[i];
    }
    for(int i = 0; i<n; i++){
        cin >> weight[i];
    }
    
    int sack[n+1][m+1];
    
    for(int i = 0; i<n+1; i++){
        sack[i][0] = 0;
    }
    for(int j = 0; j<m+1; j++){
        sack[0][j] = 0;
    }

    for(int i = 1; i < n+1; i++){
        for(int j = 1; j<m+1; j++){

            if(weight[i - 1] > j){
                sack[i][j] = sack[i-1][j];
            } else{
                sack[i][j] = max(sack[i-1][j], sack[i-1][j - weight[i-1]] + profit[i-1]);
            }
        }
    }

    for(int i = 0; i<n+1; i++){
        for(int j = 0; j<m+1; j++){
            cout << sack[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Max Profit " << sack[n][m] << endl;
    
    int i = n, j = m;

    while(i>0){
        
        if(sack[i][j] == sack[i-1][j]){
            --i;
            continue; 
        } else {
            cout << "Product " << i << " is selected "<< endl;
            j = j - weight[i-1];
            --i;
        }
    }
}

void Coin_Change(){
    int n, m;
    cin >> n >> m;

    int coin[n];

    for(int i = 0; i<n; i++){
        cin >> coin[i];
    }

    long long int dp_coin[n+1][m+1];
    for(int i = 0; i < n+1; i++){
        dp_coin[i][0] = 0;
    }
    for(int j = 1; j < m+1; j++){
        dp_coin[0][j] = INT_MAX;
    }

    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<m+1; j++){
            
            if(coin[i-1] > j){
                dp_coin[i][j] = dp_coin[i-1][j];
            } else {
                dp_coin[i][j] = min(dp_coin[i-1][j], 1 + dp_coin[i][j - coin[i - 1]]);
            }
        }
    }

    for(int i = 0; i<n+1; i++){
        for(int j = 0; j<m+1; j++){
            cout << dp_coin[i][j] << " ";
        }
        cout << endl;
    }

    int i = n, j = m;
    while(i > 0){
        
        while(dp_coin[i][j] != dp_coin[i - 1][j]){
            j = j - coin[i - 1];
            cout << coin[i - 1] << " is selected " << endl;
            continue;
        }
        --i;
    }
}

int main(){
    
    char ch;
    cin >> ch;

    switch(ch){
        case('C'):
        Coin_Change();
        break;

        case('0'):
        ZeroOne_Knapsack();
        break;
    }
    
    return 0;
}