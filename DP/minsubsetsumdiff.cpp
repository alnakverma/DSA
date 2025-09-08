#include<bits/stdc++.h>
using namespace std;

bool t[1001][1001]; 
int minsubsetsumdiff(vector<int>& arr, int sum){
    //subset sum code
    int n = arr.size();
    vector<int> temp;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(j == 0) t[i][j] = true;
            else if(i == 0) t[i][j] = false;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(arr[i-1]<=j){
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
            //storing the last row of the table in temp where the stored value is true
            //collecting all possible subset sums from the last row
            if(i==n-1 && t[i][j]==true) temp.push_back(j);
        }
    }
    //Finding the minimum subset sum difference
    int mn = INT_MAX;
    for(int i=0; i<n; i++){
        mn = min(mn, sum-2*temp[i]);
    }
    return mn;
}

int main()
{
    int sum = 0, n = 3;
    vector<int> arr = {1,2,5};
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }
    cout<<minsubsetsumdiff(arr,sum)<<endl;
    return 0;
}

