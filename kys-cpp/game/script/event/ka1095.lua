Talk("你終於來了．快走吧，我們強暴武林美女的計劃還沒完成呢．", 61, 0);
if AskJoin () == true then goto label0 end;
    Talk("嗯! 對不起，臨時想到有事情，我先走一步，這事下次再說．", 0, 1);
    exit();
::label0::
    Talk("是啊，少了歐陽兄，這大事就辦不成了．", 0, 1);
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 61, 0);
        exit();
::label1::
        Talk("走吧．", 61, 0);
        DarkScence();
        ModifyEvent(-2, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2);
        ModifyEvent(-2, 1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2);
        LightScence();
        Join(61);
exit();
