Talk("你能帶我去找義父嗎？", 9, 0);
if AskJoin () == true then goto label0 end;
    Talk("這恐怕不行，我還有許多要事在身，無法帶你去找他．", 0, 1);
    Talk("．．．．．", 9, 0);
    exit();
::label0::
    Talk("好啊，走．", 0, 1);
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 9, 0);
        exit();
::label1::
        Talk("大哥真的很感謝你．", 9, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2);
        LightScence();
        Join(9);
        AddMorality(2);
exit();
