class Solution {
public:
    void subset(vector<int> &nums,int i,vector<int>&result,vector<int> &sub){
        if(i==nums.size()){
            if(sub.empty())return;
            int temp=sub[0];
            for(int j=1;j<sub.size();j++){
                temp|=sub[j];
            }
            result.push_back(temp);
            return;
        }
        sub.push_back(nums[i]);
        subset(nums,i+1,result,sub);
        sub.pop_back();
        subset(nums,i+1,result,sub);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        vector<int> result,sub;
        subset(nums,0,result,sub);
        int m=*max_element(result.begin(),result.end());
        return count(result.begin(),result.end(),m);
    }
};