<h2><a href="https://leetcode.com/problems/minimum-increments-for-target-multiples-in-an-array">Minimum Increments for Target Multiples in an Array</a></h2> <img src='https://img.shields.io/badge/Difficulty-Hard-red' alt='Difficulty: Hard' /><hr><p>You are given two arrays, <code>nums</code> and <code>target</code>.</p>

<p>In a single operation, you may increment any element of <code>nums</code> by 1.</p>

<p>Return <strong>the minimum number</strong> of operations required so that each element in <code>target</code> has <strong>at least</strong> one multiple in <code>nums</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2,3], target = [4]</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<p>The minimum number of operations required to satisfy the condition is 1.</p>

<ul>
	<li>Increment 3 to 4 with just one operation, making 4 a multiple of itself.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [8,4], target = [10,5]</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p>The minimum number of operations required to satisfy the condition is 2.</p>

<ul>
	<li>Increment 8 to 10 with 2 operations, making 10 a multiple of both 5 and 10.</li>
</ul>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [7,9,10], target = [7]</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<p>Target 7 already has a multiple in nums, so no additional operations are needed.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= target.length &lt;= 4</code></li>
	<li><code>target.length &lt;= nums.length</code></li>
	<li><code>1 &lt;= nums[i], target[i] &lt;= 10<sup>4</sup></code></li>
</ul>
