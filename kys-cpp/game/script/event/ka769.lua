if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("老媽，小寶回來了，老媽，看來你的生意還是一樣差．", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
