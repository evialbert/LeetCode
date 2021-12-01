class TeamRank implements Comparable<TeamRank> {
	public char name;
	public int[] rank;

	public TeamRank(char name) {
		this.name = name;
		this.rank = new int[27];
	}

	@Override
	public int compareTo(TeamRank other) {
		for (int i = 0; i < 27; i++) {
			if (this.rank[i] != other.rank[i]) {
				return other.rank[i] - this.rank[i];
			}
		}

		return this.name - other.name;
	}
}


class Solution {
    public String rankTeams(String[] votes) {
        int m = votes.length, n = votes[0].length();

        Map<Character, TeamRank> rankMap = new HashMap<>();

        for (int i = 0; i < votes[0].length(); i++) {
        	char team = votes[0].charAt(i);
        	rankMap.put(team, new TeamRank(team));
        }

        for (String vote: votes) {
        	for (int i = 0; i < vote.length(); i++) {
        		char team = vote.charAt(i);

        		rankMap.get(team).rank[i]++;
        	}
        }

        List<TeamRank> rankList = new ArrayList<>(rankMap.values());

        Collections.sort(rankList);

        StringBuilder result = new StringBuilder();

        for (TeamRank team: rankList) {
        	result.append(team.name);
        }

        return result.toString();
    }
}