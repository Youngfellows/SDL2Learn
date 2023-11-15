if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("一個外人來到王爺府做啥，再不走把你當成奸細抓起來．", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
