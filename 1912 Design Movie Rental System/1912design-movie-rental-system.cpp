class MovieRentingSystem {
public:
    // movie={price,shop}
    unordered_map<int,set<pair<int,int>>> available;
    //movie=shop=price
    unordered_map<int,map<int,int>> forrenting;
    // price,shop,movie
    set<vector<int>> rented;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto &it:entries){
            int shop=it[0];
            int movie=it[1];
            int price=it[2];
            available[movie].insert({price,shop});
            forrenting[movie].insert({shop,price});
        }
    }
    
    vector<int> search(int movie) {
        vector<int> result;
        if(available.find(movie)!=available.end()){
            for(auto &[p,s]:available[movie]){
                result.push_back(s);
                if(result.size()>=5){break;}
            }
        }
        return result;
    }
    
    void rent(int shop, int movie) {
        int p=forrenting[movie][shop];
        available[movie].erase({p,shop});
        rented.insert({p,shop,movie});
    }
    
    void drop(int shop, int movie) {
        int p=forrenting[movie][shop];
        available[movie].insert({p,shop});
        rented.erase({p,shop,movie});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> result;
        for(auto &it:rented){
            int s=it[1];
            int m=it[2];
            result.push_back({s,m});
            if(result.size()>=5){break;}
        }
        return result;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */