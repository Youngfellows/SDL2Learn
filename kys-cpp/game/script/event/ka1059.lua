Talk("公子別來無恙？", 145, 0);
if AskJoin () == true then goto label0 end;
    Talk("一切還好．", 0, 1);
    exit();
::label0::
    Talk("少了細心可人的小昭姑娘，我的生活起居都不知道該怎麼辦，不知小昭姑娘能再幫我忙嗎？", 0, 1);
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 145, 0);
        exit();
::label1::
        Talk("小昭愿意幫公子的忙．", 145, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2);
        LightScence();
        Join(114);
exit();
