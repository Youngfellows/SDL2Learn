Talk("有什麼事嗎？", 50, 0);
if AskJoin () == true then goto label0 end;
    Talk("沒事，打個招呼．", 0, 1);
    exit();
::label0::
    Talk("少了喬幫主的降龍十八掌，簡直快混不下去了．", 0, 1);
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 50, 0);
        exit();
::label1::
        Talk("就隨你闖蕩江湖吧!", 50, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2);
        LightScence();
        Join(50);
exit();
