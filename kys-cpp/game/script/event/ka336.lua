ModifyEvent(-2, -2, -1, -1, -1, -1, -1, 2612, 2612, 2612, -2, -2, -2);
AddItem(41, 1);
Talk("小毛賊，本事不小啊。竟然偷到我摩天崖上來了？", 182, 0);
Talk("你就是“摩天居士”謝煙客？", 0, 1);
Talk("怎么，想逃了嗎？可惜太晚了。", 182, 0);
if TryBattle(144) == true then goto label0 end;
    Dead();
    exit();
::label0::
    LightScence();
    Talk("看來該逃的是你，謝煙客也會彈指神通，不知道和黃藥師是啥關系。", 0, 0);
exit();
