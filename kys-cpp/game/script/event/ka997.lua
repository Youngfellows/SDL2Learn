Talk("哈摟，你好嗎．", 0, 0);
Talk("有人逃獄了，來人啊!", 94, 1);
if TryBattle(223) == true then goto label0 end;
    Dead();
    exit();
::label0::
    ModifyEvent(-2, 15, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    LightScence();
    Talk("干，快逃．", 0, 0);
exit();
