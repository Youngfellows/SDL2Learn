if isUsingItem(161) == true then goto label0 end;
    exit();
::label0::
    if InTeam(35) == true then goto label1 end;
        exit();
::label1::
        SetSubMapLayerData(-2, 1, 29, 25, 0);
        SetSubMapLayerData(-2, 1, 29, 24, 3698);
        SetSubMapLayerData(-2, 1, 28, 24, 3696);
        AddItemWithoutHint(161, -1);
        ModifyEvent(-2, -2, -2, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
exit();
