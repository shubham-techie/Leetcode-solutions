class Solution {
public:
    void help(vector<int>& nums, int t, int idx, vector<vector<int>>& res, vector<int> subset){
        if(t==0){
            res.push_back(subset);
            return;
        }
        
        if(t<0) return;
        
//         subset.push_back(nums[idx]);
//         help(nums, t-nums[idx], idx+1, res, subset);
//         subset.pop_back();
        
//         while(idx+1<nums.size() && nums[idx]==nums[idx+1]) ++idx;
        
//         help(nums, t, idx+1, res, subset);
        
        for(int i=idx;i<nums.size();++i){
            if(i>idx && nums[i]==nums[i-1]) continue;
            
            subset.push_back(nums[i]);
            help(nums, t-nums[i], i+1, res, subset);
            subset.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int t) {
        sort(begin(nums), end(nums));
        
        vector<vector<int>> res{};
        vector<int> subset{};
        
        help(nums, t, 0, res, subset);
        return res;
    }
};