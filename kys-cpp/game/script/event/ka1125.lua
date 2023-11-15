Talk("敏妹!別走啊!我剛才只是要安撫芷若，敏妹!", 50, 0);
if AskJoin () == true then goto label0 end;
    Talk("哈哈哈，趙敏，就算我得不到無忌哥哥的愛，我也會讓你永生不能和無忌哥哥再一起。", 0, 5);
    exit();
::label0::
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 50, 0);
        exit();
::label1::
        Talk("蕭大俠，請你先回我家去，有需要幫忙我會去找你．", 0, 1);
        Talk("少俠別來無恙?", 50, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Join(40);
exit();
