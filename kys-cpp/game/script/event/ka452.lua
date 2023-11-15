if HaveItemBool(148) == true then goto label0 end;
    exit();
::label0::
    Talk("他媽的，四周都是黑泥，這鬼地方要怎麼進去啊！", 67, 1);
    if TryBattle(72) == true then goto label1 end;
        Dead();
        exit();
::label1::
        ModifyEvent(-2, -2, -2, -2, 451, -1, -1, -2, -2, -2, -2, -2, -2);
        ModifyEvent(-2, 16, -2, -2, 474, -1, -1, -2, -2, -2, -2, -2, -2);
        ModifyEvent(-2, 17, -2, -2, 474, -1, -1, -2, -2, -2, -2, -2, -2);
        ModifyEvent(-2, 18, -2, -2, 474, -1, -1, -2, -2, -2, -2, -2, -2);
        LightScence();
        Talk("找了那么多幫手啊。不過可惜一個比一個膿包。", 0, 1);
exit();
