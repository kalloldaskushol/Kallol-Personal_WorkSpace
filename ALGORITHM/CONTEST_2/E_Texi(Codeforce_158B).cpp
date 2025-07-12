#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n; // taking the grp number
    vector<int> vec(n); // making vector
    
    int GrpOne = 0,GrpTwo = 0, GrpThree = 0, GrpFour = 0; // initially they aree 0

    for(int i = 0; i<n; i++){
        cin >> vec[i]; // update them

        if(vec[i] == 1) GrpOne++;
        else if(vec[i] == 2) GrpTwo++;
        else if(vec[i] == 3) GrpThree++;
        else if(vec[i] == 4) GrpFour++;
    }

    int texi = 0;

    texi = texi + GrpFour; // 4 will get 1 texi

    /// pair 3member & 1member groups
    int pair31 = min(GrpThree, GrpOne); // if we have 5grps of 3members and 2 grps of 1 member. There can be 2 pairs. So we use the min to calculate the number of pair can be created by the Grp of one member.

    texi = texi + pair31;
    //now lets cut of them.
    GrpThree = GrpThree - pair31;
    GrpOne = GrpOne - pair31;

    // now the rest 3member grp will have a separate texi.
    texi = texi + GrpThree;

    // Pair 2 member groups.
    // Two grps of 2members will get a texi
    texi = texi + (GrpTwo/2);
    // any unpaired 2member grps left
    GrpTwo = GrpTwo%2; //gives 1 if any pair left

    //we have to give a texi to the left over GrpTwo, So we can do a idea that in the rest two seats we can add two pupils of 1grp member people. but highest we can give two seats so min has to be used.

    if(GrpTwo == 1){
        texi = texi + 1;

        GrpOne = GrpOne - min(GrpOne, 2); // as we have only two seats, if we have 3 grpone then we will take 2 of them. if we have 1 grpOne then we will take the 1.
    }

    // Put the 1 member grps
    if(GrpOne>0){
        texi = texi + ((GrpOne + 3)/4); //if their are 5 person left then we have to give him 2 texi. their can be 1 grpOne left we need a text for him also
    }

    cout << texi << endl;
    return 0;
}