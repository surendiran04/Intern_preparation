class Solution {
  public:
  static bool comp(Item a, Item b){
       return float(a.value)/a.weight > float(b.value)/b.weight;
   }
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        sort(arr,arr+n,comp); //based on profit value
        double totalval=0;
        for(int i=0;i<n;i++){
            if(arr[i].weight<=w){
                w-=arr[i].weight;
                totalval+=arr[i].value;
            }else{
                totalval+=double(arr[i].value)/arr[i].weight*w; //type casting
                break;
            }
        }
        return totalval;
    }
};
