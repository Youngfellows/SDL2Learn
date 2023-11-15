if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("這不是阿珂嗎?阿珂你放心，我不會再強迫你當我老婆，管你是喜歡鄭克爽還是足爽，我都不管了，咦，你怎麼哭了．", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
