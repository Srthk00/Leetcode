class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        vector<int> result;
        int temp=cbrt(n);
        vector<long long> cubes;
        for(int i=1;i<=temp;i++){
            cubes.push_back(1LL*i*i*i);
        }
        unordered_map<long long,int> x;
        for(int i=1;i<=temp;i++){
            for(int j=i;j<=temp;j++){
                x[cubes[i-1]+cubes[j-1]]++;
            }
        }
        for(auto &it:x){
            if(it.first>n){
                continue;
            }
            if(it.second>=2){
                result.push_back(it.first);
            }
        }
        sort(result.begin(),result.end());
        return result;
    }
};