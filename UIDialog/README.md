# 可以设置字体的文本框
- 以QDialog作为窗口基类
- 字体样式设置：采用复选框，通过`connectSlotsByName`将信号与槽关联（而不是`connect`函数）
- 字体颜色设置：采用单选框，三个signal触发同一个slot
