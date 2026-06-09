#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxCrossingSum(int i, int j, int middle, int A[]){
    int sum = 0;
    int left_sum = INT_MIN;
    for (int k = middle; k >= i; k--)
    {
        sum += A[k];
        left_sum = max(left_sum, sum);
    }

    sum = 0;
    int right_sum = INT_MIN;
    for (int k = middle + 1; k <= j; k++)
    {
        sum += A[k];
        right_sum = max(right_sum, sum);
    }

    return left_sum + right_sum;
}

int maxSum(int i, int j, int A[]){
    if (i == j)//check if the array has only one element

    return A[i];  
    
  
    int middle = (i + j) / 2;//find position of middle element to slit the array into two halves
    
    //recursive for left of suba
    int max_left = maxSum(i, middle, A);

    //recursive for right of subarray
    int max_right = maxSum(middle + 1, j, A);
    
    int max_crossing = maxCrossingSum(i,j,middle,A);




    //6. Trả về phương án tốt nhất
    return max(max(max_left, max_right), max_crossing);
}

int main(){
    int n;
    cin >> n;
    vector<int> L;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        L.push_back(x);
    }

    cout << maxSum(0, n-1, L.data()) << endl;
    return 0;
}
/*#include <iostream>
#include <vector>
using namespace std;

int A[100005];

long long solve(int i, int j, int K) {
    if (j <= i)
        return 0;
        
    int m = (i + j)/2;
    long long left = solve(i, m, K);
    long long right = solve(m + 1, j, K);
    
    int F[102];
    for (int k = 0; k < K; k++)
        F[k] = 0;
    
    for (int k = i; k <= m; k++) {
        int r = (A[k] % K + K) % K;
        F[r]++;
    }
    
    long long cnt = 0;
    
    for (int k = m + 1; k <= j; k++) {
        int r = (A[k] % K + K) % K;
        cnt += F[(K - r)%K];
    }

    return left + right + cnt;
        
}



int main() {
    int n, K;
    cin >> n >> K;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    
    cout << solve(0, n - 1, K) << endl;
    
    
}*/
// loi giai cua thay