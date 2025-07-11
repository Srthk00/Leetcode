class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int gp=0,sp=0,count=0;
        while(gp<g.size() && sp<s.size()){
            if(s[sp]>=g[gp]){
                count++;
                sp++;gp++;
            }
            else{
                sp++;
            }
        }
        return count;
    }
};