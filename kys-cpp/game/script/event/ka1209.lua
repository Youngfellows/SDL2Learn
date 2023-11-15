if isUsingItem(176) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(176, -1);
    Talk("狄兄有什麼打算?", 161, 0);
    AddItem(0, 1);
exit();
