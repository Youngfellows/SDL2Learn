Talk("爹，等等我!", 0, 0);
if AskJoin () == true then goto label0 end;
    Talk("．．．．．．這啥小，難怪那個太監會把書還我．", 201, 1);
    exit();
::label0::
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 201, 0);
        exit();
::label1::
        LightScence();
        Talk("蕭姑娘，你先到我高昇客棧等我，有需要幫忙我會去找你．", 201, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Join(72);
exit();
