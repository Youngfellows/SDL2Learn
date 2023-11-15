if InTeam(49) == true then goto label0 end;
    exit();
::label0::
    Talk("干!你怎麼帶我來這操，我要被抓去吃齋念佛了．", 49, 1);
    ModifyEvent(-2, 0, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    ModifyEvent(-2, 1, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    ModifyEvent(-2, 2, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    SetSubMapLayerData(53, 1, 22, 24, 1532);
    SetSubMapLayerData(53, 1, 22, 23, 1534);
    SetSubMapLayerData(53, 1, 23, 24, 0);
    SetSubMapLayerData(53, 1, 24, 24, 1536);
    SetSubMapLayerData(53, 1, 24, 23, 1538);
    LeaveTeam(49);
    AddMorality(10);
exit();
