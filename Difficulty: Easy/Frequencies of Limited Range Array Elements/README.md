<h2><a href="https://www.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/0">Frequencies of Limited Range Array Elements</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">You are given an array arr[] containing positive integers. These integers can be from 1 to p, and some numbers may be repeated or absent. Your task is to count the frequency of all numbers that lie in the range 1 to n.</span></p>
<p><span style="font-size: 18px;"><em>Note: </em></span></p>
<ol>
<li><span style="font-size: 18px;">Do <strong>modify</strong> the array <strong>in-place </strong>changes in arr[], such that arr[i] = frequency(i) and <em>assume<strong> 1-based</strong> indexing<strong>.</strong></em></span></li>
<li><span style="font-size: 18px;">The elements greater than n in the array can be ignored when counting.</span></li>
</ol>
<p><span style="font-size: 18px;"><strong>Examples</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>n = 5, arr[] = [2, 3, 2, 3, 5], p = 5
<strong>Output:</strong> [0, 2, 2, 0, 1]<strong>
Explanation: </strong>Counting frequencies of each array element We have: 1 occurring 0 times. 2 occurring 2 times. 3 occurring 2 times. 4 occurring 0 times. 5 occurring 1 time, all the modifications done in the same given arr[].</span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>n = 4, arr[] = [3, 3, 3, 3], p = 3
<strong>Output: </strong>[0, 0, 4, 0]<strong>
Explanation: </strong>Counting frequencies of each array element We have: 1 occurring 0 times. 2 occurring 0 times. 3 occurring 4 times. 4 occurring 0 times.</span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>n = 2, arr[] = [8, 9], p = 9
<strong>Output: </strong>[0, 0]<strong>
Explanation: </strong>Counting frequencies of each array element We have: 1 occurring 0 times. 2 occurring 0 times. Since here P=9, but there are no 9th Index present so can't count the value.
</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ n ≤ 10<sup>5</sup><br>1 ≤ p ≤ 4*10<sup>4</sup><sup>&nbsp;</sup><br>1 &lt;= arr[i] &lt;= p</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Paytm</code>&nbsp;<code>VMWare</code>&nbsp;<code>Zoho</code>&nbsp;<code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Hash</code>&nbsp;<code>Data Structures</code>&nbsp;