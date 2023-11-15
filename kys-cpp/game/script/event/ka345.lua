Talk("白姑娘美麗大方又聰明，要跟葛葛一起闖蕩江湖嗎？", 0, 0);
if AskJoin () == true then goto label0 end;
    exit();
::label0::
    if InTeam(38) == true then goto label1 end;
        Talk("你這個人比石中玉還難看惡心，我才不要．", 181, 1);
        Talk("．．．．．．", 0, 0);
        exit();
::label1::
        if TeamIsFull() == false then goto label2 end;
            Talk("你的隊伍已滿，我無法加入．", 181, 0);
            exit();
::label2::
            Talk("你這個人比石中玉還難看惡心，我才不要．", 181, 1);
            Talk("是啊，阿秀跟我一起走好嗎?我還要去找我媽跟小黃．", 124, 0);
            Talk("如果跟石公子在一起當然沒問題．", 181, 1);
            Talk("奇怪，我怎麼覺得我這個主角越來越被女性度濫了．", 0, 0);
            DarkScence();
            ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
            LightScence();
            Join(52);
            AddFame(3);
exit();
