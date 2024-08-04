class Solution {  //first approach is to sort the array and check the i-1 and i th element if it equal return the element
public:            //Second approach is using a hash map find the frequency if the frequency is raised to 2 then return the number
    int findDuplicate(std::vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];  //while traversing like this after a point the elements will be same and loop stops
        } while (slow != fast);
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
