Talk("你在沖啥小，”老二”不會痛嗎？", 0, 1);
Talk("我有一本神功秘笈，為了練這門神功，痛也得忍．要知練完之後，我就是武林中”最硬最久”之人．", 29, 0);
Talk("去．我不用練就比你猛了．弱B", 0, 1);
Talk("嘿．本來我還想一起分享這們神功秘笈．看來是不用了．", 29, 0);
Talk("好啦，大爺．借看一下拉!", 0, 1);
Talk("不借，就是不想借", 29, 0);
ModifyEvent(-2, -2, -2, -2, 306, -1, -1, -2, -2, -2, -2, -2, -2);
if AskJoin () == false then goto label0 end;
    Talk("好，不妨咱倆一起在這世界中，好好的干他一炮．", 0, 1);
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 29, 0);
        exit();
::label1::
        Talk("我們就一起去游戲人間吧．美女我來了．", 29, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Join(29);
        AddMorality(-6);
        exit();
::label0::
        Talk("你自己玩好了，我自己OGC就夠了．", 0, 1);
        Talk("少裝了，難不成你想演”斷臂山”．", 29, 0);
        ModifyEvent(-2, -2, -2, -2, 306, -1, -1, -2, -2, -2, -2, -2, -2);
        AddFame(1);
exit();
