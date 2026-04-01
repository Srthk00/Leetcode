class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& p, vector<int>& h, string d) {
        int n=h.size();
        vector<tuple<int,int,char,int>> robots;
        for(int i=0;i<n;i++){
            robots.push_back({p[i],h[i],d[i],i});
        }
        sort(robots.begin(),robots.end());
        vector<int> st;
        for(int i=0;i<n;i++){
            auto &[pos,health,dir,idx]=robots[i];
            if(st.empty() || get<2>(robots[st.back()])==dir){
                st.push_back(i);
            } 
            else {
                while(!st.empty() && get<2>(robots[st.back()])=='R' && dir=='L' && health>0){
                    auto &[p2,h2,d2,idx2]=robots[st.back()];
                    if(h2==health){
                        st.pop_back();
                        health=0;
                        break;
                    } 
                    else if(h2>health){
                        h2--;
                        health=0;
                        break;
                    }
                    else {
                        st.pop_back();
                        health--;
                    }
                }
                if(health>0) st.push_back(i);
            }
        }
        vector<pair<int,int>> left;
        for(int i:st){
            auto &[pos,health,dir,idx]=robots[i];
            if(health>0){
                left.push_back({idx,health});
            }
        }
        sort(left.begin(),left.end());
        vector<int> result;
        for(auto &x:left){
            result.push_back(x.second);
        }
        return result;
    }
};