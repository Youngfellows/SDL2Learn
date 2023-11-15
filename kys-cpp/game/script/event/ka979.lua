if HaveItemBool(69) == false then goto label0 end;
    Talk("他娘的，好在那個叫海公公的老太監還沒將我"割"了，不然我一定會為了我的小頭找你報仇．", 199, 0);
    exit();
::label0::
    Talk("哈哈，過一陣子再來看這個韋小寶。", 199, 0);
    AddItem(69, 1);
    ModifyEvent(-2, 48, 0, -2, -2, -2, 701, -2, -2, -2, -2, -2, -2);
    ModifyEvent(85, 9, -2, -2, 980, 981, -1, -2, -2, -2, -2, -2, -2);
exit();
