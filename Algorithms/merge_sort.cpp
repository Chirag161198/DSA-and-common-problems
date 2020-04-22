#include<iostream>
#include<vector>

using namespace std;

/*
    Description:
        merges arr[low : mid] and arr[mid+1 : high] in increasing order
    Arguments:
        arr - array to be merged in-place
        low, mid, high - indices
*/
void merge(vector <int> & arr, int low, int mid, int high){
    vector <int> firstArr;
    vector <int> secondArr;

    for(int i=low;i<=mid;i++) firstArr.push_back(arr[i]);
    for(int i=mid+1;i<=high;i++) secondArr.push_back(arr[i]);

    int first = 0;
    int second = 0;
    int i = low;
    while(first<mid-low+1 && second<high-mid){
        if(firstArr[first]<=secondArr[second]){
            arr[i] = firstArr[first];
            first++;
        }    
        else{
            arr[i] = secondArr[second];
            second++;
        }
        i++;
    }
    while(first<mid-low+1){
        arr[i] = firstArr[first];
        first++;
        i++;
    }
    while(second<high-mid){
        arr[i] = secondArr[second];
        second++;
        i++;
    }
}

/*
    Description:
        performs mergesort
    Arguments:
        low - index of first element
        high - index of last element
*/
void mergesort(vector <int> & arr, int low, int high){
    if(low<high){
        int mid = (low+high)/2;
        mergesort(arr, low, mid);
        mergesort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    vector <int> A({1,5,2,7,3,9,0});
    mergesort(A, 0, A.size()-1);
    for(int i=0;i<A.size();i++) cout<<A[i]<<" ";
    cout<<endl;
}