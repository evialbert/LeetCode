class Solution {
    
    long mod = 1_000_000_007;
    
    public int numberOfWays(String s, String t, long k) {
        
        
        
        long hash = 0;
        
        //long [] pow = new long [s.length()];
        long mul = 1;
        int idx = 0;

        long mul2 = 1;

        long hash2 = 0; 
        long sHash2 = 0;
        
        for (char c : t.toCharArray()) {

            mul *= 26;
            mul %= mod;

            mul2 *= 27;
            mul2 %= mod;
            
            hash *= 26;
            hash += c - 'a';
            hash %= mod;

            hash2 *= 27;
            hash2 += c - 'a';
            hash2 %= mod;
        }
        
        long sHash = 0;
        
        for (char c : s.toCharArray()) {
            sHash *= 26;
            sHash += c - 'a';
            sHash %= mod;

            sHash2 *= 27;
            sHash2 += c - 'a';
            sHash2 %= mod;
        }
        
        List<Integer> index = new ArrayList<>();
        
        long other, other2;
        
        int n = s.length();
        
        
        for (int i = 0, j = s.length() - 1; i < s.length(); ++i) {
            if (sHash == hash && sHash2 == hash2)
                index.add((n - i) % n);
            
            sHash *= 26;
            sHash2 *= 27;
            
            sHash += mod;
            sHash2 += mod;

            other = s.charAt(i) - 'a';
            other2 = other * mul;
            other2 %= mod;
            sHash -= other2;
            sHash += other;

            other = s.charAt(i) - 'a';
            other2 = other * mul2;
            other2 %= mod;
            sHash2 -= other2;
            sHash2 += other;

            
            sHash %= mod;
            sHash2 %= mod;
        }
        
        
        long result = 0;
        
        long [][] root = new long [][] {{0, n - 1}, {1 , n - 2}};
        
        long [][] pow = powerExp(root, k);
        
        long a = pow[0][0] * 1;
        long b = pow[1][0] * 1;

        //System.out.println(index);
         
        for (int num : index) {
            result += num == 0 ? a : b;
            
            result %= mod;
        }
        
        
        return (int)result;
        
    }
    
    private long [][] powerExp (long [][] mat, long pow) {
		Map<Long, long [][]> map = new HashMap<>();
		
		long current = 1;
		long [][] val = mat;
		long [][] result = new long [mat.length][mat.length];
		
		for (int i = 0; i < mat.length; ++i) {
			result[i][i] = 1;
		}
		
		while (current <= pow) {
			map.put(current, val);
			
			val = multiplyMat(val, val);
			current *= 2;
		}
		
		while (current > 1) {
			current /= 2;
			
			if (pow >= current) {
				pow -= current;
				result = multiplyMat(result, map.get(current));
			}
		}
		
		return result;
	}
	
	
	
	private long [][] multiplyMat(long [][] mat1, long [][] mat2) {
		long [][] result = new long [mat1.length][mat2[0].length];
		long sum = 0;
		
		for (int i = 0; i < mat1.length; ++i) {
			for (int j = 0; j < mat2[0].length; ++j) {
				sum = 0;
				
				for (int k = 0; k < mat1.length; ++k) {
					sum += mat1[i][k] * mat2[k][j];
					sum %= mod;
				}
				
				sum %= mod;
				result[i][j] = sum;
			}
		}
		
		return result;
	}
}
