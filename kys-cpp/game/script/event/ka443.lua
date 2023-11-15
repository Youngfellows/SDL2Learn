Talk("這有本書，書名是神．．．神鵰俠侶．找到了，我終於找到了．果然跟這對俠侶有些關系，這可能是她們古墓派前輩所留下來的．找這本書的過程中，都發生了一些與”情”字有關的故事，是巧合呢，還是天意？", 0, 1);
AddItem(153, 1);
Talk("誰？", 0, 0);
Talk("我，“赤練仙子”李莫愁。", 2, 1);
if InTeam(59) == true then goto label0 end;
    Talk("手下敗將，也敢囂張。", 0, 0);
    Talk("今天看我不要你的命！", 2, 1);
    Talk("別廢話了，上吧！", 129, 0);
    Talk("原來請了幫手。", 0, 1);
    if TryBattle(145) == true then goto label1 end;
        Dead();
        exit();
::label1::
        LightScence();
        ModifyEvent(-2, 4, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 5, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
exit();
::label0::
        Talk("師姐！", 121, 0);
        Talk("師妹，這東西不能給他。", 2, 1);
        Talk("難道給你，你行嗎？", 0, 0);
        Talk("她不配，那我呢？", 129, 1);
        Talk("師姐你竟然勾結金輪？", 121, 0);
        if TryBattle(145) == true then goto label2 end;
            Dead();
            exit();
::label2::
            LightScence();
            Talk("不自量力。", 0, 0);
            Talk("唉，其實師姐也是可憐人……", 121, 1);
            ModifyEvent(-2, 4, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
            ModifyEvent(-2, 5, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
            AddFame(5);
exit();
