Talk("怎麼，你準備好了嗎？", 50, 0);
if AskBattle() == true then goto label0 end;
    Talk("嗯，還沒．", 0, 1);
    Talk("喬某隨時在此等候少俠．", 50, 0);
    exit();
::label0::
    Talk("在下特來領教喬大俠的”降龍十八掌”．", 0, 1);
    if TryBattle(83) == true then goto label1 end;
        LightScence();
        Talk("你還不行，再回去苦練吧．", 50, 0);
        exit();
::label1::
        LightScence();
        Talk("少俠經這多日來的修練，武功果然不凡，喬某拜服．”天龍八部”你就拿去吧．", 50, 0);
        Talk("那里，喬幫主承讓了．", 0, 1);
        AddItem(147, 1);
        ModifyEvent(-2, -2, -2, -2, 529, -1, -1, -2, -2, -2, -2, -2, -2);
        ModifyEvent(-2, 20, -2, -2, -1, -1, 530, -2, -2, -2, -2, -2, -2);
        ModifyEvent(-2, 21, -2, -2, -1, -1, 530, -2, -2, -2, -2, -2, -2);
        if HaveItemBool(183) == true then goto label2 end;
            exit();
::label2::
            ModifyEvent(28, 12, -2, -2, 518, -1, -1, -2, -2, -2, -2, -2, -2);
            AddMorality(12);
            AddFame(15);
exit();
