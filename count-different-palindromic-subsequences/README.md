<h2>730. Count Different Palindromic Subsequences</h2><h3>Hard</h3><hr><div><p>Given a string <code>s</code>, find the number of different non-empty palindromic subsequences in <code>s</code>, and <b>return that number modulo <code>10^9 + 7</code>.</b></p>

<p>A subsequence of a string <code>s</code> is obtained by deleting 0 or more characters from <code>s</code>.</p>

<p>A sequence is palindromic if it is equal to the sequence reversed.</p>

<p>Two sequences <code>A_1, A_2, ...</code> and <code>B_1, B_2, ...</code> are different if there is some <code>i</code> for which <code>A_i != B_i</code>.</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b> 
s = 'bccb'
<b>Output:</b> 6
<b>Explanation:</b> 
The 6 different non-empty palindromic subsequences are 'b', 'c', 'bb', 'cc', 'bcb', 'bccb'.
Note that 'bcb' is counted only once, even though it occurs twice.
</pre>

<p><b>Example 2:</b></p>

<pre><b>Input:</b> 
s = 'abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba'
<b>Output:</b> 104860361
<b>Explanation:</b> 
There are 3104860382 different non-empty palindromic subsequences, which is 104860361 modulo 10^9 + 7.
</pre>

<p><b>Note:</b></p>

<ul>
	<li>The length of <code>s</code> will be in the range <code>[1, 1000]</code>.</li>
	<li>Each character <code>s[i]</code> will be in the set <code>{'a', 'b', 'c', 'd'}</code>.</li>
</ul>
</div>