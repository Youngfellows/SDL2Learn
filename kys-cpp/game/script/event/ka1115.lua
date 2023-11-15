Talk("最近過的如何?", 178, 0);
if AskJoin () == true then goto label0 end;
    exit();
::label0::
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 178, 0);
        exit();
::label1::
        Talk("少了阿朱姑娘神奇的易容術，還真不好混!", 0, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Join(73);
exit();
