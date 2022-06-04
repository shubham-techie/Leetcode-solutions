class Solution {
public:
    int kadaneAlgo(vector<int>& nums){
        int cSum{}, mxSum{nums[0]};
        
        for(int& i:nums){
            cSum=max(cSum+i, i);
            mxSum=max(mxSum,cSum);
        }
        
        return mxSum;
    }
    
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int nonCircularSum=kadaneAlgo(nums);
        int totalSum{};
        
        for(int i=0;i<nums.size();++i){
            totalSum+=nums[i];
            nums[i]=-nums[i];
        }
        
        int circularSum=totalSum+kadaneAlgo(nums);
        
        if(circularSum==0)
            return nonCircularSum;
        return max(circularSum, nonCircularSum);
    }
};