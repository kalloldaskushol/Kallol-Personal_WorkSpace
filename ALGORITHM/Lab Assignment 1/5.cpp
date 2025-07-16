/*
5. Write any favourite code of yours from the midterm syllabus, and then comment why this code is your favourite, and share your thoughts using comments on that same code.
*/

/*
Optimal merge pattern is one of the most fvrt codes in the mid term sylebus, the main reason is that, we live in an arra of modern science and for that communication is the main use case of our daily life. For the communication we have to use the memory and if a msg takes more memory it is less optimize. becasuse of the higher cost every msg has to deal with a large space. To solve the problem we use the methods to reduce the size of the msg.

the best method is variable size ending for that we need the Optimal merge pattern algorithm, which helps us to allcated the low code to the higest freq, which feels very interest. By the every step it does the process of reduction. which felt very interesting to me. Also the time comp of the code is very optimal which is O(nlogn). means its not only a workfull code but also works in a optimal time. Thats why it is my fvrt code.
*/
#include <bits/stdc++.h>
using namespace std;

int optimalMerge(vector<int> files) { // O(nlogn) complexity
    
    priority_queue<int, vector<int>, greater<int> > minHeap; // Build the min-heap
    for (int i = 0; i < files.size(); i++) {
        minHeap.push(files[i]);
    }
    int total_COST = 0; // initally total cost is 0.
    
    while(minHeap.size() > 1){ // I have to get minimum 2 for Merging 
        int first = minHeap.top(); // to get the 1st minimum element
        minHeap.pop();
        
        int second = minHeap.top(); // to get the 2nd minimum element
        minHeap.pop();
        
        int merge_COST = first + second; // Merge cost of both.
        total_COST = total_COST + merge_COST;

        minHeap.push(merge_COST); // push the Merge_Cost 
    }
    
    cout<< minHeap.top() << endl;
    return total_COST;
}

int main() {
  vector<int> files = {10, 20, 30, 5, 30};  // Making array by 5 arrays size

  int cost = optimalMerge(files);

  cout << "Minimum Cost: " << cost << endl;

  return 0;
}