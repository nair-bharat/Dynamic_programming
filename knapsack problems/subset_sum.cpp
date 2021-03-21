#include<bits/stdc++.h>
using namespace std;


static bool t[100][1000];
int knapsack(int arr[], int sum, int n) {

    memset(t, -1, sizeof(t)); 
    for (int i = 0; i < n +1; i++)
    {
        for (int j = 0; j < sum +1; j++) {

            //Base condition

            if(i == 0) {

                t[i][j] = false;
            }

            if(j == 0) {

                t[i][j] = true;
            }
        }
    }

    
    for (int i = 1; i < n +1; i++)
    {
        for (int j = 1; j < sum +1; j++) {

            if (arr[i -1] <= j) {

                t[i][j] = t[i -1][j - arr[i -1]] or t[i -1][j];
            }

            else
            {
                t[i][j] = t[i -1][j];
             }
        }
    }

    return t[n][sum];

}
int main() {

    int n, sum;
    cout<<"enter the limit "<<endl;
    cin>>n;

    int arr[n];
    cout<<"enter the elements of the array: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter element of the array index"<<" "<<i +1 <<endl;
        cin>>arr[i];
        
    }

    cout<<"enter the subset sum"<<endl;
    cin>>sum;

    bool res = knapsack(arr , sum, n);

    if(res) {

        cout<<"The sum is present in the array"<<endl;
    }

    else {

        cout<<"The sum is not present in the array"<<endl;
    }
    

    return 0;
}

