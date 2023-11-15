Talk("聰明徒弟，這里無聊，我也要走了，有事到百花谷找我。", 0, 0);
Talk("郭兄弟，洪前輩的傷好了嗎?", 55, 0);
if AskJoin () == true then goto label0 end;
    Talk("好在老頑童曾經教過我九陰真經，師父照著九陰真經上的方法療傷，傷都復原了。", 0, 0);
    exit();
::label0::
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 55, 0);
        exit();
::label1::
        Talk("既然靖哥哥要跟你去大漠，那我也跟你走好了", 0, 0);
        Talk("沒事真是太好了。", 55, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(84, 1, 1, -2, 1185, -1, -1, 6126, 6148, 6126, 18, -2, -2);
        LightScence();
        Join(55);
exit();
