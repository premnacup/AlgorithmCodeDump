#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

double findSum(const vector<int>& arr, int n, vector<double>& memo) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return arr[0];
    }
    
    if (memo[n] != -1) {
        return memo[n];
    }
    memo[n] = arr[n-1] + findSum(arr, n-1, memo);
    
    return memo[n];
}


double findMean(const vector<int>& arr, int n, vector<double>& memo) {
    return findSum(arr, n, memo) / n;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<double> memo(n + 1, -1);
    double mean = findMean(arr, n, memo);
    cout << fixed << setprecision(2) << mean << endl;
    
    return 0;
}