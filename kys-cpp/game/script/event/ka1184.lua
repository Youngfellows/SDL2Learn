if InTeam(25) == false then goto label0 end;
    Talk("施主雖然闖過老僧這一關，謹記老僧之言，因果循環，報應不爽……唉，老僧能做的，也只有如此了。希望後好自為之。", 87, 0);
    ModifyEvent(-2, 5, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    ModifyEvent(-2, 6, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    exit();
::label0::
    Talk("干，不想教我就用搶的，就算你練成易筋經黑級浮屠，武功天下第一，還是敵不過我們龍虎群邪的群毆。", 87, 0);
    if AskBattle() == true then goto label1 end;
        Talk("上面寫著:華山絕頂。", 0, 5);
        exit();
::label1::
        Talk("這里乃五毒教的禁地，閑雜人等禁止進入。", 0, 5);
        if TryBattle(206) == true then goto label2 end;
            Dead();
            exit();
::label2::
            LightScence();
            ModifyEvent(-2, 5, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
            ModifyEvent(-2, 6, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
exit();
