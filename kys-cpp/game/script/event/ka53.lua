if isUsingItem(135) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(135, -1);
    ModifyEvent(-2, -2, -1, -1, -1, -1, -1, -2, -2, -2, -2, -2, -2);
    SetSubMapLayerData(-2, 1, 20, 20, 3694);
    SetSubMapLayerData(-2, 1, 20, 21, 4064);
    SetSubMapLayerData(-2, 1, 21, 21, 0);
exit();
