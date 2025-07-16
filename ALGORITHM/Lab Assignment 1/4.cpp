/*
4. Write a code to implement both LCS and EDIT distance. Both should be in separate functions. If I press 'L', it will call the LCS function and calculate the LCS and its subsequence. If I press 'E', it will call the ED function and determine the edit distance as well as the operations.
*/

#include <bits/stdc++.h>
using namespace std;

int n, m;

int LCS (char A[], char B[], int i, int j){
    if(i==n || j==m) return 0;
    
    else if(A[i] == B[j]) return 1 + LCS(A,B,++i,++j);
    
    else return max(LCS(A, B, ++i, j), LCS(A, B, i, ++j));

}
int main(){

    char test; cin>>test;
    
    switch(test){
        case 'L':
            cin >> n >> m;
            char A[n], B[m];
            cin >> A >> B;
            
            int ans = LCS(A, B, 0, 0);
            cout << ans << endl; 
            break;

        case 'E'
    }


    return 0;
}