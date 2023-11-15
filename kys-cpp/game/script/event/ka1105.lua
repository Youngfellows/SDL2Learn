Talk("郭兄弟還好嗎?", 0, 0);
Talk("我還好，蓉兒呢?他還好嗎．．．", 55, 0);
if AskJoin () == true then goto label0 end;
    Talk("雖然你是我的朋友，但還是要體醒你，蓉兒是你叫的嗎?金刀駙馬．", 0, 0);
    exit();
::label0::
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 55, 0);
        exit();
::label1::
        Talk("蓉兒還好，沒有金刀駙馬幫助，諸事不順啊．", 0, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Join(55);
exit();
