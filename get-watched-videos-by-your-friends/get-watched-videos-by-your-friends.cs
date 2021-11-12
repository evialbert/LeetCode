public class Solution {
    public IList<string> WatchedVideosByFriends(IList<IList<string>> watchedVideos, int[][] friends, int id, int level) {
        
        var n = friends.Length;
        
        var set = new HashSet<int>();
        set.Add(id);
        var visited = new bool[n];
        visited[id] = true;
        
        while(level-- > 0)
        {
            var newSet = new HashSet<int>();
            foreach(var item in set)
            {               
                foreach(var i in friends[item])
                {
                    if(!visited[i])
                    {
                        newSet.Add(i);
                        visited[i] = true;
                    }                        
                }                
            }
            set = newSet;
        }        
        
        var map = new Dictionary<string, int>();
        var output = new List<string>();
        foreach(var item in set)
        {
            foreach(var video in watchedVideos[item])
            {
                if(!map.ContainsKey(video))
                {
                    map.Add(video, 0);
                    output.Add(video);
                }                
                map[video]++;
            }            
        }
        output.Sort((a,b) => {
            if(map[b] == map[a])
                return a.CompareTo(b);
            else
                return map[a] - map[b];
        });
        return output;
    }
}