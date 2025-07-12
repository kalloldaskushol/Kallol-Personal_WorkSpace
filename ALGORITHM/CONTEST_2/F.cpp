#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, r;
    cin >> n >> r; // Number of days and rent cost
    int price[n]; // building array of price

    for(int i = 0;i<n; i++){
        cin >> price[i]; // taking all the price of the respective day
    }

    int maxProfit = 0; // initally maxProfit is 0.

    for(int i = 0; i<n-1; i++){ // last business will be the n-2_th day.
        int profit = price[i] - price[i+1] - r; // the profit will be the selling price(price[i]) - the buying price (price[i+1]) - the rent price.
        
        if(profit>maxProfit){ // if the profit is bigger than maxProfit then update the maxProfit value
            maxProfit = profit;
        }
    }

    cout << maxProfit << endl; // print the maxProfit value

    return 0;
}