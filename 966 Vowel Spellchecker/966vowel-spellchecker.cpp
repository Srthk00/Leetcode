class Solution {
public:
    unordered_set<string> strs;
    unordered_map<string,string> Case;
    unordered_map<string,string> vowel;
    string toLower(string str){
        for(int i=0;i<str.size();i++){
            str[i]=tolower(str[i]);
        }
        return str;
    }

    string replacevowel(string str){
        for(int i=0;i<str.size();i++){
            str[i]=tolower(str[i]);
            if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u'){
                str[i]='*';
            }
        }
        return str;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> result;
        for(string w:wordlist){
            if(strs.find(w)==strs.end()){
                strs.insert(w);
            }
            string lower=toLower(w);
            if(Case.find(lower)==Case.end()){
                Case[lower]=w;
            }
            string n=replacevowel(lower);
            if(vowel.find(n)==vowel.end()){
                vowel[n]=w;
            }
        }
        for(string q:queries){
           string lowerq=toLower(q);
           string starq=replacevowel(q);
            if(strs.find(q)!=strs.end()){
                result.push_back(q);
            }
            else if(Case.find(lowerq)!=Case.end()){
                result.push_back(Case[lowerq]);
            }
            else if(vowel.find(starq)!=vowel.end()){
                result.push_back(vowel[starq]);
            }
            else{
                result.push_back("");
            }
        }
        return result;
    }
};