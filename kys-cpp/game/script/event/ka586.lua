PlayAnimation(12, 6420, 6448);
Talk("哇！鱷魚！", 0, 1);
if TryBattle(89) == true then goto label0 end;
    Dead();
    exit();
::label0::
    ModifyEvent(-2, -2, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    ModifyEvent(-2, 12, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    SetSubMapLayerData(-2, 0, 28, 26, 358);
    LightScence();
    AddFame(1);
exit();
