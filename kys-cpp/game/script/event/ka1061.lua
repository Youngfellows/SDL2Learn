Talk("這麼久都不來看我，可想死人家了．這次來是不是來帶我走的．", 25, 0);
if AskJoin () == true then goto label0 end;
    Talk("沒有．我們只是炮友，順路進來看看你．", 0, 1);
    exit();
::label0::
    Talk("我這不是來了嗎．走吧．", 0, 1);
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 25, 0);
        exit();
::label1::
        Talk("真的，沒騙我．我原以為你也是個負心漢，看來是誤會你了．走吧．", 25, 0);
        Talk("偶是誰，這麼好的炮友哪里找!不是，我堂堂七尺男兒啟會不守信用", 0, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2);
        LightScence();
        Join(25);
exit();
