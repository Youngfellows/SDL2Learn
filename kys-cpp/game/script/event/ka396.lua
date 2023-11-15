if isUsingItem(134) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(134, -1);
    AddMorality(4);
    Talk("楊兄，你快將這服下．", 0, 1);
    Talk("這是什麼？", 118, 0);
    Talk("這是生長在情花叢旁的斷腸草．", 0, 1);
    Talk("好，我便服這斷腸草試試，倘若無效，十六年後，請少俠告知我那苦命的妻子罷！", 118, 0);
    Talk("．．．啊．．．", 118, 0);
    Talk("楊兄怎麼了？", 0, 1);
    Talk("．．．．．", 118, 0);
    DarkScence();
    ModifyEvent(-2, -2, -2, -2, 397, -1, -1, 6186, 6186, 6186, -2, -2, -2);
    LightScence();
    Talk("我楊某這條命是少俠你救回來的．", 118, 0);
    Talk("你身上的毒質當真都解了？還好還好，我剛真捏了把冷汗．", 0, 1);
    Talk("這次真謝謝少俠的幫忙，讓楊某從鬼門關回來．", 118, 0);
    Talk("不知楊兄今後有何打算？", 0, 1);
    Talk("我也不知道，但總是要保持著健康，待十六年後與我妻子相見．對了，我這里有瓶玉蜂漿，就送給兄臺好了．", 118, 0);
    AddItem(124, 1);
    if AskJoin () == true then goto label1 end;
        Talk("那楊兄就好好休養吧，過些時候我再來看你．", 0, 1);
        exit();
::label1::
        Talk("不知楊兄是否有意與我為伴云游各地，一覽這五岳三川的風貌．", 0, 1);
        if TeamIsFull() == false then goto label2 end;
            Talk("你的隊伍已滿，我無法加入．", 118, 0);
            exit();
::label2::
            Talk("好啊！或許旅途中會有龍兒的下落也說不定．對了鵰兄好像一直想到我到劍塚看看，先去劍塚看看後後再離開吧．", 118, 0);
            DarkScence();
            ModifyEvent(-2, -2, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
            LightScence();
            Join(58);
            AddMorality(3);
exit();
