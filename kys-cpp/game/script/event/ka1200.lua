Talk("龍王，為啥你還帶著面具。", 0, 0);
if AskJoin () == true then goto label0 end;
    Talk("波斯總壇不再追殺你了，你又長的那麼正，干麻還戴著老太婆面具。", 0, 0);
    exit();
::label0::
    if InTeam(35) == true then goto label1 end;
        Talk("波斯總壇不再追殺你了，你又長的那麼正，干麻還戴著老太婆面具。", 0, 0);
        exit();
::label1::
        Talk("戴了幾十年，不戴感覺怪怪的。", 35, 0);
        if TeamIsFull() == false then goto label2 end;
            Talk("你的隊伍已滿，我無法加入．", 153, 0);
            exit();
::label2::
            Talk("任小姐，如今你父親已經奪回教主之位，你已無事一身輕，要隨我闖蕩江湖嗎?", 153, 0);
            DarkScence();
            ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
            LightScence();
            Join(30);
            exit();
exit();
