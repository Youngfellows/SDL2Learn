Talk("公子有什麼事嗎？", 109, 0);
if AskJoin () == true then goto label0 end;
    Talk("沒事，姑娘真是美麗．", 0, 1);
    exit();
::label0::
    Talk("聽說姑娘武學淵博，不知是否能於在下旅程中，給予一些指導．", 0, 1);
    if InTeam(51) == true then goto label1 end;
        Talk("我要留下來陪我表哥．", 109, 0);
        exit();
::label1::
        if TeamIsFull() == false then goto label2 end;
            Talk("你的隊伍已滿，我無法加入．", 109, 0);
            exit();
::label2::
            Talk("既然我表哥都加入了，我當然要伴著他．", 109, 0);
            DarkScence();
            ModifyEvent(-2, -2, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
            LightScence();
            Join(76);
            AddMorality(1);
exit();
