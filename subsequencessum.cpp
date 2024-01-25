#include <bits/stdc++.h>
using namespace std;
void sumsubsequences(int ind , vector<int>& v, int sum ,int n, vector<int> &arr){
    if(ind == n){
        v.push_back(sum);
        for (auto i : v)
        {
            cout << i << " ";
        }
        return;
    }
    
    sumsubsequences(ind + 1, v, sum + arr[ind],n,arr);

    sumsubsequences(ind + 1, v,sum,n,arr);

    
}
int main(){
    vector<int> g = {1 , 6 , 7 , 8};
    int n = 4;
    vector<int> ans;
    sumsubsequences(0 , ans, 0 ,n,g);
    return 0;
    //return 0;
}