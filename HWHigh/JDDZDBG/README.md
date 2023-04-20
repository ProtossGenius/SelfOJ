# 简单的自动曝光
## 题目描述
一个图像有 n 个像素点，存储在一个长度为 n 的数组 img 里，每个像素点的取值范围[0,255]
的正整数。
请你给图像每个像素点值加上一个整数 k（可以是负数），得到新图 newImg，使得新图newImg 的所有像素平均值最接近中位值 128。
请输出这个整数 k。 
## 输入描述
n 个整数，中间用空格分开
例如：
0 0 0 0
4 个数值，中间用空格分开

- 1 <= n <= 100
- 如有多个整数k都满足，输出小的那个k；
- 新图的像素值会自动截取到[0,255]范围。当新像素值<0，其值会更改为0；当新像素值>255，其值会更改为255；
例如newImg=”-1 -2 256″,会自动更改为”0 0 255″
## 输出描述
一个整数 k

## 示例

- 输入

```
0 0 0 0
```

- 输出
```
128
```

# Catalog
---
[<<< upper page](../README.md)
---

# SubCatalog

---
[<<< upper page](../README.md)
---