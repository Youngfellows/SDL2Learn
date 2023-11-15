if InTeam(9) == true then goto label0 end;
    Talk("．．．．．．", 194, 0);
    exit();
::label0::
    Talk("芷若，我對你一向敬重，對小昭是意存憐惜，但對趙姑娘卻是……卻是銘心刻骨的相愛。", 194, 1);
    if AskJoin () == true then goto label1 end;
        exit();
::label1::
        if TeamIsFull() == false then goto label2 end;
            Talk("．．．．．．", 194, 0);
            exit();
::label2::
            Talk("銘心刻骨的相愛，銘心刻骨的相愛。無忌哥哥，你的心上人就在隔壁房間，來人 將趙姑娘帶出來。", 9, 5);
            DarkScence();
            ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
            LightScence();
            Join(39);
exit();
