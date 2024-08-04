// Given an array of integers. Find the Inversion Count in the array. Two array elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    int count=0;
    
    for(int i=0;i<n-1;i++){
        for(int j=1;j<n;j++){
            if(v[i]>v[j] && i<j){
                count++;
            }
        }
    }
    
    cout<<count;
    return 0;
}

//using queue logic
int countInversions(queue<int> &q) {
    int inv_count = 0;
    queue<int> temp;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        temp = q; 
        while (!temp.empty()) {
            if (current > temp.front()) { //same array logic using queue
                inv_count++;
            }
            temp.pop();
        }
    }
    return inv_count;
}

int main() {
    int n;
    cin >> n;

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        q.push(x);
    }
    cout << countInversions(q);

    return 0;
}
