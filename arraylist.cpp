#include <iostream>
#include <vector>       //to use vector class
using namespace std;

int main() {
    //1. Create an empty list L to store integer using vector<int> class.
    vector<int> L; //create an empty list


    //2. Read n integer from stdin and append them to L
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        //read an integer and append it to L using push_back() function
        int value;
        cin >> value;
        L.push_back(value);
    }

    //3. Print elements of L in format: a1, a2, a3
    for(size_t i = 0; i < L.size(); i++){
        cout << L[i];
        if(i < L.size() - 1) cout << ", "; //print comma after each element except the last one
    }
    cout << endl;

    //4. 
    if(L.size() >= 3){
        L.insert(L.begin() + 3, 20);
    }else{
        L.push_back(20); //if L has less than 3 elements, append 20 to the end of L
    }
    
    //task 5
    for(size_t i = 0; i < L.size(); i++){
        cout << L[i];
        if(i < L.size() - 1) cout << ", "; //print comma after each element except the last one
    }
    cout << endl;

    //task 6
    if(!L.empty()){
        L.erase(L.begin()); //remove the first element from L
    }
    //task 7
    for(size_t i = 0; i < L.size(); i++){
        cout << L[i];
        if(i < L.size() - 1) cout << ", "; //print comma after each element except the last one
    }
    cout << endl;

    int x;
    cin >> x;
    int pos = -1;
    for(size_t i = 0; i < L.size(); i++) {
        if (L[i] == x) {
            pos = i + 1;
            break;
        }
    }
    cout << pos << endl;
    return 0;
}