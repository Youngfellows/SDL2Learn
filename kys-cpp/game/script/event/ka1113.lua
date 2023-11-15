Talk("芷若，芷若!", 157, 0);
if AskJoin () == true then goto label0 end;
    Talk("歐陽兄，你還是呆在你的白駝山莊玩女人，少來惹我。", 0, 0);
    exit();
::label0::
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 157, 0);
        exit();
::label1::
        Talk("陸姑娘，你就先回我家休息，有需要你的幫忙我會去找你。", 0, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Join(16);
exit();
