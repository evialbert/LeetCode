class Solution {
        public String addStrings(String num1, String num2) {

              if (num1.length()<num2.length()) {
                  String temp = num1;
                  num1 = num2;
                  num2 = temp;
              }
              int i = num1.length()-1;
              int temp=0;
              StringBuilder res = new StringBuilder();
              while (i>=0) {
                  if (i == 0) {
                      int sum = 0;
                      if (num1.length() == num2.length()) {
                          sum = num1.charAt(i) - '0' + num2.charAt(i) - '0' + temp;
                      } else {
                          sum = num1.charAt(i) - '0' + temp;
                      }
                      if (sum >= 10) {
                          res.append(sum % 10);
                          res.append(sum / 10);
                          break;
                      } else {

                      }
                  }

                  int a = num1.charAt(i) - '0';
                  int b = 0;
                  if (num2.length() - num1.length() + i >= 0) {
                      b = num2.charAt(num2.length() - num1.length() + i) - '0';
                  }
                  int sum = a + b + temp;
                  res.append(sum % 10);
                  temp = sum / 10;

                  i--;
              }
              if (res.equals("")) {
                  res = res.append("0");
              }
              return new String(res.reverse());
        }
}