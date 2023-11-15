if CheckRoleAttack(0, 200, 1000) == true then goto label0 end;
    Talk("你知道嗎？聽說黃藥師出現在河洛客棧．", 94, 0);
    exit();
::label0::
    Talk("你知道嗎？聽說黃藥師出現在河洛客棧．", 94, 0);
    Talk("干你媽，我花了一千兩只得到這個爛情報．", 0, 0);
    DarkScence();
    OldSetScencePosition(48, 38);
    ModifyEvent(-2, 26, 0, -2, -1, -1, 984, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 27, 0, -2, -1, -1, 984, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 28, 0, -2, -1, -1, 984, -2, -2, -2, -2, -2, -2);
    LightScence();
exit();
