Talk("公子別來無恙？", 37, 0);
if AskJoin () == true then goto label0 end;
    Talk("一切還好．", 0, 1);
    exit();
::label0::
    Talk("我這次來是找狄兄幫忙的．", 0, 1);
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 37, 0);
        exit();
::label1::
        Talk("狄某欠公子一個人情，公子需要幫忙，狄某自當義不容辭．", 37, 0);
        DarkScence();
        ModifyEvent(-2, 7, 0, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2);
        ModifyEvent(-2, 8, 0, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2);
        ModifyEvent(-2, 10, 0, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2);
        LightScence();
        Join(37);
exit();
