if isUsingItem(165) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(165, -1);
    ModifyEvent(-2, -2, -2, -2, -1, -1, -1, 2608, 2608, 2608, -2, -2, -2);
    AddItem(39, 1);
    AddItem(5, 5);
    AddItem(186, 2);
    AddItem(170, 1);
    if InTeam(35) == false then goto label1 end;
        exit();
::label1::
        AddMorality(-1);
exit();
