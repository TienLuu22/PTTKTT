#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getPivot(vector<int>& A);

void Partition(vector<int>& A, int pivot, vector<int>& L, int& pivotVal, vector<int>& R){
    pivotVal = pivot;
    bool pivotFound = false;
    for(int x : A){
        if(x == pivotVal && !pivotFound){
            pivotFound = true;
        } else if(x < pivotVal){
            L.push_back(x);
        } else {
            R.push_back(x);
        }
    }

}

int select(vector<int>& A, int k){
    if(A.size() <= 50) {
        sort(A.begin(), A.end());
        return A[k-1];
    }
    int p = getPivot(A);

    // prepare containers for partition
    vector<int> L, R;
    int pivotVal;
    Partition(A, p, L, pivotVal, R);

    if(k == L.size() + 1) {
        return pivotVal;
    } else if(k < L.size() + 1) {
        return select(L, k);
    } else {
        return select(R, k - L.size() - 1);
    }
        
}

int getPivot(vector<int>& A){
    vector<int> medians;
    for(size_t i = 0; i < A.size(); i+=5){
        vector<int> group;
        for(size_t j = i; j < i + 5 && j < A.size(); j++){
            group.push_back(A[j]);
        }
        sort(group.begin(), group.end());
        medians.push_back(group[group.size() / 2]);
    }
    return select(medians, medians.size() / 2 + 1);
}

void Partition(vector<int>& A, int pivot, vector<int>& L, int& pivotVal, vector<int>& R){
    pivotVal = pivot;
    bool pivotFound = false;
    for(int x : A){
        if(x == pivotVal && !pivotFound){
            pivotFound = true;
        } else if(x < pivotVal){
            L.push_back(x);
        } else {
            R.push_back(x);
        }
    }

}

int main(){
    vector<int> A = {-2072, 2967, 427, -1476, -2593, -1629, 3884, -1019};
    
    cout << "--- Ket qua chay thu nghiem ---" << endl;
    for (int k = 1; k <= (int)A.size(); ++k) {
        cout << "select(A, " << k << ") = " << select(A, k) << endl;
    }
    
    return 0;
}