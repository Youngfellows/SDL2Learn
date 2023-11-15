Talk("哇塞！這人怎麼這麼丑，全身腫的像豬八戒一樣，何太沖怎麼喜歡這種貨色？莫非他有”戀豬癥”？", 0, 1);
if InTeam(9) == true then goto label0 end;
exit();
::label0::
    if HaveItemBool(158) == true then goto label1 end;
exit();
::label1::
        Talk("大哥，好像不對。", 9, 0);
        Talk("怎么了，張兄弟？", 0, 1);
        Talk("這女子不是得了怪病，而是中了“金銀血蛇”之毒。", 9, 0);
        Talk("蛇毒？那好，就用這硫磺煙火把它們逼出來。……啊，出來了，大家小心！", 0, 1);
        if TryBattle(60) == true then goto label2 end;
            Dead();
            exit();
::label2::
            LightScence();
            Talk("我還記得王前輩跟我提過，這金銀血蛇性喜食毒，而這里房前屋后種了幾株“靈脂蘭”，正是劇毒之物。", 9, 0);
            Talk("原來如此，兄弟我真是大開眼界。", 0, 1);
            AddItemWithoutHint(158, -1);
            SetRoleUsePoison(9, 100);
            SetRoleUsePoison(0, 50);
exit();
