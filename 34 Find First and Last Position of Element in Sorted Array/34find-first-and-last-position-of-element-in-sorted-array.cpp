class Solution {
public:
    int find_lower(vector<int> nums,int target){
        int low=0,high=nums.size()-1;
        int num=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>=target){
                if(nums[mid]==target)
                    num=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return num;
    }

    int find_higher(vector<int> nums,int target){
        int low=0,high=nums.size()-1;
        int num=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]<=target){
                if(nums[mid]==target)
                    num=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return num;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        result.push_back(find_lower(nums,target));
        result.push_back(find_higher(nums,target));
        return result;
    }
};