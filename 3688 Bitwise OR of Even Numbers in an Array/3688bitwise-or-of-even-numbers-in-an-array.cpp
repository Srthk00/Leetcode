class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        vector<int> even;
        for(int i:nums){
            if(i%2==0){
                even.push_back(i);
            }
        }
        if(even.size()==0){return 0;}
        int result=even[0];
        for(int i=1;i<even.size();i++){
            result|=even[i];
        }
        return result;
    }
};