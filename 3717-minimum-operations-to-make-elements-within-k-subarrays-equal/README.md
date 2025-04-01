<h2><a href="https://leetcode.com/problems/minimum-operations-to-make-elements-within-k-subarrays-equal">Minimum Operations to Make Elements Within K Subarrays Equal</a></h2> <img src='https://img.shields.io/badge/Difficulty-Hard-red' alt='Difficulty: Hard' /><hr><p>You are given an integer array <code>nums</code> and two integers, <code>x</code> and <code>k</code>. You can perform the following operation any number of times (<strong>including zero</strong>):</p>

<ul>
	<li>Increase or decrease any element of <code>nums</code> by 1.</li>
</ul>

<p>Return the <strong>minimum</strong> number of operations needed to have <strong>at least</strong> <code>k</code> <em>non-overlapping <span data-keyword="subarray-nonempty">subarrays</span></em> of size <strong>exactly</strong> <code>x</code> in <code>nums</code>, where all elements within each subarray are equal.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [5,-2,1,3,7,3,6,4,-1], x = 3, k = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">8</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Use 3 operations to add 3 to <code>nums[1]</code> and use 2 operations to subtract 2 from <code>nums[3]</code>. The resulting array is <code>[5, 1, 1, 1, 7, 3, 6, 4, -1]</code>.</li>
	<li>Use 1 operation to add 1 to <code>nums[5]</code> and use 2 operations to subtract 2 from <code>nums[6]</code>. The resulting array is <code>[5, 1, 1, 1, 7, 4, 4, 4, -1]</code>.</li>
	<li>Now, all elements within each subarray <code>[1, 1, 1]</code> (from indices 1 to 3) and <code>[4, 4, 4]</code> (from indices 5 to 7) are equal. Since 8 total operations were used, 8 is the output.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [9,-2,-2,-2,1,5], x = 2, k = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Use 3 operations to subtract 3 from <code>nums[4]</code>. The resulting array is <code>[9, -2, -2, -2, -2, 5]</code>.</li>
	<li>Now, all elements within each subarray <code>[-2, -2]</code> (from indices 1 to 2) and <code>[-2, -2]</code> (from indices 3 to 4) are equal. Since 3 operations were used, 3 is the output.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>6</sup> &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>2 &lt;= x &lt;= nums.length</code></li>
	<li><code>1 &lt;= k &lt;= 15</code></li>
	<li><code>2 &lt;= k * x &lt;= nums.length</code></li>
</ul>
