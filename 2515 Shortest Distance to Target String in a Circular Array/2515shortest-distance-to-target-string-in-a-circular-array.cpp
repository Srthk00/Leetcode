class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();
        if(words[startIndex]==target){
            return 0;
        }
        for(int i=1;i<n;i++){
            int next=(startIndex+i)%n;
            int prev=(startIndex-i+n)%n;
            if(words[next]==target || words[prev]==target){
                return i;
            }
        }
        return -1;
    }
};