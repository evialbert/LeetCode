<h2><a href="https://leetcode.com/problems/apply-operations-to-make-two-strings-equal/">2896. Apply Operations to Make Two Strings Equal</a></h2><h3>Medium</h3><hr><div><p>You are given two <strong>0-indexed</strong> binary strings <code>s1</code> and <code>s2</code>, both of length <code>n</code>, and a positive integer <code>x</code>.</p>

<p>You can perform any of the following operations on the string <code>s1</code> <strong>any</strong> number of times:</p>

<ul>
	<li>Choose two indices <code>i</code> and <code>j</code>, and flip both <code>s1[i]</code> and <code>s1[j]</code>. The cost of this operation is <code>x</code>.</li>
	<li>Choose an index <code>i</code> such that <code>i &lt; n - 1</code> and flip both <code>s1[i]</code> and <code>s1[i + 1]</code>. The cost of this operation is <code>1</code>.</li>
</ul>

<p>Return <em>the <strong>minimum</strong> cost needed to make the strings </em><code>s1</code><em> and </em><code>s2</code><em> equal, or return </em><code>-1</code><em> if it is impossible.</em></p>

<p><strong>Note</strong> that flipping a character means changing it from <code>0</code> to <code>1</code> or vice-versa.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s1 = "1100011000", s2 = "0101001010", x = 2
<strong>Output:</strong> 4
<strong>Explanation:</strong> We can do the following operations:
- Choose i = 3 and apply the second operation. The resulting string is s1 = "110<u><strong>11</strong></u>11000".
- Choose i = 4 and apply the second operation. The resulting string is s1 = "1101<strong><u>00</u></strong>1000".
- Choose i = 0 and j = 8 and apply the first operation. The resulting string is s1 = "<u><strong>0</strong></u>1010010<u><strong>1</strong></u>0" = s2.
The total cost is 1 + 1 + 2 = 4. It can be shown that it is the minimum cost possible.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s1 = "10110", s2 = "00011", x = 4
<strong>Output:</strong> -1
<strong>Explanation:</strong> It is not possible to make the two strings equal.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == s1.length == s2.length</code></li>
	<li><code>1 &lt;= n, x &lt;= 500</code></li>
	<li><code>s1</code> and <code>s2</code> consist only of the characters <code>'0'</code> and <code>'1'</code>.</li>
</ul>
</div>