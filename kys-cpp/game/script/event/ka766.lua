if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("何姑娘，你先回島上吧，有需要幫忙我會去找你．", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
