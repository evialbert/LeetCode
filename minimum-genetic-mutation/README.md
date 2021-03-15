<h2>433. Minimum Genetic Mutation</h2><h3>Medium</h3><hr><div><p>A gene string can be represented by an 8-character long string, with choices from <code>"A"</code>, <code>"C"</code>, <code>"G"</code>, <code>"T"</code>.</p>

<p>Suppose we need to investigate about a mutation (mutation from "start" to "end"), where ONE mutation is defined as ONE single character changed in the gene string.</p>

<p>For example, <code>"AACCGGTT"</code> -&gt; <code>"AACCGGTA"</code> is 1 mutation.</p>

<p>Also, there is a given gene "bank", which records all the valid gene mutations. A gene must be in the bank to make it a valid gene string.</p>

<p>Now, given 3 things - start, end, bank, your task is to determine what is the minimum number of mutations needed to mutate from "start" to "end". If there is no such a mutation, return -1.</p>

<p><b>Note:</b></p>

<ol>
	<li>Starting point is assumed to be valid, so it might not be included in the bank.</li>
	<li>If multiple mutations are needed, all mutations during in the sequence must be valid.</li>
	<li>You may assume start and end string is not the same.</li>
</ol>

<p>&nbsp;</p>

<p><b>Example 1:</b></p>

<pre>start: "AACCGGTT"
end:   "AACCGGTA"
bank: ["AACCGGTA"]

return: 1
</pre>

<p>&nbsp;</p>

<p><b>Example 2:</b></p>

<pre>start: "AACCGGTT"
end:   "AAACGGTA"
bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]

return: 2
</pre>

<p>&nbsp;</p>

<p><b>Example 3:</b></p>

<pre>start: "AAAAACCC"
end:   "AACCCCCC"
bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]

return: 3
</pre>

<p>&nbsp;</p>
</div>