#include <bits/stdc++.h>
using namespace std;

int main(){

    int t; // number of test cases
    cin >> t;

    while(t--){ // until the test case number becomes 0 it will run
        string str;
        cin >> str; // input the string

        int size = str.size(); // take the size so that the loop can be worked acording to it

        int i = 0;
        while(i<size){
            char ch = str[i]; // take the character and store it, so that we can chech the contineous frequency of it.
            int cnt = 0; // to count the contineous frequency
                
            // Count how many times the character appears contineously
            while(i<size && str[i] == ch){ // the loop will run for count. and the will got till the size and also if the the i_th character is the same of the ch character.
                cnt++; // uppdate the count 
                i++; // update the i
            }
            cout << cnt << ch; // print the count with the following character.
        }
        cout << endl;
    }

    return 0;
}