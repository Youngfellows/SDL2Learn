Talk("小子，你居然還敢再來，找死．", 91, 0);
if TryBattle(99) == true then goto label0 end;
    Dead();
    exit();
::label0::
    ModifyEvent(-2, 5, -2, -2, 628, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 6, -2, -2, 628, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 7, -2, -2, 628, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 8, -2, -2, 628, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 9, -2, -2, 628, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 10, -2, -2, 628, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 11, -2, -2, 628, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 20, -2, -2, -1, -1, 629, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 21, -2, -2, -1, -1, 629, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 22, -2, -2, -1, -1, 629, -2, -2, -2, -2, -2, -2);
    LightScence();
exit();
