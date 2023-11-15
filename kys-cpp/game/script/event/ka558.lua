if InTeam(50) == true then goto label0 end;
    Talk("你還在這做什麼．", 130, 0);
    Talk("我看阿紫姑娘聰明伶利，又會毒術，所以想請阿紫姑娘加入我．", 0, 1);
    Talk("不要．我要等我姐夫．", 130, 0);
    exit();
::label0::
    Talk("阿紫，不要再胡鬧了，你離家出走，鬧的是人仰馬翻，你姊姊阿朱臨終前托我要好好照顧你，快跟我回家．", 50, 0);
    Talk("我就知道姐夫你一定會擔心我，嘻嘻．", 130, 0);
    if AskJoin () == true then goto label1 end;
        exit();
::label1::
        if TeamIsFull() == false then goto label2 end;
            Talk("你的隊伍已滿，我無法加入．", 130, 0);
            exit();
::label2::
            DarkScence();
            ModifyEvent(-2, 3, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
            ModifyEvent(-2, 4, -2, -2, 562, -1, -1, -2, -2, -2, -2, -2, -2);
            LightScence();
            Join(47);
            AddMorality(-2);
            Talk("阿紫姑娘，你別丟下我一個人．求求少俠讓我加入，好讓我跟在阿紫姑娘身旁服侍她．", 48, 0);
            if AskJoin () == true then goto label3 end;
                exit();
::label3::
                if TeamIsFull() == false then goto label4 end;
                    Talk("你的隊伍已滿，我無法加入．", 48, 0);
                    exit();
::label4::
                    Talk("你怎麼讓這個臭鐵頭也跟過來．", 130, 0);
                    Talk("這個鐵頭武功還不錯，可以當個打手．", 0, 0);
                    DarkScence();
                    ModifyEvent(-2, 4, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
                    LightScence();
                    Join(48);
                    AddMorality(-2);
exit();
