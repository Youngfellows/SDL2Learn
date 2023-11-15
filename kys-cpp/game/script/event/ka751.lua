if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("別看瓦斯爆裂斬威力不強，等你把瓦斯爆裂斬空揮九百次，太概就是你稱霸江湖的時候．", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
