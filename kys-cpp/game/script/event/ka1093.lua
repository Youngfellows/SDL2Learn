Talk("公子近來無恙？", 121, 0);
if AskJoin () == true then goto label0 end;
    Talk("托龍姑娘的福，一切還好．", 0, 1);
    exit();
::label0::
    Talk("還好，不過是否能再請龍姑娘出馬幫忙呢？", 0, 1);
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 121, 0);
        exit();
::label1::
        Talk("好的．", 121, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2);
        LightScence();
        Join(59);
exit();
