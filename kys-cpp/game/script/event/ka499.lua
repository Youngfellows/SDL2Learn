Talk("還在OGC啊？", 0, 1);
Talk("吃屎．", 49, 0);
if AskJoin () == true then goto label0 end;
    Talk("掰，那改天我們再見．", 0, 1);
    exit();
::label0::
    Talk("既然如此，我就帶你去擂鼓山找你的師父師兄弟吧．", 0, 1);
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 49, 0);
        exit();
::label1::
        Talk("好啊．", 49, 0);
        DarkScence();
        ModifyEvent(-2, 2, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 15, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Join(49);
        AddMorality(3);
exit();
