if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("多謝姑娘，姑娘的恩情來日必定回報．", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
