#include<iostream>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
int K;

int max_crossing(int i, int j, int mid, const vector<int>& A) {
    vector<int> left_count;
    for(int temp = mid; temp >= i; temp--){
        left_count.push_back(abs(A[temp]));
    }
    vector<int> right_count;
    for(int temp = mid + 1; temp <= j; temp++){
        right_count.push_back(abs(A[temp]));
    }
    map<int, int> count_pair;
    for(int val : left_count){    
        count_pair[val]++;
    }
    int count = 0;
    for(int val : right_count){
        int needed = K - val;
        if(needed >= 0 && count_pair.count(needed)){
            count += count_pair[needed];
        }
    }
    return count;
}

int maxSumEqual(const vector<int>& A,int i, int j ){
    if(i >= j) return 0;

    int mid = (i+j)/2;

    int left = maxSumEqual(A, i, mid);
    int right = maxSumEqual(A, mid+1, j);
    int max_cross = max_crossing(i, j, mid, A);
    return left + right + max_cross;
}

int main(){
    
    int n;
    cin >> n >> K;
    vector<int> A(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    cout << maxSumEqual(A, 0, n-1) << endl;
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
    
    int F[1003];
    for (int k = 0; k <= K; k++)
        F[k] = 0;
    
    for (int k = i; k <= m; k++) {
        int r = A[k] > 0 ? A[k] : -A[k];
        F[r]++;
    }
    
    long long cnt = 0;
    
    for (int k = m + 1; k <= j; k++) {
        int r = A[k] > 0 ? A[k] : -A[k];
        if (r <= K && K - r >= 0)
            cnt += F[K - r];
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
