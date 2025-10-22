<h2><a href="https://leetcode.com/problems/count-binary-palindromic-numbers">Count Binary Palindromic Numbers</a></h2> <img src='https://img.shields.io/badge/Difficulty-Hard-red' alt='Difficulty: Hard' /><hr><p>You are given a <strong>non-negative</strong> integer <code>n</code>.</p>

<p>A <strong>non-negative</strong> integer is called <strong>binary-palindromic</strong> if its binary representation (written without leading zeros) reads the same forward and backward.</p>

<p>Return the number of integers <code><font face="monospace">k</font></code> such that <code>0 &lt;= k &lt;= n</code> and the binary representation of <code><font face="monospace">k</font></code> is a palindrome.</p>

<p><strong>Note:</strong> The number 0 is considered binary-palindromic, and its representation is <code>&quot;0&quot;</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 9</span></p>

<p><strong>Output:</strong> <span class="example-io">6</span></p>

<p><strong>Explanation:</strong></p>

<p>The integers <code>k</code> in the range <code>[0, 9]</code> whose binary representations are palindromes are:</p>

<ul>
	<li><code>0 &rarr; &quot;0&quot;</code></li>
	<li><code>1 &rarr; &quot;1&quot;</code></li>
	<li><code>3 &rarr; &quot;11&quot;</code></li>
	<li><code>5 &rarr; &quot;101&quot;</code></li>
	<li><code>7 &rarr; &quot;111&quot;</code></li>
	<li><code>9 &rarr; &quot;1001&quot;</code></li>
</ul>

<p>All other values in <code>[0, 9]</code> have non-palindromic binary forms. Therefore, the count is 6.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 0</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<p>Since <code>&quot;0&quot;</code> is a palindrome, the count is 1.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 10<sup>15</sup></code></li>
</ul>
