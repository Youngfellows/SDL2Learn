ModifyEvent(-2, -2, -2, -2, -1, -1, -1, 2608, 2608, 2608, -2, -2, -2);
AddItem(192, 1);
Talk("大膽小賊，敢到我武當來偷東西。擺陣。", 76, 0);
Talk("是真武七截陣，就讓老子來破這爛陣吧。", 0, 1);
if TryBattle(142) == true then goto label0 end;
    Dead();
    exit();
::label0::
    LightScence();
    AddMorality(-1);
exit();
