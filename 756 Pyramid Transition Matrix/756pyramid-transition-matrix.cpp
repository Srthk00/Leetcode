class Solution {
public:
    unordered_map<string,bool> dp;
    bool func(string bottom,string curr,int i,vector<string> &nums,unordered_map<string,vector<char>> &mp){
        if(bottom.size()==1){return true;}
        if(i==bottom.size()-1){
            return dp[bottom]=func(curr,"",0,nums,mp);
        }
        string key=bottom+curr+to_string(i);
        if(dp.count(key)){return dp[key];}
        string temp=bottom.substr(i,2);
        if(!mp.count(temp)){return dp[key]=false;}
        for(char ch:mp[temp]){
            if(func(bottom,curr+ch,i+1,nums,mp)){return dp[key]=true;}
        }
        return dp[key]=false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string,vector<char>> mp;
        for(int i=0;i<allowed.size();i++){
            string key=allowed[i].substr(0,2);
            mp[key].push_back(allowed[i][2]);
        }
        return func(bottom,"",0,allowed,mp);
    }
};