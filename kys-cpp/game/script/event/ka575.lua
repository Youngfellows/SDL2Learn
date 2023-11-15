Talk("客倌想住宿嗎？本店有上好客房供應．一間２０兩．", 105, 0);
if AskRest() == true then goto  label0 end;
    exit();
::label0::
    if CheckEnoughMoney(20) == true then goto label1 end;
        Talk("走，走，走，沒錢就不要妨礙我做生意！", 105, 0);
        exit();
::label1::
        Talk("荒野之地多兇險，龍門地界只怕兵禍臨頭不遠．", 0, 1);
        DarkScence();
        Rest();
        AddItemWithoutHint(174, -20);
        OldSetScencePosition(14, 14);
        SetTowards(3);
        LightScence();
exit();
