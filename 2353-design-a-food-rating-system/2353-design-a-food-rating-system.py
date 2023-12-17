class FoodRatings:

    def __init__(self, f: List[str], c: List[str], r: List[int]):
        self.fr = {}
        self.cf = defaultdict(list)
        for i in range(len(f)):
            self.fr[f[i]] = [-r[i], f[i], c[i]]
            heappush(self.cf[c[i]], self.fr[f[i]])

    def changeRating(self, f: str, nr: int) -> None:
        e = self.fr[f]
        e[-2] = "#REMOVED"
        ne = [-nr, f, e[-1]]
        heappush(self.cf[e[-1]], ne)
        self.fr[f] = ne

    def highestRated(self, c: str) -> str:
        while self.cf[c][0][-2] == "#REMOVED":
            heappop(self.cf[c])

        return self.cf[c][0][-2]
        
# Your FoodRatings object will be instantiated and called as such:
# obj = FoodRatings(foods, cuisines, ratings)
# obj.changeRating(food,newRating)
# param_2 = obj.highestRated(cuisine)