#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // int n;
    // cin>>n;
    // int a[n];
    
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    // }
    int a[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;

    int min_val = INT_MAX;
    int max_val = INT_MIN;
    int sum = 0;
    double avg = 0;

#pragma omp parallel for reduction(min : min_val) reduction(max : max_val) reduction(+ : sum)

    for (int i = 0; i < n; i++)
    {
        if (min_val > a[i])
        {
            min_val = a[i];
        }
        if (max_val < a[i])
        {
            max_val = a[i];
        }

        sum += a[i];
    }
    avg = static_cast<double>(sum) / n;

    cout << "min : " << min_val<<endl;
    cout << "max : " << max_val<<endl;
    cout << "sum : " << sum<<endl;
    cout << "avg : " << avg<<endl;
    return 0;
}