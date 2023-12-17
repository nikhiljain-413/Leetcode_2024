class FoodRatings {
public:
    unordered_map<string, int> rat;
    unordered_map<string, set<pair<int,string>>> fod_cui;
    unordered_map<string, string> cui;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i=0;i<n;i++){
            rat[foods[i]] = ratings[i];
            fod_cui[cuisines[i]].insert({-1*ratings[i], foods[i]});
            cui[foods[i]] = cuisines[i];
        }
    }
    
    void changeRating(string foodd, int newRating) {
        string cuisine = cui[foodd];
        int ratt = rat[foodd];

        fod_cui[cuisine].erase({-1*ratt, foodd});
        fod_cui[cuisine].insert({-1*newRating, foodd});
        rat[foodd] = newRating;
    }
    
    string highestRated(string cuisine) {
        return (*fod_cui[cuisine].begin()).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */