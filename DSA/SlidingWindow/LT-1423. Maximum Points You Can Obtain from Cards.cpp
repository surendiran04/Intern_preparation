// In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
// Your score is the sum of the points of the cards you have taken.
// Given the integer array cardPoints and the integer k, return the maximum score you can obtain.
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int max=0,leftSum=0,rightSum=0;
        for(int i=0;i<k;i++){
            leftSum+=cardPoints[i];
        }
        max=leftSum;
        int j=cardPoints.size()-1;
        for(int i=k-1;i>=0;i--){
            leftSum-=cardPoints[i];
            rightSum+=cardPoints[j];
            j--;
            max=(max<(leftSum+rightSum))?(leftSum+rightSum):max;
        }
        return max;
    }
};
