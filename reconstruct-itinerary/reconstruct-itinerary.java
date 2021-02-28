//Topo Sort
class Solution {
    public List<String> findItinerary(List<List<String>> tickets) {
    
        Map<String, List<String>> adjMap = new HashMap<String, List<String>>();
        
        //keep count of number of tickets per each dept city - arrival city
        Map<String, Integer> countEachTicket = new HashMap<String, Integer>();
        countEachTicket.put("NOWHERE~JFK" , 1);
        
        //build graph
        for(List<String> ticket : tickets)
        {
            String trip = ticket.get(0) + "~" + ticket.get(1);
            countEachTicket.put(trip, countEachTicket.getOrDefault(trip,0) + 1);

            if(adjMap.containsKey(ticket.get(0)))
            {
                List<String> temp = adjMap.get(ticket.get(0));
                temp.add(ticket.get(1));
                Collections.sort(temp);
                adjMap.put(ticket.get(0),temp);
            }
            else
            {
                List<String> temp = new ArrayList<String>();
                temp.add(ticket.get(1));
                adjMap.put(ticket.get(0),temp);
            }
        }
        
        
        List<String> results = new ArrayList<String>();
        
        dfs("JFK" , "NOWHERE",  adjMap, results, countEachTicket);
        
        Collections.reverse(results);
        return results;
        
    }
    
    public void dfs(String city, String fromCity, Map<String, List<String>> adjMap, List<String> results, Map<String, Integer> countEachTicket)
    {
        countEachTicket.put(fromCity+"~"+city, countEachTicket.get(fromCity+"~"+city) - 1);
        if(adjMap.containsKey(city))
        {          
           for(String toCity : adjMap.get(city))
           {
               //make the trip only if you have a ticket for 'tocity' from 'city'
                if(countEachTicket.get(city +"~" + toCity) > 0)
                    dfs(toCity, city, adjMap, results, countEachTicket);   
            }
        }
        
        results.add(city);
    }
}