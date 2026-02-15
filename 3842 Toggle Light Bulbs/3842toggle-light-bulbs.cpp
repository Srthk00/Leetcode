class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int> temp(101,0);
        for(int i=0;i<bulbs.size();i++){
            if(temp[bulbs[i]]){
                temp[bulbs[i]]=0;
            }
            else{
                temp[bulbs[i]]=1;
            }
        }
        vector<int> result;
        for(int i=0;i<101;i++){
            if(temp[i]){
                result.push_back(i);
            }
        }
        return result;
    }
};