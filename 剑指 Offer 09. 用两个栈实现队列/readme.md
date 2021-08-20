问题：

用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

思路：

1. 使用栈A的 push 操作实现 appendTail 的功能。
2. 在执行 deleteHead 时，将栈A的元素逆序输出到B中，输出B中的第一元素。同时清空栈A。