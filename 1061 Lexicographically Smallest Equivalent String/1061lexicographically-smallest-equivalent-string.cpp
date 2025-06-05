class Solution {
private:
    int parent[26];

public:
    int find(int x){
        if(parent[x]!=x){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }

    void UNION(int x,int y){
        int parentx=find(x);
        int parenty=find(y);
        if(parentx==parenty){
            return;
        }
        else if(parentx<parenty){
            parent[parenty]=parentx;
        }
        else{
            parent[parentx]=parenty;
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
        
        for(int i=0;i<s1.size();i++){
            UNION(s1[i]-'a',s2[i]-'a');
        }
        string result="";
        for(int i=0;i<baseStr.size();i++){
            int ch=find(baseStr[i]-'a');
            result+=(char)ch+'a';
        }
        return result;
    }
};