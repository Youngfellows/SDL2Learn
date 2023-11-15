Talk("沒有我大概遇到瓶頸了吧，哈哈", 49, 0);
if AskJoin () == true then goto label0 end;
    Talk("屁， 一切還好．", 0, 1);
    exit();
::label0::
    Talk("大師，我有麻煩了，快幫幫我．", 0, 1);
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 49, 0);
        exit();
::label1::
        Talk("真是廢物．", 49, 0);
        DarkScence();
        ModifyEvent(-2, 2, 0, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2);
        ModifyEvent(-2, 15, 0, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2);
        LightScence();
        Join(49);
exit();
