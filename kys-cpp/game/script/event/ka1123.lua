Talk("怎麼?想反悔?", 194, 0);
if AskJoin () == true then goto label0 end;
    Talk("趙姑娘，歡迎你加入我的K隆小隊，我以隊長軍曹的名義歡迎你．", 0, 1);
    exit();
::label0::
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 194, 0);
        exit();
::label1::
        Talk("趙姑娘，你先回萬安寺吧!有需要幫忙我會去找你．", 0, 1);
        DarkScence();
        ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Join(39);
exit();
