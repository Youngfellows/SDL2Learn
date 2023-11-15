Talk("閣下若無請帖，還請離開．", 82, 0);
Talk("說不得只好打了．", 0, 1);
if TryBattle(27) == true then goto label0 end;
    Dead();
    exit();
::label0::
    ModifyEvent(-2, 0, -2, -2, 183, -1, -1, 5192, 5192, 5192, -2, 30, 48);
    ModifyEvent(-2, 20, -2, -2, 183, -1, -1, 5186, 5186, 5186, -2, 27, 48);
    ModifyEvent(-2, 1, -2, -2, 183, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 2, -2, -2, 183, -1, -1, -2, -2, -2, -2, -2, -2);
    LightScence();
    AddFame(1);
exit();
