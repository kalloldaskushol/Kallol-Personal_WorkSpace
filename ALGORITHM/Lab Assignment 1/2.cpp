/*
2. Write a code to implement the greedy knapsack. But the greedy part has to be in a separate function. The test case of giving input has to be defined so that I can check it as many times as I want. Must use structure sort, or else you can use pair also.
*/
#include <bits/stdc++.h>
using namespace std;

void PrintTheArray(int n, double arr[]) { // print the array
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

struct knap{
    int obj;
    double P_by_W;
};

bool compareByPbyW(knap n1, knap n2){
    return n1.P_by_W > n2.P_by_W;
}

double knapSack(int n, int m, int profit[], int weight[]){
    knap sack[n];

    for(int i = 0; i<n; i++){
        sack[i].obj = i;
        sack[i].P_by_W = double(profit[i])/ double(weight[i]);
    }

    sort(sack, sack+n, compareByPbyW);

    int RW = m;
    double X[n];
    memset(X, 0.0, sizeof(X));

    int i = 0;
    while(RW>0 && i < n){

        if(RW >= weight[ sack[i].obj ] ){
            X[sack[i].obj] = 1;
            RW -= weight[sack[i].obj];
            i++;
        } else {
            X[sack[i].obj] = double(RW) / double(weight[ sack[i].obj ]);
            RW = 0;
        }
    }
    PrintTheArray(n,X);

    double maxProfit = 0;
    for(int i = 0; i<n; i++){
        maxProfit += (X[i] * double(profit[i]));
    }
    return maxProfit;
}
int n, m;
int main(){

    int T;
    cin >> T;
    while(T--){
        cin >> n;
        cin >> m;
    
        int profit[n];
        int weight[n];
        for(int i = 0; i<n; i++){
            cin >> profit[i];
        }
        for(int i = 0; i<n; i++){
            cin >> weight[i];
        }
        cout << knapSack(n, m, profit, weight);    
    }
    return 0;
}