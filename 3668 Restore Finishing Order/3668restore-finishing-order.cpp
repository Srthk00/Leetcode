class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> result;
        for(int o:order){
            for(int f:friends){
                if(o==f){
                    result.push_back(o);
                    break;
                }
            }
        }
        return result;
    }
};