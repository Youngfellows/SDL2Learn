if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("你們怎麼會在這?", 0, 0);
    AddItem(174, 10);
    AddMorality(-1);
exit();
