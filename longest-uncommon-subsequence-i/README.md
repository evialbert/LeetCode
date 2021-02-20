<h2>521. Longest Uncommon Subsequence I</h2><h3>Easy</h3><hr><div><p>Given two strings <code>a</code>&nbsp;and <code>b</code>, find the length of the&nbsp;<strong>longest uncommon subsequence</strong>&nbsp;between them.</p>

<p>A&nbsp;<b>subsequence</b>&nbsp;of&nbsp;a string&nbsp;<code>s</code>&nbsp;is a string that can be obtained after deleting any number of characters from <code>s</code>. For example, <code>"abc"</code>&nbsp;is a subsequence of <code>"aebdc"</code>&nbsp;because you can delete the underlined characters in&nbsp;<code>"a<u>e</u>b<u>d</u>c"</code>&nbsp;to get <code>"abc"</code>. Other subsequences of&nbsp;<code>"aebdc"</code>&nbsp;include&nbsp;<code>"aebdc"</code>,&nbsp;<code>"aeb"</code>,&nbsp;and&nbsp;<code>""</code>&nbsp;(empty string).</p>

<p>An&nbsp;<strong>uncommon subsequence</strong>&nbsp;between two strings&nbsp;is a string that is a <strong>subsequence of one&nbsp;but not the other</strong>.</p>

<p>Return <em>the length of the <strong>longest uncommon subsequence</strong>&nbsp;between <code>a</code>&nbsp;and <code>b</code></em>. If the longest uncommon subsequence doesn't exist, return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> a = "aba", b = "cdc"
<strong>Output:</strong> 3
<strong>Explanation:</strong> One longest uncommon subsequence is "aba" because "aba" is a subsequence of "aba" but not "cdc".
Note that "cdc" is also a longest uncommon subsequence.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> a = "aaa", b = "bbb"
<strong>Output:</strong> 3
<strong>Explanation:</strong>&nbsp;The longest uncommon subsequences are "aaa" and "bbb".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> a = "aaa", b = "aaa"
<strong>Output:</strong> -1
<strong>Explanation:</strong>&nbsp;Every subsequence of string a is also a subsequence of string b. Similarly, every subsequence of string b is also a subsequence of string a.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= a.length, b.length &lt;= 100</code></li>
	<li><code>a</code> and <code>b</code> consist of lower-case English letters.</li>
</ul>
</div>