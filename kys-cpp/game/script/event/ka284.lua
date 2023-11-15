if InTeam(9) == true then goto label0 end;
    exit();
::label0::
    if InTeam(39) == true then goto label1 end;
        exit();
::label1::
        Talk("哼!原來你是天魔傳人，天魔傳人居然趕來挖我墳，受死吧!", 122, 0);
        Talk("天魔和我項羽乃是死敵，你既然為天魔傳人就別在肖想我的紫雷刀法跟雷刀了，這兩樣東西我收回．", 194, 1);
        LeaveTeam(39);
        Talk("媽的，賠了夫人又折兵，差點掛在這．", 9, 5);
        Talk("你這害死師父的女人，來到峨嵋難道還想全身而退嗎?", 0, 1);
        if InTeam(49) == false then goto label2 end;
            Talk("無忌哥哥救我．", 49, 5);
::label2::
            ModifyEvent(-2, 0, 0, -2, -1, -1, 599, -2, -2, -2, -2, -2, -2);
            ModifyEvent(-2, 1, 0, -2, -1, -1, 599, -2, -2, -2, -2, -2, -2);
            ModifyEvent(-2, 21, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
exit();
