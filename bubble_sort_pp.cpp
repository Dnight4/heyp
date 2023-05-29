#include <iostream>
#include <bits/stdc++.h>
#include <omp.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    #pragma omp parallel
    {
        // double start=omp_get_wtime();
        #pragma omp for
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n - j - 1; i++) {
                if (a[i] > a[i + 1]) {
                    swap(a[i], a[i + 1]);
                }
            }
        }
    // double end=omp_get_wtime();
    // double time=end-start;
    }
   
    // cout<<"\nTime taken => "<<time<<endl;
    // omp_set_num_threads(2);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
