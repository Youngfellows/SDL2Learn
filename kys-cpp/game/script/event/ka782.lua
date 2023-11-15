if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("強一點好不好，你們兩連雜碎也不如．", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
