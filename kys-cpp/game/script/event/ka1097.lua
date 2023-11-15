Talk("公子近來無恙？", 136, 0);
if AskJoin () == true then goto label0 end;
    Talk("托程姑娘的福，一切還好．", 0, 1);
    exit();
::label0::
    Talk("還好，不過有程姑娘在隊中會更好．", 0, 1);
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 136, 0);
        exit();
::label1::
        Talk("好吧，我就再陪你走一遭．", 136, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2);
        LightScence();
        Join(63);
exit();
