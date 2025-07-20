class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        map<int,int> map;
        for(auto &it:points){
            map[it[1]]++;
        }
        vector<long long> cal;
        for(auto it=map.begin();it!=map.end();it++){
            if(it->second>=2){
                long long temp=it->second;
                cal.push_back((temp*(temp-1)/2)%1000000007);
            }
        }
        long long n=0,r=0;
        for(long long c:cal){
            n=(n+c)%1000000007;
            r=(r+(c*c)%1000000007)%1000000007;
        }
        long long result=((n*n)%1000000007-r+1000000007)%1000000007;
        return (result*500000004LL)%1000000007;
    }
};