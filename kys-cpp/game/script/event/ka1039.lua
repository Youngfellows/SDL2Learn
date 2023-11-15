if InTeam(58) == false then goto label0 end;
    Talk("可惜，老子的興趣就是愛管閑事", 118, 0);
    Talk("對，你知道他的下落嗎?", 133, 0);
    if AskJoin () == true then goto label1 end;
        Talk("不了，我還是在這里等他<有了金輪法王的前車之監，我還是別認相信人好了>", 0, 0);
        exit();
::label1::
        if TeamIsFull() == true then goto label2 end;
            Talk("楊過我當然認識，要不要我帶你一起去找他?", 0, 0);
            DarkScence();
            ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
            LightScence();
            Join(95);
            exit();
::label2::
            Talk("你的隊伍已滿，我無法加入．", 133, 0);
            exit();
::label0::
            Talk("兄弟莫怕，我也帶來幾個人來相助", 0, 0);
            Talk("就這點水平?快去練練，我的女婿功夫豈能如此差勁", 133, 0);
            Talk("很好，有如此武功才不會讓我丟臉", 0, 0);
            Talk("干，你都不教我功夫當然打不過你", 133, 0);
            Talk("我為了找我的大哥哥四處云游，對了!你認識他嗎?他很容易認的...獨臂，鬢角泛白，背後背著又黑又重的巨劍，有時旁邊會跟著一之大鵰", 0, 0);
            if AskJoin () == true then goto label3 end;
                Talk("你說的人應該就是神鵰大俠楊過吧!", 133, 0);
                exit();
::label3::
                Talk("你說的人應該就是神鵰大俠楊過吧!", 133, 0);
exit();
