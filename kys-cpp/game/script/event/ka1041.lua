Talk("這個離隊會不會太西斯了?", 45, 0);
Talk("閣下且住。", 0, 0);
Talk("在下欲求見段皇爺，麻煩通報。", 45, 0);
if TryBattle(193) == true then goto label0 end;
    Dead();
    exit();
::label0::
    ModifyEvent(-2, 5, 0, -2, -1, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 6, 0, -2, -1, -1, -1, -2, -2, -2, -2, -2, -2);
    LightScence();
    Talk("想見段皇爺先問過我手中的鐵槳。", 0, 0);
exit();
