if InTeam(35) == false then goto label0 end;
    Talk("小尼姑，你們的令狐掌門有意把你當作掌門接班人，多跟我到江湖去游歷吧!", 35, 5);
    Talk("恒山派掌門令狐沖，前來拜見左師伯．", 55, 0);
    Talk("恒山掌門令狐沖，前來拜見左師伯", 35, 5);
    Talk("恒山掌門令狐沖，前來拜見左師伯．", 55, 0);
    Talk("我瞧瞧，這不是統領數百尼姑，享盡艷福的令狐師弟嗎?怎麼?今天并派大會也想參加啊．", 0, 1);
    if TryBattle(29) == true then goto label1 end;
        Dead();
        exit();
::label1::
        LightScence();
        Talk("大會快開始了，請師兄讓路．", 0, 1);
        ModifyEvent(-2, 1, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 2, -2, -2, 205, -1, -1, -2, -2, -2, -2, -2, -2);
        ModifyEvent(-2, 3, -2, -2, 205, -1, -1, -2, -2, -2, -2, -2, -2);
        exit();
::label0::
        Talk("今天嵩山頂上似乎很熱鬧？", 0, 1);
        Talk("又是你！今日是我五岳劍派并派的大日子．閑雜人等，還請離去．", 55, 0);
        Talk("這樣大的盛會，怎能少得了大爺我．快讓讓．", 0, 1);
        Talk("閣下再不離去，休怪我們不客氣了．", 14, 0);
        Talk("我正有此意．", 0, 1);
        if TryBattle(29) == true then goto label2 end;
            Dead();
            exit();
::label2::
            ModifyEvent(-2, 1, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
            ModifyEvent(-2, 2, -2, -2, 205, -1, -1, -2, -2, -2, -2, -2, -2);
            ModifyEvent(-2, 3, -2, -2, 205, -1, -1, -2, -2, -2, -2, -2, -2);
            LightScence();
            AddFame(2);
exit();
