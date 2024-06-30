int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,k;
    cin>>n>>k;
    
    vector<int> queue(n);
    for (int i = 0; i < n; ++i) {
        cin >> queue[i];  
    }
    reverse(queue.begin(),queue.begin()+k);  //using in-built methods
    
    for (int i = 0; i < n; ++i) {
        cout << queue[i] << " ";
    }
    
    return 0;
}
