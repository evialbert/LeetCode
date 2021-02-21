<h2>1114. Print in Order</h2><h3>Easy</h3><hr><div><p>Suppose we have a class:</p>

<pre>public class Foo {
&nbsp; public void first() { print("first"); }
&nbsp; public void second() { print("second"); }
&nbsp; public void third() { print("third"); }
}
</pre>

<p>The same instance of <code>Foo</code> will be passed to three different threads. Thread A will call <code>first()</code>, thread B will call <code>second()</code>, and thread C will call <code>third()</code>. Design a mechanism and modify the program&nbsp;to ensure that&nbsp;<code>second()</code>&nbsp;is executed after&nbsp;<code>first()</code>, and&nbsp;<code>third()</code> is executed after&nbsp;<code>second()</code>.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><b>Input:</b> [1,2,3]
<b>Output:</b> "firstsecondthird"
<strong>Explanation:</strong> There are three threads being fired asynchronously. The input [1,2,3] means thread A calls first(), thread B calls second(), and thread C calls third(). "firstsecondthird" is the correct output.
</pre>

<p><strong>Example 2:</strong></p>

<pre><b>Input:</b> [1,3,2]
<b>Output:</b> "firstsecondthird"
<strong>Explanation:</strong> The input [1,3,2] means thread A calls first(), thread B calls third(), and thread C calls second(). "firstsecondthird" is the correct output.</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<p>We do not know how the threads will be scheduled in the operating system, even though the numbers in the input seems to imply the ordering. The input format you see is mainly&nbsp;to ensure our tests' comprehensiveness.</p>
</div>