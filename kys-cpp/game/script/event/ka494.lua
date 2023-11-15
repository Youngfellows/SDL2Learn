Talk("閣下考慮的怎麼樣，要不要我加入你，讓你能輕易獲得”天龍八部”？", 139, 0);
if AskJoin () == true then goto label0 end;
    Talk("慕容公子的”好”意，在下心領了．在下對自己的武功還有一點自信，我寧愿光明正大的與喬大俠打斗，也不愿用卑鄙的方法去得到那本”天龍八部”．", 0, 1);
    Talk("你再考慮清楚．", 139, 0);
    exit();
::label0::
    Talk("好，我就和你上少林，揭發喬峰的秘密．", 0, 1);
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 139, 0);
        exit();
::label1::
        DarkScence();
        ModifyEvent(-2, -2, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Join(51);
        AddMorality(-4);
        ChangeMainMapMusic(3);
exit();
