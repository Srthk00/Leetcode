class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        for(int i:asteroids) {
            bool flag = false;
            while(!result.empty() && result.back()>0 && i<0){
                if(abs(result.back())<abs(i)){
                    result.pop_back();
                    continue;
                } 
                else if(abs(result.back())==abs(i)){
                    result.pop_back();
                    flag=true;
                    break;
                } 
                else{
                    flag=true;
                    break;
                }
            }
            if(!flag){
                result.push_back(i);
            }
        }
        return result;
    }
};