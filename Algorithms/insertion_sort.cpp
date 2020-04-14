#include<iostream>
#include<vector>

using namespace std;

void InsertionSortDecreasing(vector <int> & list){
    int n = list.size();
    for(int i=1;i<n;i++){
        int element = list[i];
        for(int j=0;j<i;j++){
            if(element>list[j]){
                int breakIndex = j;
                for(int k=i;k>breakIndex;k--){
                    list[k] = list[k-1];
                }
                list[breakIndex] = element;
                break;
            }
        }
    }
}

void InsertionSortIncreasing(vector <int> & list){
    int n = list.size();
    for(int i=1;i<n;i++){
        int element = list[i];
        for(int j=0;j<i;j++){
            if(element<list[j]){
                int breakIndex = j;
                for(int k=i;k>breakIndex;k--){
                    list[k] = list[k-1];
                }
                list[breakIndex] = element;
                break;
            }
        }
    }
}

void show(vector <int> & list){
    for(int i=0;i<list.size();i++){
        cout<<list[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n; // Size of sequence
    
    vector <int> list(n);
    for(int i=0;i<n;i++){
        cin>>list[i];
    }

    InsertionSortDecreasing(list);
    show(list);
}