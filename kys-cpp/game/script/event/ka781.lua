if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("上次你們用用毒的下三濫手法迷昏我，今日可沒這麼簡單．", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
