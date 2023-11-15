Talk("怎麼？需要我的治療嗎?", 45, 0);
if AskJoin () == true then goto label0 end;
    Talk("沒有，我生病時再來找你．", 0, 1);
    exit();
::label0::
    Talk("少了薛先生的奇妙醫術，一路上難免病痛煩身，是否可以再請薛先生幫忙呢？", 0, 1);
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 45, 0);
        exit();
::label1::
        Talk("薛某自當效力．", 45, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2);
        LightScence();
        Join(45);
exit();
