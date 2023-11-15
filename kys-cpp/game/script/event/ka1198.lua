if InTeam(37) == true then goto label0 end;
    Talk("交你媽，這麼想性交我找一只豬來干你。", 0, 0);
    Talk("周姑娘，看來你今天當不上掌門，還是先下山從長計議吧。", 154, 0);
    exit();
::label0::
    Talk("周師妹你勾結魔教妖人，欲奪掌門之位，我們峨嵋派啟會就范，要殺要剮隨你。", 154, 0);
    Talk("交你媽，這麼想性交我找一只豬來干你。", 37, 0);
    Talk("水笙姑娘，你怎麼還在這雪山，你不是回去找你爹跟表哥了嗎?", 154, 0);
    Talk("嗚嗚~~~", 37, 0);
    Talk("狄大哥，我就知道你一定會回來這里。", 0, 0);
    Talk("．．．．．．", 37, 0);
    if AskJoin () == true then goto label1 end;
        exit();
::label1::
        Talk("我回家後，他們都說要殺了你，我替你澄清你是個君子，不是淫賊，他們卻說．．．嗚嗚嗚。", 0, 0);
        if TeamIsFull() == false then goto label2 end;
            Talk("你的隊伍已滿，我無法加入．", 154, 0);
            exit();
::label2::
            Talk("．．．．．．", 154, 0);
            DarkScence();
            ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
            LightScence();
            Join(17);
exit();
