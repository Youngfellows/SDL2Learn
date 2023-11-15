Talk("清哥，那個叫石破天的跟玉兒好像，你看會不會是．．．", 0, 0);
if AskJoin () == true then goto label0 end;
    exit();
::label0::
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 181, 0);
        exit();
::label1::
        Talk("我知道你想說直兒，但直兒出生不久後便被梅孤芳抱走，并將屍體掛在我門莊前．．．咱還是快下山找玉兒，以免他闖出更大的禍", 181, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Join(52);
exit();
