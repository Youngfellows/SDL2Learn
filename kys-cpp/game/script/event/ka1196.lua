Talk("芷若，記得師父交代的話和你發的毒誓，從今天起，你就是峨嵋派第四代掌門 。魔教的淫徒，你若玷污了我愛徒清白，我做鬼也不饒過……", 0, 0);
if AskJoin () == true then goto label0 end;
    exit();
::label0::
    if InTeam(9) == true then goto label1 end;
        Talk("師父，師父！", 122, 0);
        exit();
::label1::
        Talk("干你娘，死的好。", 9, 0);
        if TeamIsFull() == false then goto label2 end;
            Talk("你的隊伍已滿，我無法加入．", 122, 0);
            exit();
::label2::
            Talk("教主神功無敵 救六大派的一定手到擒來 等下教主和我對打的話請裝做不認識我。", 122, 0);
            DarkScence();
            ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
            ModifyEvent(-2, 25, -2, -2, 1040, -2, -2, -2, -2, -2, -2, -2, -2);
            ModifyEvent(33, 0, 0, -2, -1, -1, 1197, -2, -2, -2, -2, -2, -2);
            ModifyEvent(33, 1, 0, -2, -1, -1, 1197, -2, -2, -2, -2, -2, -2);
            LightScence();
            Join(28);
exit();
