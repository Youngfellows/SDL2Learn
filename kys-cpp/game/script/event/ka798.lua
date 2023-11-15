if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("小僧鳩摩智，前來天龍寺拜見各位大師，天龍威名，小僧素所欽慕，今日得見莊嚴寶相，大是歡喜。", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
