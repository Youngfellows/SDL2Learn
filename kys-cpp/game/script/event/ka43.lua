if InTeam(58) == true then goto label0 end;
    exit();
::label0::
    if HaveItemBool(208) == false then goto label1 end;
        exit();
::label1::
        WalkFromTo(25, 18, 24, 13);
        DarkScence();
        OldSetScencePosition(22, 15);
        ModifyEvent(-2, 8, -2, -2, -2, -2, -2, 8338, 8338, 8338, -2, -2, -2);
        LightScence();
        Talk("楊兄好興致，為何突然想看海．", 0, 5);
        Talk("驚濤拍岸，所擁有勁道遠勝山洪，如在此修練，可能更有助益，就讓我對抗這巨浪，愈強則強，喝!", 118, 1);
        Talk("靠北，怎麼說跳海就跳海，楊兄，我可不會游泳啊，溺水好自為之．", 0, 5);
        Talk("霜華，這怎麼回事，你怎麼會死了呢?霜華!!!!!!", 118, 1);
        Talk("干，巨浪打過來了，楊兄小心．", 0, 5);
        Talk("來的好，今日我就將這些巨浪當作曾經傳我武功的前輩對我考驗，第一個來的是義父嗎?", 118, 1);
        Talk("兒子，讓為父考驗你武功的進境．", 60, 5);
        if TryBattle(225) == true then goto label2 end;
            ModifyEvent(-2, 6, 0, -2, -1, -1, -1, -2, -2, -2, -2, -2, -2);
            ModifyEvent(-2, 7, 0, -2, -1, -1, -1, -2, -2, -2, -2, -2, -2);
            ModifyEvent(-2, 8, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
            LightScence();
            Talk("巨浪海潮之威，果然非人力所能及．我會再來挑戰的．", 118, 1);
            exit();
::label2::
            LightScence();
            Talk("第二道巨浪，是洪七公洪前輩嗎?", 118, 1);
            Talk("小子小心，老叫化可不會像你義父一樣手下留情．", 69, 5);
            if TryBattle(226) == true then goto label3 end;
                ModifyEvent(-2, 6, 0, -2, -1, -1, -1, -2, -2, -2, -2, -2, -2);
                ModifyEvent(-2, 7, 0, -2, -1, -1, -1, -2, -2, -2, -2, -2, -2);
                ModifyEvent(-2, 8, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
                LightScence();
                Talk("巨浪海潮之威，果然非人力所能及．我會再來挑戰的．", 118, 1);
                exit();
::label3::
                LightScence();
                Talk("剩最後兩道巨浪，黃藥師跟老頑童．", 118, 1);
                Talk("楊過小友，你若不成擊退我跟老頑童，想匯集各派所長，離自創武功成為一代宗師的路還長的很．", 57, 5);
                if TryBattle(227) == true then goto label4 end;
                    ModifyEvent(-2, 6, 0, -2, -1, -1, -1, -2, -2, -2, -2, -2, -2);
                    ModifyEvent(-2, 7, 0, -2, -1, -1, -1, -2, -2, -2, -2, -2, -2);
                    ModifyEvent(-2, 8, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
                    LightScence();
                    Talk("巨浪海潮之威，果然非人力所能及．我會再來挑戰的．", 118, 1);
                    exit();
::label4::
                    LightScence();
                    Talk("過兒，我在絕情谷立了十六年之約，你不怪我嗎?", 121, 5);
                    Talk("龍兒!                  沒錯，我便用我思戀龍兒的心情來創出一套掌法，龍兒我來領教你的玉女素心劍．", 118, 1);
                    if TryBattle(228) == true then goto label5 end;
                        LightScence();
                        exit();
::label5::
                        SetRoleMagic(58, 0, 24, 900);
                        LightScence();
                        PlayAnimation(8, 8340, 8364);
                        Talk("黯然銷魂者，唯別而已矣，這套掌法就取名為黯然銷魂掌．", 118, 1);
                        AddItem(208, 1);
                        DarkScence();
                        ModifyEvent(-2, 8, 0, -2, -2, -2, -2, -1, -1, -1, -2, -2, -2);
                        LightScence();
                        Talk("恭喜楊兄創出這掌法，從這掌法可看出你真的對你的夫人很癡情，希望你能盡快找到她．", 0, 5);
                        Talk("謝謝你，兄弟，我和龍兒十六年之約的期限將近，我想我很快就能就到龍兒．", 118, 1);
exit();
