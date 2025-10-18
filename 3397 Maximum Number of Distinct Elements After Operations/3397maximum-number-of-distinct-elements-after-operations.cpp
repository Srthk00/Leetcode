class Solution {
public:
    // note:- any element of nums can only be updated to an integer in range [nums[i]-k,nums[i]+k]
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        nums[0]=nums[0]-k; // minimize the first element
        // then update further elements by +1 than previous element
        for(int i=1;i<nums.size();i++){
            // but if nums[i] cannot be updated to prev+1, update it to nums[i]-k
            int temp=max(nums[i]-k,nums[i-1]+1);
            // also prevent it from exceeding nums[i]+k;
            if(temp<=nums[i]+k){nums[i]=temp;}
            else{nums[i]=nums[i]+k;}
        }
        unordered_set<int> st(nums.begin(),nums.end());
        return st.size();
    }
};