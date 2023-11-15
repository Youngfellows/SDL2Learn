if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("中肯!靠北，你什麼時候發言變的那麼中肯．", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
