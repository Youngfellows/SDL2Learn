if isUsingItem(132) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(132, -1);
    Talk("公子請往里面走，島主已恭候多時了．", 41, 0);
    DarkScence();
    ModifyEvent(-2, -2, -2, -2, 351, -1, -1, 5146, 5146, 5146, -2, 30, 50);
    LightScence();
exit();
