Talk("你又想做什麼？", 15, 0);
if AskBattle() == true then goto label0 end;
    exit();
::label0::
    Talk("晚輩斗膽向前輩討教討教．", 0, 1);
    Talk("好，我們來玩玩．", 15, 0);
    if TryBattle(14) == false then goto label1 end;
        ModifyEvent(-2, -2, -2, -2, 100, -1, -1, -2, -2, -2, -2, -2, -2);
        SetSubMapLayerData(-2, 1, 21, 17, 0);
        LightScence();
        Talk("好小子，有你的．真是長江後浪推前浪．", 15, 0);
        Talk("前輩老當益壯啊!", 0, 1);
        Talk("太師父，無忌好冷．", 15, 0);
        Talk("什麼!我很老嗎?", 0, 0);
        AddFame(3);
        exit();
::label1::
        LightScence();
        Talk("看你資質挺好的，老婆婆我不想殺你。", 15, 0);
exit();
