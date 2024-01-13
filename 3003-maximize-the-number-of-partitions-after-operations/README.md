<h2><a href="https://leetcode.com/problems/maximize-the-number-of-partitions-after-operations/">3003. Maximize the Number of Partitions After Operations</a></h2><h3>Hard</h3><hr><div><p>You are given a <strong>0-indexed</strong> string <code>s</code> and an integer <code>k</code>.</p>

<p>You are to perform the following partitioning operations until <code>s</code> is <strong>empty</strong>:</p>

<ul>
	<li>Choose the <strong>longest</strong> <strong>prefix</strong> of <code>s</code> containing at most <code>k</code> <strong>distinct</strong> characters.</li>
	<li><strong>Delete</strong> the prefix from <code>s</code> and increase the number of partitions by one. The remaining characters (if any) in <code>s</code> maintain their initial order.</li>
</ul>

<p><strong>Before</strong> the operations, you are allowed to change <strong>at most</strong> <strong>one</strong> index in <code>s</code> to another lowercase English letter.</p>

<p>Return <em>an integer denoting the <strong>maximum</strong> number of resulting partitions after the operations by optimally choosing at most one index to change.</em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "accca", k = 2
<strong>Output:</strong> 3
<strong>Explanation: </strong>In this example, to maximize the number of resulting partitions, s[2] can be changed to 'b'.
s becomes "acbca".
The operations can now be performed as follows until s becomes empty:
- Choose the longest prefix containing at most 2 distinct characters, "<u>ac</u>bca".
- Delete the prefix, and s becomes "bca". The number of partitions is now 1.
- Choose the longest prefix containing at most 2 distinct characters, "<u>bc</u>a".
- Delete the prefix, and s becomes "a". The number of partitions is now 2.
- Choose the longest prefix containing at most 2 distinct characters, "<u>a</u>".
- Delete the prefix, and s becomes empty. The number of partitions is now 3.
Hence, the answer is 3.
It can be shown that it is not possible to obtain more than 3 partitions.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "aabaab", k = 3
<strong>Output:</strong> 1
<strong>Explanation: </strong>In this example, to maximize the number of resulting partitions we can leave s as it is.
The operations can now be performed as follows until s becomes empty: 
- Choose the longest prefix containing at most 3 distinct characters, "<u>aabaab</u>".
- Delete the prefix, and s becomes empty. The number of partitions becomes 1. 
Hence, the answer is 1. 
It can be shown that it is not possible to obtain more than 1 partition.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> s = "xxyz", k = 1
<strong>Output:</strong> 4
<strong>Explanation:</strong> In this example, to maximize the number of resulting partitions, s[1] can be changed to 'a'.
s becomes "xayz".
The operations can now be performed as follows until s becomes empty:
- Choose the longest prefix containing at most 1 distinct character, "<u>x</u>ayz".
- Delete the prefix, and s becomes "ayz". The number of partitions is now 1.
- Choose the longest prefix containing at most 1 distinct character, "<u>a</u>yz".
- Delete the prefix, and s becomes "yz". The number of partitions is now 2.
- Choose the longest prefix containing at most 1 distinct character, "<u>y</u>z".
- Delete the prefix, and s becomes "z". The number of partitions is now 3.
- Choose the longest prefix containing at most 1 distinct character, "<u>z</u>".
- Delete the prefix, and s becomes empty. The number of partitions is now 4.
Hence, the answer is 4.
It can be shown that it is not possible to obtain more than 4 partitions.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> consists only of lowercase English letters.</li>
	<li><code>1 &lt;= k &lt;= 26</code></li>
</ul>
</div>