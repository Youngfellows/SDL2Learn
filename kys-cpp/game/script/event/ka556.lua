Talk("少俠有什麼吩咐？", 45, 0);
if AskJoin () == true then goto label0 end;
    Talk("沒什麼事，我路過這里，進來看看你．", 0, 1);
    exit();
::label0::
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 45, 0);
        exit();
::label1::
        Talk("走吧．", 0, 1);
        Talk("走．", 45, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Join(45);
exit();
