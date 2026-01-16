class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        unordered_set<int> h,v;
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());
        for(int i=0;i<hFences.size();i++){
            for(int j=i+1;j<hFences.size();j++){
                h.insert(hFences[j]-hFences[i]);
            }
        }
        for(int i=0;i<vFences.size();i++){
            for(int j=i+1;j<vFences.size();j++){
                v.insert(vFences[j]-vFences[i]);
            }
        }
        int result=-1;
        for(int i:h){
            if(v.find(i)!=v.end()){
                result=max(result,i);
            }
        }
        return result==-1?-1:((long long)result*result)%(int)(1e9+7);
    }
};