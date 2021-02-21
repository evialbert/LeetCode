<h2>893. Groups of Special-Equivalent Strings</h2><h3>Easy</h3><hr><div><p>You are given an array <code>A</code> of strings.</p>

<p>A <em>move&nbsp;onto <code>S</code></em> consists of swapping any two even indexed characters of <code>S</code>, or any two odd indexed characters of <code>S</code>.</p>

<p>Two strings <code>S</code> and <code>T</code> are&nbsp;<em>special-equivalent</em>&nbsp;if after any number of <em>moves onto <code>S</code></em>, <code>S == T</code>.</p>

<p>For example, <code>S = "zzxy"</code> and <code>T = "xyzz"</code> are special-equivalent because we may make the moves <code>"zzxy" -&gt; "xzzy" -&gt; "xyzz"</code>&nbsp;that swap <code>S[0]</code> and <code>S[2]</code>, then <code>S[1]</code> and <code>S[3]</code>.</p>

<p>Now, a <em>group of special-equivalent strings from <code>A</code></em>&nbsp;is a non-empty subset of&nbsp;A such that:</p>

<ol>
	<li>Every pair of strings in the group are special equivalent, and;</li>
	<li>The group is the largest size possible (ie., there isn't a string S not in the group such that S is special equivalent to every string in the group)</li>
</ol>

<p>Return the number of groups of special-equivalent strings from <code>A</code>.</p>

<div>&nbsp;</div>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">["abcd","cdab","cbad","xyzz","zzxy","zzyx"]</span>
<strong>Output: </strong><span id="example-output-1">3</span>
<strong>Explanation: </strong>
One group is ["abcd", "cdab", "cbad"], since they are all pairwise special equivalent, and none of the other strings are all pairwise special equivalent to these.

The other two groups are ["xyzz", "zzxy"] and ["zzyx"].  Note that in particular, "zzxy" is not special equivalent to "zzyx".
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">["abc","acb","bac","bca","cab","cba"]</span>
<strong>Output: </strong><span id="example-output-2">3</span></pre>

<p>&nbsp;</p>
</div>
</div>

<div>
<div>
<div>
<div>
<p><strong>Note:</strong></p>

<ul>
	<li><code>1 &lt;= A.length &lt;= 1000</code></li>
	<li><code>1 &lt;= A[i].length &lt;= 20</code></li>
	<li>All <code>A[i]</code> have the same length.</li>
	<li>All <code>A[i]</code> consist of only lowercase letters.</li>
</ul>
</div>
</div>
</div>
</div>
</div>