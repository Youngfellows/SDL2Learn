if InTeam(58) == true then goto label0 end;
    Talk("桃花影落飛神劍，碧海潮聲按玉蕭", 57, 0);
    Talk("<這詩句，加上此人的氣質， 是東邪黃藥師>", 0, 0);
    if InTeam(63) == true then goto label1 end;
        Talk("晚輩參見黃島主", 0, 0);
        Talk("滾!別煩我", 57, 0);
        Talk("<干你娘，罵屁啊，我還以為可以A到好的武功>", 0, 0);
        exit();
::label1::
        Talk("徒兒拜見師尊", 136, 0);
        Talk("很好狠好", 57, 0);
        Talk("<干，態度差真多>", 0, 0);
        if HaveItemBool(199) == true then goto label2 end;
            Talk("闖蕩江湖多兇險，這本掌法你拿去參詳吧", 57, 0);
            Talk("謝謝師父", 136, 0);
            OldLearnMagic(63, 83, 0);
            AddItem(199, 1);
            exit();
::label2::
            Talk("徒兒未能陪在師父身邊，師父是否可安好?", 136, 0);
            Talk("日子過的愜意，逍遙不已哈哈哈", 57, 0);
            Talk("<干，你在爽我在累>", 0, 0);
            exit();
::label0::
            Talk("黃前輩，許久不見，多虧前輩所傳玉蕭劍法跟彈指神通，晚輩才有今日成就", 118, 0);
            Talk("楊過小友，看來這些年來你武功大進啊", 57, 0);
            Talk("哈!黃前輩手養了嗎?", 118, 0);
            Talk("就讓我領教楊過小友的黯然消魂掌吧!", 57, 0);
            if TryBattle(185) == true then goto label3 end;
                LightScence();
                Talk("前輩果然厲害，想來得到那南海神尼所傳掌法", 118, 0);
                Talk("楊過小友掌法威猛，并不輸在下洛英神掌<南海神尼是誰?>", 57, 0);
                exit();
::label3::
                LightScence();
                Talk("楊過小友所創掌法，天下間可能只有降龍十八掌可以相比", 57, 0);
                Talk("黃前輩過獎了", 118, 0);
exit();
