class Solution {
public: 
    typedef pair<int,char> P;
    string reorganizeString(string s) {
        vector<int> freq(26,0);
        for(char ch:s){
            freq[ch-'a']++;
        }
        priority_queue<P,vector<P>> pq;
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                pq.push({freq[i],(char)(i+'a')});
            }
        }
        string result="";
        while(pq.size()>1){
            auto [f1,c1]=pq.top();
            pq.pop();
            auto [f2,c2]=pq.top();
            pq.pop();
            result+=c1;
            f1--;
            result+=c2;
            f2--;
            if(f1>0){
                pq.push({f1,c1});
            }
            if(f2>0){
                pq.push({f2,c2});
            }
        }
        if(pq.size()==1){
            P p=pq.top();
            if(p.first>1){return "";}
            result+=p.second;
        }
        return result;
    }
};