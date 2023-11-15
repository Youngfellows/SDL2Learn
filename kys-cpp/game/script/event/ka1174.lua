Talk("離開大漠這麼久了，我也該回去一趟看看義兄和大汗。", 0, 0);
if AskJoin () == true then goto label0 end;
    Talk("蓉兒．．．黃姑娘．．．要跟我一起走嗎?", 0, 0);
    exit();
::label0::
    if InTeam(55) == true then goto label1 end;
        Talk("算了，我不免強你", 137, 0);
        exit();
::label1::
        if TeamIsFull() == false then goto label2 end;
            Talk("你的隊伍已滿，我無法加入．", 137, 0);
            exit();
::label2::
            Talk("大哥，對不起，我要跟靖哥哥留在這．．．", 137, 0);
            DarkScence();
            LightScence();
            ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
            Join(56);
exit();
