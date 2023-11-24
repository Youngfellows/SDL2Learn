if isUsingItem(183) == true then goto label0 end;
    exit();
::label0::
    AddMorality(-15);
    AddItemWithoutHint(183, -1);
    Talk("喬峰，你看這是什麼？", 0, 1);
    Talk("是什麼？", 50, 0);
    Talk("你看了便知道．", 0, 1);
    DarkScence();
    PlayMusic(9);
    LightScence();
    Talk("這．．這是真的嗎？", 50, 0);
    Talk("少林方丈親筆寫的，會是假的嗎！", 0, 1);
    Talk("我．．我．．我不是漢人．．．．我是契丹人．．．．", 50, 0);
    Talk("喬峰，你是契丹人，非我漢族人士，怎可擔任這丐幫幫主一職，保管”天龍八部”一書呢！", 0, 1);
    Talk("你要我怎麼做！", 50, 0);
    Talk("辭去丐幫幫主之位，交出”天龍八部”一書．", 0, 1);
    Talk("好！我今天就辭去這丐幫幫主之位。關于我的身世我自然會去查明，但這之前喬某要先殺了你這惡賊。", 50, 0);
    Talk("什么？", 0, 1);
    Talk("如果我是漢人，你今日如此羞辱冤枉，喬某自要殺你報仇；若我真是契丹人，你我遼漢不兩立，我殺你有何不妥？", 50, 0);
    if TryBattle(83) == true then goto label1 end;
        Dead();
        exit();
::label1::
        DarkScence();
        ModifyEvent(-2, -2, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        AddItem(147, 1);
        Talk("“北喬峰”果然厲害！", 0, 1);
        Talk("閣下來此，揭發喬峰的真實身份，讓我丐幫不致誤奉一契丹人為幫主，很是感激．", 93, 0);
        Talk("沒什麼，這是中原武林的大事，小弟應該做的．", 0, 1);
        Talk("但是，拜你所賜，我丐幫也將因此事貽笑武林．你拿的”天龍八部”是丐幫鎮幫之寶，還請閣下留下．", 93, 0);
        Talk("怎麼可以，我好不容易才拿到手的．", 0, 1);
        Talk("那只好得罪了．", 93, 0);
        if TryBattle(84) == true then goto label2 end;
            Dead();
            exit();
::label2::
            LightScence();
            ModifyEvent(28, 12, -2, -2, 578, -1, -1, -2, -2, -2, -2, -2, -2);
            ModifyEvent(-2, 2, -2, -2, 532, -1, -1, -2, -2, -2, -2, -2, -2);
            ModifyEvent(-2, 3, -2, -2, 532, -1, -1, -2, -2, -2, -2, -2, -2);
            ModifyEvent(-2, 4, -2, -2, 532, -1, -1, -2, -2, -2, -2, -2, -2);
            ModifyEvent(-2, 6, -2, -2, 532, -1, -1, -2, -2, -2, -2, -2, -2);
            ModifyEvent(-2, 7, -2, -2, 532, -1, -1, -2, -2, -2, -2, -2, -2);
            ModifyEvent(-2, 8, -2, -2, 532, -1, -1, -2, -2, -2, -2, -2, -2);
            ModifyEvent(-2, 9, -2, -2, 532, -1, -1, -2, -2, -2, -2, -2, -2);
            ModifyEvent(-2, 10, -2, -2, 532, -1, -1, -2, -2, -2, -2, -2, -2);
            ModifyEvent(-2, 11, -2, -2, 532, -1, -1, -2, -2, -2, -2, -2, -2);
            ModifyEvent(-2, 12, -2, -2, 532, -1, -1, -2, -2, -2, -2, -2, -2);
            ModifyEvent(-2, 13, -2, -2, 532, -1, -1, -2, -2, -2, -2, -2, -2);
            ModifyEvent(-2, 15, -2, -2, 532, -1, -1, -2, -2, -2, -2, -2, -2);
            ModifyEvent(-2, 16, -2, -2, 532, -1, -1, -2, -2, -2, -2, -2, -2);
            ModifyEvent(-2, 17, -2, -2, 532, -1, -1, -2, -2, -2, -2, -2, -2);
            ModifyEvent(-2, 18, -2, -2, 532, -1, -1, -2, -2, -2, -2, -2, -2);
            ModifyEvent(-2, 19, -2, -2, 532, -1, -1, -2, -2, -2, -2, -2, -2);
            if InTeam(51) == true then goto label3 end;
                AddFame(5);
exit();
::label3::
                Talk("哈哈，現在喬峰已去，我便少了一個心腹大患，這本秘笈就當我給你的謝禮。", 139, 0);
                AddItem(74, 1);
                AddFame(5);
exit();