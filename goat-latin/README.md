<h2>824. Goat Latin</h2><h3>Easy</h3><hr><div><p>A sentence <code>S</code> is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.</p>

<p>We would like to convert the sentence to "<em>Goat Latin"</em>&nbsp;(a made-up language similar to Pig Latin.)</p>

<p>The rules of Goat Latin are as follows:</p>

<ul>
	<li>If a word begins with a vowel (a, e, i, o, or u), append <code>"ma"</code>&nbsp;to the end of the word.<br>
	For example, the word 'apple' becomes 'applema'.<br>
	&nbsp;</li>
	<li>If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add <code>"ma"</code>.<br>
	For example, the word <code>"goat"</code>&nbsp;becomes <code>"oatgma"</code>.<br>
	&nbsp;</li>
	<li>Add one letter <code>'a'</code>&nbsp;to the end of each word per its word index in the sentence, starting with 1.<br>
	For example,&nbsp;the first word gets <code>"a"</code> added to the end, the second word gets <code>"aa"</code> added to the end and so on.</li>
</ul>

<p>Return the&nbsp;final sentence representing the conversion from <code>S</code>&nbsp;to Goat&nbsp;Latin.&nbsp;</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>"I speak Goat Latin"
<strong>Output: </strong>"Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>"The quick brown fox jumped over the lazy dog"
<strong>Output: </strong>"heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
</pre>

<p>&nbsp;</p>

<p>Notes:</p>

<ul>
	<li><code>S</code> contains only uppercase, lowercase and spaces.&nbsp;Exactly one space between each word.</li>
	<li><code>1 &lt;= S.length &lt;= 150</code>.</li>
</ul>
</div>