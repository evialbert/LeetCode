class Solution {
    List<String> mat = new ArrayList<>();
    int[] assignedChar = new int[26];
    int[] assignedInt = new int[10];
    boolean success;
    public boolean isSolvable(String[] words, String result) {
      Arrays.fill(assignedChar, -1);
      for (int i = 0; i < words.length; i++) {mat.add(words[i]);}
      mat.add(result);
      dfs(0,0,0);
      return success;
    }

    private void dfs(int i, int j, int carryOver) {
      if (success) return;
      int m = mat.size();
      if (i == m - 1) {
          if(j >= mat.get(m-1).length()) {
            if (carryOver == 0) {
                success = true;
            }
          } else {
            int state = assign(mat.get(m-1), j, carryOver % 10);
            if (state != -1) {dfs(0, j+1, carryOver / 10);}
            if (state == 1) {unassign(mat.get(m-1), j, carryOver % 10);}
          }
      } else {
          String str = mat.get(i);
          if (isAssigned(str, j)) {
              dfs(i+1, j, carryOver + getAssignedVal(str, j));
          } else {
              for (int z = 0; z < 10; z++) {
                  int state = assign(str, j, z);
                  if (state != -1) {dfs(i+1, j, carryOver + getAssignedVal(str, j));}
                  if (state == 1) {unassign(str, j, z);}
              }
          }
      }
    }

    private boolean isAssigned(String str, int p) {
        if (p >= str.length()) return true;
        return assignedChar[str.charAt(str.length() - 1 - p) - 'A'] != -1;
    }
    
    private boolean isAssignedInt(int i) {
        if (i < 0 || i > 9) { 
            System.out.println("isAssignedInt called with number out of range : " + i);
            return false;
        }
        return assignedInt[i] != 0;
    }

    private int getAssignedVal(String str, int p) {
        if (p >= str.length()) return 0;
        return assignedChar[str.charAt(str.length() - 1 - p) - 'A'];
    }
    
    private int assign(String str, int p, int val) {
      if (p >= str.length()) return -1;
      if (isAssigned(str, p)) { return getAssignedVal(str, p) == val? 0 : -1; }
      if (isAssignedInt(val)) return -1;
      if (val == 0) {
          for (String s : mat) {
              if (s.length() > 1 && s.charAt(0) == str.charAt(str.length() - 1 - p)) return -1;
          }
      }
      assignedChar[str.charAt(str.length() - 1 - p) - 'A'] = val;
      assignedInt[val] = str.charAt(str.length() - 1 - p);
      return 1;
    }
    
    private boolean unassign(String str, int p, int val) {
        if (p >= str.length() || val < 0 || val > 9) return false;
        if (assignedChar[str.charAt(str.length() - 1 - p) - 'A'] != val) return false;
        if (assignedInt[val] != str.charAt(str.length() - 1 - p)) return false;
        assignedChar[str.charAt(str.length() - 1 - p) - 'A'] = -1;
        assignedInt[val] = 0;
        return true;
    }
}