if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("那天地會跟康熙那怎麼交代?", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
