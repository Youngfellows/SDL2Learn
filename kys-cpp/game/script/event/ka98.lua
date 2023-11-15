Talk("老婆婆，這島很美，您一個人住著嗎？", 0, 1);
Talk("小子，來我島上尋晦氣的嗎？", 15, 0);
Talk("沒的事，我只是四處旅游，無意間來到這島上的．", 0, 1);
Talk("說實話，你是那一派的弟子？到這島上來做什麼？", 15, 0);
Talk("我無門無派，無師自通，自己四處”練練功”罷了．", 0, 1);
Talk("自已四處練練？那好，我老太婆就來陪你玩玩．", 15, 0);
if AskBattle() == true then goto label0 end;
    ModifyEvent(-2, -2, -2, -2, 99, -1, -1, -2, -2, -2, -2, -2, -2);
    exit();
::label0::
    Talk("好啊！閑來無事，就跟您老人家練練功增加些經驗點數吧．", 0, 1);
    if TryBattle(14) == false then goto label1 end;
        ModifyEvent(-2, -2, -2, -2, 100, -1, -1, -2, -2, -2, -2, -2, -2);
        SetSubMapLayerData(-2, 1, 21, 17, 0);
        LightScence();
        Talk("好小子，有你的．真是長江後浪推前浪．", 15, 0);
        Talk("前輩老當益壯啊!", 0, 1);
        AddFame(3);
        exit();
::label1::
        ModifyEvent(-2, -2, -2, -2, 99, -1, -1, -2, -2, -2, -2, -2, -2);
        LightScence();
        Talk("看你資質挺好的，老婆婆我不想殺你。", 15, 0);
exit();
