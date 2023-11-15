if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("臭小子，我還沒去找你，你居然還趕來到我們的地盤，有種．", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
