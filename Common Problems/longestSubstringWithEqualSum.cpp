#include<iostream>
#include<string>

using namespace std;

int main(){
    int n, len, maxLength = -1, start, end, halfSum, firstHalfSum, secondHalfSum;
    string s;

    cin>>s;
    n = s.length();
    
    float cumulativeSum[n];

    cumulativeSum[0] = int(s[0]-'0');
    for(int i=1;i<n;i++)
        cumulativeSum[i] = cumulativeSum[i-1] + int(s[i]-'0');

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j += 2){
            len = j-i+1;
            
            if(maxLength>len)
                continue;

            firstHalfSum = cumulativeSum[i + len/2 - 1];
            firstHalfSum -= i!=0 ? cumulativeSum[i-1]:0;

            secondHalfSum = cumulativeSum[j]-cumulativeSum[i + len/2 - 1];
            if(firstHalfSum==secondHalfSum){
                maxLength = len;
                start = i;
                end = j;
                halfSum = firstHalfSum;
            }
        }
    }

    if(maxLength==-1)
        cout<<"No such sub-string"<<endl;
    else{
        for(int i=start;i<=end;i++)
            cout<<s[i];

        cout<<endl<<"Sum of half sub-string = "<<halfSum<<endl;
    }
}