<h2>331. Verify Preorder Serialization of a Binary Tree</h2><h3>Medium</h3><hr><div><p>One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as <code>#</code>.</p>

<pre>     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
</pre>

<p>For example, the above binary tree can be serialized to the string <code>"9,3,4,#,#,1,#,#,2,#,6,#,#"</code>, where <code>#</code> represents a null node.</p>

<p>Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.</p>

<p>Each comma separated value in the string must be either an integer or a character <code>'#'</code> representing <code>null</code> pointer.</p>

<p>You may assume that the input format is always valid, for example it could never contain two consecutive commas such as <code>"1,,3"</code>.</p>

<p><b>Example 1:</b></p>

<pre><strong>Input: </strong><code>"9,3,4,#,#,1,#,#,2,#,6,#,#"</code>
<strong>Output: </strong><code>true</code></pre>

<p><b>Example 2:</b></p>

<pre><strong>Input: </strong><code>"1,#"</code>
<strong>Output: </strong><code>false</code>
</pre>

<p><b>Example 3:</b></p>

<pre><strong>Input: </strong><code>"9,#,#,1"</code>
<strong>Output: </strong><code>false</code></pre></div>