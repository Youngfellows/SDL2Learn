if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("媽的，那是我的錢啊~~~~~~~~~~", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
