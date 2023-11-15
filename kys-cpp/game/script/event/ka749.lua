if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("你這孩子叫我什么？", 161, 0);
    Add3EventNum(-2, 0, 0, 1, -1)
exit();
