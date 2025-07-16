/*
4. Write a code to implement both LCS and EDIT distance. Both should be in separate functions. If I press 'L', it will call the LCS function and calculate the LCS and its subsequence. If I press 'E', it will call the ED function and determine the edit distance as well as the operations.
*/

#include <bits/stdc++.h>
using namespace std;

void ED(){
    cin.ignore();
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    int m = s1.size(); // s1 to col -> s1 need to be changed
    int n = s2.size(); 

    int edit[n+1][m+1];

    for(int i = 0; i<n+1; i++){ // insertion up->down 
        edit[i][0] = i;
    }
    for(int j = 0; j<m+1; j++){ // delete left -> right
        edit[0][j] = j;
    }

    
    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<m+1; j++){
            if(s2[i-1] == s1[j-1]){ // matched so the value comes directly from the diagonal
                                    // s2 in row so we use s1[j-1];
                                    // s1 in col so we use s1[i-1];   
                edit[i][j] = edit[i-1][j-1];
            } else {
                edit[i][j] = 1 + min({edit[i-1][j], edit[i][j-1], edit[i-1][j-1]});
            }
        }
    }

    
    for(int i = 0; i<n+1; i++){
        for(int j = 0; j<m+1; j++){
            cout << edit[i][j] << " ";
        }
        cout << endl;
    }

    int i = n, j = m;
    while(i>0){
        if(s2[i-1] == s1[j-1]){ // matched no operation
            i = i - 1;
            j = j - 1;
        } else {
            if(edit[i][j] == 1 + edit[i-1][j-1]){ // replace
                cout << s1[j-1] << " is replaced to " << s2[i-1] << endl;
                i = i - 1;
                j = j - 1;
            } else if (edit[i][j] == 1 + edit[i-1][j]){ // insert
                cout << s2[i-1] << " is inserted " << endl;
                i = i - 1;

            } else { // delete
                cout << s1[j-1] << " is deleted "<< endl;
                j = j - 1;
            }
        }
    }
}
int n, m;

int LCS (){
    cin.ignore();  // To clear newline after taking 'L'
    
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    int n = s1.size(); // row
    int m = s2.size(); // col

    int LCS[n+1][m+1];

    for(int i = 0; i<n+1; i++){ // col 0
        LCS[i][0] = 0;
    }
    for(int j = 0; j<m+1; j++){ // row 0
        LCS[0][j] = 0;
    }

    
    for(int i = 1; i<n+1; i++){ 
        for(int j = 1; j<m+1; j++){

            if(s1[i-1] == s2[j-1]){ // -1 so that we can cal the 0th index of s1 and s2.
                LCS[i][j] = 1 + LCS[i-1][j-1];
            } else {
                LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]);
            }
        }
    }

    for(int i = 0; i<n+1; i++){
        for(int j = 0; j<m+1; j++){
            cout << LCS[i][j] << " ";
        }
        cout << endl;
    }
    // sequecnce
    string ans;
    int i = n, j= m;

    while(i>0){
        if(s1[i-1] == s2[j-1]){
            ans.push_back(s2[j-1]); // s2 cz the value comes from col
            i = i-1;
            j = j-1;
        } else {
            if(LCS[i][j] == LCS[i-1][j]){ // comes from up
                i = i - 1;
            } else { // comes from left 
                j = j - 1;
            }
        }
    }

    for(int i = ans.size()-1; i>=0; i--){
        cout << ans[i];
    }

}
int main(){

    char test; 
    cin>>test;
    
    switch (test){
        case 'L':
            LCS();
            break;

        case 'E':
            ED();
            break;
    }


    return 0;
}