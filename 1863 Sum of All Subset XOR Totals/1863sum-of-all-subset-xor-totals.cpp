class Solution {
public:
    void findall(vector<int> &nums,vector<vector<int>> &all,vector<int> &curr,int index){
        if(index==nums.size()){
            all.push_back(curr);
            return;
        }
        findall(nums,all,curr,index+1);

        curr.push_back(nums[index]);
        findall(nums,all,curr,index+1);
        curr.pop_back();
    }

    vector<int> findxor(vector<vector<int>> &all){
        vector<int> result;
        for(int i=0;i<all.size();i++){
            if(all[i].empty())
                continue;
            int temp=all[i][0];
            for(int j=1;j<all[i].size();j++){
                temp=temp^all[i][j];
            }
            result.push_back(temp);
        }
        return result;
    }

    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> allsubsets;
        vector<int> curr;
        findall(nums,allsubsets,curr,0);
        vector<int> result=findxor(allsubsets);
        int sum=0;
        for(int i:result){
            sum+=i;
        }
        return sum;
    }
};