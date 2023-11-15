Talk("這里悶死了，大哥哥快帶我出去玩．", 133, 0);
if AskJoin () == true then goto label0 end;
    Talk("辟邪劍法．．．天下無敵．．．辟邪劍法．．．天下無敵．．．哈哈哈。", 0, 1);
    exit();
::label0::
    Talk("少了小郭襄，一路上無聊的要死", 0, 1);
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 133, 0);
        exit();
::label1::
        Talk("快走吧．", 133, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Join(95);
exit();
