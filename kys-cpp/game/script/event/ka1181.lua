if InTeam(9) == false then goto label0 end;
    if HaveItemBool(92) == true then goto label1 end;
        Talk("連公子也練不會，倒要瞧瞧是怎樣的難法。", 0, 0);
        exit();
::label1::
        Talk("好了，要看時間多的是，我們快離開這吧!", 9, 0);
        DarkScence();
        ModifyEvent(-2, 2, 1, 1, -1, -1, -1, 7746, 7746, 7746, -2, -2, -2);
        ModifyEvent(-2, 3, 0, 0, -1, -1, -1, 7804, 7804, 7804, -2, -2, -2);
        ModifyEvent(-2, 4, 1, 1, -1, -1, -1, 7862, 7862, 7862, -2, -2, -2);
        ModifyEvent(-2, 6, 1, -2, 1214, -1, -1, -2, -2, -2, -2, -2, -2);
        LightScence();
        exit();
::label0::
        if HaveItemBool(92) == true then goto label2 end;
            Talk("連公子也練不會，倒要瞧瞧是怎樣的難法。", 0, 0);
            exit();
::label2::
            Talk("我今日練成乾坤大挪移第七層心法，雖有一十九句跳過，未免略有缺陷，但正如你曲中所說：『日盈昃，月滿虧蝕。天地尚無完體。』我何可人心不足，貪多務得？想我有何福澤功德，該受這明教的神功心法？能留下一十九句練之不成，那才是道理啊。", 0, 0);
            BreakStoneGate();
            ModifyEvent(-2, 2, 1, 1, -1, -1, -1, 7746, 7746, 7746, -2, -2, -2);
            ModifyEvent(-2, 3, 0, 0, -1, -1, -1, 7804, 7804, 7804, -2, -2, -2);
            ModifyEvent(-2, 4, 1, 1, -1, -1, -1, 7862, 7862, 7862, -2, -2, -2);
            ModifyEvent(-2, 6, 1, -2, 1214, -1, -1, -2, -2, -2, -2, -2, -2);
exit();
