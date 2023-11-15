Talk("愣小子，要干嘛？", 130, 0);
if AskJoin () == true then goto label0 end;
    Talk("沒事．", 0, 1);
    exit();
::label0::
    Talk("阿紫姑娘，再加入我好嗎？", 0, 1);
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 130, 0);
        exit();
::label1::
        Talk("你不怕我的話就走吧．", 130, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2);
        LightScence();
        Join(47);
exit();
