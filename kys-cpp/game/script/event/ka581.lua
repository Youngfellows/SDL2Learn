Talk("走", 0, 0);
if TeamIsFull() == false then goto label0 end;
    Talk("你的隊伍已滿，我無法加入．", 49, 0);
    exit();
::label0::
    DarkScence();
    ModifyEvent(-2, 2, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    LightScence();
    AddMaxMP(49, 1000);
    AddMaxHP(49, 1000);
    AddAttack(49, 80);
    AddSpeed(49, 20);
    SetMPType(person(49),2);
    Join(49);
exit();
