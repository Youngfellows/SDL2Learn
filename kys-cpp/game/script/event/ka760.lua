if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("小寶，暈倒的阿珂姑娘鄭公子還有馮錫范怎麼辦．", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
