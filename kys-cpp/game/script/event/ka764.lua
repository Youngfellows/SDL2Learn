if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("我也很想，但是沒有師父的允許我是不會離開渤泥島的", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
