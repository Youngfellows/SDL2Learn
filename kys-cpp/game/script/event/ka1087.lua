Talk("公子別來無恙？", 138, 0);
if AskJoin () == true then goto label0 end;
    Talk("一切還好．", 0, 1);
    exit();
::label0::
    Talk("段兄弟愿再陪我一游嗎？", 0, 1);
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 138, 0);
        exit();
::label1::
        Talk("好啊．", 138, 0);
        DarkScence();
        ModifyEvent(-2, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -2, -2);
        ModifyEvent(-2, 8, 0, 0, -1, -1, -1, -1, -1, -1, -1, -2, -2);
        LightScence();
        Join(53);
exit();
