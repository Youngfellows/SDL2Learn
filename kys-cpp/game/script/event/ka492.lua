Talk("段兄，你在這過的還好吧？", 0, 1);
if InTeam(76) == true then goto label0 end;
    Talk("能天天在這陪著神仙姊姊，要我做牛做馬我都愿意．", 138, 0);
    exit();
::label0::
    Talk("兄弟，讓我加入你吧，我想跟王姑娘在一起．", 138, 0);
    if AskJoin () == true then goto label1 end;
        Talk("很抱歉，段兄．王姑娘的風采也挺令小弟著迷的．", 0, 1);
        Talk("你也喜歡王姑娘嗎?公平競爭吧!", 138, 0);
        exit();
::label1::
        Talk("段兄你真是個癡情種子，我們當然是一起走嘍！", 0, 1);
        if TeamIsFull() == false then goto label2 end;
            Talk("你的隊伍已滿，我無法加入．", 138, 0);
            exit();
::label2::
            DarkScence();
            ModifyEvent(-2, -2, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
            LightScence();
            Join(53);
exit();
