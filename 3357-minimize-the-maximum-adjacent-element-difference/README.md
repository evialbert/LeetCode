<h2><a href="https://leetcode.com/problems/minimize-the-maximum-adjacent-element-difference/">3357. Minimize the Maximum Adjacent Element Difference</a></h2><h3>Hard</h3><hr><div><p>You are given an array of integers <code>nums</code>. Some values in <code>nums</code> are <strong>missing</strong> and are denoted by -1.</p>

<p>You can choose a pair of <strong>positive</strong> integers <code>(x, y)</code> <strong>exactly once</strong> and replace each&nbsp;<strong>missing</strong> element with <em>either</em> <code>x</code> or <code>y</code>.</p>

<p>You need to <strong>minimize</strong><strong> </strong>the<strong> maximum</strong> <strong>absolute difference</strong> between <em>adjacent</em> elements of <code>nums</code> after replacements.</p>

<p>Return the <strong>minimum</strong> possible difference.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2,-1,10,8]</span></p>

<p><strong>Output:</strong> <span class="example-io">4</span></p>

<p><strong>Explanation:</strong></p>

<p>By choosing the pair as <code>(6, 7)</code>, nums can be changed to <code>[1, 2, 6, 10, 8]</code>.</p>

<p>The absolute differences between adjacent elements are:</p>

<ul>
	<li><code>|1 - 2| == 1</code></li>
	<li><code>|2 - 6| == 4</code></li>
	<li><code>|6 - 10| == 4</code></li>
	<li><code>|10 - 8| == 2</code></li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [-1,-1,-1]</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<p>By choosing the pair as <code>(4, 4)</code>, nums can be changed to <code>[4, 4, 4]</code>.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [-1,10,-1,8]</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<p>By choosing the pair as <code>(11, 9)</code>, nums can be changed to <code>[11, 10, 9, 8]</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>nums[i]</code> is either -1 or in the range <code>[1, 10<sup>9</sup>]</code>.</li>
</ul>
</div>