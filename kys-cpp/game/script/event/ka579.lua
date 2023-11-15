Talk("阿朱！阿朱！是你們害死阿朱，你們都的死!", 0, 0);
Talk("別攻擊我，我是自己人啊!靠，蕭峰殺紅眼了!", 50, 0);
Talk("蕭峰帶著阿朱的屍體跑了，干!怎麼除了我其他人都掛了", 0, 0);
Talk("喬幫主，上次聚賢莊一役你就消失了，你怎麼會出現在我家．", 50, 0);
if AskJoin () == true then goto label0 end;
    Talk("我早就已經不是啥幫主，別再叫我喬幫主，我來除了向少俠道歉，上次聚賢莊一戰我不分敵我的攻擊你，蕭峰厚顏，還希望少俠幫我一個忙．", 0, 0);
    exit();
::label0::
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 50, 0);
        exit();
::label1::
        Talk("我能幫當然就會幫你", 0, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Join(40);
exit();
