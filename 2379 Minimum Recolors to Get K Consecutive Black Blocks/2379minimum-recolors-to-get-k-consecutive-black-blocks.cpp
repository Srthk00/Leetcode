class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        if(blocks.size()<k)
            return 0;
        int m=INT_MAX,count=0;
        for(int i=0;i<k;i++){
            if(blocks[i]=='W')
            count++;
        }
        m=count;
        for(int i=k;i<blocks.size();i++){
            if(blocks[i-k]=='W'){
                count--;
            }
            if(blocks[i]=='W'){
                count++;
            }
            m=min(m,count);
        }
        return m;
    }
};