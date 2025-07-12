#include <bits/stdc++.h>
using namespace std;

int main(){

    int n; //no of std
    int k; // no of min time HOD wants them
    cin >> n >> k;
    
    int count = 0; // the no of std is allowed to go
    for(int i = 0; i<n; i++){ // taking input the of the no of time they had already participated
        int j;
        cin >> j;

        if(5-j >= k) count++; // max time possible acording to the ICPC rule is 5, and the std had already participated j time, so left is 5-j th time they can go to the ICPC. The HOD wants that the number of 5-j should be greater than or equal to the k time
    }

    int team = count/3; // each team is created by 3 members
    cout << team <<endl; // no of teams

    return 0;
}