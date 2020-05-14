#include<iostream>
#include<string>

using namespace std;

int main(){
    int n, len, maxLength = -1, start, end, halfSum, firstHalfSum, totalSum;
    string s;

    cin>>s;
    n = s.length();
    
    for(int i=0;i<n;i++){
        
        firstHalfSum = 0;
        totalSum = 0;

        for(int j=i+1, k=i;j<n;j += 2, k++){
            firstHalfSum += int(s[k]-'0');
            totalSum += int(s[j-1]-'0') + int(s[j]-'0');

            len = j-i+1;
            
            if(maxLength>len)
                continue;

            if(firstHalfSum==totalSum-firstHalfSum){
                maxLength = len;
                start = i;
                end = j;
                halfSum = firstHalfSum;
            }
        }
    }

    cout<<endl;
    if(maxLength==-1)
        cout<<"No such sub-string"<<endl;
    else{
        cout<<"Sub-string: ";
        for(int i=start;i<=end;i++)
            cout<<s[i];

        cout<<endl<<"Sum of half sub-string = "<<halfSum<<endl;
    }
}