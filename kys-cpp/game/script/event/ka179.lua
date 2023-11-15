Talk("天門老道，近來可好？", 0, 1);
Talk("哼！你來做什麼．是不是岳不群派你來的，顯顯他五岳派掌門的威風．", 23, 0);
if AskBattle() == true then goto label0 end;
    exit();
::label0::
    Talk("聽你的口氣似乎很不服氣，我們就再來玩玩．", 0, 1);
    if TryBattle(40) == true then goto label1 end;
        Dead();
        exit();
::label1::
        LightScence();
        AddMorality(-1);
exit();
