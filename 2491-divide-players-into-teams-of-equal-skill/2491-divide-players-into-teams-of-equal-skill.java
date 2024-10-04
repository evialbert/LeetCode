class Solution {
  public long dividePlayers(int[] skill) {
    final int n = skill.length;
    int total = 0;
    int[] count = new int[2001];
    for (int s : skill) {
      total += s;
      count[s]++;
    }

    if (total % (n / 2) != 0) {
      return -1;
    }

    // skill of each team
    final int chemistry = total / (n / 2);
    // number of player paired
    int seen = 0;
    long result = 0;
    for (int i = 1; i < Math.min(chemistry, 2001); i++) {
      if (count[i] != count[chemistry - i]) {
        return -1;
      }

      if (i == chemistry - i) {
        // player with same skill with even count
        if (count[i] % 2 != 0) {
          return -1;
        }
        result += (long) count[i] / 2 * i * (chemistry - i);
        seen += count[i];
      } else {
        result += (long) count[i] * i * (chemistry - i);
        seen += 2 * count[i];
      }

      count[i] = 0;
      count[chemistry - i] = 0;
    }

    if (seen != n) {
      return -1;
    }

    return result;
  }
}