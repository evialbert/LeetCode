<h2>208. Implement Trie (Prefix Tree)</h2><h3>Medium</h3><hr><div><p>Implement a trie with <code>insert</code>, <code>search</code>, and <code>startsWith</code> methods.</p>

<p><b>Example:</b></p>

<pre>Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
</pre>

<p><b>Note:</b></p>

<ul>
	<li>You may assume that all inputs are consist of lowercase letters <code>a-z</code>.</li>
	<li>All inputs are guaranteed to be non-empty strings.</li>
</ul>
</div>