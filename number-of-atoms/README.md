<h2>726. Number of Atoms</h2><h3>Hard</h3><hr><div><p>Given a chemical <code>formula</code> (given as a string), return the count of each atom.</p>

<p>The atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.</p>

<p>One or more digits representing that element's count may follow if the count is greater than 1. If the count is 1, no digits will follow. For example, H2O and H2O2 are possible, but H1O2 is impossible.</p>

<p>Two formulas concatenated together to produce another formula. For example, H2O2He3Mg4 is also a formula.</p>

<p>A formula placed in parentheses, and a count (optionally added) is also a formula. For example, (H2O2) and (H2O2)3 are formulas.</p>

<p>Given a <code>formula</code>, return <em>the count of all elements as a string in the following form</em>: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.</p>

<p>&nbsp;</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> formula = "H2O"
<strong>Output:</strong> "H2O"
<strong>Explanation:</strong> The count of elements are {'H': 2, 'O': 1}.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> formula = "Mg(OH)2"
<strong>Output:</strong> "H2MgO2"
<strong>Explanation:</strong> The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> formula = "K4(ON(SO3)2)2"
<strong>Output:</strong> "K4N2O14S4"
<strong>Explanation:</strong> The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> formula = "Be32"
<strong>Output:</strong> "Be32"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= formula.length&nbsp;&lt;= 1000</code></li>
	<li><code>formula</code> consists of English letters, digits, <code>'('</code>, and <code>')'</code>.</li>
	<li><code>formula</code> is always valid.</li>
</ul>
</div>