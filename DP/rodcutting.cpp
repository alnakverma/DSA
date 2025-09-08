// same as unbounded knapsack
#include<bits/stdc++.h>
using namespace std;

int t[1001][1001]; 
int rodcutting(vector<int>& len, vector<int>& price, int h){
    int n = len.size();
    for(int i=1; i<n+1; i++){
        for(int j=1; j<h+1; j++){
            if(i==0 || j==0) t[i][j]=0;
        }
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<h+1; j++){
            if(len[i-1]<=j){
                t[i][j] = max(price[i-1] + t[i][j-len[i-1]], t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    
    return t[n][h];
}

int main()
{
    int h=10;
    vector<int> len = {4,5,2,7,1};
    vector<int> price = {4,8,2,9,7};
    int k = rodcutting(len,price,h);
    cout<<k<<endl;
    return 0;
}