SubMapViewFromTo(47, 35, 25, 34);
PlayAnimation(0, 6228, 6254);
DarkScence();
LightScence();
Talk("七公，我還是不怎麼懂，不過我會慢慢練的．", 69, 0);
Talk("沒我出場的份，話說回來，黃蓉夠正，難怪那個歐陽克，嘿嘿．", 55, 0);
Talk("懂了嗎?剛才是降龍十八掌的最後第十八掌", 69, 0);
Talk("沒想到這幾日來，居然將掌法都傳給了你，看你笨頭笨腦的，實在是不想收你當徒弟．", 137, 0);
Talk("七公!", 69, 0);
Talk("哈哈，罵到你的心上人了，雖然靖兒沒你聰明 但心地善良耿直，當我徒弟到也不會日後會玷污我老叫化的威名．", 137, 0);
Talk("七公，桃花島你記得要來歐．", 69, 0);
Talk("放心，你們的事老叫化管到底．", 137, 0);
Talk("嘻嘻，謝謝七公．", 69, 0);
DarkScence();
SetRoleMagic(55, 0, 25, 700);
ModifyEvent(-2, 0, 1, 0, 460, -1, -1, 6126, 6148, 6126, 18, -2, -2);
ModifyEvent(-2, 6, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
ModifyEvent(-2, 7, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
ModifyEvent(-2, 8, 0, -2, -1, -1, -1, -2, -2, -2, -2, -2, -2);
ModifyEvent(-2, 9, 0, -2, -1, -1, -1, -2, -2, -2, -2, -2, -2);
OpenSubMap(75);
ModifyEvent(75, 6, 0, -2, -1, -1, 1166, -2, -2, -2, -2, -2, -2);
ModifyEvent(75, 7, 0, -2, -1, -1, 1166, -2, -2, -2, -2, -2, -2);
LightScence();
Talk("好了，你們快去桃花島，老叫化會依約前去．", 0, 0);
exit();
