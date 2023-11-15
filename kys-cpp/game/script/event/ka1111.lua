Talk("是啊，隨我們闖蕩武林笑傲江湖，是何等快意。", 153, 0);
if AskJoin () == true then goto label0 end;
    Talk("看在令狐大哥的份上，隨你一起走。", 0, 0);
    exit();
::label0::
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 153, 0);
        exit();
::label1::
        Talk("任大小姐，你先回黑木崖，有需要你的幫忙我會去找你。", 0, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Join(30);
exit();
