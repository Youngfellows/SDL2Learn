if isUsingItem(194) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(194, -1);
    ModifyEvent(-2, -2, -2, -2, 199, 241, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(40, 2, -2, -2, 239, -1, -1, -2, -2, -2, -2, -2, -2);
    Talk("這燒刀子真是辛辣有勁，可惜美味不足．", 35, 0);
exit();
