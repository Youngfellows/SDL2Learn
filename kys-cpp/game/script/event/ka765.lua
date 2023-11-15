if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("既然師父都跟你走了，我當然沒問題．", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
