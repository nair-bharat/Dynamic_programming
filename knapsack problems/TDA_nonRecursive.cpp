#include<bits/stdc++.h>
using namespace std;


static int t[100][1000];
int knapsack(int wt[], int val[], int w, int n) {

    memset(t, -1, sizeof(t)); 
    for (int i = 0; i < n +1; i++)
    {
        for (int j = 0; j < w +1; j++) {

            //Base condition
            if(i == 0 or j == 0) {

                t[i][j] = 0;
            }
        }
    }

    
    for (int i = 1; i < n +1; i++)
    {
        for (int j = 1; j < w +1; j++) {

            if (wt[i -1] <= j) {

                t[i][j] = max(val[i -1] + t[i -1][j - wt[i -1]], t[i -1][j]);
            }

            else
            {
                t[i][j] = t[i -1][j];
             }
        }
    }

    return t[n][w];

}
int main() {

    int n, w;
    cout<<"enter the limit "<<endl;
    cin>>n;

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

