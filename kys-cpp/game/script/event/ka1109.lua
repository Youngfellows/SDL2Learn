Talk("你這害死師父的惡人，休想要我幫你。", 122, 0);
if AskJoin () == true then goto label0 end;
    Talk("周姑娘，既然你師父將掌門傳給你，我就送你到武當吧。", 0, 0);
    exit();
::label0::
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 122, 0);
        exit();
::label1::
        Talk("周姑娘，你先到我家等我，我會在去找你。", 0, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Join(28);
exit();
