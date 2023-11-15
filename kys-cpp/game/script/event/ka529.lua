Talk("英雄出少年，不錯，不錯．", 50, 0);
if AskJoin () == true then goto label0 end;
    Talk("還好啦", 0, 0);
    exit();
::label0::
    Talk("喬幫主降龍十八掌威震江湖，能助我一臂之力嗎?", 0, 0);
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 50, 0);
        exit();
::label1::
        Talk("你是義弟的好友，我當然助你", 50, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, -1, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Join(50);
        AddMorality(1);
exit();
