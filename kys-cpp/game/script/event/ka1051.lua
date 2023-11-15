Talk("兄弟別來無恙？", 1, 0);
if AskJoin () == true then goto label0 end;
    Talk("一切還好．", 0, 1);
    exit();
::label0::
    Talk("少了大哥胡家刀法助威，小弟辦起事來總覺得不順，．．．", 0, 1);
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 1, 0);
        exit();
::label1::
        Talk("別說了，我就再助你一臂之力．", 1, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2);
        LightScence();
        Join(1);
exit();
