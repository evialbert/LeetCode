class ThroneInheritance {
public:
    unordered_map<string,vector<string>> mp;
    unordered_map<string,int> dead;
    string King;
    ThroneInheritance(string kingName) {
        King = kingName;
    }
    
    void birth(string parentName, string childName) {
        mp[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead[name] = 1;
    }

    void getOrder(vector<string> &order , string name){
        if(!dead[name]) order.push_back(name);
        for(string &children : mp[name]){
            getOrder(order,children);
        }
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> order;
        getOrder(order,King);
        return order;
    }
};


/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */