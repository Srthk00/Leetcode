class Solution {
public:
    vector<int> func(int n){
        string result="";
        while(n>0){
            result=result+to_string(n%2);
            n/=2;
        }
        int s=result.size();
        vector<int> power;
        for(int i=0;i<s;i++){
            if(result[i]=='1'){
                power.push_back(pow(2,i));
            }
        }
        return power;
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> power=func(n);
        vector<int> result;
        for(auto &it:queries){
            int l=it[0],r=it[1];
            long long prod=1;
            for(int i=l;i<=r;i++){
                prod=(prod*power[i])%1000000007;
            }
            result.push_back((int)prod);
        }
        return result;
    }
};