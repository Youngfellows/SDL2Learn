Talk("哈哈，看來還有好處可以撈，那就去見太后吧。", 162, 1);
DarkScence();
ModifyEvent(-2, 32, -2, -2, -2, -2, -2, 8282, 8282, 8282, -2, -2, -2);
LightScence();
Talk("皇上，萬睡萬睡萬萬睡．", 0, 1);
Talk("平身!", 148, 5);
Talk("小桂子參見太后，小桂子將人帶來了．", 0, 1);
Talk("參見太后千歲千歲千千歲．．．", 148, 5);
Talk("哀家有點不舒服，不便起身 ，你就是生擒鰲拜的那位少俠吧!你是否在殺死鰲拜後從他身上拿走一本四十二章經?", 0, 1);
Talk("在下并未動過鰲拜屍身，也沒看到太后所說的四十二章經 <媽的，跟我要起四十二章經來，智障才會說有看到．>", 148, 5);
Talk("少俠還想騙哀家嗎?既然如此我也有我的做法．", 162, 1);
Talk("鰲拜都打不過我，皇宮大內高手我也看不在眼里，難道太后想動手?", 0, 5);
PlayAnimation(-1, 5994, 6012);
DarkScence();
ModifyEvent(-2, 0, -2, -2, 990, -1, -1, -2, -2, -2, -2, -2, -2);
ModifyEvent(-2, 6, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
ModifyEvent(-2, 7, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
ModifyEvent(-2, 12, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
ModifyEvent(-2, 14, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
ModifyEvent(-2, 15, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
ModifyEvent(-2, 32, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
ModifyEvent(-2, 33, 1, -2, -1, -1, -1, 1840, 1840, 1840, -2, -2, -2);
LightScence();
PlayAnimation(-1, 6026, 6036);
AddItemWithoutHint(164, -1);
Talk("小桂子，想要豹胎易筋丸解藥就快動手!", 0, 0);
exit();
