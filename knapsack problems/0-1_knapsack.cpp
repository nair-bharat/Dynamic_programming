#include<bits/stdc++.h>
using namespace std;

int knapsack(int wt[], int val[], int w, int n) {

    if (n == 0 or w == 0)
    {
        return 0;
    }
    

    if (wt[n -1] <= w)
    {
        return max((val[n -1] + knapsack(wt, val, w -wt[n -1], n -1)), knapsack(wt, val, w, n -1));
    }

    else if (wt[n -1] > w)
    {
        return knapsack(wt, val, w, n -1);
    }

    return 0;
    
}
int main() {

    int n, w;
    cout<<"enter the limit "<<endl;
    cin>>n;

    int wt[n], val[n];
    cout<<"enter the weight and value of the objects"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>wt[i];
        cin>>val[i];
    }

    cout<<"enter the weight of the bag"<<endl;
    cin>>w;

    cout<<knapsack(wt , val, w, n)<<endl;
    

    return 0;
}

