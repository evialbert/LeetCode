<h2><a href="https://leetcode.com/problems/find-the-string-with-lcp/">2573. Find the String with LCP</a></h2><h3>Hard</h3><hr><div><p>We define the <code>lcp</code> matrix of any <strong>0-indexed</strong> string <code>word</code> of <code>n</code> lowercase English letters as an <code>n x n</code> grid such that:</p>

<ul>
	<li><code>lcp[i][j]</code> is equal to the length of the <strong>longest common prefix</strong> between the substrings <code>word[i,n-1]</code> and <code>word[j,n-1]</code>.</li>
</ul>

<p>Given an&nbsp;<code>n x n</code> matrix <code>lcp</code>, return the alphabetically smallest string <code>word</code> that corresponds to <code>lcp</code>. If there is no such string, return an empty string.</p>

<p>A string <code>a</code> is lexicographically smaller than a string <code>b</code> (of the same length) if in the first position where <code>a</code> and <code>b</code> differ, string <code>a</code> has a letter that appears earlier in the alphabet than the corresponding letter in <code>b</code>. For example, <code>"aabd"</code> is lexicographically smaller than <code>"aaca"</code> because the first position they differ is at the third letter, and <code>'b'</code> comes before <code>'c'</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> lcp = [[4,0,2,0],[0,3,0,1],[2,0,2,0],[0,1,0,1]]
<strong>Output:</strong> "abab"
<strong>Explanation:</strong> lcp corresponds to any 4 letter string with two alternating letters. The lexicographically smallest of them is "abab".
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> lcp = [[4,3,2,1],[3,3,2,1],[2,2,2,1],[1,1,1,1]]
<strong>Output:</strong> "aaaa"
<strong>Explanation:</strong> lcp corresponds to any 4 letter string with a single distinct letter. The lexicographically smallest of them is "aaaa". 
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> lcp = [[4,3,2,1],[3,3,2,1],[2,2,2,1],[1,1,1,3]]
<strong>Output:</strong> ""
<strong>Explanation:</strong> lcp[3][3] cannot be equal to 3 since word[3,...,3] consists of only a single letter; Thus, no answer exists.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n ==&nbsp;</code><code>lcp.length == </code><code>lcp[i].length</code>&nbsp;<code>&lt;= 1000</code></li>
	<li><code><font face="monospace">0 &lt;= lcp[i][j] &lt;= n</font></code></li>
</ul>
</div>