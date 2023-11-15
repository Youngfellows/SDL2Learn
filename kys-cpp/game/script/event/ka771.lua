if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("娘，你不用再擔心客人越來越少了，因為我發了，哈哈哈，你看這麼多的銀兩跟銀票．", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
