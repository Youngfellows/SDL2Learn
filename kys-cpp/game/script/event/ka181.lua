if InTeam(29) == true then goto label0 end;
    exit();
::label0::
    ModifyEvent(-2, 37, 0, -2, -2, -2, -2, 5298, 5298, 5298, -2, -2, -2);
    ModifyEvent(-2, 38, 0, -2, -2, -2, -2, 5196, 5196, 5196, -2, -2, -2);
    SubMapViewFromTo(29, 27, 29, 35);
    Talk("事情一切順利．", 18, 0);
    Talk("少了蕭大俠的降龍十八掌，簡直快混不下去了．", 175, 5);
    Talk("少俠需要蕭某幫忙，蕭某義不容辭．", 18, 0);
    Talk("．．．．．．", 175, 0);
    DarkScence();
    ModifyEvent(-2, 38, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    ModifyEvent(-2, 39, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    ModifyEvent(-2, 40, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    LightScence();
    Talk("他奶奶的，這田伯光色膽包天敢擄走我女兒，倒也算有眼光，可是你說的那令狐沖，可真是個不識貨的東西，我女兒貌美如花，見了居然還不動心。", 18, 0);
    Talk("爹，誰叫你在這亂胡說，你在胡說，我就不再見你．", 29, 0);
    if TryBattle(255) == true then goto label1 end;
::label1::
        LightScence();
        Talk("這華山令狐沖，正好圣姑下令要治好他的傷，我就把他擄來治傷，順便把你日思夜想的令狐大哥帶來跟你見面如何?", 29, 0);
        Talk("這女娃兒臉皮真薄，說說而已就跑了，話說回來要是讓我碰到田伯光的話，我一定讓他好看．", 18, 1);
        Talk("．．．．．．", 29, 0);
        Talk("大和尚不用費心了，田伯光就在這，想要教訓在下，就憑自己的本事吧．", 18, 1);
        Talk("士可殺不可辱，你給我吃的是啥毒藥?", 29, 0);
        DarkScence();
        ModifyEvent(57, 2, -2, -2, 198, -1, -1, -2, -2, -2, -2, -2, -2);
        ModifyEvent(57, 3, -2, -2, 198, -1, -1, -2, -2, -2, -2, -2, -2);
        ModifyEvent(57, 4, -2, -2, 198, -1, -1, -2, -2, -2, -2, -2, -2);
        ModifyEvent(57, 5, -2, -2, 198, -1, -1, -2, -2, -2, -2, -2, -2);
        ModifyEvent(57, 6, -2, -2, 198, -1, -1, -2, -2, -2, -2, -2, -2);
        ModifyEvent(-2, 37, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
exit();
