class Solution {
public:
    unordered_map<int,int> map;
    int findSmallestInteger(vector<int>& nums, int value) {
        for(int i=0;i<nums.size();i++){
            nums[i]=((nums[i]%value)+value)%value;
            map[nums[i]]++;
        }
        int flag=0;
        vector<int> result;
        while(true){
            int temp=flag%value;
            if(map[temp]==0){return flag;}
            else{
                map[temp]--;
                flag++;
            }
        }
        return flag;
    }
};