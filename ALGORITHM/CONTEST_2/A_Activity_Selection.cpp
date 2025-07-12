#include <bits/stdc++.h>
using namespace std;

struct Activity { // we have to make a custom data type, the main reason is we have to use sort in the prgm so that the respective start value goes along with it, we use structure.
    int st;
    int end;

    Activity(int s, int e){ // it is a constructor so that i can initialize the Activity structure easily.
        st = s;
        end = e; 
    }
};

bool compare_By_Endtime(Activity a, Activity b){ // Custom made compare function
    return a.end < b.end; // returns  1 if a_end is greater than b_end otherwise it will swap  
}
int main(){

    int t; // number of test cases
    cin >> t;

    while(t--){ // until the test case number becomes 0 it will run
        int n; // number of activity
        cin >> n;

        vector<Activity> acts; // making a vector of type Activity which is our custom made variable.

        int start, end; 
        for(int i = 0; i<n; i++){
            cin >> start >> end; // taking the value of start and ending time
            acts.push_back(Activity(start, end)); // push back them into our custom made variable. Here we use the benefits of constructor
        }
        sort(acts.begin(), acts.end(), compare_By_Endtime); // soring the vector in acending order of its end_time
        
        // now the acts vector is sorted we will now pick the works.
        // always we select the 1st one bcz it will be selected all the time as it is on the top.
        int count = 1;

        // Every time the end will be changed initially we assume that it's value is 0th end.
        int last_End = acts[0].end;

        for(int i = 1; i<n; i++){ // as the 0th is initalized
            if(acts[i].st >= last_End){  // if the acts start is greater than or equal to the last end means the work can be done without conflict.
                count++; // update the count
                last_End = acts[i].end; // update the end to the current end.
            }
        }

        cout << count << endl; // print the count end
    }

    return 0;
}