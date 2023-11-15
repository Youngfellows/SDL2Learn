ModifyEvent(-2, -2, -2, -2, -1, -1, -1, 2956, 2956, 2956, -2, -2, -2);
AddItem(211, 1);
Talk("何人大膽，敢來我靈鷲宮密室盜寶？", 59, 0);
Talk("靈鷲宮？", 0, 1);
Talk("姐妹們上！", 59, 0);
if TryBattle(153) == true then goto label0 end;
    Dead();
    exit();
::label0::
    LightScence();
    Talk("不行了，要不是尊主不在。怎容你這小賊如此囂張。", 59, 0);
    Talk("聽起來她們的主人一定挺厲害，我還是見好就收，先走為妙。免得麻煩。", 0, 1);
exit();
