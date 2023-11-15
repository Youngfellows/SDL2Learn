Talk("大哥救我，這惡和尚把我抓住後，逼我抄寫劍譜，實在可惡．", 138, 0);
Talk("原來段兄弟被明王抓到這里，明王乃前輩高人，又是吐蕃國師，做出這種以大欺小的事情，傳出去不免貽笑江湖．", 0, 1);
Talk("小僧勸你別多管閑事，以免惹禍上身．", 140, 0);
if AskBattle() == true then goto label0 end;
    Talk("跑的還真快。", 0, 0);
    exit();
::label0::
    Talk("兄弟你好自為知吧<這和尚不好惹，算了>", 0, 0);
    if TryBattle(191) == true then goto label1 end;
        Dead();
        exit();
::label1::
        ModifyEvent(-2, 13, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        AddItem(200, 1);
        AddMorality(2);
        AddFame(2);
        Talk("劍法也罷，劍陣也罷，適才比刀論劍，是明王贏了，還是我們天龍寺贏了？", 0, 0);
        if AskJoin () == true then goto label2 end;
            ModifyEvent(-2, 0, -2, -2, 1087, -2, -2, -2, -2, -2, -2, -2, -2);
            ModifyEvent(-2, 8, -2, -2, 1087, -2, -2, -2, -2, -2, -2, -2, -2);
            exit();
::label2::
            Talk("聽說十四天書中的碧血劍在袁承志身上，自從十年前他隱居在一個叫渤泥島的地方，就沒有他的消息了．大海茫茫，要找到他還真的很困難．", 0, 1);
            if TeamIsFull() == false then goto label3 end;
                Talk("你的隊伍已滿，我無法加入．", 138, 0);
                ModifyEvent(-2, 0, -2, -2, 1087, -2, -2, -2, -2, -2, -2, -2, -2);
                ModifyEvent(-2, 8, -2, -2, 1087, -2, -2, -2, -2, -2, -2, -2, -2);
                exit();
::label3::
                Talk("好啊．", 138, 0);
                DarkScence();
                ModifyEvent(-2, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -2, -2);
                ModifyEvent(-2, 8, 0, 0, -1, -1, -1, -1, -1, -1, -1, -2, -2);
                LightScence();
                Join(53);
                AddItem(206, 1);
exit();
