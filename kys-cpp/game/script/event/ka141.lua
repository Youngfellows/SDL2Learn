Talk("不知少俠光臨我三圣坳有何貴事？", 7, 0);
if AskBattle() == true then goto label0 end;
    Talk("我是來叮嚀你的，以後要跟明教和平相處哦！不要再互相殘殺了．", 0, 1);
    Talk("哼！", 7, 0);
    exit();
::label0::
    Talk("我想找你練練功，賺些經驗點數．", 0, 1);
    Talk("哼！那就來吧．", 7, 0);
    if TryBattle(19) == true then goto label1 end;
        Dead();
        exit();
::label1::
        LightScence();
        Talk("嗯，這經驗點數還真好賺．", 0, 1);
        AddMorality(-1);
exit();
