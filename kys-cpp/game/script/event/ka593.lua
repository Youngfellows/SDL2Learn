if InTeam(76) == false then goto label0 end;
    Talk("大哥，讓我也加入你，好不好？", 138, 0);
    if AskJoin () == true then goto label1 end;
        Talk("沒關系，我還應付得來．暫且不勞你費心．", 0, 1);
        exit();
::label1::
        Talk("我就知道你想跟著王姑娘，兄弟我當然不會拆散你們．", 0, 1);
        if TeamIsFull() == false then goto label2 end;
            Talk("你的隊伍已滿，我無法加入．", 138, 0);
            exit();
::label2::
            DarkScence();
            ModifyEvent(-2, -2, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
            LightScence();
            Join(53);
            exit();
::label0::
            Talk("兄弟，你還真會享福．躲在洞中過著清幽的生活．那像我，還得在外東奔西走的．", 0, 1);
            Talk("大哥，近來一切可好吧？有沒有什麼我可以效勞的．", 138, 0);
            if AskJoin () == true then goto label3 end;
                Talk("沒什麼問題，我還應付得來．", 0, 1);
                exit();
::label3::
                Talk("不瞞兄弟，此次我就是特地來找兄弟幫忙的．只是怕擾了兄弟的清靜．", 0, 1);
                if TeamIsFull() == false then goto label4 end;
                    Talk("你的隊伍已滿，我無法加入．", 138, 0);
                    exit();
::label4::
                    Talk("那的話．兄弟能有今天，還不是靠大哥幫忙的嗎？今日大哥既然有難，兄弟我當然義不容辭的幫你了．", 138, 0);
                    DarkScence();
                    ModifyEvent(-2, -2, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
                    LightScence();
                    Join(53);
                    AddMorality(2);
exit();
