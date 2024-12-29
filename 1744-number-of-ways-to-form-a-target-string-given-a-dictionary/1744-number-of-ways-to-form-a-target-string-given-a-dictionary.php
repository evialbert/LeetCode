class Solution {

    /**
     * @param String[] $words
     * @param String $target
     * @return Integer
     */
     private $MOD = 1000000007;
     private $freq;
     private $memo;
     private $n;
     private $m;
    function numWays($words, $target) {
        $this->n = strlen($words[0]);
        $this->m = strlen($target);

        // Initialize frequency array
        $this->freq = array_fill(0, $this->n, array_fill(0, 26, 0));
        foreach ($words as $word) {
            for ($i = 0; $i < $this->n; $i++) {
                $this->freq[$i][ord($word[$i]) - ord('a')]++;
            }
        }

        // Initialize memoization array
        $this->memo = array_fill(0, $this->n + 1, array_fill(0, $this->m + 1, -1));

        // Start recursion
        return $this->traverse(0, 0, $target);
    }
    private function traverse($level, $index, $target) {
        if ($index === $this->m) return 1; // All characters of target matched
        if ($level === $this->n) return 0; // No more columns to process

        if ($this->memo[$level][$index] !== -1) return $this->memo[$level][$index];

        // Skip the current column
        $ways = $this->traverse($level + 1, $index, $target);

        // Use the current column if the character exists
        $charIndex = ord($target[$index]) - ord('a');
        if ($this->freq[$level][$charIndex] > 0) {
            $ways = ($ways + $this->freq[$level][$charIndex] * $this->traverse($level + 1, $index + 1, $target)) % $this->MOD;
        }

        return $this->memo[$level][$index] = $ways;
    }
}