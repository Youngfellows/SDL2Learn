Talk("如此甚好，下月十五五岳劍派合并大會，我們在嵩山派大鬧一番，以報定閑師太之仇", 175, 0);
if AskJoin () == true then goto label0 end;
    exit();
::label0::
    Talk("掌門人既如此謙光，自當從命。", 0, 4);
    if InTeam(35) == true then goto label1 end;
        Talk("完全聽屬掌門師兄吩咐。", 175, 0);
        exit();
::label1::
        Talk("小尼姑，要跟我一起走嗎?", 35, 5);
        if TeamIsFull() == false then goto label2 end;
            Talk("你的隊伍已滿，我無法加入．", 175, 0);
            exit();
::label2::
            Talk("不過大家須得答應我一件事，我只做你們的掌門師兄，卻不做掌門師叔。", 175, 0);
            DarkScence();
            ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
            LightScence();
            Join(41);
exit();
