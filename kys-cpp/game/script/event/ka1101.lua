Talk("我的小忽蘭，先回我家去幫我看家吧!", 144, 0);
Talk("這麼久都不來，我還以為你騙我", 0, 0);
if AskJoin () == true then goto label0 end;
    Talk("就算騙了全天下人，也不敢騙我的小忽蘭", 0, 0);
    exit();
::label0::
    if TeamIsFull() == true then goto label1 end;
        Talk("我回來拿些藥，乖乖幫我看家", 0, 0);
        DarkScence();
        ModifyEvent(-2, 12, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Join(115);
        exit();
::label1::
        Talk("你的隊伍已滿，我無法加入．", 144, 0);
exit();
