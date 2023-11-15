if AskJoin () == true then goto label0 end;
    exit();
::label0::
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 186, 0);
        exit();
::label1::
        Talk("想要拜我為師算什麼壞主意 好，小寶，今日我就收你到我門下。", 0, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Join(74);
exit();
