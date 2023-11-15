if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("每個男人心中，都有一座斷臂山……", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
