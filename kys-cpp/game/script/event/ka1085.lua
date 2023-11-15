Talk("怎麼？想通了．", 139, 0);
if AskJoin () == true then goto label0 end;
    Talk("不行，我不能這麼做．", 0, 1);
    exit();
::label0::
    Talk("好，就聽你的．", 0, 1);
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 139, 0);
        exit();
::label1::
        Talk("走．", 139, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2);
        LightScence();
        Join(51);
exit();
