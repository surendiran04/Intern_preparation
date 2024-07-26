//return the length of the array after removing duplicates
class Solution { 
public:
    int removeDuplicates(vector<int>& nums) { 
        set<int> set(nums.begin(),nums.end());
        nums.erase(nums.begin(),nums.end());
        for(auto a:set){
            nums.push_back(a);
        }
        return set.size();
    }
};
int removeDuplicates(int arr[], int n) //two-pointer approach
{
  int i = 0;
  for (int j = 1; j < n; j++) {
    if (arr[i] != arr[j]) {
      i++;
      arr[i] = arr[j];
    }
  }
  return i + 1;
}
