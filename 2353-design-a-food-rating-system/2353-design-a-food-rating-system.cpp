class FoodRatings {
public:
    map<string, string> f_to_c;
    map<string, int> f_to_r;
    map<string, set<pair<int, string>>> mp;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0; i<foods.size(); i++) {
            f_to_c[foods[i]] = cuisines[i];
            f_to_r[foods[i]] = ratings[i];
            mp[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = f_to_c[food];
        mp[cuisine].erase({-f_to_r[food], food});
        mp[cuisine].insert({-newRating, food});
        f_to_r[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return mp[cuisine].begin()->second;
    }
};