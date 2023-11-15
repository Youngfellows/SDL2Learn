Talk("客倌想住宿嗎？本店有上好客房供應．一間２００兩．", 105, 0);
Talk("奇怪，招牌上不是寫２０兩嗎？怎麼漲價了．", 0, 1);
Talk("你沒看這幾天有這麼多人來西域麼？你不要，別人還搶著要呢！", 105, 0);
if AskRest() == true then goto  label0 end;
    exit();
::label0::
    if CheckEnoughMoney(200) == true then goto label1 end;
        Talk("走，走，走，沒錢就不要妨礙我做生意！", 105, 0);
        Talk("干你媽的黑店，今天讓我姚天子來教訓你", 0, 0);
        Talk("保安!保安!", 105, 0);
        if TryBattle(180) == true then goto label2 end;
            Dead();
            exit();
::label2::
            LightScence();
            Talk("干，錢順便交出來", 0, 0);
            Talk("大爺請笑納", 105, 0);
            AddItem(174, 2000);
            exit();
::label1::
            Talk("荒野之地多兇險，龍門地界只怕兵禍臨頭不遠．", 0, 1);
            DarkScence();
            Rest();
            AddItemWithoutHint(174, -200);
            OldSetScencePosition(14, 14);
            SetTowards(3);
            LightScence();
exit();
