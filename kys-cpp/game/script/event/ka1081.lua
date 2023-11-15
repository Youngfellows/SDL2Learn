Talk("你要干嘛？", 48, 0);
if AskJoin () == true then goto label0 end;
    Talk("沒事．", 0, 1);
    exit();
::label0::
    Talk("鐵面，我需要你的幫忙，走吧．", 0, 1);
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 48, 0);
        exit();
::label1::
        Talk("嗯．", 48, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2);
        LightScence();
        Join(48);
exit();
