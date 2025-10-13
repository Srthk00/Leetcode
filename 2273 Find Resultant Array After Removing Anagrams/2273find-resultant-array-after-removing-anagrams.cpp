class Solution {
public:
    bool isanagram(string str1,string str2){
        if(str1.size()!=str2.size()){return false;}
        sort(str1.begin(),str1.end());
        sort(str2.begin(),str2.end());
        if(str1!=str2){return false;}
        return true;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        if(words.size()==1){return words;}
        vector<string> result;
        result.push_back(words[0]);
        for(int i=1;i<words.size();i++){
            if(!isanagram(words[i],result.back())){
                result.push_back(words[i]);
            }
        }
        return result;
    }
};