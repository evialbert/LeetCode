<h2>686. Repeated String Match</h2><h3>Medium</h3><hr><div><p>Given two strings&nbsp;<code>a</code> and <code>b</code>, return the minimum number of times you should repeat string&nbsp;<code>a</code>&nbsp;so that string&nbsp;<code>b</code>&nbsp;is a substring of it. If it is&nbsp;impossible for&nbsp;<code>b</code>​​​​​​ to be a substring of&nbsp;<code>a</code> after repeating it, return&nbsp;<code>-1</code>.</p>

<p><strong>Notice:</strong>&nbsp;string&nbsp;<code>"abc"</code>&nbsp;repeated 0 times is&nbsp;<code>""</code>,&nbsp; repeated 1 time is&nbsp;<code>"abc"</code>&nbsp;and repeated 2 times is&nbsp;<code>"abcabc"</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> a = "abcd", b = "cdabcdab"
<strong>Output:</strong> 3
<strong>Explanation:</strong> We return 3 because by repeating a three times "ab<strong>cdabcdab</strong>cd", b is a substring of it.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> a = "a", b = "aa"
<strong>Output:</strong> 2
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> a = "a", b = "a"
<strong>Output:</strong> 1
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> a = "abc", b = "wxyz"
<strong>Output:</strong> -1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= a.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= b.length &lt;= 10<sup>4</sup></code></li>
	<li><code>a</code>&nbsp;and&nbsp;<code>b</code>&nbsp;consist of lower-case English letters.</li>
</ul>
</div>