if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("明王遠來，老衲未克遠迎。明王慈悲。", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
