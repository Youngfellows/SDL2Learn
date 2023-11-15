Talk("小兄弟想要與老朽切磋武學的奧妙嗎？", 5, 0);
if AskBattle() == true then goto label0 end;
    exit();
::label0::
    Talk("還望前輩指導．", 0, 1);
    if TryBattle(22) == false then goto label1 end;
        LightScence();
        Talk("少俠武功已到如此境界，老朽也沒什麼好教你的了．", 5, 0);
        ModifyEvent(-2, -2, -2, -2, 158, -1, -1, -2, -2, -2, -2, -2, -2);
        AddFame(20);
        exit();
::label1::
        LightScence();
        if CheckRoleMorality(0, 50, 100) == true then goto label2 end;
            Talk("小兄弟，看來你還需再下一番努力才是．", 5, 0);
            exit();
::label2::
            if CheckRoleAttack(0, 0, 100) == true then goto label3 end;
                Talk("小兄弟，看來你還需再下一番努力才是．", 5, 0);
                exit();
::label3::
                Talk("小兄弟資質不錯，這是我的內功的心法，你拿去好好參詳吧．", 5, 0);
                Talk("謝謝前輩．", 0, 1);
                AddItem(185, 1);
                ModifyEvent(-2, -2, -2, -2, 156, -1, -1, -2, -2, -2, -2, -2, -2);
exit();
