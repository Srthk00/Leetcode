class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int result=0;
        while(i<j){
            int base=j-i;
            int curr=0;
            if(height[i]<=height[j]){
                curr=base*height[i++];
            }
            else{
                curr=base*height[j--];
            }
            result=max(result,curr);
        }
        return result;
    }
};