#include <bits/stdc++.h>
using namespace std;
void printsubwithsum(int ind, vector<int> &v, int initial, int arr[], int sum, int n)
{
    if (ind == n)
    {
        if (initial == sum)
        {
            for (auto i : v)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        return;
    }
    v.push_back(arr[ind]);
    initial += arr[ind];

    printsubwithsum(ind + 1, v, initial, arr, sum, n); // case of taking the element

    //initial -= arr[ind];
    v.pop_back();
    initial -= arr[ind];

    printsubwithsum(ind + 1, v, initial, arr, sum, n); // case of not taking the element
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum;
    cin >> sum;
    vector<int> s;

    printsubwithsum(0, s, 0, arr, sum, n);

    return 0;
}