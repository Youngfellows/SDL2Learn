Talk("怎麼?回心轉意了嗎？", 29, 0);
if AskJoin () == false then goto label0 end;
    Talk("好，不妨咱倆一起在這世界中，好好的干他一炮．", 0, 1);
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 29, 0);
        exit();
::label1::
        Talk("我們就一起去游戲人間吧．美女我來了．", 29, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Join(29);
        AddMorality(-6);
        exit();
::label0::
        Talk("你自己玩好了，我自己OGC就夠了．", 0, 1);
        Talk("少裝了，難不成你想演”斷臂山”．", 29, 0);
        ModifyEvent(-2, -2, -2, -2, 306, -1, -1, -2, -2, -2, -2, -2, -2);
exit();
