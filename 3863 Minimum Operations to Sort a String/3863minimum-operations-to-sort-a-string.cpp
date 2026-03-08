class Solution {
public:
    int minOperations(string s) {
        string temp=s;
        sort(temp.begin(),temp.end());
        if(temp==s){return 0;}
        char mini=*min_element(s.begin(),s.end());
        char large=*max_element(s.begin(),s.end());
        if(s[0]==mini || s[s.size()-1]==large){
            return 1;
        }
        else{
            if(s.size()==2 && s[0]>s[1]){
                return -1;
            }
            else{
                int n=s.size();
                string t=s;
                sort(t.begin(),t.begin()+n-1);
                sort(t.begin()+1,t.end());
                if(t==temp){return 2;}
                t=s;
                sort(t.begin()+1,t.end());
                sort(t.begin(),t.begin()+n-1);
                if(t==temp){return 2;}
            }
        }
        if(s[0]==large && s[s.size()-1]==mini){return 3;}
        return -1;
    }
};