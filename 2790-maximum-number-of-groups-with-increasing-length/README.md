<h2><a href="https://leetcode.com/problems/maximum-number-of-groups-with-increasing-length/">2790. Maximum Number of Groups With Increasing Length</a></h2><h3>Hard</h3><hr><div><p>You are given a <strong>0-indexed</strong> array <code>usageLimits</code> of length <code>n</code>.</p>

<p>Your task is to create <strong>groups</strong> using numbers from <code>0</code> to <code>n - 1</code>, ensuring that each number, <code>i</code>, is used no more than <code>usageLimits[i]</code> times in total <strong>across all groups</strong>. You must also satisfy the following conditions:</p>

<ul>
	<li>Each group must consist of <strong>distinct </strong>numbers, meaning that no duplicate numbers are allowed within a single group.</li>
	<li>Each group (except the first one) must have a length <strong>strictly greater</strong> than the previous group.</li>
</ul>

<p>Return <em>an integer denoting the <strong>maximum</strong> number of groups you can create while satisfying these conditions.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> <code>usageLimits</code> = [1,2,5]
<strong>Output:</strong> 3
<strong>Explanation:</strong> In this example, we can use 0 at most once, 1 at most twice, and 2 at most five times.
One way of creating the maximum number of groups while satisfying the conditions is: 
Group 1 contains the number [2].
Group 2 contains the numbers [1,2].
Group 3 contains the numbers [0,1,2]. 
It can be shown that the maximum number of groups is 3. 
So, the output is 3. </pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> <code>usageLimits</code> = [2,1,2]
<strong>Output:</strong> 2
<strong>Explanation:</strong> In this example, we can use 0 at most twice, 1 at most once, and 2 at most twice.
One way of creating the maximum number of groups while satisfying the conditions is:
Group 1 contains the number [0].
Group 2 contains the numbers [1,2].
It can be shown that the maximum number of groups is 2.
So, the output is 2. 
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> <code>usageLimits</code> = [1,1]
<strong>Output:</strong> 1
<strong>Explanation:</strong> In this example, we can use both 0 and 1 at most once.
One way of creating the maximum number of groups while satisfying the conditions is:
Group 1 contains the number [0].
It can be shown that the maximum number of groups is 1.
So, the output is 1. 
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= usageLimits.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= usageLimits[i] &lt;= 10<sup>9</sup></code></li>
</ul>
</div>