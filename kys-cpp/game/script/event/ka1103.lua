Talk("蓉兒，我看你了．", 0, 0);
Talk("大哥，找書的事情還順利嗎?", 137, 0);
Talk("還好．", 0, 0);
if AskJoin () == true then goto label0 end;
    Talk("蓉兒在桃花島好無聊，帶蓉兒去闖蕩江湖好不好．", 137, 0);
    exit();
::label0::
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 137, 0);
        exit();
::label1::
        Talk("少了蓉兒的機智，闖蕩江湖多了很多兇險．", 0, 0);
        DarkScence();
        ModifyEvent(-2, 5, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Join(56);
exit();
