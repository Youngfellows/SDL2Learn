Talk("少俠別來無恙，旅程一切還好吧．", 118, 0);
Talk("一切還好．", 0, 1);
if AskJoin () == true then goto label0 end;
    exit();
::label0::
    Talk("不知楊兄是否有意與我為伴云游各地，一覽這五岳三川的風貌．", 0, 1);
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 118, 0);
        exit();
::label1::
        Talk("好啊！或許旅途中會有龍兒的下落也說不定．對了鵰兄好像一直想到我到劍塚看看，先去劍塚看看後後再離開吧．", 118, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Join(58);
        AddMorality(3);
exit();
