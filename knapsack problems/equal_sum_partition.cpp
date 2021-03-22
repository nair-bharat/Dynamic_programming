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

    int n, sum = 0;
    bool res;
    cout<<"enter the limit "<<endl;
    cin>>n;

    int arr[n];
    cout<<"enter the elements of the array: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter element of the array index"<<" "<<i +1 <<endl;
        cin>>arr[i];
        sum = sum + arr[i];
        
    }

    if(sum % 2 != 0) {

        res = false;
    }

    else {

        res = knapsack(arr , sum/2, n);
    }

    

    if(res) {

        cout<<"Equal partition of the array is possible"<<endl;
    }

    else {

        cout<<"Equal partition of the array is not possible"<<endl;
    }
    

    return 0;
}

