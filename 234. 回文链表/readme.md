问题描述：

给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。

用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题

解决思路：

1. 找到链表中点，对链表一半进行反转。
2. 对两个链表进行遍历，比较数值是否相同。

详细解法：

```cpp
while (fast->next != nullptr && fast->next->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
}
```
使用经典的快慢指针，确定链表的中点。对于偶数个元素，可以找到中点偏左。对于奇数个元素，正好找到正中间。

```cpp
slow = slow->next;
if (fast->next != nullptr) {
    fast = fast->next;
}
```
将 slow 移动到链表的后半部分。将 fast 移动到链表的末尾。

```cpp
reverse(slow, nullptr);
```
翻转链表后，fast 为头指针
