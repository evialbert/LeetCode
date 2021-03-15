//BFS
class Solution {
  public int minMutation(String start, String end, String[] bank) {
    HashSet<String> nodes = new HashSet<>(Arrays.asList(bank));
    char[] choices = new char[] { 'A', 'C', 'G', 'T' };

    if (!nodes.contains(end)) {
      return -1;
    }

    HashSet<String> seen = new HashSet<>();
    Queue<String> qe = new LinkedList<>();
    qe.add(start);
    int depth = 0;

    while (!qe.isEmpty()) {
      int n = qe.size();

      for (int i = 0; i < n; i++) {
        String curr = qe.poll();
        char[] temp = curr.toCharArray();
        for (int j = 0; j < temp.length; j++) {
          char old = temp[j];
          for (char c : choices) {
            temp[j] = c;
            String s = String.valueOf(temp);
            if (curr.equals(s)) {
              continue;
            }
            if (s.equals(end)) {
              return depth + 1;
            }
            if (!seen.contains(s) && nodes.contains(s)) {
              seen.add(s);
              qe.add(s);
            }
          }
          temp[j] = old;
        }
      }

      depth++;
    }

    return -1;
  }
}