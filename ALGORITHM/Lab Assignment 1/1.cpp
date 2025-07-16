/*
1. Write a code where all five sorts (Insertion, Selection, Bubble, Quick, and Merge Sort) will be defined as five individual functions. An array will be taken as input. And from the Main Function, all five sorting functions will be called using this given array as an argument, and those functions will sort the array with their respective algorithms. Finally, print the sorted array. Must comment on each line describing its work. 
*/
#include <bits/stdc++.h>
using namespace std;

void PrintTheArray(int n, int arr[]) { // print the array
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void BubbleSortFunc(int n, int arr[]) { // Bubble Sort Function
  for (int i = 0; i < n; i++) { // to get all the elements in array 
    for (int j = 0; j < (n - i - 1); j++) { // to compare all the elements with each other
      if (arr[j] > arr[j+1]) { // if the jth element is greater then j+1 th element then push the j th element to j+1 th index
        swap(arr[j], arr[j+1]);
      }
    } // after 1 iteration the largest value will be moved to the last idx
  }
  PrintTheArray(n, arr);
}

void quickSort(int start, int ending, int a[]){  // quick sort function
    if(start> ending) return; // if start is greater than ending then stop

    int pivot = start, i =start, j=ending; // we select pivot as the pointer which will be used to compare, i will start from the lowest index and go till the end, j will start from the last index and will go till the start.

    while(i<=j){ // if i is less than or equal to j then do the work, otherwise the array index is not included
        while(a[i]<=a[pivot])   i++; // if i_th idx of a is less or equal to the pivot_th element of a then increment the i.
        while(a[j]>a[pivot])   j--; // when equal then break that's why we didnt use = sign here. if the j_th idx greater than the pivot_th element of a than decrement the j. 
        if(i < j) swap(a[i], a[j]); // if i is less than the j than swap i and j th idx which will sort the array iinto aceanding order
    }
    swap(a[pivot], a[j]); // swap the pivot element with the j th element, it will make the pivot element positioned correctly
    
    quickSort(start, j-1,a); // call the QC for left sub array
    quickSort(j+1, ending, a); // call the QC for right sub array
}


void insertionSortFunc(int n, int arr[]) { // insertion sort function
  for (int i = 0; i < n; i++) { //to get all the indices
    int pick = arr[i]; //pick the perticular index
    int j = i - 1; // j will be initialized with the previous value of i & it will be used to compare elements with i.
    while (j >= 0 && arr[j] > pick) { // the loop will be working if the value of j is greater than 0(bcz, if the array starts with 0 index)..
      // if the j-th element of the array is greater than the pick element
      swap(arr[j + 1], arr[j]); // if the loop runs means both the condition are true. than lets swap the j+1 th element with jth element
      j--; // decrement the value of j so that the rest values can be compared
    }
    arr[j + 1] = pick; // after the loop ends we got the perfect index to insert the pick, bcz from the 0 to j-th index every element is lesser than the pick element and after j all the elememnts are larger. So finally j+1 is the correct index for my picked element
    }
    PrintTheArray(n, arr); //to print the array 
}


void SelectionSortFunc(int arr[], int n) {
  for (int i = 0; i < (n - 1); i++) { // The loop is to select all the elements of the array
    int mini = i; // This will store the index of the smallest value, at the case we assume that the smallest value is i
    for (int j = i + 1; j < n; j++) { // j loop is to compare the rest values with the mini
      if (arr[j] < arr[mini]) { // if we found any value of j which is less then our current mini then we will change the mini value to the lowest value which is j.
        mini = j;
      }
    }
    if (i != mini) { // now it is time to put the lowest value to the perticular index. If the upper if statement is true at any point then after the loop is terminated, the value of mini will be changed from i to j(which would be the lowest value of array)
        // if the i is equal to mini that we can say that the index holds the correct value, no swaps needed
        // but if i is not equal to mini then the i doesnt holds the correct value we have to swap the mini value to the i-th index 
      swap(arr[i], arr[mini]);
    }
  }

    PrintTheArray(n, arr);// Print the array
}
void MergeingFunc(int L, int mid, int H, int arr[]) { // making merge function
  int m = mid - L + 1; // left sub array size
  int n = H - mid; // right sub array size
  int A[m], B[n]; // making temp array for comparing

  for (int i = 0; i < m; i++) { // giving values of A
    A[i] = arr[L + i]; // the left sub array will start from L
  }
  for (int j = 0; j < n; j++) { // giving values to B
    B[j] = arr[mid + 1 + j]; // the right sub array will start from (mid+1)
  }

  int i = 0, j = 0, k = L; // K = L so that the sorted array in not overwrited
  while (i < m && j < n) { // merging 
    if (A[i] < B[j]) { // if the value of A[i] is less than the B[j] means that the lowest element stands in A[i]
      arr[k] = A[i]; // to give the correct value to the arr[k]
      i++;
      k++;
    } else {
      arr[k] = B[j]; // if it is false then B[j] is the lowest value. Give the value to arr[k]
      j++;
      k++;
    }
  }

  for (; i < m; i++) { //Copy rest elements from A
    arr[k] = A[i];
    k++;
  }
  for (; j < n; j++) { //Copy rest elements from B
    arr[k] = B[j];
    k++;
  }
}

void MargeSortFunc(int L, int H, int arr[]) { // This is the margesort function
  if (L < H) { // if low is equal to high means i got the index value
    int mid = (L + H) / 2; // it will get the mid

    MargeSortFunc(L, mid, arr); // calling the sort for left sub array
    MargeSortFunc(mid + 1, H, arr); // calling the sort for right sub array
    MergeingFunc(L, mid, H, arr); // merging function will merge the values in a sorted way
  }
}

int main(){

    int n;
    cin >> n;
    int arr[n];
    
    for(int i  = 0; i<n; i++){
        cin >> arr[i];
    }

    char sort_name; // Taking the input of what sort does the user wants
    cout << " S for Selection sort \n M for Merge sort \n B for Bubble sort \n I for Insertion sort" <<endl;
    cin >> sort_name;

    switch (sort_name){
        case 'S':
            SelectionSortFunc(arr, n); // Selection Sort function calling
            break;
        case 'M':
            MargeSortFunc(0, n-1, arr); // Merge Sort function calling
            PrintTheArray(n, arr);
            break;
        case 'B':
            BubbleSortFunc(n, arr);  // Bubble Sort function calling
            break;
        case 'I':
            insertionSortFunc(n, arr); // Insertion Sort function calling
            break;
        case 'Q':
            quickSort(0, n-1, arr);
            PrintTheArray(n, arr);
            break;
        default: 
            cout << "wrong cmd" << endl;
            break;
    }
    return 0;
}