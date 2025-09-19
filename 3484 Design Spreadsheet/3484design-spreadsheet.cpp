class Spreadsheet {
public:
    unordered_map<string,int> map;
    Spreadsheet(int rows) {}
    void setCell(string cell, int value) {
        map[cell]=value;
    }
    
    void resetCell(string cell) {
        map[cell]=0;
    }
    
    int getValue(string formula) {
        string str=formula.substr(1);
        for(int i=0;i<str.size();i++){
            if(str[i]=='+'){
                string s1=str.substr(0,i);
                string s2=str.substr(i+1);
                int left,right;
                if(s1[0]>='A' && s1[0]<='Z'){
                    left=map[s1];
                }
                else{
                    left=stoi(s1);
                }
                if(s2[0]>='A' && s2[0]<='Z'){
                    right=map[s2];
                }
                else{
                    right=stoi(s2);
                }
                return left+right;
            }
        }
        return 0;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */