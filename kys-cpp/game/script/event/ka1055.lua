Talk("公子別來無恙？", 9, 0);
if AskJoin () == true then goto label0 end;
    Talk("一切還好．", 0, 1);
    exit();
::label0::
    Talk("少了張兄的九陽神功，一路上頗多兇險，是否可以再請張兄出馬？", 0, 1);
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 9, 0);
        exit();
::label1::
        Talk("好的．", 9, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2);
        LightScence();
        Join(9);
exit();
