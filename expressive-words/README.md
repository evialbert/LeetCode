<h2>809. Expressive Words</h2><h3>Medium</h3><hr><div><p>Sometimes people repeat letters to represent extra feeling, such as "hello" -&gt; "heeellooo", "hi" -&gt; "hiiii".&nbsp; In these strings like "heeellooo", we have <em>groups</em> of adjacent letters that are all the same:&nbsp; "h", "eee", "ll", "ooo".</p>

<p>For some given string <code>s</code>, a query word is <em>stretchy</em> if it can be made to be equal to <code>s</code> by any&nbsp;number of&nbsp;applications of the following <em>extension</em> operation: choose a group consisting of&nbsp;characters <code>c</code>, and add some number of characters <code>c</code> to the group so that the size of the group is 3 or more.</p>

<p>For example, starting with "hello", we could do an extension on the group "o" to get "hellooo", but we cannot get "helloo" since the group "oo" has size less than 3.&nbsp; Also, we could do another extension like "ll" -&gt; "lllll" to get "helllllooo".&nbsp; If <code>s = "helllllooo"</code>, then the query word "hello" would be stretchy because of these two extension operations:&nbsp;<code>query = "hello" -&gt; "hellooo" -&gt;&nbsp;"helllllooo" = s</code>.</p>

<p>Given a list of query words, return the number of words that are stretchy.&nbsp;</p>

<p>&nbsp;</p>

<pre><strong>Example:</strong>
<strong>Input:</strong> 
s = "heeellooo"
words = ["hello", "hi", "helo"]
<strong>Output:</strong> 1
<strong>Explanation:</strong> 
We can extend "e" and "o" in the word "hello" to get "heeellooo".
We can't extend "helo" to get "heeellooo" because the group "ll" is not size 3 or more.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= len(s) &lt;= 100</code>.</li>
	<li><code>0 &lt;= len(words) &lt;= 100</code>.</li>
	<li><code>0 &lt;= len(words[i]) &lt;= 100</code>.</li>
	<li><code>s</code> and all words in <code>words</code>&nbsp;consist only of&nbsp;lowercase letters</li>
</ul>
</div>