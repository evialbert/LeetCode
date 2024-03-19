<h2><a href="https://leetcode.com/problems/maximum-strength-of-k-disjoint-subarrays/">3077. Maximum Strength of K Disjoint Subarrays</a></h2><h3>Hard</h3><hr><div><p>You are given a <strong>0-indexed</strong> array of integers <code>nums</code> of length <code>n</code>, and a <strong>positive</strong> <strong>odd</strong> integer <code>k</code>.</p>

<p>The strength of <code>x</code> subarrays is defined as <code>strength = sum[1] * x - sum[2] * (x - 1) + sum[3] * (x - 2) - sum[4] * (x - 3) + ... + sum[x] * 1</code> where <code>sum[i]</code> is the sum of the elements in the <code>i<sup>th</sup></code> subarray. Formally, strength is sum of <code>(-1)<sup>i+1</sup> * sum[i] * (x - i + 1)</code> over all <code>i</code>'s such that <code>1 &lt;= i &lt;= x</code>.</p>

<p>You need to select <code>k</code> <strong>disjoint <span data-keyword="subarray-nonempty">subarrays</span></strong> from <code>nums</code>, such that their <strong>strength</strong> is <strong>maximum</strong>.</p>

<p>Return <em>the <strong>maximum</strong> possible <strong>strength</strong> that can be obtained</em>.</p>

<p><strong>Note</strong> that the selected subarrays <strong>don't</strong> need to cover the entire array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,-1,2], k = 3
<strong>Output:</strong> 22
<strong>Explanation:</strong> The best possible way to select 3 subarrays is: nums[0..2], nums[3..3], and nums[4..4]. The strength is (1 + 2 + 3) * 3 - (-1) * 2 + 2 * 1 = 22.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [12,-2,-2,-2,-2], k = 5
<strong>Output:</strong> 64
<strong>Explanation:</strong> The only possible way to select 5 disjoint subarrays is: nums[0..0], nums[1..1], nums[2..2], nums[3..3], and nums[4..4]. The strength is 12 * 5 - (-2) * 4 + (-2) * 3 - (-2) * 2 + (-2) * 1 = 64.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [-1,-2,-3], k = 1
<strong>Output:</strong> -1
<strong>Explanation:</strong> The best possible way to select 1 subarray is: nums[0..0]. The strength is -1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
	<li><code>1 &lt;= n * k &lt;= 10<sup>6</sup></code></li>
	<li><code>k</code> is odd.</li>
</ul>
</div>