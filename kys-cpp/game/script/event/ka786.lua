if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("小寶．．．你能帶我走嗎?", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
