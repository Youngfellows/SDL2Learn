if isUsingItem(174) == true then goto label0 end;
    Talk("哈哈，等你處理完我的教眾後，我已逃離這里，後會有期．", 116, 0);
    exit();
::label0::
    if CheckEnoughMoney(100) == true then goto label1 end;
        Talk("哈哈，等你處理完我的教眾後，我已逃離這里，後會有期．", 116, 0);
        Talk("．．．．．．", 0, 0);
        exit();
::label1::
        AddItemWithoutHint(174, -100);
        ShowFame();
exit();
