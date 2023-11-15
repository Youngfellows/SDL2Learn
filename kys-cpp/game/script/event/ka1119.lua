Talk("哈哈，那個鄭公子有湯喝了。", 0, 0);
if AskJoin () == true then goto label0 end;
    exit();
::label0::
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 186, 0);
        exit();
::label1::
        Talk("雙兒姑娘，我們就跟小寶走吧!", 186, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Join(74);
exit();
