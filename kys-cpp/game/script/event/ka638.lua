Talk("看到你的樣子，我的心也整個活躍了起來．", 54, 0);
if AskJoin () == true then goto label0 end;
    exit();
::label0::
    Talk("不如這樣，袁兄何不暫時離開這小島，和在下一起到江湖上闖闖，再顯當年威風．", 0, 1);
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 54, 0);
        exit();
::label1::
        Talk("好．離開武林這麼多年，也　不知變得怎麼樣了．袁某的功夫不知是否還管用．", 54, 0);
        Talk("我們走吧．", 0, 1);
        DarkScence();
        ModifyEvent(-2, -2, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Join(54);
        AddMorality(5);
exit();
