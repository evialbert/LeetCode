<h2><a href="https://leetcode.com/problems/minimum-reverse-operations/">2612. Minimum Reverse Operations</a></h2><h3>Hard</h3><hr><div><p>You are given an integer <code>n</code> and an integer <code>p</code> in the range <code>[<font face="monospace">0</font>, n - 1]</code>. Representing a <strong>0-indexed</strong> array <code>arr</code>&nbsp;of length <code>n</code> where all positions are set to <code>0</code>'s, except position <code>p</code> which is set to <code>1</code>.</p>

<p>You are also given an integer array <code>banned</code> containing some positions from the array. For the <strong>i</strong><sup><strong>th</strong></sup> position in <code>banned</code>, <code>arr[banned[i]] = 0</code>, and <code>banned[i] != p</code>.</p>

<p>You can perform <strong>multiple</strong> operations on <code>arr</code>. In an operation, you can choose a <strong>subarray</strong> with size <code>k</code> and <strong>reverse</strong> the subarray. However, the <code>1</code> in <code>arr</code> should never go to any of the positions in <code>banned</code>. In other words, after each operation <code>arr[banned[i]]</code> <strong>remains</strong> <code>0</code>.</p>

<p><em>Return an array</em> <code>ans</code> <em>where</em><em> for each </em><code>i</code><em> from </em><code>[0, n - 1]</code>, <code>ans[i]</code> <em>is the <strong>minimum</strong> number of reverse operations needed to bring the</em> <code>1</code> <em>to position</em> <code>i</code><em> in arr</em>, <em>or</em> <code>-1</code> <em>if it is impossible</em>.</p>

<ul>
	<li>A <strong>subarray</strong> is a contiguous <strong>non-empty</strong> sequence of elements within an array.</li>
	<li>The values of <code>ans[i]</code> are independent for all <code>i</code>'s.</li>
	<li>The <strong>reverse </strong>of an array is an array containing the values in <strong>reverse order</strong>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> n = 4, p = 0, banned = [1,2], k = 4
<strong>Output:</strong> [0,-1,-1,1]
<strong>Explanation:</strong> In this case <code>k = 4</code> so there is only one possible reverse operation we can perform, which is reversing the whole array. Initially, 1<strong> </strong>is placed at position 0 so the amount of operations we need for position 0 is <code>0</code>. We can never place a 1 on the banned positions, so the answer for positions 1 and 2 is <code>-1</code>. Finally, with one reverse operation we can bring the 1 to index 3, so the answer for position 3 is <code>1</code>. 
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> n = 5, p = 0, banned = [2,4], k = 3
<strong>Output:</strong> [0,-1,-1,-1,-1]
<strong>Explanation:</strong> In this case the 1 is initially at position 0, so the answer for that position is <code>0</code>. We can perform reverse operations of size 3. The 1 is currently located at position 0, so we need to reverse the subarray <code>[0, 2]</code> for it to leave that position, but reversing that subarray makes position 2 have a 1, which shouldn't happen. So, we can't move the 1 from position 0, making the result for all the other positions <code>-1</code>. 
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> n = 4, p = 2, banned = [0,1,3], k = 1
<strong>Output:</strong> [-1,-1,0,-1]
<strong>Explanation:</strong> In this case we can only perform reverse operations of size 1.<strong>&nbsp;</strong>So the 1 never changes its position.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= p &lt;= n - 1</code></li>
	<li><code>0 &lt;= banned.length &lt;= n - 1</code></li>
	<li><code>0 &lt;= banned[i] &lt;= n - 1</code></li>
	<li><code>1 &lt;= k &lt;= n&nbsp;</code></li>
	<li><code>banned[i] != p</code></li>
	<li>all values in <code>banned</code>&nbsp;are <strong>unique</strong>&nbsp;</li>
</ul>
</div>