if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("好好，我走．", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
