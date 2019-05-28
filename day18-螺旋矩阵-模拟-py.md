@[TOC](LeetCode-[54. 螺旋矩阵](https://leetcode-cn.com/problems/spiral-matrix/))

## 题目回顾

[传送门](https://leetcode-cn.com/problems/spiral-matrix/solution/luo-xuan-ju-zhen-by-leetcode/)

给定一个包含 *m* x *n* 个元素的矩阵（*m* 行, *n* 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

**示例 1:**

```
输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
```

**示例 2:**

```
输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]
```



## 题解

> 参考[题解](https://leetcode-cn.com/problems/spiral-matrix/solution/mo-ni-guo-cheng-by-powcai-2/)，方法一模拟过程
> 时间复杂度是 $O(n)$， 
> 空间复杂度$O(n)$,
> 执行用时：$52 ms$ 

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
