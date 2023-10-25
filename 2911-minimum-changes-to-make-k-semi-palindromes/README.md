<h2><a href="https://leetcode.com/problems/minimum-changes-to-make-k-semi-palindromes/">2911. Minimum Changes to Make K Semi-palindromes</a></h2><h3>Hard</h3><hr><div><p>Given a string <code>s</code> and an integer <code>k</code>, partition <code>s</code> into <code>k</code> <strong>substrings</strong> such that the sum of the number of letter changes required to turn each <strong>substring</strong> into a <strong>semi-palindrome</strong> is minimized.</p>

<p>Return <em>an integer denoting the <strong>minimum</strong> number of letter changes required.</em></p>

<p><strong>Notes</strong></p>

<ul>
	<li>A string is a <strong>palindrome</strong> if it can be read the same way from left to right and right to left.</li>
	<li>A string with a length of <code>len</code> is considered a <strong>semi-palindrome</strong> if there exists a positive integer <code>d</code> such that <code>1 &lt;= d &lt; len</code> and <code>len % d == 0</code>, and if we take indices that have the same modulo by <code>d</code>, they form a <strong>palindrome</strong>. For example, <code>"aa"</code>, <code>"aba"</code>, <code>"adbgad"</code>, and, <code>"abab"</code> are <strong>semi-palindrome</strong> and <code>"a"</code>, <code>"ab"</code>, and, <code>"abca"</code> are not.</li>
	<li>A <strong>substring</strong> is a contiguous sequence of characters within a string.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "abcac", k = 2
<strong>Output:</strong> 1
<strong>Explanation:</strong> We can divide s into substrings "ab" and "cac". The string "cac" is already a semi-palindrome. If we change "ab" to "aa", it becomes a semi-palindrome with d = 1.
It can be shown that there is no way to divide the string "abcac" into two semi-palindrome substrings. Therefore, the answer would be at least 1.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "abcdef", k = 2
<strong>Output:</strong> 2
<strong>Explanation:</strong> We can divide it into substrings "abc" and "def". Each of the substrings "abc" and "def" requires one change to become a semi-palindrome, so we need 2 changes in total to make all substrings semi-palindrome.
It can be shown that we cannot divide the given string into two substrings in a way that it would require less than 2 changes.</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> s = "aabbaa", k = 3
<strong>Output:</strong> 0
<strong>Explanation:</strong> We can divide it into substrings "aa", "bb" and "aa".
The strings "aa" and "bb" are already semi-palindromes. Thus, the answer is zero.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 200</code></li>
	<li><code>1 &lt;= k &lt;= s.length / 2</code></li>
	<li><code>s</code> consists only of lowercase English letters.</li>
</ul>
</div>