@[TOC](LeetCode-[59. 螺旋矩阵 II](https://leetcode-cn.com/problems/spiral-matrix-ii/))

## 题目回顾

[传送门](https://leetcode-cn.com/problems/spiral-matrix-ii/)

给定一个正整数 *n*，生成一个包含 1 到 *n*2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

**示例:**

```
输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
```



## 题解

> 同螺旋矩阵一类似，参考[题解](https://leetcode-cn.com/problems/spiral-matrix/solution/mo-ni-guo-cheng-by-powcai-2/)，方法一模拟过程
> 时间复杂度是 $O(n^2)$， 
> 空间复杂度$O(n^2)$,
> 执行用时：$48 ms$ 

**模拟**

分为四个遍历过程，

1. 从左到右遍历首行的所有元素，并更新当前首行
2. 从上到下遍历最右列所有元素，并更新当前最右列
3. 从右向左遍历尾行的所有元素，并更新当前尾行
4. 从下到上遍历最左列所有元素，并更新当前最左列

举例：

`1 1 1 1 1`

`4 5 5 5 2`

`4 7 7 6 2` 

`3 3 3 3 2`

与之前螺旋矩阵原理类似，不同的地方，需要重新初始化一个矩阵，并且有个计数的count。



## python代码实现

```python
class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if not matrix:
            return []
        head_row=0
        rail_row=len(matrix)-1      #当前尾部的行数索引
        l_col=0
        r_col=len(matrix[0])-1      #当前最右边的列数索引
        res=[]
        while head_row<=rail_row and l_col<=r_col:
            for i in range(l_col,r_col+1):          #1.从左到右遍历首行的所有元素  
                res.append(matrix[head_row][i])
            head_row=head_row+1                     #更新当前首行
            if head_row>rail_row: 
                break
            for i in range(head_row,rail_row+1):    #2.从上到下遍历最右列所有元素
                res.append(matrix[i][r_col])
            r_col=r_col-1                           #更新当前最右列
            if r_col<l_col:
                break
            for i in range(r_col,l_col-1,-1):       #3.从右向左遍历尾行所有元素
                res.append(matrix[rail_row][i])
            rail_row=rail_row-1                     #更新当前尾行
            for i in range(rail_row,head_row-1,-1): #4.从下到上遍历最左列所有元素
                res.append(matrix[i][l_col])        
            l_col=l_col+1                           #更新当前最左列

        return res
```
