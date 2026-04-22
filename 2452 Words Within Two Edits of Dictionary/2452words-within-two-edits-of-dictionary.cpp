class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;
        for(string &q:queries){
            for(string &d:dictionary){
                int changes=0;
                for(int i=0;i<d.size();i++){
                    if(q[i]!=d[i]){changes++;}
                }
                if(changes<=2){
                    result.push_back(q);
                    break;
                }
            }
        }
        return result;
    }
};