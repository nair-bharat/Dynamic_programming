#include <bits/stdc++.h>
using namespace std;
//In this we will use the concept of dp where we will not recursively call the values if they are already computed so we will make use of a table to solve them
//for n and w -> initiliazed to 100 and 1000
int static t[100][1000];

int knapsack(int wt[], int val[], int w, int n) {

    
     if (n == 0 or w == 0)
    {
        return 0;
    }
    
    if(t[n][w] != -1) {

        return t[n][w]; //DP Logic
    }

    if (wt[n -1] <= w)
    {
        return t[n][w] = max((val[n -1] + knapsack(wt, val, w -wt[n -1], n -1)), knapsack(wt, val, w, n -1));
    }

    else if (wt[n -1] > w)
    {
        return t[n][w] = knapsack(wt, val, w, n -1);
    }

    return 0;

}
int main() {

    int n, w;
    cout<<"enter the limit "<<endl;
    cin>>n;

    memset(t, -1, sizeof(t)); //initializing to -1

    int wt[n], val[n];
    cout<<"enter the weight and value of the objects"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter weight"<<" "<<i +1 <<endl;
        cin>>wt[i];
        cout<<"Enter value"<<" "<<i +1 <<endl;
        cin>>val[i];
        
    }

    cout<<"enter the weight of the bag"<<endl;
    cin>>w;

    cout<<"Max Profit is "<<knapsack(wt , val, w, n)<<endl;
    

    return 0;

    
}