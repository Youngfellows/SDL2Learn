Talk("媽媽跟小黃不知道怎麼樣了．", 124, 0);
if AskJoin () == true then goto label0 end;
    exit();
::label0::
    Talk("當然，還得到一門俠客行神功回來 真爽．", 0, 1);
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 124, 0);
        exit();
::label1::
        Talk("好啊！", 124, 0);
        DarkScence();
        ModifyEvent(-2, 7, 0, 0, -1, -1, -1, -1, -1, -1, -1, -2, -2);
        ModifyEvent(-2, 8, 0, 0, -1, -1, -1, -1, -1, -1, -1, -2, -2);
        LightScence();
        Join(38);
        AddMorality(1);
exit();
