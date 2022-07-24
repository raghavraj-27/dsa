struct comp{
    bool operator()(pair<int,string>a,pair<int,string>b)const{
        if(a.first!=b.first)
            return a.first>b.first;
        return a.second<b.second;
    }
};
class FoodRatings {
    /*static bool comp(pair<int,string>a,pair<int,string>b){
        if(a.first!=b.first)
            return a.first>b.first;
        return a.second<b.second;
    }*/
public:
    vector<string>f,c;
    vector<int>r;
    int n,i;
    map<string,set<pair<int,string>,comp>>m;
    map<string,int>name;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        f=foods;c=cuisines;r=ratings;
        n=foods.size();
        for(i=0; i<n; i++){
            m[c[i]].insert({r[i],f[i]});
            name[f[i]]=i;
        }
    }
    
    void changeRating(string food, int nr) {
        string cu=c[name[food]];
        int old=r[name[food]];
        r[name[food]]=nr;
        m[cu].erase({old,food});
        m[cu].insert({nr,food});
    }
    
    string highestRated(string c) {
        for(auto it:m[c])
            return it.second;
        return "";
    }
};