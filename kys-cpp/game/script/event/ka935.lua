if isUsingItem(189) == true then goto label0 end;
    exit();
::label0::
    Talk("武林大會即將展開，請少俠趕快進場．", 81, 0);
    DarkScence();
    ModifyEvent(-2, -2, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    LightScence();
exit();
