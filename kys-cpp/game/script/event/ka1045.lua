if InTeam(58) == true then goto label0 end;
    Talk("．．．．．．", 136, 0);
    exit();
::label0::
    Talk("姑娘沒事吧!那李莫愁從不講理，我也有吃過他的虧．", 0, 0);
    if AskJoin () == true then goto label1 end;
        Talk("程英謝公子關心．", 136, 0);
        exit();
::label1::
        if TeamIsFull() == false then goto label2 end;
            Talk("你的隊伍已滿，我無法加入．", 136, 0);
            exit();
::label2::
            Talk("二妹，看來那李莫愁不會善罷甘休，就暫時跟大哥一起走吧!", 118, 0);
            DarkScence();
            ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
            LightScence();
            Join(63);
exit();
