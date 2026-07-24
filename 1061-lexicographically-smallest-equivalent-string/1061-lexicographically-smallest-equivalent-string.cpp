class Solution {
public:
    vector<int> parent,rank;

    int find(int x){
        if(parent[x]!=x){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x,int y){
        int p1=find(x);
        int p2=find(y);
        if(p1<p2){
            parent[p2]=p1;
        }
        else{
            parent[p1]=p2;
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.size();
        parent=vector<int>(26);
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
        rank=vector<int>(26,1);
        for(int i=0;i<n;i++){
            if(find(s1[i]-'a')!=s2[i]-'a'){
                unite(s1[i]-'a',s2[i]-'a');
            }
        }
        string result="";
        for(char ch:baseStr){
            result+=(char)find(parent[ch-'a'])+'a';
        }
        return result;
    }
};