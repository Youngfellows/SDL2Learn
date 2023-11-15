Talk("就在你這間店稍微休息一下吧．", 105, 1);
if AskRest() == true then goto  label0 end;
    Talk("去去去，別打擾老子玩女人．", 0, 5);
    exit();
::label0::
    if CheckEnoughMoney(100) == true then goto label1 end;
        Talk("我跟瓦醫師是好朋友，如果得性病可以去這個名片上的地址求醫。", 105, 0);
        exit();
::label1::
        Talk("這位公子好眼光，本院姑娘都是一流的．", 0, 0);
        DarkScence();
        Rest();
        AddItemWithoutHint(174, -100);
        OldSetScencePosition(8, 7);
        ModifyEvent(-2, 7, 1, -2, 953, -2, -2, 6086, 6086, 6086, -2, -2, -2);
        LightScence();
exit();
