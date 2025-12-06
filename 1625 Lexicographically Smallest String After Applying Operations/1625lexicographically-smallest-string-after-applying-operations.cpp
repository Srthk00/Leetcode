class Solution {
public:
    string result;
    unordered_set<string> visited;

    void dfs(string s,int a,int b){
        if(visited.count(s)){return;}
        visited.insert(s);
        string temp=s;
        shift(temp,a);
        result=min(result,temp);
        dfs(temp,a,b);
        rotate(s,b);
        result=min(result,s);
        dfs(s,a,b);
    }

    void shift(string &s,int a){
        for(int i=1;i<s.size();i+=2){
            int n=s[i]-'0';
            n=(n+a)%10;
            s[i]=n+'0';
        }
    }

    void rotate(string &s,int b){
        reverse(s.begin(),s.begin()+b);
        reverse(s.begin()+b,s.end());
        reverse(s.begin(),s.end());
    }

    string findLexSmallestString(string s, int a, int b) {
        result=s;
        dfs(s,a,b);
        return result;
    }
};