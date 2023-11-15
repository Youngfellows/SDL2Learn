ModifyEvent(-2, -2, -2, -2, -1, -1, -1, 2612, 2612, 2612, -2, -2, -2);
AddItem(60, 1);
Talk("小賊，偷東西？", 91, 0);
Talk("不好，被發現了。", 0, 1);
if TryBattle(99) == true then goto label0 end;
    Dead();
    exit();
::label0::
    LightScence();
    AddMorality(-1);
exit();
