#include<iostream>
#include<vector>

using namespace std;
int k;
int count_crossing(int i, int j, int middle, const vector<int>& A){
    vector<int> left_remain ;
    for (int idx = i; idx <= middle; idx++)
    {
        left_remain.push_back(((A[idx] % k) + k) % k);
    }
    vector<int> right_remain;
    for (int idx = middle + 1; idx <= j; idx++)
    {
        right_remain.push_back(((A[idx] % k) + k) % k);
    }

    vector<int> count_pair(k, 0);
    for(int i : left_remain){
        count_pair[i]++;
    }
    int count =0;
    for(int i : right_remain){
        count += count_pair[(k - i) % k];
    }
    return count;
}

int Maxdivided(int i, int j, const vector<int>& A){
    if (i >= j)//check if the array has only one element

    return 0;  
    
  
    int middle = (i + j) / 2;//find position of middle element to slit the array into two halves
    
    //recursive for left of suba
    int count_left = Maxdivided(i, middle, A);

    //recursive for right of subarray
    int count_right = Maxdivided(middle + 1, j, A);
    
    int max_crossing = count_crossing(i, j, middle, A);




    //6. Trả về phương án tốt nhất
    return count_left + count_right + max_crossing;
}

int main(){
    int n;
    cin >> n >> k;
    vector<int> L;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        L.push_back(x);
    }

    cout << Maxdivided(0, n-1, L) << endl;
    return 0;
}
/*#include<iostream>
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
}*/
// loi giai cua thay