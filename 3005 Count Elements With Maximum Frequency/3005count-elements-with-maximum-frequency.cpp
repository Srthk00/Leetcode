class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int i:nums){
            map[i]++;
        }
        int result=0;
        int maxi_freq=0;
        for(auto &[k,f]:map){
            if(f==maxi_freq){
                result+=f;
            }
            else if(f>maxi_freq){
                result=f;
                maxi_freq=f;
            }
        }
        return result;
    }
};