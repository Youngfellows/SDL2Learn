if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("真有此事，他奶奶的我現在就去找那鄭克爽，替你出口氣．", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
