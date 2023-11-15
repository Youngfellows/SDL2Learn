if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("雖然我現在只是一個下人，但我相信日後民進黨一定會在我手上名揚江湖．", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
