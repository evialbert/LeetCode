<h2><a href="https://leetcode.com/problems/maximum-number-that-sum-of-the-prices-is-less-than-or-equal-to-k/">3007. Maximum Number That Sum of the Prices Is Less Than or Equal to K</a></h2><h3>Medium</h3><hr><div><p>You are given an integer <code>k</code> and an integer <code>x</code>.</p>

<p>Consider <code>s</code> is the <strong>1-indexed </strong>binary representation of an integer <code>num</code>. The <strong>price</strong> of a number <code>num</code> is the number of <code>i</code>'s such that <code>i % x == 0</code> and <code><font face="monospace">s[i]</font></code> is a <strong>set bit</strong>.</p>

<p>Return <em>the <b>greatest</b> integer </em><code>num</code><em> such that the sum of <strong>prices</strong> of all numbers from </em><code>1</code><em> to </em><code>num</code><em> is less than or equal to </em><code>k</code><em>.</em></p>

<p><strong>Note</strong>:</p>

<ul>
	<li>In the binary representation of a number <strong>set bit</strong> is a bit of value <code>1</code>.</li>
	<li>The binary representation of a number will be indexed from right to left. For example, if <code>s == 11100</code>, <code>s[4] == 1</code> and <code>s[2] == 0</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> k = 9, x = 1
<strong>Output:</strong> 6
<strong>Explanation:</strong> The numbers 1, 2, 3, 4, 5, and 6 can be written in binary representation as "1", "10", "11", "100", "101", and "110" respectively.
Since x is equal to 1, the price of each number is the number of its set bits.
The number of set bits in these numbers is 9. So the sum of the prices of the first 6 numbers is 9.
So the answer is 6.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> k = 7, x = 2
<strong>Output:</strong> 9
<strong>Explanation:</strong> Since x is equal to 2, we should just check even<sup>th</sup> bits.
The second bit of binary representation of numbers 2 and 3 is a set bit. So the sum of their prices is 2.
The second bit of binary representation of numbers 6 and 7 is a set bit. So the sum of their prices is 2.
The fourth bit of binary representation of numbers 8 and 9 is a set bit but their second bit is not. So the sum of their prices is 2.
Numbers 1, 4, and 5 don't have set bits in their even<sup>th</sup> bits in their binary representation. So the sum of their prices is 0.
The second and the fourth bit of the binary representation of the number 10 are a set bit. So its price is 2.
The sum of the prices of the first 9 numbers is 6.
Because the sum of the prices of the first 10 numbers is 8, the answer is 9.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= 10<sup>15</sup></code></li>
	<li><code>1 &lt;= x &lt;= 8</code></li>
</ul>
</div>