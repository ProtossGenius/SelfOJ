# 优秀学员统计
## 题目描述
公司某部门软件教导团正在组织新员工每日打卡学习活动，他们开展这项学习活动已经一个月了，所以想统计下这个月优秀的打卡员工。每个员工会对应一个 id，每天的打卡记录记录当天打卡员工的 id 集合，一共 30 天。
请你实现代码帮助统计出打卡次数 top5 的员工。假如打卡次数相同，将较早参与打卡的员工排在前面，如果开始参与打卡的时间还是一样，将 id 较小的员工排在前面。注：不考虑并列的情况，按规则返回前 5 名员工的 id 即可，如果当月打卡的员工少于5 个，按规则排序返回所有有打卡记录的员工 id。 
## 输入描述
第一行输入为新员工数量 N，表示新员工编号 id 为 0 到 N-1，N 的范围为[1,100]
第二行输入为 30 个整数，表示每天打卡的员工数量，每天至少有 1 名员工打卡之后 30 行为每天打卡的员工 id 集合，id 不会重复
## 输出描述
按顺序输出打卡 top5 员工的 id，用空格隔开


## 示例

- 输入

```
5
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 2 3 4 5 1 6 6 6 6 1 1 3 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
```

- 输出
```
1 6 2 3 4
```

# Catalog
---
[<<< upper page](../README.md)
---

# SubCatalog

---
[<<< upper page](../README.md)
---