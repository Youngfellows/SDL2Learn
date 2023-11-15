if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("這個一直想嫁入豪門的腦殘女終於想開了，最後跟著一心一意待他好的好人．", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
