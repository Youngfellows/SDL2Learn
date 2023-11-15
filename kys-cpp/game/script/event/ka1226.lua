Talk("．．．．．．", 49, 0);
if AskJoin () == true then goto label0 end;
    Talk("貪心不足蛇吞象，看你一臉靠北。", 0, 1);
    exit();
::label0::
    Talk("看你一臉雖樣，看來昨天晚上三秒就結束了吧，走吧嘴炮男。", 0, 1);
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 49, 0);
        exit();
::label1::
        Talk("我心情很差，不要跟我說話。", 49, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Join(49);
exit();
