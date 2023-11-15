Talk("水姑娘在這冰天雪地呆這麼久，過的如何?", 0, 0);
if AskJoin () == true then goto label0 end;
    Talk("這里是人間天堂，沒有江湖上的人心險惡。", 154, 0);
    exit();
::label0::
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 154, 0);
        exit();
::label1::
        Talk("老叫化，你武功不錯，你叫什麼名字。", 154, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Join(17);
exit();
