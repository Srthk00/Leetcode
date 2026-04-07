class Robot {
public:
    int x=0,y=0;
    int m,n;
    vector<string> dir={"East","North","West","South"};
    int d=0;

    Robot(int M, int N) {
        m=M;n=N;
    }
    
    void step(int num) {
        int per=2*(m+n-2);
        if(per>0) num%=per;
        if(num==0){
            num=per;
        }
        for(int i=0;i<num;i++){
            if(d==0){ 
                if(x==m-1){
                    d=1;
                    y++;
                } else x++;
            }
            else if(d==1){ 
                if(y==n-1){
                    d=2;
                    x--;
                } else y++;
            }
            else if(d==2){ 
                if(x==0){
                    d=3;
                    y--;
                } else x--;
            }
            else{ 
                if(y==0){
                    d=0;
                    x++;
                } else y--;
            }
        }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        return dir[d];
    }
};