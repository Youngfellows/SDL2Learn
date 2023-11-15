Talk("公子近來無恙？", 109, 0);
if AskJoin () == true then goto label0 end;
    Talk("托王姑娘的福，一切還好．", 0, 1);
    exit();
::label0::
    Talk("還好，不過若有王姑娘在隊　中指導我們攻擊與防御，我　們會更好．", 0, 1);
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 109, 0);
        exit();
::label1::
        if HaveItemBool(147) == true then goto label2 end;
            Talk("好吧，我加入你們．", 109, 0);
            DarkScence();
            ModifyEvent(-2, -2, 0, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2);
            LightScence();
            Join(76);
exit();
::label2::
            if HaveItemBool(88) == true then goto label3 end;
                Talk("好吧，我加入你們．", 109, 0);
                AddItem(88, 1);
                DarkScence();
                ModifyEvent(-2, -2, 0, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2);
                LightScence();
                Join(76);
exit();
::label3::
                Talk("好吧，我加入你們．", 109, 0);
                DarkScence();
                ModifyEvent(-2, -2, 0, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2);
                LightScence();
                Join(76);
exit();
