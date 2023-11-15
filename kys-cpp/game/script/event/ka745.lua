Talk("看你剛才三言兩語唬走那個大內高手，瞧你武功也不怎樣，不把鴛刀拿來我就要搶了．", 201, 0);
Talk("好，我就他媽的看看誰搶誰的．", 0, 5);
Talk("哈哈哈，看來是我搶你．", 201, 0);
if AskJoin () == true then goto label0 end;
    Talk("你．．．你還算是男人嗎?用武力搶了女人的東西還這麼得意．", 0, 5);
    exit();
::label0::
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 201, 0);
        exit();
::label1::
        Talk("算了，女人就是不講理，不想跟你辯解，我要帶著你的鴛鴦刀，去鴛鴦刀山洞了，解開鴛鴦刀天下無敵的秘密，哈哈．", 0, 5);
        DarkScence();
        ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Join(72);
exit();
