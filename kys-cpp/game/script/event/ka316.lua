Talk("無本教黑木令牌者，不準進入黑木崖．", 88, 0);
Talk("〈那是什么鬼東西啊，該如何是好呢？〉", 0, 1);
if HaveItemBool(64) == true then goto label0 end;
    exit();
::label0::
    Talk("少俠，我們又見面了。", 34, 0);
    Talk("是曲長老啊，你怎么看上去要離開？", 0, 1);
    Talk("唉，不瞞小兄弟，老夫決意歸隱山中安心撫琴弄簫，神教事務不打算再理了。", 34, 0);
    Talk("是嘛，不過這樣也好，江湖確實不適合你這樣的音樂人。對了，你既然要離開，能不能把黑木令送給我？", 0, 1);
    Talk("小兄弟難道想要去見東方教主？黑木令我是可以送，但東方教主……我勸你還是不要見的好。", 34, 0);
    Talk("我知道你是一片好意，但我要去見他實在也是不得已。", 0, 1);
    Talk("既如此，給你吧。少俠，一切小心！", 34, 0);
    AddItem(125, 1);
    ModifyEvent(-2, -2, -2, -2, 317, 47, -2, -2, -2, -2, -2, -2, -2);
    ModifyEvent(30, 5, -2, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    ModifyEvent(30, 6, -2, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
exit();
