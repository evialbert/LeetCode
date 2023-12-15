class Solution 
{
public:
    string destCity(vector<vector<string>>& paths) 
    {
        map<string, string> hashmap;
        for(int i = 0; i < paths.size(); i++)
            hashmap.insert({paths[i][0], paths[i][1]});//Hashmap store in pair (Departure, Destination)
        string ans = hashmap.find(paths[0][0])->second;
        while(hashmap.count(ans))
            ans = hashmap.find(ans)->second;
        return ans;
    }
};