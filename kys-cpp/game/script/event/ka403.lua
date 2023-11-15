Talk("公子再次拜訪，不知有何貴事？", 136, 0);
if AskJoin () == true then goto label0 end;
    Talk("在下途經貴府，順道進來看看程姑娘是否安好．", 0, 1);
    Talk("謝謝公子的關心．", 136, 0);
    exit();
::label0::
    Talk("那程姑娘可否與在下一游，幫忙在下尋找那十四天書？", 0, 1);
    if InTeam(58) == true then goto label1 end;
        Talk("對不起，我要等我大哥。", 136, 0);
        exit();
::label1::
        Talk("媽的，這小白臉居然跑到我家來嫖我老婆，他奶奶的，這綠帽子戴的可大了，看我用蒙汗藥迷昏你們，再搜括你身上的銀兩銀票。", 136, 0);
        Talk("小賊，想對我們家公子做什麼?", 118, 1);
        Talk("奇怪……公子怎麼暈了過去，怎麼連我馮錫范也感到昏昏沉沉，尋常的蒙汗藥怎麼可能迷的倒我……", 136, 0);
        Talk("奇怪，怎麼今天我的蒙汗藥這麼有效。", 118, 1);
        if TeamIsFull() == false then goto label2 end;
            Talk("你的隊伍已滿，我無法加入．", 136, 0);
            exit();
::label2::
            Talk("呵呵，小娃娃，要不是我幫你加點料，憑你的蒙汗藥怎麼可能迷倒像馮錫范這樣內力深厚的高手。", 136, 0);
            AddItem(46, 1);
            DarkScence();
            ModifyEvent(-2, -2, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
            LightScence();
            Join(63);
            AddMorality(2);
exit();
