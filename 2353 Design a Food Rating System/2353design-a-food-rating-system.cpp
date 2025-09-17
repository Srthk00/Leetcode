class FoodRatings {
public:
    struct cmp {
        bool operator()(const pair<int,string>& a,const pair<int,string>& b)const{
            if(a.first!=b.first){return a.first>b.first;}
            return a.second<b.second;
        }
    };

    vector<string> foods,cuisines;
    vector<int> ratings;
    // cuisine={food,rating},{food,rating},{food,rating}...............
    unordered_map<string,set<pair<int,string>,cmp>> map;

    // food=cuisine,rating (helper for changeRating())
    unordered_map<string,pair<string,int>> foodmap;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        this->foods=foods;
        this->cuisines=cuisines;
        this->ratings=ratings;
        for(int i=0;i<foods.size();i++){
            string c=cuisines[i];
            string f=foods[i];
            int r=ratings[i];
            map[c].insert({r,f});
            foodmap[f]={c,r};
        }
    }
    
    void changeRating(string food, int newRating) {
        auto[c,r]=foodmap[food];
        map[c].erase({r,food});
        map[c].insert({newRating,food});
        foodmap[food]={c,newRating};
    }
    
    string highestRated(string cuisine) {
        return map[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */