<h2><a href="https://leetcode.com/problems/maximum-element-sum-of-a-complete-subset-of-indices/">2862. Maximum Element-Sum of a Complete Subset of Indices</a></h2><h3>Hard</h3><hr><div><p>You are given a <strong>1</strong><strong>-indexed</strong> array <code>nums</code> of <code>n</code> integers.</p>

<p>A set of numbers is <strong>complete</strong> if the product of every pair of its elements is a perfect square.</p>

<p>For a subset of the indices set <code>{1, 2, ..., n}</code> represented as <code>{i<sub>1</sub>, i<sub>2</sub>, ..., i<sub>k</sub>}</code>, we define its <strong>element-sum</strong> as: <code>nums[i<sub>1</sub>] + nums[i<sub>2</sub>] + ... + nums[i<sub>k</sub>]</code>.</p>

<p>Return <em>the <strong>maximum element-sum</strong> of a <strong>complete</strong> subset of the indices set</em> <code>{1, 2, ..., n}</code>.</p>

<p>A perfect square is a number that can be expressed as the product of an integer by itself.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [8,7,3,5,7,2,4,9]
<strong>Output:</strong> 16
<strong>Explanation:</strong> Apart from the subsets consisting of a single index, there are two other complete subsets of indices: {1,4} and {2,8}.
The sum of the elements corresponding to indices 1 and 4 is equal to nums[1] + nums[4] = 8 + 5 = 13.
The sum of the elements corresponding to indices 2 and 8 is equal to nums[2] + nums[8] = 7 + 9 = 16.
Hence, the maximum element-sum of a complete subset of indices is 16.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [5,10,3,10,1,13,7,9,4]
<strong>Output:</strong> 19
<strong>Explanation:</strong> Apart from the subsets consisting of a single index, there are four other complete subsets of indices: {1,4}, {1,9}, {2,8}, {4,9}, and {1,4,9}.
The sum of the elements corresponding to indices 1 and 4 is equal to nums[1] + nums[4] = 5 + 10 = 15.
The sum of the elements corresponding to indices 1 and 9 is equal to nums[1] + nums[9] = 5 + 4 = 9.
The sum of the elements corresponding to indices 2 and 8 is equal to nums[2] + nums[8] = 10 + 9 = 19.
The sum of the elements corresponding to indices 4 and 9 is equal to nums[4] + nums[9] = 10 + 4 = 14.
The sum of the elements corresponding to indices 1, 4, and 9 is equal to nums[1] + nums[4] + nums[9] = 5 + 10 + 4 = 19.
Hence, the maximum element-sum of a complete subset of indices is 19.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n == nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>
</div>