Talk("公子近來可好？", 109, 0);
if AskJoin () == true then goto label0 end;
    Talk("一切還好，謝謝王姑娘的關心．", 0, 1);
    exit();
::label0::
    Talk("說來慚愧，在下此次來是想麻煩王姑娘出馬幫忙的．", 0, 1);
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 109, 0);
        exit();
::label1::
        Talk("小女子愿盡綿薄之力．", 109, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Join(76);
        AddMorality(2);
exit();
