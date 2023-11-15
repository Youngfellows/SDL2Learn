if CheckRoleMorality(0, 0, 40) == true then goto label0 end;
    Talk("公子別來無恙?", 0, 0);
    exit();
::label0::
    ModifyEvent(-2, -2, -2, -2, -1, -1, -1, 3500, 3500, 3500, -2, -2, -2);
    AddItem(212, 1);
    Talk("這……這是天魔功，難道就是紂王楊廣練的那個天魔功嗎?沒想到會在這里發現天魔功心法", 0, 0);
exit();
