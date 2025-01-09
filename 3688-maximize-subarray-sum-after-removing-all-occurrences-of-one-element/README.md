<h2><a href="https://leetcode.com/problems/maximize-subarray-sum-after-removing-all-occurrences-of-one-element">Maximize Subarray Sum After Removing All Occurrences of One Element</a></h2> <img src='https://img.shields.io/badge/Difficulty-Hard-red' alt='Difficulty: Hard' /><hr><p>You are given an integer array <code>nums</code>.</p>

<p>You can do the following operation on the array <strong>at most</strong> once:</p>

<ul>
	<li>Choose <strong>any</strong> integer <code>x</code> such that <code>nums</code> remains <strong>non-empty</strong> on removing all occurrences of <code>x</code>.</li>
	<li>Remove&nbsp;<strong>all</strong> occurrences of <code>x</code> from the array.</li>
</ul>

<p>Return the <strong>maximum</strong> <span data-keyword="subarray-nonempty">subarray</span> sum across <strong>all</strong> possible resulting arrays.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [-3,2,-2,-1,3,-2,3]</span></p>

<p><strong>Output:</strong> <span class="example-io">7</span></p>

<p><strong>Explanation:</strong></p>

<p>We can have the following arrays after at most one operation:</p>

<ul>
	<li>The original array is <code>nums = [<span class="example-io">-3, 2, -2, -1, <u><strong>3, -2, 3</strong></u></span>]</code>. The maximum subarray sum is <code>3 + (-2) + 3 = 4</code>.</li>
	<li>Deleting all occurences of <code>x = -3</code> results in <code>nums = [2, -2, -1, <strong><u><span class="example-io">3, -2, 3</span></u></strong>]</code>. The maximum subarray sum is <code>3 + (-2) + 3 = 4</code>.</li>
	<li>Deleting all occurences of <code>x = -2</code> results in <code>nums = [<span class="example-io">-3, <strong><u>2, -1, 3, 3</u></strong></span>]</code>. The maximum subarray sum is <code>2 + (-1) + 3 + 3 = 7</code>.</li>
	<li>Deleting all occurences of <code>x = -1</code> results in <code>nums = [<span class="example-io">-3, 2, -2, <strong><u>3, -2, 3</u></strong></span>]</code>. The maximum subarray sum is <code>3 + (-2) + 3 = 4</code>.</li>
	<li>Deleting all occurences of <code>x = 3</code> results in <code>nums = [<span class="example-io">-3, <u><strong>2</strong></u>, -2, -1, -2</span>]</code>. The maximum subarray sum is 2.</li>
</ul>

<p>The output is <code>max(4, 4, 7, 4, 2) = 7</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2,3,4]</span></p>

<p><strong>Output:</strong> <span class="example-io">10</span></p>

<p><strong>Explanation:</strong></p>

<p>It is optimal to not perform any operations.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>6</sup> &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>
