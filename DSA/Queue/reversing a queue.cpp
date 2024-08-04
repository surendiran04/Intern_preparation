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

//using stack and queue
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,k;
    cin>>n>>k;
    
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >>x;
        q.push(x);
    }
    
    stack<int> s;
    for(int i=0;i<k;i++){
        s.push(q.front());
        q.pop(); 
    }
    
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    
    for(int i=0;i<n-k;i++){
        q.push(q.front());
        q.pop();
    }
    
   while(!q.empty()){
       cout<<q.front()<<" ";
       q.pop();
   }
    return 0;
}
