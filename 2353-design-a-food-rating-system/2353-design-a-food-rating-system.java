class FoodRatings {

    private HashMap<String, TreeMap<Integer, TreeSet<String>>> map;
    private HashMap<String, List<String>> pairs;

    public FoodRatings(String[] foods, String[] cuisines, int[] ratings) {
        map = initialize(foods, cuisines, ratings);
    }

    private HashMap<String, TreeMap<Integer, TreeSet<String>>> initialize(String[] food, String[] cuisine, int[] rating) {
        pairs = new HashMap<>();
        map = new HashMap<>();
        for (int i = 0; i < cuisine.length; i++) {
            map.putIfAbsent(cuisine[i], new TreeMap<>());
            map.get(cuisine[i]).putIfAbsent(rating[i], new TreeSet<>());
            map.get(cuisine[i]).get(rating[i]).add(food[i]);
            pairs.put(food[i], List.of(String.valueOf(rating[i]), cuisine[i]));
        }
        return map;
    }

    public void changeRating(String food, int newRating) {
        String cuisine = pairs.get(food).get(1);
        int rating = Integer.parseInt(pairs.get(food).get(0));
        pairs.put(food, List.of(String.valueOf(newRating), cuisine));
        if (map.get(cuisine).get(rating).size() == 1) {
            map.get(cuisine).remove(rating);
        } else {
            map.get(cuisine).get(rating).remove(food);
        }
        map.get(cuisine).putIfAbsent(newRating, new TreeSet<>());
        map.get(cuisine).get(newRating).add(food);
    }

    public String highestRated(String cuisine) {
        return map.get(cuisine).get(map.get(cuisine).lastKey()).first();
    }
}
/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings obj = new FoodRatings(foods, cuisines, ratings);
 * obj.changeRating(food,newRating);
 * String param_2 = obj.highestRated(cuisine);
 */