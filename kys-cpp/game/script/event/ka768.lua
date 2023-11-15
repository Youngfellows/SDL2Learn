if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("愛裝傻，你這小子內力深厚，連我都毒死不了你，何況是其他下三濫．", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
