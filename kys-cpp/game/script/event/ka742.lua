Talk("阿曼!阿曼!", 0, 5);
Talk("干．狗命保住了還不快走．<趁成吉思汗還沒改變心意之前快走．>", 195, 0);
if AskJoin () == true then goto label0 end;
    Talk("事情我都聽蘇普說了，這高昌迷宮地圖你還是拿去吧!", 0, 5);
    exit();
::label0::
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 195, 0);
        exit();
::label1::
        Talk("看見蘇普的未婚妻跑了，你心理其實很高興吧!", 0, 5);
        Talk("你．．．你在胡說什麼．．．", 195, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Join(42);
exit();
