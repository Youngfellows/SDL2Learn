Talk("兄弟，一路上還爽吧？又搞了幾個女人呀？", 29, 0);
if AskJoin () == true then goto label0 end;
    Talk("沒有搞到，還是繼續當宅男而已．", 0, 1);
    exit();
::label0::
    Talk("沒有你同行，小弟一人怎麼玩得起來．", 0, 1);
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 29, 0);
        exit();
::label1::
        Talk("那就走吧．我一個人玩也沒什麼意思，多P的比較好玩．", 29, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2);
        LightScence();
        Join(29);
exit();
