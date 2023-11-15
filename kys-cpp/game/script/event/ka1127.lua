Talk("不了，沒有掌門的允許，我不能離開見性峰。", 175, 0);
if AskJoin () == true then goto label0 end;
    Talk("儀琳師妹，在這見性峰有啥意思，我掌門師兄一起闖蕩江湖吧!有我在沒有惡人動的了你。", 0, 5);
    exit();
::label0::
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 175, 0);
        exit();
::label1::
        Talk("小尼姑，你先回恒山見性峰 ，我會再去找你．", 0, 5);
        DarkScence();
        ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Join(41);
exit();
